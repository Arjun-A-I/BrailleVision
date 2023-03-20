# Copyright (c) <2023>, <MANU N S>
# All rights reserved.

# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. 

import cv2
from cvzone.ClassificationModule import Classifier
import numpy as np
import math
import pytesseract
import subprocess
import speech_recognition
import pyttsx3
from cvzone.HandTrackingModule import HandDetector
from cvzone.ClassificationModule import Classifier
import subprocess
import serial
mySerial = serial.Serial("COM11", 9600)

left = "$110"
right = "$101"
stop = "$100"

cap = cv2.VideoCapture(0)

#loading ml model
classifier = Classifier("Models/main_model.h5", "Models/labels.txt")
classifier_light  = Classifier("Models/light_model.h5","Models/labels_light.txt")
classifier_sign = Classifier("Models/sign_model.h5","Models/labels_sign.txt")
imgSize = 300

detectorasl = HandDetector(maxHands=1)
classifierasl = Classifier("Models/asl_model.h5", "Models/labels_asl.txt")

offsetasl = 20
imgSizeasl = 300

folder = "Data/C"
counterasl = 0

NumFramesasl=0
pLetterasl=""
cLetterasl=""
wordasl =""

#object classs selection for the output from asl
apple = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 47 "
orange = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 49 "
banana = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 46 "
bottle = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 39 "
sandwich = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 48 "
cellphone = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 67 "
cup = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 41 "
mouse = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 64 "
remote = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 65 "
cake = "python yolov5/detect.py --weights yolov5s.pt --source 0 --class 55 "
default = "python yolov5/detect.py --weights yolov5s.pt --source 0 "

