import pyttsx3
import speech_recognition as voiceInput
import webbrowser
import datetime
import wikipedia
import os
import pywhatkit
import pyjokes
import time

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)

#print(voices[1].id)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    speak("Hello Git ish")

def takeCommand():
    r = voiceInput.Recognizer()
    with voiceInput.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        print("Listning...")
        r.pause_threshold = 1
        audio = r.listen(source)
    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        # print(e)
        print("Sorry I couldn't understand...")
        return "None"
    return query


if __name__=="__main__" :
    wishMe()


    while True:
        #if 1:
        query = takeCommand().lower()

        if "what's the time" in query:
            time = datetime.datetime.now().strftime('%H:%M:')
            print(time)
            speak('Time is just running. By the way its ' + time)

        elif 'wikipedia' in query:
            speak('searching...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("Wikipedia Says")
            print (results)
            speak (results)

        elif 'open youtube' in query:
            webbrowser.open("youtube.com")
            speak("Working on It")
            speak("There you go")

        elif 'open google' in query:
            webbrowser.open("google.com")
            speak("Working on It")
            speak("There you go")
        
        elif 'play' in query:
            song = query.replace('play', '')
            speak('Let me get it')
            pywhatkit.playonyt(song)
            speak('playing' + song)

        elif 'feeling a bit low' in query:
            speak('no dont be. Let me crack a joke')
            speak(pyjokes.get_joke())
        
        elif 'what is' in query:
            results = wikipedia.summary(query, sentences=2)
            print(results)
            speak (results)

        elif 'miss you' in query:
            speak("Well i don't miss you. So Fuck you!")
            

