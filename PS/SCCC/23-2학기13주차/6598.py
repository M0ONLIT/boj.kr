import sys

def arbitrage_possible(exchange_rates):
    n = len(exchange_rates)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                exchange_rates[i][j] = max(exchange_rates[i][j], exchange_rates[i][k] * exchange_rates[k][j])

    for i in range(n):
        if exchange_rates[i][i] > 1:
            return True
    return False

def solve():
    case = 1
    while True:
        n = int(input())
        if n == 0:
            break

        currencies = {}
        for i in range(n):
            currency = input().strip()
            currencies[currency] = i

        m = int(input())
        exchange_rates = [[0.0] * n for _ in range(n)]
        for _ in range(m):
            source, rate, dest = input().split()
            rate = float(rate)
            exchange_rates[currencies[source]][currencies[dest]] = rate

        possible = arbitrage_possible(exchange_rates)
        print(f"Case {case}: {'Yes' if possible else 'No'}")
        case += 1

        # Skip blank line between test cases
        input()

solve()
