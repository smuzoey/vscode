package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"os"
)

/*
复制一个文件到另一个文件
*/

func copy1(file1 string, file2 string) error {
	byteStr, err1 := ioutil.ReadFile(file1)
	if err1 != nil {
		return err1
	}

	err2 := ioutil.WriteFile(file2, byteStr, 0666)
	if err2 != nil {
		return err2
	}
	return nil

}

func copy2(file1 string, file2 string) error {
	fileS, err1 := os.Open(file1)
	fileD, err2 := os.OpenFile(file2, os.O_CREATE|os.O_WRONLY, 0666)
	defer fileS.Close()
	defer fileD.Close()
	if err1 != nil {
		return err1
	}
	if err2 != nil {
		return err2
	}

	var tempSlice = make([]byte, 128)
	for {
		n1, err := fileS.Read(tempSlice)
		if err == io.EOF {
			break
		}
		if err != nil {
			return err
		}
		if _, err := fileD.Write(tempSlice[:n1]); err != nil {
			return err
		}
	}
	return nil
}

func main() {
	err := copy2("file01.go", "test1.txt")
	if err != nil {
		fmt.Println(err)
		return
	}

}
