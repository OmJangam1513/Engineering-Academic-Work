from flask import Flask, render_template, request, redirect, url_for
import oracledb



app = Flask(__name__)

connection = oracledb.connect(
    user="system",
    password="your_password",   # ← your actual password here
    dsn="localhost:1521/XE"
)

@app.route('/')
def index():
    cur = conn.cursor()
    cur.execute("SELECT * FROM students ORDER BY id")
    rows = cur.fetchall()
    cur.close()
    return render_template('index.html', students=rows)

@app.route('/add', methods=['POST'])
def add():
    name = request.form['name']
    age = request.form['age']
    marks = request.form['marks']
    cur = conn.cursor()
    cur.execute("INSERT INTO students (name, age, marks) VALUES (:1, :2, :3)", (name, age, marks))
    conn.commit()
    cur.close()
    return redirect(url_for('index'))

@app.route('/edit/<int:id>')
def edit(id):
    cur = conn.cursor()
    cur.execute("SELECT * FROM students WHERE id=:id", {'id': id})
    student = cur.fetchone()
    cur.close()
    return render_template('edit.html', student=student)

@app.route('/update/<int:id>', methods=['POST'])
def update(id):
    name = request.form['name']
    age = request.form['age']
    marks = request.form['marks']
    cur = conn.cursor()
    cur.execute("UPDATE students SET name=:1, age=:2, marks=:3 WHERE id=:4",
                (name, age, marks, id))
    conn.commit()
    cur.close()
    return redirect(url_for('index'))

@app.route('/delete/<int:id>')
def delete(id):
    cur = conn.cursor()
    cur.execute("DELETE FROM students WHERE id=:id", {'id': id})
    conn.commit()
    cur.close()
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
