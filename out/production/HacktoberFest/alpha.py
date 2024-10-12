#Sorting the words from the list as arranged in a dictionary
def alpha(list):
    for i in range(len(words)):
        if words[i]>words[i+1]:
            words[i],words[i+1]=words[i+1],words[i]
            if words==sorted(words):
                return words
            else:
                return alpha(words)
words=["HASH", "ALGO", "NAME", "TIME", "DATE", "ZONE", "ROOM", "DUTY", "ROLE"]
print(alpha(words))
