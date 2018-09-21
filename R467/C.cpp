#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("C.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    ll K, D, T;
    cin >> K >> D >> T;
    ll off = 0;
    for (ll i=K; ; ++i, ++off) {
    	if (i % D == 0) break;
    }
	ll lb=1, ub=(ll)2e18;
	ll tot = K+off;
	while (lb < ub) {
		ll xs = (lb+ub)/2;
		double tmp = 0;
		ll cycles = xs / tot;
		tmp += (K + (.5*off))*cycles;
		ll cur = xs % tot;
		if (cur < K) {
			tmp += (cur+1)*K;
		}
		
	}
}
