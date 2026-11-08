
import random


achievements = [
    "First Steps",
    "Boss Slayer",
    "Master Explorer",
    "Treasure Hunter",
    "Speed Runner",
    "World Savior",
    "Crafting Genius",
    "Collector Supreme",
    "Untouchable",
    "Strategist",
    "Unstoppable",
    "Survivor",
    "Sharp Mind",
    "Hidden Path Finder",
]


def gen_player_achievements() -> set[str]:
    count_players_ach = random.randint(5, 8)
    taken_ach = random.sample(achievements, count_players_ach)
    return set(taken_ach)


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    print()

    alice = gen_player_achievements()
    bob = gen_player_achievements()
    charlie = gen_player_achievements()
    dylan = gen_player_achievements()

    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")
    print()

    all_distinct: set[str] = alice.union(bob, charlie, dylan)
    print(f"All distinct achievements: {all_distinct}")

    common_achievements: set[str] = alice.intersection(
        bob, charlie, dylan
    )
    print(f"Common achievements: {common_achievements}")
    print()

    only_alice = alice.difference(bob, charlie, dylan)
    only_bob = bob.difference(alice, charlie, dylan)
    only_charlie = charlie.difference(alice, bob, dylan)
    only_dylan = dylan.difference(alice, bob, charlie)

    print(f"Only Alice has: {only_alice}")
    print(f"Only Bob has: {only_bob}")
    print(f"Only Charlie has: {only_charlie}")
    print(f"Only Dylan has: {only_dylan}")
    print()

    all_possible: set[str] = set(achievements)

    missing_alice = all_possible.difference(alice)
    missing_bob = all_possible.difference(bob)
    missing_charlie = all_possible.difference(charlie)
    missing_dylan = all_possible.difference(dylan)

    print(f"Alice is missing: {missing_alice}")
    print(f"Bob is missing: {missing_bob}")
    print(f"Charlie is missing: {missing_charlie}")
    print(f"Dylan is missing: {missing_dylan}")
