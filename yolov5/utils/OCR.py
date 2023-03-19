import pytesseract
import numpy as np
import cv2 

img = cv2.imread('./book.jpg')
rgb = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
cv2.imshow("image",img)
config_tesseract = '--tessdata-dir tessdata --psm 6'
text = pytesseract.image_to_string(rgb,lang='eng',config = config_tesseract)
print(text)