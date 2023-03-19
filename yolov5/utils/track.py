# import subprocess


# apple = "python detect.py --weights yolov5s.pt --source 0 --class 47 "
# orange = "python detect.py --weights yolov5s.pt --source 0 --class 49 "
# banana = "python detect.py --weights yolov5s.pt --source 0 --class 46 "
# bottle = "python detect.py --weights yolov5s.pt --source 0 --class 39 "
# sandwich = "python detect.py --weights yolov5s.pt --source 0 --class 48 "
# cellphone = "python detect.py --weights yolov5s.pt --source 0 --class 67 "
# cup = "python detect.py --weights yolov5s.pt --source 0 --class 41 "
# mouse = "python detect.py --weights yolov5s.pt --source 0 --class 64 "
# remote = "python detect.py --weights yolov5s.pt --source 0 --class 65 "
# cake = "python detect.py --weights yolov5s.pt --source 0 --class 55 "
# default = "python detect.py --weights yolov5s.pt --source 0 "



# def check_for_class(text):
#     if text == "":
#         return default
#     if "apple" in text.lower():
#         print("INITIALISING WITH APPLE.... ")
#         return apple
#     if "orange" in text.lower():
#         print("INITIALISING WITH ORANGE.... ")
#         return orange
#     if "banana" in text.lower():
#         print("INITIALISING WITH BANANA.... ")
#         return banana
#     if "bottle" in text.lower():
#         print("INITIALISING WITH BOTTLE.... ")
#         return bottle
#     if "sandwich" in text.lower():
#         print("INITIALISING WITH SANDWICH.... ")
#         return sandwich
#     if "cellphone" in text.lower():
#         print("INITIALISING WITH CELLPHONE.... ")
#         return cellphone
#     if "cup"  in text.lower():
#         print("INITIALISING WITH CUP.... ")
#         return cup
#     if "mouse" in text.lower():
#         print("INITIALISING WITH MOUSE.... ")
#         return mouse
#     if "remote" in text.lower():
#         print("INITIALISING WITH REMOTE.... ")
#         return remote
#     if "cake" in text.lower():
#         print("INITIALISING WITH CAKE.... ")
#         return cake
#     else:
#         return 0



# command = check_for_class(word)

# process = subprocess.Popen(command.split(), stdout=subprocess.PIPE)
# output, error = process.communicate()
# print(output.decode())