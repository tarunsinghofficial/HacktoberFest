import pygame, sys, os, time
import random
import config

IS_WINDOWS = os.name == "nt"
IS_MAC = sys.platform == "darwin"

def clear_screen():
    if IS_WINDOWS:
        os.system("cls")
    else:
        os.system("clear")

def songloop():
    print("Playing a random song... [{}]".format(time.ctime()))
    pygame.mixer.init()
    try:
        pygame.mixer.music.load("songs/{}".format(random.choice(config.songs)))
        pygame.mixer.music.play()
    except:
        clear_screen()
        input("Unable to play/load a song!")
        songloop()
    while pygame.mixer.music.get_busy() == True:
        continue
    songloop()

clear_screen()
print("Song Log:\n")
print("CTRL + C Exit")
songloop()
