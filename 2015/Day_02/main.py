from itertools import combinations

def get_input():
    f = open('input.txt')
    return f.read().splitlines()

def solver_1(boxes):
    square_feet = 0
    for box in boxes:
        sides = map(int, box.split('x'))
        area_sides = list(map(lambda x: x[0] * x[1], combinations(sides, 2)))
        square_feet += sum(map(lambda x: 2*x, area_sides)) + min(area_sides)
    return square_feet

def solver_2(boxes):
    feet = 0
    for box in boxes:
        sides = sorted(map(int, box.split('x')))
        wrap = sum(map(lambda x: 2*x, sides[:2]))  
        bow = sides[0]*sides[1]*sides[2] 
        feet += wrap + bow
    return feet

def main():

    d = get_input()
    print(f'Papper: {solver_1(d)}')
    print(f'Ribbon: {solver_2(d)}')

if __name__ == "__main__":
    main()

