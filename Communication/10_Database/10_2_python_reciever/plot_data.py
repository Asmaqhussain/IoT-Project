import sqlite3
import matplotlib.pyplot as plt

conn = sqlite3.connect("sensor_data.db")
cursor = conn.cursor()

cursor.execute("SELECT id, value FROM sensor_data")
rows = cursor.fetchall()

conn.close()

ids = [row[0] for row in rows]
values = [row[1] for row in rows]

plt.plot(ids, values, marker="o")
plt.title("Sensor Values Over Time")
plt.xlabel("Reading Number")
plt.ylabel("Sensor Value")
plt.grid(True)
plt.show()