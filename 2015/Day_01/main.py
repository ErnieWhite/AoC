# --- Day 1: Not Quite List ---


def get_puzzle_input():
    with open('input.txt', 'r', encoding='utf-8') as f:
        text = f.read()
    return text


def solver_1(d):
    return d.count('(') - d.count(')')


def solver_2(d):
   return [solver_1(d[:i]) for i in range(len(d))].index(-1)


def main():
    txt = get_puzzle_input()
    print(solver_1(txt))
    print(solver_2(txt))


if __name__ == '__main__':
    main()

