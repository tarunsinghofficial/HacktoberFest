#Created by Subhadeep Mandal
weight = int(input("Enter weight in kg\n"))
height = float(input("Enter height  in metre\n"))

BMI=weight/(height*height)

if BMI < 18.5:
    print ("Underweight")
elif BMI >=18.5 and BMI<25:
    print ("Normal")
elif BMI >=25 and BMI<30:
    print ("Overweight")
elif BMI>30:
    print ("Obesity")
