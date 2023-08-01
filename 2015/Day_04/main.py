import hashlib 

def solver_1(s):
    num = 0
    my_hash = ''
    while my_hash[:6] != '000000':
        num += 1
        my_hash = hashlib.md5((s + str(num)).encode('utf-8')).hexdigest()
    return my_hash, num
        
def solver_2(s):
    pass

def main():
    s = 'bgvyzdsv'
    print(solver_1(s))
    print(solver_2(s))

if __name__ == '__main__':
    main()

