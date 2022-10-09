def Sasta_Binary_Decryption(binary):
    string = int(binary, 2)
    return string

bin_data = (input("Enter Binary:\n"))
n = int(input("Msg Length:\n"))

str_data =''


for i in range (0,len(bin_data)):
    bin_data = bin_data[n:2*n] 
    break
#print(bin_data)

for i in range(0, len(bin_data), 7):

    temp_data = bin_data[i:i + 7]

    decimal_data = Sasta_Binary_Decryption(temp_data)

    str_data = str_data + chr(decimal_data)

# printing the result

print("Decrypted Text:\n"+str_data.replace("\\"," "))
