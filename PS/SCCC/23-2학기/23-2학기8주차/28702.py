for i in range(3)[::-1]:
    s=input()
    if s not in 'FizzBuzz':
        x=int(s)+i+1
c=0
if x%3==0:
    print('Fizz', end='')
    c=1
if x%5==0:
    print('Buzz')
    c=1
if not c:
    print(x)
