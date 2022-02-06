import serial
import cv2
import pytesseract
import numpy as np


pytesseract.pytesseract.tesseract_cmd = r"C:\\Program Files\\Tesseract-OCR\\tesseract.exe"
img = cv2.imread("./dataset/example.jpg")


# # Grayscale image
# img = Image.open('num.png').convert('L')
# ret,img = cv2.threshold(np.array(img), 125, 255, cv2.THRESH_BINARY)
ser = serial.Serial('COM8' , 9600 , timeout=0)

while 1:
    ser.write("words_in_image.encode()".encode())