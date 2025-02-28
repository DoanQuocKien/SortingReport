import numpy as np
import time

# File names
input_file = "testcase.txt"
output_file = "raw_report.txt"

# Read the input file
with open(input_file, "r") as f:
    arrays = [list(map(float, line.split())) for line in f]

times = []

# Sort each array and measure time
for arr in arrays:
    start = time.time()
    np.sort(arr)  # Sorting using NumPy
    end = time.time()
    times.append(end - start)

# Compute average time
avg_time = sum(times) / len(times)

# Append results to output file
with open(output_file, "a") as f:
    f.write("np.sort(Python) ")
    f.write(" ".join(f"{t:.6f}" for t in times) + f" {avg_time:.6f}\n")

print("Sorting complete. Results appended to raw_report.txt.")