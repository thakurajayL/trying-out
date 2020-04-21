#include "stdio.h"
#include "stdlib.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "string.h"
#include "stdbool.h"

struct in_addr addr_i, mask_i;
#define GET_UE_IP(ue_index) \
      (((addr_i.s_addr | (~mask_i.s_addr)) \
           - htonl(ue_index)) - 0x00000000)

struct ip_table
{
  struct ip_table *byte[256];
  char *address; // address
};
struct ip_table *root;

void add_node(struct in_addr addr);
bool find_node(struct in_addr host);

int main()
{
  int i;
  char *addr = "10.1.1.0";
  char *mask = "255.255.255.0";
  inet_aton(addr, &addr_i);
  inet_aton(mask, &mask_i);
  printf("\n Addr/Mask  = %s %s \n", addr, mask);
  printf("\n Addr/Mask  = %s %s \n", inet_ntoa(addr_i), inet_ntoa(mask_i));

  for(i=0; i <10; i++)
  {
     struct in_addr ue_ip;
     ue_ip.s_addr = GET_UE_IP(i);
     printf("UE IP address = %s \n", inet_ntoa(ue_ip));
     add_node(ue_ip);
  }
    char *addr1 = "10.1.1.250";
  struct in_addr addr1_i;
  inet_aton(addr1, &addr1_i);
  find_node(addr1_i);
  for(i=0; i <20; i++)
  {
     struct in_addr ue_ip;
     ue_ip.s_addr = GET_UE_IP(i);
     printf("Search UE IP address = %s \n", inet_ntoa(ue_ip));
     find_node(ue_ip);
  }
}
//     struct in_addr ue_ip = (((addr_i.s_addr | (~mask_i.s_addr)) - htonl(i)) - 0x01000000);

void add_node(struct in_addr host)
{
   struct ip_table *search_tree=NULL;
   unsigned char first_byte, second_byte, third_byte, fourth_byte;
   uint32_t addr = host.s_addr;
   if(root == NULL)
     root = calloc(1, sizeof(struct ip_table));

   search_tree = root;
   first_byte = (0xff000000 & addr) >> 24;
   if(root->byte[first_byte] == NULL)
   {
     search_tree->byte[first_byte] = calloc(1, sizeof(struct ip_table));
   }
   search_tree = search_tree->byte[first_byte];


   second_byte = (0xff0000 & addr) >> 16;
   if(search_tree->byte[second_byte] == NULL)
   {
     search_tree->byte[second_byte] = calloc(1, sizeof(struct ip_table));
   }
   search_tree = search_tree->byte[second_byte];

   third_byte = (0xff00 & addr) >> 8;
   if(search_tree->byte[third_byte] == NULL)
   {
     search_tree->byte[third_byte] = calloc(1, sizeof(struct ip_table));
   }
   search_tree = search_tree->byte[third_byte];


   fourth_byte = (0xff & addr) >> 0;
   if(search_tree->byte[fourth_byte] == NULL)
   {
     search_tree->byte[fourth_byte] = calloc(1, sizeof(struct ip_table));
   }
   search_tree = search_tree->byte[fourth_byte];
   char *p = inet_ntoa(host);
   search_tree->address = calloc(1,20);
   strcpy(search_tree->address, p);

   return;
}

bool find_node(struct in_addr host)
{
  struct ip_table *search_tree=NULL;
  unsigned char byte;
  search_tree = root;

  byte = ((host.s_addr) & 0xff000000)>>24;
  if(search_tree->byte[byte] == NULL)
  {
    return false;
  }
  search_tree = search_tree->byte[byte];

  byte = ((host.s_addr) & 0xff0000)>>16;
  if(search_tree->byte[byte] == NULL)
  {
    return false;
  }
  search_tree = search_tree->byte[byte];

  byte = ((host.s_addr) & 0xff00)>>8;
  if(search_tree->byte[byte] == NULL)
  {
    return false;
  }
  search_tree = search_tree->byte[byte];


  byte = ((host.s_addr) & 0xff);
  if(search_tree->byte[byte] == NULL)
  {
    return false;
  }

    search_tree = search_tree->byte[byte];
  printf("Found address %s \n", search_tree->address);
  return true;
}
