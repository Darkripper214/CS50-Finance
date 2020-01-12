import csv
import sys
import copy

dbPath = sys.argv[1]
seqPath = sys.argv[2]

if len(sys.argv) > 3:
    print("error")
    exit()

str_list = []
DB= open(dbPath,'r')
DBreader = csv.DictReader(DB)
for row in DBreader:
#    print(DBreader.fieldnames)
# Store the str for checking in SEQ
    str_list = DBreader.fieldnames
#    print(row)
#    dict_list.update(row)

#for i in range(1,len(str_list)):
#    print(str_list[i])

str_list.pop(0)

#for i in range(0,len(str_list)):
#    print(str_list[i])

seq_dict ={}
seq_dict = dict.fromkeys(str_list,1)
#print(seq_dict)

cur_count = 1
SQ = open(seqPath,"r")
for line in SQ:
    for y in range(len(str_list)):
        for i in range(len(line)):
            if line[i:i+len(str_list[y])] == str_list[y] and line[i:i+len(str_list[y])] == line[i+len(str_list[y]):i+2*len(str_list[y])]:
                seq_dict[str_list[y]] += 1


print(seq_dict)
match = 0
DB= open(dbPath,'r')
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


