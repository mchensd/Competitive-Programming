#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int f[505];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("fcount.in", "r", stdin);
    freopen("fcount.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=0; i<N; ++i ){
    	cin >> f[i];
    }
    for (int i=0; i<N; ++i) {
    	vector<int> cur;
    	for (int j=0; j<N; ++j) {
    		if (i == j) continue;
    		cur.pb(f[j]);
    	}
    	sort(cur.begin(), cur.end());
    	for (int j=0; j<N-1; ++j) {
    		int mx = 0, ind = 0;
    		for (int k=j+1; k<N-1; ++k) {
    			if (cur[k] > mx) {
    				mx = cur[k];
    				ind = k;
    			}
    		}
    		if (mx == 0) break;
    		--
    	}
    }
}
