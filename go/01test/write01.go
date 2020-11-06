package main

import (
	"fmt"
	"os"
)

/*
打开文件 os.OpenFile("file", 权限, 066)
1、file.Write([]byte(str))  // 将 byte 写入
2、file.WriteString("写入")  // 直接写入字符串



权限：
	os.O_WRONLY  只写
	os.O_CREATE	 创建文件
	os.O_RDONLY  只读
	os.O_RDWR    读写
	os.O_TRUNC	 清空
	os.O_APPEND  追加


	清空文件用 os.O_TRUNC
	直接在文件结尾部分添加则 os.O_APPEND
*/

func main() {
	file, err := os.OpenFile("./test1.txt", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0666)
	defer file.Close()
	if err != nil {
		fmt.Println(err)
		return
	}

	// 写入
	for i := 0; i < 5; i++ {
		file.WriteString("&&&&&\r\n")
	}

}
