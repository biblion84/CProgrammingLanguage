package main

import (
	"fmt"
	"log"
	"os"
	"strings"
)
func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func main() {
	f, err := os.ReadFile("input.txt")
	ck(err)

	oxygen := getOxygen(f)
	scrubber := getScrubber(f)

	print(oxygen, "\n", scrubber)

}

func getOxygen(f []byte) string {
	input := strings.Split(string(f), "\r\n")
	size := len(input[0])
	found := ""
	for i := 0; i < size; i++ {
		zero := 0
		one := 0
		for _, line := range input {
			if line[i] == '0' {
				zero++
			} else {
				one++
			}
		}
		newInput := []string{}
		toFind := '0'
		if one >= zero {
			toFind = '1'
		}
		fmt.Printf("Y : %d : %d \n", zero, one)

		fmt.Printf("X : %c \n", toFind)
		for _, line := range input {
			if []rune(line)[i] == toFind {
				newInput = append(newInput, line)
			}
		}
		input = newInput
		if len(input) == 1 {
			print("XXX\n")
			found = input[0]
			break
		}
	}
	return found
}
func getScrubber(f []byte) string {
	input := strings.Split(string(f), "\r\n")
	size := len(input[0])
	found := ""
	for i := 0; i < size; i++ {
		zero := 0
		one := 0
		for _, line := range input {
			if line[i] == '0' {
				zero++
			} else {
				one++
			}
		}
		newInput := []string{}
		toFind := '1'
		if one >= zero {
			toFind = '0'
		}
		fmt.Printf("Y : %d : %d \n", zero, one)

		fmt.Printf("X : %c \n", toFind)
		for _, line := range input {
			if []rune(line)[i] == toFind {
				newInput = append(newInput, line)
			}
		}
		input = newInput
		if len(input) == 1 {
			print("XXX\n")
			found = input[0]
			break
		}
	}
	return found
}
