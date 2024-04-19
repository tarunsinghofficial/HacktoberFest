# importing speech recognition package from google api 
import speech_recognition as sr 
import playsound # to play saved mp3 file 
from gtts import gTTS # google text to speech 
import os # to save/open files 
import wolframalpha # to calculate strings into formula 
from selenium import webdriver # to control browser operations 

num = 1
def assistant_speaks(output): 
	global num 

	# num to rename every audio file 
	# with different name to remove ambiguity 
	num += 1
	print("PerSon : ", output) 

	toSpeak = gTTS(text = output, lang ='en', slow = False) 
	# saving the audio file given by google text to speech 
	file = str(num)+".mp3 
	toSpeak.save(file) 
	
	# playsound package is used to play the same file. 
	playsound.playsound(file, True) 
	os.remove(file) 



def get_audio(): 

	rObject = sr.Recognizer() 
	audio = '' 

	with sr.Microphone() as source: 
		print("Speak...") 
		
		# recording the audio using speech recognition 
		audio = rObject.listen(source, phrase_time_limit = 5) 
	print("Stop.") # limit 5 secs 

	try: 

		text = rObject.recognize_google(audio, language ='en-US') 
		print("You : ", text) 
		return text 

	except: 

		assistant_speaks("Could not understand your audio, PLease try again !") 
		return 0


# Driver Code 
if __name__ == "__main__": 
	assistant_speaks("What's your name, Human?") 
	name ='Human'
	name = get_audio() 
	assistant_speaks("Hello, " + name + '.') 
	
	while(1): 

		assistant_speaks("What can i do for you?") 
		text = get_audio().lower() 

		if text == 0: 
			continue

		if "exit" in str(text) or "bye" in str(text) or "sleep" in str(text): 
			assistant_speaks("Ok bye, "+ name+'.') 
			break

		# calling process text to process the query 
		process_text(text) 
