# n개의 정수를 입력받습니다.
n = int(input())
numbers = list(map(int, input().split()))

# 정렬합니다.
sorted_numbers = sorted(numbers, reverse=True, key=lambda x: str(x)*20)

# 결과를 공백 없이 이어서 출력합니다.
result = ''.join(map(str, sorted_numbers))
if set(result)=={'0'}:
    print(0)
else:
    print(result)
