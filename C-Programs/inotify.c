#include <stdio.h>
#include <sys/inotify.h>
#include <errno.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>

static void
handle_events(int fd, int *wd)
{
    /* Some systems cannot read integer variables if they are not
       properly aligned. On other systems, incorrect alignment may
       decrease performance. Hence, the buffer used for reading from
       the inotify file descriptor should have the same alignment as
       struct inotify_event. */

    char buf[4096]
        __attribute__ ((aligned(__alignof__(struct inotify_event))));
    const struct inotify_event *event;
    int i;
    ssize_t len;
    char *ptr;

    /* Loop while events can be read from inotify file descriptor. */

    for (;;) {

        /* Read some events. */

        len = read(fd, buf, sizeof buf);
        if (len == -1 && errno != EAGAIN) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        /* If the nonblocking read() found no events to read, then
           it returns -1 with errno set to EAGAIN. In that case,
           we exit the loop. */

        if (len <= 0)
            break;

        /* Loop over all events in the buffer */

        for (ptr = buf; ptr < buf + len;
                ptr += sizeof(struct inotify_event) + event->len) {

            event = (const struct inotify_event *) ptr;

            /* Print event type */

            printf("\n Event mask %x \n", event->mask);

            if (event->mask & IN_ACCESS)
                printf("IN_ACCESS : ");
            if (event->mask & IN_ATTRIB)
                printf("IN_ATTRIB: ");
            if (event->mask & IN_CLOSE_WRITE)
                printf("IN_CLOSE_WRITE: ");
            if (event->mask & IN_CLOSE_NOWRITE)
                printf("IN_CLOSE_NOWRITE: ");
            if (event->mask & IN_CREATE)
                printf("IN_CREATE: ");
            if (event->mask & IN_DELETE)
                printf("IN_DELETE: ");
            if (event->mask & IN_DELETE_SELF)
                printf("IN_DELETE_SELF: ");
            
            if (event->mask & IN_MODIFY)
                printf("IN_MODIFY: ");
            if (event->mask & IN_MOVE_SELF)
                printf("IN_MOVE_SELF: ");

            if (event->mask & IN_MOVED_FROM)
                printf("IN_MOVED_FROM: ");

            if (event->mask & IN_MOVED_TO)
                printf("IN_MOVED_TO: ");
            if (event->mask & IN_OPEN)
                printf("IN_OPEN: ");
            if (event->mask & IN_IGNORED)
                printf("IN_IGNORE: file deleted ");

            /* Print the name of the watched directory */

            for (i = 1; i < 2; ++i) {
                if (wd[0] == event->wd) {
                    printf("/tmp/my.config");
                    break;
                }
            }

            /* Print the name of the file */

            if (event->len)
                printf("%s", event->name);

            /* Print type of filesystem object */

            if (event->mask & IN_ISDIR)
                printf(" [directory]\n");
            else
                printf(" [file]\n");
        }
    }
}

int main()
{
  int fd = inotify_init1(IN_NONBLOCK);
  int poll_num;
  nfds_t nfds;
  struct pollfd fds[1];
  int wd;


  if (fd == -1) 
  {
      perror("inotify_init1");
      exit(EXIT_FAILURE);
  }

  wd = inotify_add_watch(fd, "/tmp/my.config", IN_OPEN | IN_CLOSE);
  if (wd == -1) 
  {
      fprintf(stderr, "Cannot watch \n");
      perror("inotify_add_watch");
      exit(1);
  }

  /* Prepare for polling */

  nfds = 1;

  /* Inotify input */

  fds[0].fd = fd;
  fds[0].events = POLLIN;

  /* Wait for events and/or terminal input */

  printf("Listening for events.\n");
  while (1) 
  {
    poll_num = poll(fds, nfds, -1);
    if (poll_num == -1) {
        if (errno == EINTR)
            continue;
        perror("poll");
        exit(1);
    }

    if (poll_num > 0) 
    {
      if (fds[0].revents & POLLIN) 
      {

          /* Inotify events are available */

          handle_events(fd, &wd);
      }
    }
  }
  return 0;
}
