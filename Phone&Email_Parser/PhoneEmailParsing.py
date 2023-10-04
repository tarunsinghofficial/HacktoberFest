# A Python program which takes data from user's clipboard, Parses it for all Email addresses and Phone Numbers.
#Writes them to separate files and copies the entire data to the clipboard.
import re,pyperclip,pprint
PhoneFile = open("Phone.txt", "a+")
EmailFile = open("Email.txt", "a+")
EmailRegex=re.compile(r'[a-zA-Z0-9.+_]+\@[a-zA-Z0-9.+_]+')
#PhoneRegex=re.compile(r'\d\d\d-\d\d\d-\d\d\d\d') # for US
PhoneRegex=re.compile(r'\+91\d{10}') # for India 
Text=pyperclip.paste()
ExtractedPhone=PhoneRegex.findall(Text)
ExtractedEmail=EmailRegex.findall(Text)
AllPhone=[]
for Number in ExtractedPhone:
    PhoneFile.write(Number)
for Mail in ExtractedEmail:
    EmailFile.write(Mail)
print("Phone Numbers : ",end='\n')
pprint.pprint(ExtractedPhone)
print("Emails : ",end='\n')
pprint.pprint(ExtractedEmail)
Results= '\n'.join(ExtractedPhone)+'\n'+'\n'.join(ExtractedEmail)
pyperclip.copy(Results)
PhoneFile.close()
EmailFile.close()

