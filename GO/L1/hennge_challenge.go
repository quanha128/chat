package main

import "fmt"

func recSum2(n int) int {
	if (n > 1) {
		var num int
		fmt.Scanf("%d", &num)
		if (num > 0){ 
			return (num*num) + recSum2(n-1)
		} else {
			return 0 + recSum2(n-1)
		}
	} else {
		var num int
		fmt.Scanf("%d", &num)
		if (num > 0){ 
			return (num*num)
		} else {
			return 0
		}
	}
}

func loopN(n int, f func(int) int) {
	if n<=0 {
		return
	} else {
		var val int
		fmt.Scanf("%d", &val)
		res := f(val)
		fmt.Println(res)
		loopN(n-1, f)
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	loopN(n, recSum2)
}