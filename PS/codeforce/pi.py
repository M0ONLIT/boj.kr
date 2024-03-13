
with open('test.txt') as f:
    s=f.readline().replace(' ', '').strip()

def main():
    first_10_sum = sum(map(int, s[:10]))  # 첫 10자리의 합 계산
    matching_substrings = []  # 부분 문자열 저장
    
    for i in range(len(s) - 9):
        substring = s[i:i+10]
        substring_sum = sum(map(int, substring))
        
        if substring_sum == first_10_sum:
            matching_substrings.append((substring, i))
    
    for substring, start_index in matching_substrings[:10]:
        print(f"{substring} ", end=', ')

if __name__ == "__main__":
    main()
