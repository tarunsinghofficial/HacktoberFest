def convert_dec_to_binary():
    userInput = input("Enter a decimal number to convert to Binary:")
    resultText = "The binary version of {0} is {0:b}"
    print(resultText.format(int(userInput)))


# Test
convert_dec_to_binary()
input("Press Enter to Continue:")
