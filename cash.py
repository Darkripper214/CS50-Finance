from cs50 import get_float
from math import floor

def Obtain_Change():
    while True:
        change = get_float("Change owed: ")
        if (change > 0):
            cents = change * 100
            return cents

x = Obtain_Change()

Num_of_coins = 0

while x > 0:
    if x >= 25:
        x -= 25
        Num_of_coins += 1
    elif x >= 10:
        x -= 10
        Num_of_coins += 1
    elif x >= 5:
        x -= 5
        Num_of_coins += 1
    elif x >= 1:
        x -= 1
        Num_of_coins += 1

print(Num_of_coins)