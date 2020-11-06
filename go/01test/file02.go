package main

import (
	"fmt"
	"os"
)

func main() {
	err := os.Mkdir("abc", 0666)
	// err := os.MkdirAll("abc", 0666)
	// os.Remove("")
	// os.RemoveAll("")
	// os.Rename("", "")
	if err != nil {
		fmt.Println(err)
	}
}
