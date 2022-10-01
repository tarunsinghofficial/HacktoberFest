# use to convert link to qr code
import pyqrcode
from PIL import Image 
link = input("Enter the link: ")
qr = pyqrcode.create(link)
qr.png('qr.png', scale=6)
img = Image.open('qr.png')
