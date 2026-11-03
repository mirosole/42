
class Plant:
    name: str
    height: float
    days_old: int

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, "
              f"{self.days_old} days old")

    def grow(self) -> None:
        self.height += 0.8

    def age(self) -> None:
        self.days_old += 1


def main() -> None:
    print("=== Garden Plant Growth ===")

    rose = Plant()
    rose.name = "Rose"
    rose.height = 25.0
    rose.days_old = 30

    rose.show()
    old_height = rose.height

    for day in range(1, 8):
        print(f"=== Day {day} ===")
        rose.grow()
        rose.age()
        rose.show()

    growth = rose.height - old_height
    print(f"Growth this week: {growth:.1f}cm")


if __name__ == "__main__":
    main()
