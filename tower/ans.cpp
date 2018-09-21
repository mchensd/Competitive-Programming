#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 5005;
int w[MAXN];
int dp[MAXN][MAXN];
int pref[MAXN];
int N;
int qsum(int i, int j) {
	return pref[j] - pref[i-1];
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    // freopen("/Users/chen.young/Downloads/tower/tower.4.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=1; i<=N; ++i) {
    	cin >> w[i];
    	dp[1][i] = 1;
    	pref[i] = pref[i-1] + w[i];
    }
    // freopen("/Users/chen.young/Downloads/tower/tower.4.out", "r", stdin);
    // int a; cin >> a; cout << a << endl;
    int ans =1;
    for (int i=2; i<=N; ++i ){
    	int optk = i-1;
    	for (int j=i; j<=N; ++j) {
    		while (optk && (qsum(optk, i-1) < qsum(i,j) || dp[optk][i-1] == 0)) {
    			--optk;
    		}
    		dp[i][j] = dp[i-1][j];
    		if (optk == 0) break;
    		dp[i][j] = max(dp[i][j],dp[optk][i-1] + 1);
    		if (j == N) ans = max(ans, dp[i][j]);
    	}
    }
    cout << ans << endl;
}
