import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        coordinates = input(
            "Enter new coordinates as floats in format 'x,y,z': "
        )

        parts = coordinates.split(",")

        if len(parts) != 3:
            print("Invalid syntax")
            continue

        try:
            values: list[float] = []

            for part in parts:
                values.append(float(part))

            return (values[0], values[1], values[2])

        except ValueError as error:
            print(f"Error on parameter '{part}': {error}")


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print()

    print("Get a first set of coordinates")
    position = get_player_pos()

    print(f"Got a first tuple: {position}")

    x, y, z = position
    print(f"It includes: X={x}, Y={y}, Z={z}")

    d: float = math.sqrt(x**2 + y**2 + z**2)
    print(f"Distance to center: {d:.4f}")

    print("\nGet a second set of coordinates")
    position2 = get_player_pos()

    x2, y2, z2 = position2
    d2: float = math.sqrt((x2 - x) ** 2 + (y2 - y) ** 2 + (z2 - z) ** 2)

    print(f"Distance between the 2 sets of coordinates: {d2:.4f}")
