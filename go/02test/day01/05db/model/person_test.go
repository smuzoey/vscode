package model

import (
	"fmt"
	"testing"
)

func TestAddPerson(t *testing.T) {
	fmt.Println("测试添加用户")
	person := &Person{}

	person.AddPerson()
	person.AddPerson2()
}
