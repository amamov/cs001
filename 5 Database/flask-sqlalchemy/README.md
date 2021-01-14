# Flask-SQLalchemy

<br>
<br>

# CRUD

```python
class User(db.Model):
    __tablename__ = "amamov_user"
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(60), nullable=False)
    email = db.Column(db.String(120), nullable=False)

```

<br>
<br>

### 1. Create

```python
amamov = User(username='yss', email='ysangsuk78@gmail.com') # user 객체 생성
spring = User(username='spring', email='email@spring')
summer = User(username='summer', email='email@summer')
tokyo = User(username='tokyo', email='email@tokyo')
seoul = User(username='seoul', email='email@seoul')

db.session.add(amamov)
db.session.commit()

db.session.add_all([spring, summer, tokyo, seoul]) # 리스트로 한 번에 add
db.session.commit()
```

<br>
<br>

### 2. Read

```python
## User table의 모든 객체를 list 형태로 가져온다.
User.query.all()
# >> [<User amamov>, <User spring>, <User summer>, <User tokyo>, <User seoul>]

## User table의 username이 tokyo인 객체들중 첫 번째 데이터을 가져온다.
User.query.filter(User.username=='tokyo').first()
```

<br>
<br>

### 3. Update

- 방법 1

```python
tokyo = User.query.filter(User.username=='tokyo').first()

print(tokyo.email)
# 'email@tokyo'

## 값 수정
tokyo.email = 'email@ttt'
db.session.commit()

## 업데이트 확인
print(t.email)
# 'email@ttt'
```

- 방법 2

```python
# username이 amamov의 email을 업데리이트(수정)한다고 하자.
updated_data={'email': 'email@amamovamamov'}

a = User.query.filter(User.username == 'amamov').update(updated_data)
db.session.commit()
```

<br>
<br>

### 4. Delete

```python
uid = 1 # 제거 대상 객체의 id를 알고 있다고 하자.
a = User.query.filter(User.id == uid).delete()
db.session.commit()
```

---

<br>
<br>

# Query

### 1. filter

```python
User.query.filter(User.id != 1).all()
```

- User table의 객체들중 id가 1이 아닌 모든 객체들을 리스트로 가져온다.
  <br>
  <br>

### 2. like("%...%")

```python
User.query.filter(User.email.like("%gmail%")).all()
```

- User table의 객체들중 email에 gmail이라는 단어(문자열)이 존재하는 모든 객체들을 리스트로 가져온다.

### 3. in\_([...])

```python
User.query.filter(User.username.in\_(['spring', 'fall', 'amamov'])).all()
```

- User table의 객체들중 ['spring', 'fall', 'amamov']에 속하는 username인 객체들을 모두 리스트로 가져온다.
  <br>
  <br>

### 4, ~in\_([...])

```python
User.query.filter(~User.username.in\_(['spring', 'fall', 'amamov'])).all()
```

- User table의 객체들중 ['spring', 'fall', 'amamov']에 속하지 않는 username인 객체들을 모두 리스트로 가져온다.
  <br>
  <br>

### 5. None

```python
User.query.filter(User.email == None).all()
```

- User table의 객체들중 email 이 없는 객체들을 모두 리스트로 가져온다.
  <br>
  <br>

### 6. and\_(..., ...)

```python
User.query.filter(db.and\_(User.username.like('%s%), User.email.like('%gmail%))).all()
```

- User table의 객체들중 username에 s가 들어가고 email에 gmail이 들어가는 모든 객체를 리스트로 가져온다.
- User.query.filter(User.username.like('%s%')).filter(User.email.like('%gmail%')).all() 과 같다.
  <br>
  <br>

### 7. or\_(..., ...)

```python
User.query.filter(db.or\_(User.username.like('%s%), User.email.like('%gmail%))).all()
```

- User table의 객체들중 username에 s가 들어가거나 또는 email에 gmail이 들어가는 모든 객체를 리스트로 가져온다.
  <br>
  <br>

### 8. order_by()

```python
User.query.order_by(User.username).all()
```

