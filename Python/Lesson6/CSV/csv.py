import csv

with open("input.csv", "r", encoding="utf-8") as f:
    r = csv.reader(f, delimiter=',')
    for row in r:
        print(row)