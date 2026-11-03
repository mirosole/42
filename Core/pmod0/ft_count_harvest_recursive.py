def ft_count_harvest_recursive():
    def count(current, days):
        if current > days:
            return
        print("Day", current)
        count(current + 1, days)

    days = int(input("Days until harvest: "))
    count(1, days)
    print("Harvest time!")
