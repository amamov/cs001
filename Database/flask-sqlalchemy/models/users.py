from . import db


class User(db.Model):
    __tablename__ = "amamov_user"
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(60), nullable=False)
    email = db.Column(db.String(120), nullable=False)

    def __repr__(self):
        return f"<User {self.username}>"
