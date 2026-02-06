#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int num;
    cin >> num;
    if (num == 0) {
        cout << "0\n";
        return;
    }
    unsigned n = num;
    string res;
    string hex = "0123456789abcdef";
    while (n) {
        res += hex[n & 15];
        n >>= 4;
    }
    reverse(all(res));
    cout << res << '\n';
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}