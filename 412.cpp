#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) res.push_back("FizzBuzz");
            else if (i % 3 == 0) res.push_back("Fizz");
            else if (i % 5 == 0) res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<string> ans = sol.fizzBuzz(n);
    for (auto &s : ans) cout << s << ' ';
    cout << '\n';
    return 0;
} 