def get_input():
    with open('input.txt') as f:
        data = f.read().splitlines()
    return data


def _solver_1(lights, *args):
    if args[0] == 'toggle': 
        start = tuple(map(int, args[1].split(',')))
        stop = tuple(map(int, args[3].split(',')))
        for c in range(start[0], stop[0]+1):
            for r in range(start[1], stop[1]+1):
                lights[r][c] = 1 if lights[r][c] == 0 else 1 
    else: 
        start = tuple(map(int, args[2].split(',')))
        stop = tuple(map(int, args[4].split(',')))
        for c in range(start[0], stop[0] + 1):
            for r in range(start[1], stop[1] + 1):
                lights[r][c] = 1 if args[1] == 'on' else 0 
    return lights

def _solver_2(lights, *args):
    if args[0] == 'toggle': 
        start = tuple(map(int, args[1].split(',')))
        stop = tuple(map(int, args[3].split(',')))
        for c in range(start[0], stop[0]+1):
            for r in range(start[1], stop[1]+1):
                lights[r][c] += 2
    else: 
        start = tuple(map(int, args[2].split(',')))
        stop = tuple(map(int, args[4].split(',')))
        for c in range(start[0], stop[0] + 1):
            for r in range(start[1], stop[1] + 1):
                lights[r][c] += 1 if args[1] == 'on' else -1
                if lights[r][c] < 0:
                    lights[r][c] = 0
    return lights

def solver_1(lst):
    lights = [[0 for c in range(1000)] for r in range(1000)] 

    for e in lst:
        lights = _solver_1(lights, *e.split())

    return lights

def solver_2(lst):
    lights = [[0 for c in range(1000)] for r in range(1000)]
    for e in lst:
        lights = _solver_2(lights, *e.split())
    return lights

def main():
    data = get_input()
    lights = solver_1(data)
    print(sum(light for string in lights for light in string))
    lights = solver_2(data)
    print(sum(light for string in lights for light in string))

if __name__ == '__main__':
    main()
