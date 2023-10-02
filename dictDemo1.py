#fromkeys(key,val): used to take keys and assign values from iterable

#creaing dict from list using fromkeys() method
list1 = [1,2,3,4,5]
my_dict  = dict.fromkeys(list1)
print("dict", my_dict)
#creating list using range()
print({}.fromkeys(range(1,7),10))

#--------------------------------------------------------------------
#setdefault(key, values):  using this method we can check if the value is present in the dictionary, if not it will add the value
my_dict.setdefault(6)
print(my_dict)

#--------------------------------------------------------------------
#update()
#concatenating 2 dict
d1 = {1:'one',2:'two',3:'three'}
d2 = {4:'four', 5:'five', 6:'six'}
print(d1.update(d2))
print(d1)


#adding list values in dict------------------------------------------
list1 = [7,'seven']
d1.update([list1])
print(d1)

#adding expressions using update command
print(d1)

#-----------------------------------------------------------------
#pop()-return value of the element to be deleted
dict_abc = {'a':'cat', 'b':'bat', 'c':'dog'}
print("dictionary before deleting ele: ",dict_abc)
#del---------------------------------------------------------------
del dict_abc['a']
#pop()-------------------------------------------------------------
dict_abc.pop('b')
print("after deleting element: ",dict_abc)

#clear()-used to delete all elements from a dictionary--------------
dict_abc.clear()
print("after deleting all elements from a dictionary", dict_abc)

# to delete the actual dictionary del keyword+dict_name is used------m
del dict_abc
