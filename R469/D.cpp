#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("D.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    ll N, Q;
    cin >> N >> Q;
    while (Q--){ 
    	ll x; cin >> x;
    	while (!(x&1)) {
    		ll front = N-(x/2);
    		x += front;
    	}
    	cout << (x+1)/2 << '\n';
    }
}