#labels of ml models
labels_asl = ["A","B","c","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
labels = ["blank","apple","book","Person","Sign","traffic","hand","OHAND"]
trafficlabel = ["GREEN","RED"]
signlabel= ["STOP","CROSS","NOENTRY","HOSPITAL"]
det=False
count=0
pObj=''
desCount=0

#function to check object class
def check_for_class(text):
    if text == "":
        return default
    if "apple" in text.lower():
        print("INITIALISING WITH APPLE.... ")
        return apple
    if "orange" in text.lower():
        print("INITIALISING WITH ORANGE.... ")
        return orange
    if "banana" in text.lower():
        print("INITIALISING WITH BANANA.... ")
        return banana
    if "bottle" in text.lower():
        print("INITIALISING WITH BOTTLE.... ")
        return bottle
    if "sandwich" in text.lower():
        print("INITIALISING WITH SANDWICH.... ")
        return sandwich
    if "cellphone" in text.lower():
        print("INITIALISING WITH CELLPHONE.... ")
        return cellphone
    if "cup"  in text.lower():
        print("INITIALISING WITH CUP.... ")
        return cup
    if "mouse" in text.lower():
        print("INITIALISING WITH MOUSE.... ")
        return mouse
    if "remote" in text.lower():
        print("INITIALISING WITH REMOTE.... ")
        return remote
    if "cake" in text.lower():
        print("INITIALISING WITH CAKE.... ")
        return cake
    else:
        return 0

while True:
    success, img = cap.read()
    count=count+1
    if(count>=40):
        det=True
    if success and det:
        imgResize = cv2.resize(img, (imgSize, imgSize))
        prediction, index = classifier.getPrediction(imgResize, draw=False)
        print(prediction, index)
        print(labels[index])
        cObj = labels[index]
        out = "$"+labels[index]
        mySerial.write(out.encode('utf-8'))
        if cObj == pObj:
            desCount = desCount+1
            if desCount>=4:
                if cObj == 'traffic':
                    predictiontf, indtf = classifier_light.getPrediction(imgResize, draw=False)
                    print(predictiontf,indtf)
                    print("TRAFFIC LIGHT IS : "+trafficlabel[indtf])
                    out = "*"+trafficlabel[indtf]
                    mySerial.write(out.encode('utf-8'))
                if cObj == "book":
                    rgb = cv2.cvtColor(imgResize,cv2.COLOR_BGR2RGB)
                    #cv2.imshow("image",img)
                    config_tesseract = '--tessdata-dir tessdata --psm 6'
                    text = pytesseract.image_to_string(rgb,lang='eng',config = config_tesseract)
                    print(text)
                    out = "*"+text
                    mySerial.write(out.encode('utf-8'))
                if cObj=="sign":
                    predictionsi, indsi = classifier_sign.getPrediction(imgResize, draw=False)
                    print(predictionsi,indsi)
                    print("THE SIGN IS  : "+signlabel[indsi])
                    out = "*"+signlabel[indsi]
                    mySerial.write(out.encode('utf-8'))
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
                            out = "*"+ text
                            mySerial.write(out.encode('utf-8'))
                    except speech_recognition.UnknownValueError():
                        recognizer = speech_recognition.Recognizer()
                    
                if cObj == "hand":
                    imgOutputasl = imgasl.copy()
                    handsasl, imgasl = detectorasl.findHands(imgasl)
                    if handsasl:
                        hand = handsasl[0]
                        x, y, w, h = hand['bbox']
                        imgWhiteasl = np.ones((imgSizeasl, imgSizeasl, 3), np.uint8) * 255
                        imgCropasl = imgasl[y - offsetasl:y + h + offsetasl, x - offsetasl:x + w + offsetasl]
                        imgCropShape = imgCropasl.shape
                        aspectRatio = h / w
                        if aspectRatio > 1:
                            k = imgSizeasl / h
                            wCal = math.ceil(k * w)
                            imgResizeasl = cv2.resize(imgCropasl, (wCal, imgSizeasl))
                            imgResizeShape = imgResizeasl.shape
                            wGap = math.ceil((imgSizeasl - wCal) / 2)
                            imgWhiteasl[:, wGap:wCal + wGap] = imgResizeasl
                            predictionasl, indexasl = classifierasl.getPrediction(imgWhiteasl, draw=False)
                            print(predictionasl, index)
                            cLetterasl = labels_asl[index]
                            if cLetterasl == pLetterasl:
                                NumFramesasl = NumFramesasl+1
                                print("FRAMES = ")
                                print(NumFramesasl)
                                print("\nCurrentLetter = ")
                                print(cLetterasl)
                                print("\nPreviousLetter = ")
                                print(pLetterasl)
                                if(NumFramesasl>=10):
                                    wordasl+=cLetterasl
                                    command = check_for_class(wordasl)
                                    process = subprocess.Popen(command.split(), stdout=subprocess.PIPE)
                                    output, error = process.communicate()
                                    print(output.decode())
                                    NumFramesasl=0
                                else:
                                    pLetterasl=cLetterasl
                                print("word is = "+wordasl)
                            else:
                                pLetterasl=cLetterasl
                                NumFrames=0
                        else:
                            k = imgSizeasl / w
                            hCal = math.ceil(k * h)
                            imgResizeasl = cv2.resize(imgCropasl, (imgSizeasl, hCal))
                            imgResizeShape = imgResizeasl.shape
                            hGap = math.ceil((imgSizeasl - hCal) / 2)
                            imgWhiteasl[hGap:hCal + hGap, :] = imgResizeasl
                            prediction, index = classifierasl.getPrediction(imgWhiteasl, draw=False)

                        cv2.rectangle(imgOutputasl, (x - offsetasl, y - offsetasl-50),
                                    (x - offsetasl+90, y - offsetasl-50+50), (0, 0, 255), cv2.FILLED)
                        #cv2.putText(imgOutput, labels[index], (x, y -26), cv2.FONT_HERSHEY_COMPLEX, 1.7, (255, 255, 255), 2)
                        #cv2.rectangle(imgOutput, (x-offset, y-offset),
                                    # (x + w+offset, y + h+offset), (255, 0, 255), 4)


                        #v2.imshow("ImageCrop", imgCropasl)
                        #cv2.imshow("ImageWhite", imgWhiteasl)

                #cv2.imshow("Image", imgOutputasl)
            desCount=0
            pObj=cObj   
            pObj = cObj
            count=0
            det=False

    cv2.imshow("Image",img)
    cv2.waitKey(1)
