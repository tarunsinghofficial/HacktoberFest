from googletrans import Translator

la=input("Enter the sentence:")

t=Translator()

result=t.translate(la,src='en', dest='ne')

print(result)
