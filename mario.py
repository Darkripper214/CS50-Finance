from cs50 import get_int


def print_hash(x):
    for i in range(1, x+1):
        print("#", end="")


def print_space(y):
    for i in range(1, y+1):
        print(" ", end="")


def get_positive_int():
    i = 0
    while True:
        i = get_int("Height: ")
        if i >= 1 and i < 8:
            return i


height = get_positive_int()
spaces = height - 1
hashes = 1

for x in range(1, height+1):
    print_space(spaces)
    print_hash(hashes)
    print("  ", end="")
    print_hash(hashes)
    print("")
    spaces -= 1
    hashes += 1
