def is_leap(year):
    while year%4==0:
        if year%100==0:
            
            if year%400==0:
                leap = True
                break
            
            else:
                leap = False
                break
        
        else:
            leap = True
            break
    else:
        leap = False
        
    # Write your logic here
    
    return leap

year = int(input("Enter The Year"))
print(is_leap(year))