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
    int t;
    cin >> t;
    while (t--) {
    	int x;cin>>x;
    	bool done = false;
    	for (int i=1; i<=100000; ++i) {
    		ll cur = 1LL*i*i;
    		if (cur < x) continue;
    		ll diff = cur-x;
    		int root(round(sqrt(diff)));
    		
    		if (root && diff == root*root) {
    			if (diff <= 1LL*i*i) {
    				int test = i/root;
    				if (i/test==root){
    					cout << i << ' ' << test << '\n';
    					done=true;
    				}

    				if(i/(test+1)==root) {
    					cout << i << ' '  << test+1 << '\n';
    					done=true;
    				}
    				if (done)break;
    			}
    		}
    	}
    	if (!done) cout << -1 << '\n';
    }
}
