
def input_temperature(temp_str: str) -> int:
    number = int(temp_str)
    if number > 40:
        raise ValueError(f"{number}°C is too hot for plants (max 40°C)")
    if number < 0:
        raise ValueError(f"{number}°C is too cold for plants (min 0°C)")

    return number


def test_temperature() -> None:
    print("=== Garden Temperature Checker ===")
    print()

    temp = input_temperature("25")
    print(f"Input data is '{temp}'")
    print(f"Temperature is now {temp}°C")
    print()

    print("Input data is 'abc'")
    try:
        temp = input_temperature("abc")
        print(temp)
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    print()
    print("Input data is '100'")
    try:
        temp = input_temperature("100")
        print(f"Temperature is now {temp}°C")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    print()
    print("Input data is '-50'")
    try:
        temp = input_temperature("-50")
        print(f"Temperature is now {temp}°C")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
