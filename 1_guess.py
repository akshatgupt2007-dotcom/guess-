"""Number Guessing Game - guess the secret number with hints."""
import random


def play(low=1, high=100, max_attempts=7):
    secret = random.randint(low, high)
    print(f"I'm thinking of a number between {low} and {high}.")
    print(f"You have {max_attempts} attempts.\n")

    for attempt in range(1, max_attempts + 1):
        try:
            guess = int(input(f"Attempt {attempt}/{max_attempts} - your guess: "))
        except ValueError:
            print("Please enter a valid whole number.")
            continue

        if guess == secret:
            print(f"Correct! You got it in {attempt} attempt(s).")
            return
        print("Too low!" if guess < secret else "Too high!")

    print(f"Out of attempts. The number was {secret}.")


if __name__ == "__main__":
    while True:
        play()
        if input("\nPlay again? (y/n): ").strip().lower() != "y":
            print("Thanks for playing!")
            break
