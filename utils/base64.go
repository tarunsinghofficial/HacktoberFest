package utils

import "encoding/base64"

func EncodeBase64(data string) (result string, err error) {
	encoded := make([]byte, base64.StdEncoding.EncodedLen(len(data)))
	base64.StdEncoding.Encode(encoded, []byte(data))

	result = string(encoded)

	return result, err
}

func DecodeBase64(data string) (result string, err error) {
	decoded := make([]byte, base64.StdEncoding.DecodedLen(len(data)))
	_, err = base64.StdEncoding.Decode(decoded, []byte(data))
	if err != nil {
		return result, err
	}
	result = string(decoded)

	return result, err
}
