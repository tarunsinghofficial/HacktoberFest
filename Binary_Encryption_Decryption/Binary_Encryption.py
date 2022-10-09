import random
print("Enter Msg:")
def Sasta_Binary_Encryption(message):
    a_list1 = ['']
    a_list2 = ['']
    message = "".join(format(ord(i), 'b') for i in message)
    length = len(message)
    for i in range (length):
        value1 = random.randint(0, 1)
        value2 = random.randint(0, 1)

        a_list1.append(value1)
        a_list2.append(value2)
        #a_list =+ value
        f1 = (''.join(str(e) for e in a_list1))
        f2 = (''.join(str(e) for e in a_list2))
    print(f1+message+f2)
    print('\n')
    print(len(message))
    

Sasta_Binary_Encryption(input("").replace (" ","\\"))


#What is Lorem Ipsum Lorem Ipsum is simply dummy text of the printing and typesetting industry Lorem Ipsum has been the industry?
#889