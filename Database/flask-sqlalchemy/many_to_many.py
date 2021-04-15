from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from pathlib import Path


app = Flask(__name__)

BASE_DIR = Path(__file__).resolve().parent
DB_PATH = str(BASE_DIR / "many_to_many.sqlite")

app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///" + DB_PATH
app.config["SQLALCHEMY_COMMIT_ON_SUBMIT"] = True
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False

db = SQLAlchemy(app)


class Project(db.Model):
    # Many
    __tablename__ = "amamov_project"
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(128))

    developers = db.relationship(
        "User",
        backref="project",
        lazy="dynamic",
        secondary="user_project",
    )

    def __repr__(self):
        return f"<Project {self.title}>"


class User(db.Model):
    # Many
    __tablename__ = "amamov_user"
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(128))

    projects = db.relationship(
        "Project",
        backref="developer",
        lazy="dynamic",
        secondary="user_project",
    )

    def __repr__(self):
        return f"<User {self.username}>"


db.Table(
    "user_project",
    db.Column("user_id", db.Integer, db.ForeignKey("amamov_user.id")),
    db.Column("project_id", db.Integer, db.ForeignKey("amamov_project.id")),
)


db.create_all()

if __name__ == "__main__":
    app.run(host="localhost", port=5000, debug=True)
