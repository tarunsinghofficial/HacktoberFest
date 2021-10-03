import googletrans
dict1 = googletrans.LANGUAGES
dict2 = {}
count = 0
for i in dict1.items():
    dict2[i[1]]=i[0]
print(dict2)