from cs50 import get_float


def get_cents():
    cents = None
    while cents is None:
        try:
            dollars = get_float("Change owed: ")
            cents = round(dollars * 100)
            if cents < 0:
                print("Please enter a non-negative value.")
                cents = None
        except ValueError:
            print("Please enter a valid decimal number.")
    return cents


def calculate_coins(cents):
    quarters = cents // 25
    cents -= quarters * 25
    dimes = cents // 10
    cents -= dimes * 10
    nickels = cents // 5
    cents -= nickels * 5
    pennies = cents
    return quarters, dimes, nickels, pennies


if __name__ == "__main__":
    cents = get_cents()
    quarters, dimes, nickels, pennies = calculate_coins(cents)
    coins = quarters + dimes + nickels + pennies
    print(f"{coins}")