
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


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        days_old: int,
        color: str
    ) -> None:
        super().__init__(name, height, days_old)
        self.color = color
        self.is_blooming = False

    def bloom(self) -> None:
        self.is_blooming = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")

        if self.is_blooming:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        days_old: int,
        trunk_diameter: float
    ) -> None:
        super().__init__(name, height, days_old)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")

    def produce_shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of "
              f"{self.get_height():.1f}cm long and "
              f"{self.trunk_diameter:.1f}cm wide.")


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        days_old: int,
        harvest_season: str
    ) -> None:
        super().__init__(name, height, days_old)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def grow(self) -> None:
        super().grow()
        self.nutritional_value += 1

    def age(self) -> None:
        super().age()
        self.nutritional_value += 1

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")


def main() -> None:
    print("=== Garden Plant Types ===")

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()

    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()

    print("[asking the oak to produce shade]")
    oak.produce_shade()

    print("\n=== Vegetable")
    tomato = Vegetable("Tomato", 5.0, 10, "April")
    tomato.show()

    print("[make tomato grow and age for 20 days]")

    for day in range(20):
        tomato.grow()
        tomato.age()

    tomato.show()


if __name__ == "__main__":
    main()
