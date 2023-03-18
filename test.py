import cv2
from cvzone.ClassificationModule import Classifier
import numpy as np
import math

cap = cv2.VideoCapture(0)
classifier = Classifier("Models/light_model.h5", "Models/labels_light.txt")
imgSize = 300
labels = ["RED","GREEN"]
det=False
count=0

while True:
    success, img = cap.read()
    count=count+1
    if(count>=30):
        det=True
    if success and det:
        imgResize = cv2.resize(img, (imgSize, imgSize))
        prediction, index = classifier.getPrediction(imgResize, draw=True)
        print(prediction, index)
        print(labels[index])
        count=0
        det=False
        
    cv2.imshow("Image",img)
    cv2.waitKey(1)