package main

import (
	"fmt"
	"os"
	"log"
	"io/ioutil"
	"strings"
	"strconv"
	"github.com/pkg/errors"
)

func killServer(pidFile string) error {
	data, err := ioutil.ReadFile(pidFile)
	if err != nil {
		return errors.Wrap(err, "Cant open pidFile")
	}

	if err := os.Remove(pidFile); err != nil {
		log.Printf("warning: can't remove pid file - %s",err)
	}
	strPID := strings.TrimSpace(string(data))
	pid, err := strconv.Atoi(strPID)
	if err != nil {
		return errors.Wrap(err,"bad process PID ")
	}
	fmt.Printf("killing process with pid = %d\n",pid)
	return nil

}

func main() {
	if err := killServer("server.pid"); err != nil {
		fmt.Fprintf(os.Stderr, "Error : %s\n",err)
		os.Exit(1)
	}
}
