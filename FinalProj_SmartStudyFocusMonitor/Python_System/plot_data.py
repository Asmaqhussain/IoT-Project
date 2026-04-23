import sqlite3
import matplotlib.pyplot as plt

conn = sqlite3.connect("focus_data.db")
cursor = conn.cursor()

cursor.execute("SELECT id, value FROM focus_data")
rows = cursor.fetchall()

conn.close()

ids = [row[0] for row in rows]
values = [row[1] for row in rows]

plt.plot(ids, values, marker="o")
plt.title("Study Focus Level Over Time")
plt.xlabel("Reading Number")
plt.ylabel("Focus Level")
plt.ylim(0, 100)
plt.grid(True)
plt.show()
