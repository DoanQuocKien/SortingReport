import csv

input_file = "raw_report.txt"
output_file = "raw_report_flipped.csv"

# Read the input file
with open(input_file, "r") as f:
    lines = [line.split() for line in f]

# Transpose the table (flip rows and columns)
flipped = list(map(list, zip(*lines)))

# Multiply all numerical values by 1000
for i in range(len(flipped)):
    for j in range(len(flipped[i])):
        if flipped[i][j].replace(".", "", 1).isdigit():  # Check if it's a number
            flipped[i][j] = str(float(flipped[i][j]) * 1000)

# Write the flipped data to a CSV file
with open(output_file, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerows(flipped)

print(f"Flipped table saved as {output_file} with values multiplied by 1000.")
