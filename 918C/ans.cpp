#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    string s; cin >> s;
    int n = (int)s.size();
    int ans = 0;
    for (int i=0; i<n; ++i) {
    	int l = 0, q=0,r=0;
    	for (int k=0; k<n; ++k) {
    		int j = i+k;
    		if (j >= n) break;
    		if (s[j] == '(') ++l;
    		else if ( s[j] == ')') ++r;
    		else ++ q;
			if (r+q > l) {
				if (q) {
					--q;
					++l;
				}
				else {
					break;
				}
			}

    		if (k&1 && s[j] != '(') {
    			if (l > r+q) continue;
    			else {
    				++ans;
    				// cout<<i<<' '<<j<<'\n';
    			}
    		}
    		// printf(" %d %d %d %d %d\n",i, j, l, q, r);
    	}
    }
    cout<<ans<<'\n';
}
