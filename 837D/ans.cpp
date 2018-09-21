#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 205;
const int MAXLOG = 26;
ll nums[MAXN];
int t[MAXN], f[MAXN];
int dp[MAXN][2][MAXN*MAXLOG];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
    	ll x; cin >> x;
    	nums[i] = x;
    	while (x % 2 == 0) {
    		++t[i];
    		x /= 2;
    	}
    	while (x % 5 == 0) {
    		++f[i];
    		x /= 5;
    	}
    	// printf("%d %d\n", t[i],f[i]);
    	// ans = max(ans, min(t[i], f[i]));
    }
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<N; ++i) {
    	dp[i][0][0] = 0;
    }
    for (int k=1; k<=K; ++k){
    	int i;
    	int ki = k&1;
    	dp[0][ki][f[0]] = t[0];
    	for (i=1; i<N; ++i) {
    		for (int j=0; j<MAXN*MAXLOG; ++j) {
    			if (dp[i-1][ki][j] > -1) {
    				if (i >= k) dp[i][ki][j] = max(dp[i][ki][j], dp[i-1][ki][j]);
    				else dp[i][ki][j+f[i]] = max(dp[i][ki][j+f[i]], dp[i-1][ki][j] + t[i]);
    			}
    			if (i >= k && dp[i-1][!ki][j] > -1) {
    				// if (k == 1) cout << i << ' ' << j+f[i] << endl;
    				dp[i][ki][j+f[i]] = max(dp[i][ki][j+f[i]], dp[i-1][!ki][j] + t[i]);
    			}
    		}
    	}
    	if (k == 1) {
    		// cout << dp[2][ki][2] << endl;
    	}
    }
    int ki = K&1; int ans = 0;
    for (int i=0; i<MAXN*MAXLOG; ++i) {
    	// if (dp[N-1][ki][i] == 2) printf("%d\n", i);
    	ans = max(ans, min(dp[N-1][ki][i], i));
    }
    cout << ans << '\n';
}
