import sqlite3
import paho.mqtt.client as mqtt

BROKER = "broker.hivemq.com"
PORT = 1883
TOPIC = "asmaq/focus/level"

conn = sqlite3.connect("focus_data.db")
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS focus_data (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    value REAL,
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
)
""")
conn.commit()

def on_message(client, userdata, msg):
    value = float(msg.payload.decode())
    cursor.execute("INSERT INTO focus_data (value) VALUES (?)", (value,))
    conn.commit()
    print("Focus level:", value)

client = mqtt.Client()
client.on_message = on_message

client.connect(BROKER, PORT, 60)
client.subscribe(TOPIC)

print("Receiving focus data...")

client.loop_forever()