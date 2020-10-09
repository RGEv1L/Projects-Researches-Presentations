from flask import Flask
from flask_httpauth import HTTPBasicAuth

app = Flask(__name__)
auth = HTTPBasicAuth()


@auth.verify_password
def verify_password(username, password):
        if username =="admin" and password == "46d":
	        return 1

@app.route('/')
@auth.login_required
def index():
    return "200"

if __name__ == '__main__':
    app.run()
