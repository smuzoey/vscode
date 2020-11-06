package main

import (
	"fmt"
	"io/ioutil"
)

func main() {
	str := "hello hhhh"
	err := ioutil.WriteFile("test01.txt", []byte(str), 0666)

	if err != nil {
		fmt.Println(err)
		return
	}
}
