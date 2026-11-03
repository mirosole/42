def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        1 / 0
    elif operation_number == 2:
        open("notexist.txt", "r")
    elif operation_number == 3:
        2 + "a"


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")

    for operation in range(5):
        print(f"Testing operation {operation}...")

        try:
            garden_operations(operation)
        except ValueError as error:
            print(f"Caught ValueError: {error}")
        except ZeroDivisionError as error:
            print(f"Caught ZeroDivisionError: {error}")
        except FileNotFoundError as error:
            print(f"Caught FileNotFoundError: {error}")
        except TypeError as error:
            print(f"Caught TypeError: {error}")
        else:
            print("Operation completed successfully")

    print()
    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
