
class Plant:
    class Stats:
        def __init__(self) -> None:
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0

        def record_grow(self) -> None:
            self._grow_calls += 1

        def record_age(self) -> None:
            self._age_calls += 1

        def record_show(self) -> None:
            self._show_calls += 1

        def display(self) -> None:
            print(f"Stats: {self._grow_calls} grow, "
                  f"{self._age_calls} age, "
                  f"{self._show_calls} show")

    def __init__(self, name: str, height: float, days_old: int) -> None:
        self.name = name
        self._height = 0.0
        self._days_old = 0
        self._stats = Plant.Stats()

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
        self._stats.record_show()
        print(f"{self.name}: {self.get_height():.1f}cm, "
              f"{self.get_age()} days old")

    def grow(self, amount: float = 0.8) -> None:
        self.set_height(self.get_height() + amount)
        self._stats.record_grow()

    def age(self, days: int = 1) -> None:
        self.set_age(self.get_age() + days)
        self._stats.record_age()

    def show_stats(self) -> None:
        self._stats.display()

    @staticmethod
    def is_older_than_year(days: int) -> bool:
        return days > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)


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
        self._shade_calls = 0

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")

    def produce_shade(self) -> None:
        self._shade_calls += 1
        print(f"Tree {self.name} now produces a shade of "
              f"{self.get_height():.1f}cm long and "
              f"{self.trunk_diameter:.1f}cm wide.")

    def show_stats(self) -> None:
        super().show_stats()
        print(f" {self._shade_calls} shade")


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

    def grow(self, amount: float = 0.8) -> None:
        super().grow(amount)
        self.nutritional_value += 1

    def age(self, days: int = 1) -> None:
        super().age(days)
        self.nutritional_value += days

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height: float,
        days_old: int,
        color: str
    ) -> None:
        super().__init__(name, height, days_old, color)
        self.seed_count = 0

    def bloom(self) -> None:
        super().bloom()
        self.seed_count = 42

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seed_count}")


def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant.show_stats()


def main() -> None:
    print("=== Garden statistics ===")

    print("=== Check year-old")
    print("Is 30 days more than a year? ->",
          Plant.is_older_than_year(30))
    print("Is 400 days more than a year? ->",
          Plant.is_older_than_year(400))

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    display_statistics(rose)

    print("[asking the rose to grow and bloom]")
    rose.grow(8.0)
    rose.bloom()
    rose.show()
    display_statistics(rose)

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_statistics(oak)

    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_statistics(oak)

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()

    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30.0)
    sunflower.age(20)
    sunflower.bloom()
    sunflower.show()
    display_statistics(sunflower)

    print("\n=== Anonymous")
    anonymous = Plant.create_anonymous()
    anonymous.show()
    display_statistics(anonymous)


if __name__ == "__main__":
    main()
