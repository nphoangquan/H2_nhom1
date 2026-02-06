#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res += (sum % 10) + '0';
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    Solution sol;
    cout << sol.addStrings(a, b) << '\n';
    return 0;
} 