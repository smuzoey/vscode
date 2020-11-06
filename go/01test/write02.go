package main

import (
	"bufio"
	"fmt"
	"os"
)

/*
1、打开文件 os.OpenFile("fileName", , 0666)
2、创建 writer 对象  bufio.NewWriter(file)
3、将数据写入缓存  writer.WriteString("content")
4、将缓存内容写入文件 writer.Flush()
5、关闭文件流  file.Close()

*/
func main() {
	file, err := os.OpenFile("./test1.txt", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0666)
	defer file.Close()
	if err != nil {
		fmt.Println(err)
		return
	}

	// 写入

	writer := bufio.NewWriter(file)
	writer.WriteString("你好")
	writer.Flush()
}
