text = input("Text: ")
letter_count = 0;
word_count = 1;
sentence_count = 0;
index = 0.0;

for elem in text:
    if ord(elem.lower()) >= 97 and ord(elem.lower()) <= 122:
        letter_count += 1

    if ord(elem) == 32:
        word_count += 1

    if ord(elem) == 33 or ord(elem) == 63 or ord(elem) == 46:
        sentence_count += 1

L = 0.00
S = 0.00
L = 100 * float(letter_count) / float(word_count)
S = 100 * float(sentence_count) / float(word_count)

index = 0.0588 * L - 0.296 * S - 15.8


if index < 1:
    print("Before Grade 1")

if (index >= 1 and index < 16):
    print(f"Grade {int(round(index))}")

if index > 16:
    print("Grade 16+")
