import cv2
from cvzone.ClassificationModule import Classifier
import numpy as np
import math
import pytesseract
import subprocess
import speech_recognition
import pyttsx3

cap = cv2.VideoCapture(0)
classifier = Classifier("Models/main_model.h5", "Models/labels.txt")
classifier_light  = Classifier("Models/light_model.h5","Models/labels_light.txt")
classifier_sign = Classifier("Models/sign_model.h5","Models/labels_sign.txt")
imgSize = 300

labels = ["blank","apple","book","Person","Sign","traffic"]
trafficlabel = ["GREEN","RED"]
signlabel= ["STOP","CROSS","NOENTRY","HOSPITAL"]
det=False
count=0
pObj=''
desCount=0

while True:
    success, img = cap.read()
    count=count+1
    if(count>=30):
        det=True
    if success and det:
        imgResize = cv2.resize(img, (imgSize, imgSize))
        prediction, index = classifier.getPrediction(imgResize, draw=False)
        print(prediction, index)
        print(labels[index])
        cObj = labels[index]
        if cObj == pObj:
            desCount = desCount+1
            if desCount>=4:
                if cObj == 'traffic':
                    predictiontf, indtf = classifier_light.getPrediction(imgResize, draw=False)
                    print(predictiontf,indtf)
                    print("TRAFFIC LIGHT IS : "+trafficlabel[indtf])
                if cObj == "book":
                    rgb = cv2.cvtColor(imgResize,cv2.COLOR_BGR2RGB)
                    #cv2.imshow("image",img)
                    config_tesseract = '--tessdata-dir tessdata --psm 6'
                    text = pytesseract.image_to_string(rgb,lang='eng',config = config_tesseract)
                    print(text)
                if cObj=="sign":
                    predictionsi, indsi = classifier_sign.getPrediction(imgResize, draw=False)
                    print(predictionsi,indsi)
                    print("THE SIGN IS  : "+signlabel[indsi])
                if cObj == "Person":
                    recognizer = speech_recognition.Recognizer()
                    try:
                        with speech_recognition.Microphone() as mic:
                            print("START SPEAKING.......")
                            recognizer.adjust_for_ambient_noise(mic,duration=5)
                            audio =recognizer.listen(mic)
                            text = recognizer.recognize_google(audio)
                            text=text.lower()
                            print(f"Recognized {text}")
                    except speech_recognition.UnknownValueError():
                        recognizer = speech_recognition.Recognizer()
                desCount=0
            pObj=cObj   
        pObj = cObj
        count=0
        det=False

    cv2.imshow("Image",img)
    cv2.waitKey(1)