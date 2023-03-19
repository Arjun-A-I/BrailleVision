from flask import Flask, jsonify, render_template, Response
from flask_cors import CORS
import cv2
app = Flask(__name__)
CORS(app)
camera = cv2.VideoCapture(0)


def gen_frames():
    while True:
        success, frame = camera.read()
        if not success:
            break
        else:
            ret, buffer = cv2.imencode('.jpg', frame)
            frame = buffer.tobytes()
            yield (b'--frame\r\n'
                   b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')


@app.route('/')
def hello():
    return render_template('index.html')


@app.route('/maps')
def maps():
    # retrieve data for map, such as latitude and longitude
    lat = 51.505
    lng = -0.09
    return render_template('demo.html', lat=lat, lng=lng)


@app.route('/video')
def video():
    return Response(gen_frames(), mimetype='multipart/x-mixed-replace;boundary=frame')


@app.route('/message', methods=['GET'])
def message():
    return jsonify({"message": "Hello World"})


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
#
