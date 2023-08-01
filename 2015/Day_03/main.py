def get_data():
    with open('input.txt') as f:
        data = f.read()
    return data

def solver_1(directions):
    x = 0
    y = 0
    present_count = {}
    for move in list(directions):
        match move:
            case '^':
                y -= 1
            case 'v':
                y += 1
            case '<':
                x -= 1
            case '>':
                x += 1
        present_count[(x, y)] = present_count.setdefault((x,y), 0) + 1
    return len(present_count)


def solver_2(directions):
    robo_x = 0
    robo_y = 0
    santa_x = 0
    santa_y = 0
    present_count = {}
    for i, move in enumerate(list(directions)):
        x = 0
        y = 0
        if move == '^': y = 1
        if move == 'v': y = -1
        if move == '<': x = -1
        if move == '>': x = 1
        if i % 2:
            robo_x += x
            robo_y += y
            present_count[(robo_x, robo_y)] = present_count.setdefault((robo_x,robo_y), 0) + 1
        else:
            santa_x += x
            santa_y += y
            present_count[(santa_x, santa_y)] = present_count.setdefault((santa_x,santa_y), 0) + 1
    return len(present_count)


def main():
    data = get_data()
    print(solver_1(data))
    print(solver_2(data))

if __name__ == '__main__':
    main()
