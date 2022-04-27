import random

with open('word_list.txt', 'r') as f:
	words = f.readlines()

word = random.choice(words)[:-1]

guesses_allowed = 7
guesses = []
done = False

print("Hello player welcome to hangman")
print("Please enter your next guess: ")

while not done:
	for letter in word:
		if letter.lower() in guesses:
			print(letter, end="")
		else:
			print("*", end=" ")
	print("\n")
	print(guesses)
	print("")

	guess = input(f"Remaining Lives {guesses_allowed}, Next Guess:")
	guesses.append(guess.lower())

	if not guess.isalpha():
		print("Only enter letters")
		continue
	elif len(guess) > 1:
		print("Only enter a single letter")
		continue

	if guess.lower() not in word.lower():
		guesses_allowed -= 1
		if guesses_allowed == 0:
			break

	done = True
	for letter in word:
		if letter.lower() not in guesses:
			done = False

if done:
	print("Congratulations you win")

else:
	print("You lose")
