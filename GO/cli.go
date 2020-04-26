package main

import (
  "os"

  "github.com/urfave/cli"
)

func main() {
  (&cli.App{}).Run(os.Args)
}
