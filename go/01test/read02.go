package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

/*	
	只读方式打开文件 os.Open("")
	创建 reader 对象 reader := bufio.NewReader(file)
	ReadString 读取文件 str, err := reader.ReadString('\n') // 读取一行
	关闭文件流 defer file.Close()
*/

func main() {
	file, err := os.Open("./main.go")
	defer file.Close()

	if err != nil {
		fmt.Println(err)
		return
	}

	// bufio 读取文件
	var fileStr string
	reader := bufio.NewReader(file)
	for {
		str, err := reader.ReadString('\n') // 读取一行
		if err == io.EOF {
			fileStr += str
			break
		}
		if err != nil {
			fmt.Println(err)
			return
		}
		fileStr += str
	}
	fmt.Println(fileStr)

}
