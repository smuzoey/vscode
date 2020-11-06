package main

import (
	"fmt"
	"io/ioutil"
)

/*
	封装好的  就一行就可以
	ioutil.ReadFile("")
*/

func main() {
	byteStr, err := ioutil.ReadFile("./main.go")
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(string(byteStr))
}
