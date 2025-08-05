import random

def fail():
    random_number = random.random()
    return 1 / random_number

if __name__ == "__main__":
    try:
        result = fail()
        print(result)
    except ZeroDivisionError:
        print("can't divide by zero")
    finally:
        print("The end")
