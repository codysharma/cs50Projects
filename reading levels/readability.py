# TODO
#import cs50

#sample = cs50.get_string("Text: ")
sample = get_string("Text: ")

length = len(sample)

#calculate_length
total = len(sample)
for i in range(length):
    if sample[i].isalpha() == False:
        total = total-+ 1


#calculate_words
words = 1
for i in range(length):
    if sample[i] == " ":
        words = words + 1


#calculate_sentences
sentences = 0
for i in range(length):
    if sample[i] == '.' or sample[i] == '?' or sample[i] == '!':
        sentences = sentences + 1


index = 0
index = round(total / words * 100 * .0588 - sentences / words * 100 * .296 - 15.8)

if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Below Grade 1")
else:
    print(f"Grade {index}")
