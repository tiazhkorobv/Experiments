from cs50 import get_string


# Count letters
def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters


# Count words
def count_words(text):
    words = 1
    for char in text:
        if char.isspace():
            words += 1
    return words


# Count sentences
def count_sentences(text):
    characters = ".!?"
    sentences = 0
    for char in text:
        if char in characters:
            sentences += 1
    return sentences


# Get text
text = get_string("Text: ")

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)
# The formula to calculate the average number of letters per 100 words in the text
L = (letters / words) * 100
# The formula to calculate the average number of sent. per 100 words in the text
S = (sentences / words) * 100

# print(f"Ltrs = {letters}, Wrds = {words}, Stss = {sentences}")
# print(f"L = {L}, S = {S}")

grade = round(0.0588 * L - 0.296 * S - 15.8)

# Conditions
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
