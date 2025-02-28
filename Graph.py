import matplotlib.pyplot as plt
import numpy as np

# Read the raw report file
input_file = "raw_report.txt"
output_image = "sorting_comparison.png"

algorithms = []
times = []  # List of lists to store times for each algorithm

with open(input_file, "r") as f:
    for line in f:
        parts = line.split()
        if len(parts) == 12:  # Ensure the line has the expected format
            algorithms.append(parts[0])  # First item is the algorithm name
            times.append([float(x) for x in parts[1:]])  # Convert numbers to float

times = np.array(times)  # Convert to numpy array for easier manipulation
num_algorithms, num_tests = times.shape  # Get dimensions

# Set up the bar positions
x = np.arange(num_tests)  # Positions for test cases (10 arrays + 1 average)
width = 0.15  # Bar width

plt.figure(figsize=(12, 6))

# Plot bars for each algorithm
for i in range(num_algorithms):
    plt.bar(x + i * width, times[i], width, label=algorithms[i])

# Labels and title
plt.xlabel("Test Cases (1-10) + Average")
plt.ylabel("Time (seconds)")
plt.title("Sorting Algorithm Performance Across Test Cases")
plt.xticks(x + width * (num_algorithms / 2), [f"Test {i+1}" for i in range(10)] + ["Avg"], rotation=30)
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.7)

# Save the figure to a file
plt.savefig(output_image, dpi=300, bbox_inches="tight")

# Show the plot
plt.show()

print(f"Bar graph saved as {output_image}")
