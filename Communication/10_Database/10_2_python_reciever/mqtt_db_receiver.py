import sqlite3
import paho.mqtt.client as mqtt

BROKER = "broker.hivemq.com"
PORT = 1883
TOPIC = "asmaq/communication/sensor"

conn = sqlite3.connect("sensor_data.db")
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS sensor_data (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    value REAL,
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
)
""")
conn.commit()

def on_message(client, userdata, msg):
    value = float(msg.payload.decode())
    cursor.execute("INSERT INTO sensor_data (value) VALUES (?)", (value,))
    conn.commit()
    print("Saved:", value)

client = mqtt.Client()
client.on_message = on_message

client.connect(BROKER, PORT, 60)
client.subscribe(TOPIC)

print("Waiting for data...")

client.loop_forever()