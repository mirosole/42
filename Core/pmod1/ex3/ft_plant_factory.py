
class Plant:
    def __init__(self, name: str, height: float, days_old: int) -> None:
        self.name = name
        self.height = height
        self.days_old = days_old

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, "
              f"{self.days_old} days old")

    def grow(self) -> None:
        self.height += 0.8

    def age(self) -> None:
        self.days_old += 1


def main() -> None:
    print("=== Plant Factory Output ===")

    rose = Plant("Rose", 25.0, 30)
    oak = Plant("Oak", 200.0, 365)
    cactus = Plant("Cactus", 5.0, 90)
    sunflower = Plant("Sunflower", 80.0, 45)
    fern = Plant("Fern", 15.0, 120)

    print("Created:", end=" ")
    rose.show()

    print("Created:", end=" ")
    oak.show()

    print("Created:", end=" ")
    cactus.show()

    print("Created:", end=" ")
    sunflower.show()

    print("Created:", end=" ")
    fern.show()


if __name__ == "__main__":
    main()
