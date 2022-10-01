## Bash Scripting

I made these notes, while learning Bash Scripting. I hope you find this helpful 

```bash
#!/bin/bash

#Variables (No Spacing before and after =)
first_name=Anmol
second_name=Singh

#Referencing Variable withh '$' sign
echo Hii $first_name $second_name

#Difference b/w ['] & ["]
greeting='Hello World'
echo $greeting
greeting2="New $greeting"
echo $greeting2

#Command Substitution:set the value of the variable to the result of a command or program
user=$(whoami)
echo $user
#An alternative syntax for command substitution
user2=`whoami`
echo $user2

#Arguments : $1-$9 is used to [rovide 1st 9 arguments
echo Hello $1

#Special Bash Variables
echo $$         #PID of current bash
echo $USER      #Username of curr user
echo $HOSTNAME  #Hostnme of Machine
echo $RANDOM    #A Random number
echo $LINENO    #The Current Line No. in Script

#Reading User Input from interactive shell
#echo "Hello There, What is your name ??"
#read answer
#echo hiii $answer

#Advancement in Reading Input
#Prompt the user for input '-p'
#Make user input silent '-s'
#read -p 'Username:' username
#read -sp 'Password:' password
#echo "Thanks $username, your password is - $password"

#Conditional Statements
#read -p "What is Your Age ??" age
# if [ $age -lt 18 ]  #Space is mandatory
# then
#     echo "Too young for DL"
# elif [ $age -gt 60 ] 
# then 
#     echo "Re-Apply for DL"
# else
#     echo "Apply for DL"

# fi



#---------  Common Test Commands ---------------------------------
# !EXPRESSION   : The Expression is False
# -n STRING     : String length is greater than Zero
# -z STRING     : String length is zero
# STR1 != STR2  : String1 is not equal to String2
# STR1 = STR2   : String1 is equal to String2
# INT1 -eq INT2 : Integer1 is equal to Integer2
# INT1 -ne INT2 : Integer1 is not equal to Integer2
# INT1 -gt INT2 : Integer1 is greater than Integer2
# INT1 -lt INT2 : Integer1 is Less than Integer2
# INT1 -ge INT2 : Integer1 is greater than or equal to  Integer2
# INT1 -le INT2 : Integer1 is less than or equal to Integer2
# -d File       : File exists and is a Directory
# -e File       : File exists
# -r File       : File exists and has read permissions
# -s File       : File exists and is not empty
# -w File       : File exists and has write permission
# -x File       : File exists and has executable permission
#----------------------------------------------------------------------       


#Boolean Logical Operators: &&, ||,  |
# read -p 'Enter Username' user3
# grep $user3 /etc/passwd && echo "$user3 found!!" || echo "$user3 not found"


#Loops
# The for loop will take each item in the list (in order), assign that item as the value of the variable
# var-name, perform the given action between do and done,

# for ip in $(seq 1 255);
# do 
# echo 192.168.0.$ip;
# done

#While Loops

# counter=1
# while [ $counter -le 10 ]
# do
# echo "10.11.1.$counter"
# ((counter++))
# done

#Functions

# print_me(){
#     echo "Function Called: You've been printed"
# }

# print_me

# FUnctions with Arguments
print_me(){
    echo "Function Called: You've been printed $1"
}
print_me Anmol
```
