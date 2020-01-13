import csv
import sys
import copy

dbPath = sys.argv[1]
seqPath = sys.argv[2]

if len(sys.argv) > 3:
    print("error")
    exit()

str_list = []
DB = open(dbPath, 'r')
DBreader = csv.DictReader(DB)
for row in DBreader:
    #    print(DBreader.fieldnames)
    # Store the str for checking in SEQ
    str_list = DBreader.fieldnames

str_list.pop(0)

seq_dict = {}
seq_dict = dict.fromkeys(str_list, 0)
# print(seq_dict)

def equal_count():
    return cur_count


SQ = open(seqPath, "r")
for line in SQ:
    # Looping through each STR type loaded
    for y in range(len(str_list)):
        cur_count = 0
        i = 0
        x = len(line)
        while i <= x:
            # Check if DNA STR match, increase the string by i + len(STR) if match
            if line[i:i+len(str_list[y])] == str_list[y]:
                cur_count += 1
                i += len(str_list[y]) - 1
            else:
                if cur_count > seq_dict[str_list[y]]:
                    seq_dict[str_list[y]] = cur_count

                cur_count = 0
            # Increase i by 1 if doesn't match
            i += 1


# print(seq_dict)
match = 0
DB = open(dbPath, 'r')
DBreader = csv.DictReader(DB)
for row in DBreader:
    for y in range(len(str_list)):
        if int(row[str_list[y]]) == seq_dict[str_list[y]]:
            match += 1
        if match == len(str_list):
            print(row['name'])
            exit()
    match = 0

if match <= 0:
    print("No Match")