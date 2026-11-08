import sys

if __name__ == "__main__":
    args = sys.argv
    print("=== Command Quest ===")
    print(f"Program name: {args[0]}")
    if len(args) > 1:
        print(f"Arguments received: {len(args) - 1}")
        i = 1
        for arg in args[1:]:
            print(f"Argument {i}: {arg}")
            i += 1
    else:
        print("No arguments provided!")
    print(f"Total arguments: {len(args)}")
