roll_no = [23,43,41,26,45,53,2,12,74]
print("Selection Sort")
for i in range(len(roll_no)):
    min_val_index=i
    for j in range(i+1,len(roll_no)):
        if roll_no[min_val_index]>roll_no[j]:
            min_val_index=j
    
    roll_no[i],roll_no[min_val_index]=roll_no[min_val_index],roll_no[i]

print(roll_no)