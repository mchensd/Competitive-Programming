#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
#ifdef SUBLIME_RUN
    freopen("B.txt", "r", stdin);
#elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    ll l, r, x, y;
    cin >> l >> r >> x >> y;
    int sqr = floor(sqrt(y));
    int ans = 0;
    vi divs;
    for (int i=1; i<=sqr; ++i) {
        if (y%i==0) {
            divs.pb(i);
            if (y/i != i)
                divs.pb(y/i);
        }
    }
    
    for (int i=0; i<divs.size(); ++i) {
        // cout << divs[i] << endl;
        for (int j=0; j<divs.size(); ++j) {
            if (i == j) continue;
            ll gcd = __gcd(divs[i], divs[j]);
            ll prod = divs[i] * divs[j];
            ll lcm = prod/gcd;
            if (lcm == y && gcd == x && min(divs[i], divs[j]) >= l && max(divs[i], divs[j]) <= r) {
                ++ans;
                // cout << divs[i] << ' ' << divs[j] << endl;
            }
        }
    }
    cout << ans << endl;
}