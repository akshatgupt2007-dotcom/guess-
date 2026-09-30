"""Random Password Generator - builds strong passwords using the secrets module."""
import secrets
import string


def generate_password(length=12, use_digits=True, use_symbols=True):
    chars = string.ascii_letters
    required = [secrets.choice(string.ascii_lowercase),
                secrets.choice(string.ascii_uppercase)]

    if use_digits:
        chars += string.digits
        required.append(secrets.choice(string.digits))
    if use_symbols:
        chars += string.punctuation
        required.append(secrets.choice(string.punctuation))

    rest = [secrets.choice(chars) for _ in range(length - len(required))]
    password = required + rest
    secrets.SystemRandom().shuffle(password)
    return "".join(password)


def main():
    try:
        length = int(input("Password length (min 8): "))
    except ValueError:
        print("Invalid number, using 12.")
        length = 12
    length = max(length, 8)

    digits = input("Include digits? (y/n): ").strip().lower() != "n"
    symbols = input("Include symbols? (y/n): ").strip().lower() != "n"

    print("\nGenerated password:", generate_password(length, digits, symbols))


if __name__ == "__main__":
    main()
