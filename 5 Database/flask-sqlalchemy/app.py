from flask import Flask, render_template
from pathlib import Path
from models import db
from models.users import User


app = Flask(__name__)

BASE_DIR = Path(__file__).resolve().parent
DB_PATH = str(BASE_DIR / "db.sqlite")

app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///" + DB_PATH
app.config["SQLALCHEMY_COMMIT_ON_SUBMIT"] = True
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False

db.init_app(app)
db.app = app
db.create_all()


@app.route("/")
def hello():
    return render_template("index.html")


if __name__ == "__main__":
    # print(app.config)
    app.run(host="localhost", port=5000, debug=True)
