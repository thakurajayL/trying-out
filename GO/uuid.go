package main

import (
    "fmt"
    "github.com/google/uuid"
)

func main() {
    x := uuid.New().URN()
    fmt.Println("UUID ", x)
}
