package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	gridsize := strings.Fields(line)

	r, _ := strconv.Atoi(gridsize[0])
	c, _ := strconv.Atoi(gridsize[1])

	var occ [3]int
	var first int 
	var last int
	i := 0
	for scanner.Scan() {
		line := scanner.Text()
		row := strings.Fields(line)
		for j, field := range row {
			val, _ := strconv.Atoi(field)
			if i == 0 && j == 0 {
				first = val
			}
			occ[val]++
			last = val
		}
		i++
	}

	if occ[0] >= 2 {
		fmt.Println(0)
	} 
	if occ[0] == 1 {
		if occ[1] == 0 {
			fmt.Println(2)
		} else {
			if (r == 1 || c == 1) && (first != 1 && last != 1) {
				fmt.Println(2)
			} else {
				fmt.Println(1)
			}
		}
	}
	if occ[0] == 0 {
		if occ[2] % 2 == 0 {
			fmt.Println(0)
		} else {
			fmt.Println(int64(1) << (occ[2] / 2)) 
		}
	}
}
