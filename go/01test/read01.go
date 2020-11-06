package main

import (
	"fmt"
	"io"
	"os"
)

/*
	只读方式打开文件 os.Open("")
	读取文件 file.Read()
	关闭流文件 defer file.Close()
*/
func main() {
	file, err := os.Open("./main.go")
	defer file.Close()

	if err != nil {
		fmt.Println(err)
		return
	}
	var strSlice []byte
	var tempSlice = make([]byte, 128)
	for {
		n, err := file.Read(tempSlice)
		if err == io.EOF {
			fmt.Println("结束")
			break
		}
		if err != nil {
			fmt.Println(err)
			return
		}
		strSlice = append(strSlice, tempSlice[:n]...)
	}

	fmt.Println(string(strSlice))
}
