import sys

if __name__ == "__main__":
    print("=== Inventory System Analysis ===")

    inventory: dict[str, int] = {}
    for arg in sys.argv[1:]:
        parts = arg.split(":")
        if len(parts) != 2:
            print(f"Error - invalid parameter '{arg}'")
            continue
        name: str = parts[0]
        if name in inventory:
            print(f"Redundant item '{name}' - discarding")
            continue
        try:
            value: int = int(parts[1])
            if value <= 0:
                print(f"Invalid quantity for '{name}'")
                continue
            inventory[name] = value
        except ValueError as error:
            print(f"Quantity error for '{name}': {error}")
    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")
    total_quantity: int = sum(inventory.values())
    print(
        f"Total quantity of the {len(inventory)} items: " f"{total_quantity}"
    )
    if total_quantity > 0:
        max_name: str = ""
        max_quantity: int = -1

        min_name: str = ""
        min_quantity: int = total_quantity + 1

        for name in inventory.keys():
            quantity = inventory[name]

            percentage = quantity / total_quantity * 100
            print(f"Item {name} represents {percentage:.1f}%")

            if quantity > max_quantity:
                max_quantity = quantity
                max_name = name

            if quantity < min_quantity:
                min_quantity = quantity
                min_name = name

        print(
            f"Item most abundant: {max_name} " f"with quantity {max_quantity}"
        )
        print(
            f"Item least abundant: {min_name} " f"with quantity {min_quantity}"
        )
    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")
