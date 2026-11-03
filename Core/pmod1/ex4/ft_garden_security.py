class Plant:
    def __init__(self, name: str, height: float, days_old: int) -> None:
        self.name = name
        self._height = 0.0
        self._days_old = 0

        self.set_height(height)
        self.set_age(days_old)

    def set_height(self, height: float) -> None:
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            return
        self._height = height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            return
        self._days_old = age

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days_old

    def show(self) -> None:
        print(f"{self.name}: {self.get_height():.1f}cm, "
              f"{self.get_age()} days old")

    def grow(self) -> None:
        self.set_height(self.get_height() + 0.8)

    def age(self) -> None:
        self.set_age(self.get_age() + 1)


def main() -> None:
    print("=== Garden Security System ===")

    rose = Plant("Rose", 15.0, 10)

    print("Plant created:", end=" ")
    rose.show()

    print()

    rose.set_height(25.0)
    print(f"Height updated: {rose.get_height():g}cm")

    rose.set_age(30)
    print(f"Age updated: {rose.get_age()} days")

    print()

    old_height = rose.get_height()
    rose.set_height(-5.0)
    if rose.get_height() == old_height:
        print("Height update rejected")

    old_age = rose.get_age()
    rose.set_age(-10)
    if rose.get_age() == old_age:
        print("Age update rejected")

    print()

    print("Current state:", end=" ")
    rose.show()


if __name__ == "__main__":
    main()
