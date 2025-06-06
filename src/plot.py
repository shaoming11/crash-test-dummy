import pandas as pd
import matplotlib.pyplot as plt

# Load the data from the CSV file
df = pd.read_csv('src/trial3.csv')

# Plot the acceleration-time graph
plt.figure(figsize=(2000,6))
plt.plot(df['time'], df['accel'], marker='o')
plt.xlabel('Time (ms)')
plt.ylabel('Acceleration (g)')
plt.title('Acceleration-Time Graph')
plt.grid(True)
plt.show()