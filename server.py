from flask import Flask
from flask import request
app = Flask(__name__)
@app.route("/")
def hello():
    print(request.args.get("var"))
    return "We received value: "+str(request.args.get("var"))

if __name__ == '__main__':
    app.run(host='0.0.0.0')