package model

import "go.02test.day01.05db.utils"

// person 结构体
type Person struct {
	Id        int
	LastName  string
	FirstName string
	Address   string
	City      string
}

func (person *Person) AddPerson error {
	// 1. sql 语句
	sqlStr := "insert into person(LastName, FirstName, Address, City) values(?, ?, ?, ?)"
	// 2. 预编译
	inStmt, err := utils.Db.Prepare(sqlStr)

	if err != nil {
		fmt.Println("预编译出现异常", err)
		return err
	}
	// 执行
	_, err2 := inStmt.Exec("admin", "Yu", "hubei", "yichang")
	if err2 != nil {
		fmt.Println("预编译出现异常", err)
		return err
	}
	return nil

}

func (person *Person) AddPerson2 error {
	// 1. sql 语句
	sqlStr := "insert into person(LastName, FirstName, Address, City) values(?, ?, ?, ?)"

	// 2. 执行
	_, err2 := utils.Db.Exec(sqlStr, "admin", "Yu", "hubei", "yichang")
	if err2 != nil {
		fmt.Println("预编译出现异常", err)
		return err
	}
	return nil
}
