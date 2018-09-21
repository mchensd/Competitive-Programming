#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("B.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    ll a, b; cin >> a >> b;
    while (a != 0 && b!=0) {
    	if (a >= 2*b) {
    		ll sub  = 2*b;
    		ll times = a/sub;
    		a -= (sub*times);
    	}
    	else if (b >= 2*a) {
    		ll sub = 2*a, times = b/sub;
    		b -= (sub*times);
    	}
    	else {
    		break;
    	}
    }
    cout << a << ' '<< b << '\n';
}
