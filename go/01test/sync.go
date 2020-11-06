package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup

// 向 intChan 放入 1-12000 个数
func putNum(intChan chan int) {
	for i := 2; i < 100; i++ {
		intChan <- i
	}
	close(intChan)
	wg.Done()
}

// 从 intChan 取出数据, 并判断是否为素数
func primeNum(intChan chan int, primeChan chan int, exitChan chan bool) {
	for num := range intChan {
		g++
		var flag = true
		for i := 2; i < num; i++ {
			if num%i == 0 {
				flag = false
				break
			}
		}

		if flag {
			primeChan <- num
		}

	}

	// close(intChan)
	// 什么时候关闭 channal
	exitChan <- true
	wg.Done()

}

// 打印
func printPrime(primeChan chan int) {
	for v := range primeChan {
		fmt.Println(v)
	}
	wg.Done()
}

func main() {
	intChan := make(chan int, 1000)
	primeChan := make(chan int, 1000)
	exitChan := make(chan bool, 16) // 标志

	// 存放数字
	wg.Add(1)
	go putNum(intChan)

	// 统计素数
	for i := 0; i < 16; i++ {
		wg.Add(1)
		go primeNum(intChan, primeChan, exitChan)
	}

	// 打印素数
	wg.Add(1)
	go printPrime(primeChan)

	// 判断 exitChan 是否存满
	wg.Add(1)
	go func() {
		for i := 0; i < 16; i++ {
			<-exitChan
		}
		close(primeChan)
		wg.Done()
	}()

	wg.Wait()
}
