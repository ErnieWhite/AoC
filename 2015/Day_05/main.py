from more_itertools import sliding_window
from itertools import pairwise

def get_input():
    with open('input.txt') as f:
        data = f.read().splitlines()
    return data

def _solver_1(s):

    # It contains at least three vowels (aeiou only), like aei, xazegov, or aeiouaeiouaeiou.
    VOWELS = {'a', 'e', 'i', 'o', 'u'}
    test = len([x for x in s if x in VOWELS])>2
    result = test

    # It contains at least one letter that appears twice in a row, like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd). 
    test = any([x[0] == x[1] for x in sliding_window(s, 2)])
    result = result and test

    # It does not contain the strings ab, cd, pq, or xy, even if they are part of one of the other requirements. 
    BAD_STRINGS = ['ab', 'cd', 'pq', 'xy']
    test = not any(s.find(x)!=-1 for x in BAD_STRINGS)
    result = result and test

    return result

def solver_1(lst):
    return [s for s in lst if _solver_1(s)]
        
def _solver_2(s):
    """
    It contains a pair of any two letters that appears at least twice in
    the string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but
    not like aaa (aa, but it overlaps). 
    """
    i_1 = 0
    i_2 = 2
    result = False
    for i_1 in range(len(s) - 3):
        search_for = s[i_1:i_1+2]
        search_in = [''.join(x) for x in pairwise(s[i_1+2:])]
        if search_for in search_in:
            result = True
            break

    if not result:
        return result

    """
    It contains at least one letter which repeats with exactly one letter
    between them, like xyx, abcdefeghi (efe), or even aaa.
    """
    for i in range(len(s)-2):
        if s[i] == s[i+2]:
            return True
    return False

def solver_2(data):
    return  [s for s in data if _solver_2(s)]

def main():
    data = get_input()
    print(len(solver_1(data)))
    print(len(solver_2(data)))

if __name__ == '__main__':
    main()

