#Famous problem on CodeChef and LeetCode is Fizz Buzz problem
'''
The concept of this problem is that
if the number entered by user is divisible by 3 and not by 5, then we print Fizz on Console
if the number entered by user is divisible by 5 and not by 3, then we print Buzz on Console
if the number entered by user is divisible by 3 and 5 both, then we print Fizz Buzz on Console
'''

num = int(input())
if(num%3==0 and num%5==0):
    print("Fizz Buzz")
elif(num%3==0 and num%5!=0):
    print("Fizz")
elif(num%3!=0 and num%5==0):
    print("Buzz")
else:
    print("Entered number is neither divisible by 3 nor 5")