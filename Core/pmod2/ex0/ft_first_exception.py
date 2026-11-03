
def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    print("=== Garden Temperature ===")
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
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
