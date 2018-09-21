#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 21;
int dp[1<<MAXN];
int dur[MAXN];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N, L;
    cin >> N >> L;
    vector<vector<int> > starts(N);
    for (int i=0; i<N; ++i){ 
    	cin >> dur[i];
    	int x; cin >> x;
    	starts[i].resize(x);
    	for (int j=0; j<x; ++j) {
    		cin >> starts[i][j];
    	}
    	sort(starts[i].begin(), starts[i].end());
    }
    int ans = INT_MAX;
    for (int i=0; i<(1<<N); ++i) {
    	if (dp[i] >= L) {
    		ans = min(ans, __builtin_popcount(i));
    	}
    	for (int j=0; j<N; ++j){ 
    		if (!((i>>j) & 1)) {
    			auto it = upper_bound(starts[j].begin(), starts[j].end(), dp[i]);
    			if (it != starts[j].begin()) {
    				--it;
    				int st = *it;
    				if (st + dur[j] > dp[i]) {
    					dp[(1<<j) | i] = max(dp[(1<<j)|i], st+dur[j]);
    				}
    			}
    		}
    	}
    }
    if (ans == INT_MAX)
    	ans = -1;
    cout << ans << endl;
}
