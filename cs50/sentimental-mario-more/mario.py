def main():
    # Get size
    n = None
    while n is None:
        try:
            n = int(input("Height: "))
            if n < 1 or n > 8:
                print("Please enter a number between 1 and 8.")
                n = None
        except ValueError:
            print("Please enter a valid integer.")

    # Print hill
    for i in range(1, n+1):
        print(" " * (n - i) + "#" * i + " " * 2 + "#" * i)


if __name__ == "__main__":
    main()
