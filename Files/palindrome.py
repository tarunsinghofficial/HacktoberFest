#!/usr/bin/env python
# coding: utf-8

# In[3]:


def isPalindrome(s):
	return s == s[::-1]


# Driver code
s = "123321"
ans = isPalindrome(s)

if ans:
	print("Yes")
else:
	print("No")


# In[ ]:




