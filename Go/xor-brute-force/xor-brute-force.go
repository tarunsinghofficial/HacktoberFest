package main

import (
	"encoding/hex"
	"fmt"
)

func main() {
	// Hex encoded string -> Here I use "teststring" xored with 0x19
	hexString := "6d7c6a6d6a6d6b70777e"
	bytesString, _ := hex.DecodeString(hexString)
	var bytesResult []byte

	for i := 1; i <= 255; i++ {
		bytesResult = nil
		for j := 0; j < len(bytesString); j++ {
			byteResult := bytesString[j] ^ byte(i)
			bytesResult = append(bytesResult, byteResult)
		}
		h := fmt.Sprintf("%X", i)
		fmt.Println("Bytes = 0x" + h + " result = " + string(bytesResult))
	}
}
