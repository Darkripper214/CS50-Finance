import csv
import sys
from cs50 import SQL

db = SQL("sqlite:///students.db")

#db.execute("")
filePath = sys.argv[1]

if len(sys.argv) > 3 or len(sys.argv) < 2 :
    print("error")
    exit()

name_list = []
house_list = []
birth_list = []

file = open(filePath, 'r')
fileReader = csv.DictReader(file , dialect='excel')
for row in fileReader:
    name_list.append(row['name'].split())
    house_list.append(row['house'])
    birth_list.append(row['birth'])

for name in name_list:
    if len(name) == 3:
        first_name = name[0]
        middle_name = name[1]
        last_name = name [2]
    if len(name) == 2:
        first_name = name[0]
        last_name = name [1]
        middle_name = ""

    db.execute("INSERT INTO students (first, middle, last) VALUES (?,?,?)" ,first_name, middle_name, last_name)

x = 0
for house in house_list:
    x = x + 1
    db.execute("UPDATE students SET house = ? WHERE ID = ?" ,house, x)

x = 0
for birth in birth_list:
    x = x + 1
    db.execute("UPDATE students SET birth = ? WHERE ID = ?" ,birth, x)

