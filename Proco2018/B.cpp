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
    ll Q, a, b;
    cin >> Q >> a >> b;
    // ll er = 3000000000;
    // cout << er << endl;
    // cout << to_string(er) + "a" << endl;
    for (ll i=1; i<=Q; ++i) {
    	ll x = (a+b*i)%((int)1e9+7);
    	string s = to_string(x);
    	ll cnt = 0;
    	while (s.size() > 1) {
    		// cout << s << endl;
    		ll nx = 0;
    		for (int j=0; j<s.size(); ++j) {
    			nx += (s[j]-'0')*(s[j]-'0');
    		}
    		s = to_string(nx);
    		++cnt;
    	}
    	cout << cnt << "\n";
    }
}
