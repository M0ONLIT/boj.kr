#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 두 문자열을 표현하는 숫자의 합 계산
string addStrings(string num1, string num2) {
    string res = "";
    int carry = 0;
    int n1 = num1.size() - 1, n2 = num2.size() - 1;

    while (n1 >= 0 || n2 >= 0) {
        int sum = carry;
        if (n1 >= 0)
            sum += num1[n1--] - '0';
        if (n2 >= 0)
            sum += num2[n2--] - '0';
        res = to_string(sum % 10) + res;
        carry = sum / 10;
    }

    if (carry)
        res = to_string(carry) + res;

    return res;
}

// 두 문자열 숫자의 차 계산
string subStrings(string str1, string str2) {
    bool isNegative = false;
    if (str1.size() < str2.size())
        swap(str1, str2), isNegative = true;
    else if (str1.size() == str2.size() && str1 < str2)
        isNegative = true;

    string res = "";
    int n1 = str1.size() - 1, n2 = str2.size() - 1;
    int borrow = 0;

    while (n2 >= 0) {
        int sub = ((n1 >= 0) ? str1[n1] - '0' : 0) - borrow;
        if (n2 >= 0)
            sub -= (str2[n2] - '0');
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        res = to_string(sub) + res;
        n2--; n1--;
    }

    while (n1 >= 0) {
        int sub = str1[n1] - '0' - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        res = to_string(sub) + res;
        n1--;
    }

    auto it = res.find_first_not_of("0");
    if (it != string::npos)
        res = res.substr(it);
    else
        res = "0";

    return isNegative ? "-" + res : res;
}

// 두 숫자를 문자열로 표현하여 곱셈 계산 (카라츠바 알고리즘)
string multiply(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();

    // base case: 한 자리 수 곱셈
    if (n1 == 1 || n2 == 1)
        return to_string(stoll(num1) * stoll(num2));

    // 두 숫자를 반으로 나누기
    int maxDigits = max(n1, n2);
    int mid = maxDigits / 2;
    string a = num1.substr(0, mid);
    string b = num1.substr(mid);
    string c = num2.substr(0, mid);
    string d = num2.substr(mid);

    // 재귀적으로 하위 문제 계산
    string ac = multiply(a, c);
    string bd = multiply(b, d);
    string adbc = multiply(addStrings(a, b), addStrings(c, d));
    string adbc_ac_bd = subStrings(adbc, addStrings(ac, bd));

    // 가우스 기수법칙에 따라 계산
    string res = ac + string(2 * maxDigits - 2 * mid, '0') + bd;
    res = addStrings(res, adbc_ac_bd + string(maxDigits - mid, '0'));

    return res;
}

int main() {
    string num1, num2;
    cin >> num1;
    cin >> num2;

    string res = multiply(num1, num2);
    cout << res << endl;

    return 0;
}