- User table의 객체들을 username 오름차순으로 정렬하여 리스트로 모두 가져온다.
- User.query.filter(...).order_by(...) 으로 주로 사용
- 오름차순이란 작은 것부터 큰 순서로 정렬하는 방식이다.
- abcdef.., 12345...
- 내림차순으로 정렬하고 싶다면 User.query.order_by(User.username.desc()).all()로 사용한다.
  <br>
  <br>

### 9. limit()

```python
User.query.limit(3).all()
```

- User table의 객체들을 3개만 리스트로 모두 가져온다.
- User.query.filter(...).limit(...) 으로 주로 사용
  <br>
  <br>

### 10. offset()

```python
 User.query.offset(3).all()
 # 만약 User.query.all()이 [<User 'spring'>, <User 'amamov'>, <User 'fall'>, <User 'joy'>, <User 'yua'>]라면 [<User 'joy'>, <User 'yua'>]만 가져온다.
```

- User table의 객체들중 3개를 건너뛰고 나머지를 리스트로 모두 가져온다.
- User.query.filter(...).offset(...) 으로 주로 사용
- limit와 같이 써서 pagination을 구현할 수 있다.
  <br>
  <br>

### 11. count()

```python
 User.query.filter(User.password == password).count()
```

- User table의 객체들중 조건에 성립하는 객체 수를 반환한다.
  <br>
  <br>

---

# Relationship

     - 테이블 간에는 관계를 맺을 수 있으며 대표적으로 1:N(one-to-many), N:N(Many-to-many), 1:1(one-to-one) 관계이다.

<br>
<br>

### 1. one-to-many

    - 유저와 게시판 사이의 관계

```python
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
    __tablename__ = "amamov_board"  # tablename을 지정하지 않으면 디폴트로 class 명의 소문자이다.
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(128))
    writer_id = db.Column(
        db.Integer,
        db.ForeignKey("amamov_user.id", ondelete="CASCADE"),
        # tablename의 id를 저장한다.
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
        lazy="dynamic",  # 어떻게 둘을 연결하는가 (연결하는 방식:dynamic)
        passive_deletes=True,
    )

    def __repr__(self):
        return f"<User {self.username}>"


db.create_all()

if __name__ == "__main__":
    app.run(host="localhost", port=5000, debug=True)


```

```python
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
```

<br>
<br>

### 2. many-to-many

    - 프로젝트와 개발자의 관계 : 한 프로젝트에 여러명의 개발자가 들어갈 수 있고 개발자 한 명이 여러 프로젝트에 들어갈 수 있다.

```python
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
        "User", # 관계를 맺을 model class 정의
        backref="project", # User(username='amamov', project=p1)
        lazy="dynamic",
        secondary="user_project", # 종속 관계의 또 다른 테이블 이름
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

```

```python
# amamov : p1, p2 / yua : p2, p3, / joy : p1, p2, p3 / wow : p1, p3
# p1 : amamov, joy, wow / p2 : amamov, yua, joy / p3 : yua, joy, wow

amamov = User(username = 'amamov')
joy = User(username = 'joy')
yua = User(username = 'yua')

p1 = Project(title = 'p1')
p2 = Project(title = 'p2')
p3 = Project(title = 'p3')
p4 = Project(title = 'p4')

db.session.add_all([amamov, joy, yua, p1, p2, p3, p4])
db.session.commit()

p1 = Project.query.filter(Project.title == 'p1').first()
p2 = Project.query.filter(Project.title == 'p2').first()
p3 = Project.query.filter(Project.title == 'p3').first()

amamov = User.query.filter(User.username == 'amamov').first()
joy = User.query.filter(User.username == 'joy').first()
yua = User.query.filter(User.username == 'yua').first()

wow = User(username = 'wow')
db.session.add(wow)

p1.developers.append(amamov)
p1.developers.append(joy)
p1.developers.append(wow)
p2.developers.append(amamov)
p2.developers.append(yua)
p2.developers.append(joy)
p3.developers.append(yua)
p3.developers.append(joy)

wow.projects.append(p3)

p3.developers.all()
# [<User yua>, <User joy>, <User wow>]

amamov.projects.all()
# [<Project p1>, <Project p2>]

db.session.commit()

```
