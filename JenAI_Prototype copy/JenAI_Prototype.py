import pyttsx3,webbrowser,datetime,wikipedia
import speech_recognition as sr
def Com_Input():
    Recognizer=sr.Recognizer()
    with sr.Microphone() as source:
        print ("InitiliZation completed")
        
        Recognizer.pause_threshold = 0.7
        audio=Recognizer.listen(source)
        while True:
            try:
                print ("Recognizing audio...")
                Query= Recognizer.recognize_google(audio,language='en-in')
                print("Command received = ",Query)
            except Exception as e:
                print(e)
                print("Please try again")
            return Query.lower()
def speak(audio):
    engine=pyttsx3.init()
    voices = engine.getProperty('voices')
    engine.setProperty('voice', voices[1].id)
    engine.say(audio)
    engine.runAndWait()
def tellDay():
    day = datetime.datetime.today().weekday() + 1
    Day_dict = {1: 'Monday', 2: 'Tuesday',
                3: 'Wednesday', 4: 'Thursday',
                5: 'Friday', 6: 'Saturday',
                7: 'Sunday'}
    if day in Day_dict.keys():
        day_of_the_week = Day_dict[day]
        print(day_of_the_week)
        speak("The day is " + day_of_the_week)
def tellTime():
    time = str(datetime.datetime.now())
    print(time)
    hour = time[11:13]
    min = time[14:16]
    speak("Yeah Abhi , the time is " + hour + "Hours and" + min + "Minutes") 
def Hello():
    speak("What's up O V ! How may I help you?")
def Take_query():
    Hello()
    while(True):
        query = Com_Input()
        if "open spotify" in query:
            speak("Opening Spotify... ")
            webbrowser.open("www.spotify.com")
            continue
        elif "open ddg"in query:
            speak("Opening DuckDuckGo... ")
            webbrowser.open("www.duckduckgo.com")
            continue
        elif "which day is it "in query:
            tellDay()
            continue
        elif "tell me the time"in query:
            tellTime()
            continue
        elif "from wikipedia" in query:
            speak("Checking Wikipedia...")
            query = query.replace("wikipedia", "")
            result = wikipedia.summary(query, sentences=4)
            speak("According to wikipedia,")
            speak(result)
            continue
        elif "tell me your name"in query:
            speak("I am Jenny . Your desktop Assistant")
            continue
        elif "bye" in query:
            speak("Bye O V")
            exit()
        else:
            speak("I didnt understand you . Please say that again.")
if __name__ == '__main__':
    Take_query()