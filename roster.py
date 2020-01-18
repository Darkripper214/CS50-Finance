import csv
import sys
from cs50 import SQL

db = SQL("sqlite:///students.db")

#db.execute("")
house_Name = sys.argv[1]

if len(sys.argv) > 3 or len(sys.argv) < 2 :
    print("error")
    exit()

result = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", house_Name)


for row in result:
    if row["middle"] == "":
        print(row["first"] + " " + row["last"] + ", " + "born " + str(row["birth"]))
    else:
        print(row["first"] +" " + row["middle"] + " " + row["last"] + ", " + "born " + str(row["birth"]))