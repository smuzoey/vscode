package main

import (
	"fmt"
	"net/http"
	"time"
)

type MyHandler struct{}

func (m *MyHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, "通过详细配置自己的服务器信息", r.URL.Path)
}

func main() {
	myHandler := MyHandler{}

	// 创建 server 结构， 并详细配置
	server := http.Server{
		Addr:        ":8080",
		Handler:     &myHandler,
		ReadTimeout: 2 * time.Second,
	}
	server.ListenAndServe()
	//http.Handle("/myhandle", &myHandler)
	// http.ListenAndServe(":8080", nil)

}
