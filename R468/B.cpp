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
    int n, a, b; cin >>  n>> a >> b;
    if (a > b) swap(a,b);
    vector<int> v(n);
    for (int i=0;i<n;++i) 
    	v[i] = i+1;
    int r = 1;
    while (v.size() > 1) {
    	for (int i=0; i<v.size(); i++) {
    		// printf("%d %d %d\n", v[i], v[i+1],v.size());
    		if (min(v[i],v[i+1]) == a && max(v[i],v[i+1]) == b) {
    			if (v.size() == 2) {
    				return 0*puts("Final!");
    			}
    			else {
    				return cout << r << endl, 0;
    			}
    		}
    		if (v[i] == a || v[i] == b) {
    			v.erase(v.begin()+i+1);
    		}
    		else {
    			v.erase(v.begin()+i);
    		}
    	}
    	++r;
    }
}
