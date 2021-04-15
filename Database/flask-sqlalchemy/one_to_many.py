from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from pathlib import Path


app = Flask(__name__)

BASE_DIR = Path(__file__).resolve().parent
DB_PATH = str(BASE_DIR / "one_to_many.sqlite")

app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///" + DB_PATH
app.config["SQLALCHEMY_COMMIT_ON_SUBMIT"] = True
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False

db = SQLAlchemy(app)


class Board(db.Model):
    # Many
    __tablename__ = "amamov_board"  # tablename을 지정하지 않으면 class 명의 소문자이다.
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(128))

    writer_id = db.Column(
        db.Integer, db.ForeignKey("amamov_user.id", ondelete="CASCADE")
    )

    def __repr__(self):
        return f"<Board {self.title}>"


class User(db.Model):
    # One
    __tablename__ = "amamov_user"
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(128))

    boards = db.relationship(
        "Board",  # 어떤 클래스와 관계를 가지는가
        backref="writer",  # 상대방이 참조하는 이름
        lazy="dynamic",  # 어떻게 둘을 연결하는가(연결하는 방식:dynamic)
        passive_deletes=True,
    )

    def __repr__(self):
        return f"<User {self.username}>"


db.create_all()

if __name__ == "__main__":
    app.run(host="localhost", port=5000, debug=True)

"""
amamov = User(username='amamov')

db.session.add(amamov)
db.session.commit()

board1 = Board(title='hello1', writer_id=amamov.id)
board2 = Board(title='hello2', writer=amamov) # User의 backref="writer"로 접근 가능

db.session.add_all([board1, board2])
db.session.commit()

amamov = User.query.filter(User.username=='amamov').first()
amamov.boards.all()
# [<Board hello1>, <Board hello2>]
"""
