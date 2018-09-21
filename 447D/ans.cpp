#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

vector<vector<int> > sums;
ll dp[2][(int)1e6+5];
int rows[1005], cols[1005];
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int N, M, K, P;
    cin >> N >> M >> K >> P;
    sums.resize(2);
    for (int i=0; i<N; ++i) {
    	for (int j=0; j<M; ++j) {
    		int x; cin >> x;
    		rows[i] += x;
    		cols[j] += x;
    	}
    }
    for (int i=0; i<N; ++i) sums[0].pb(rows[i]);
    for (int i=0;i<M;++i) sums[1].pb(cols[i]);
    ll ans = LLONG_MIN;
    for (int i=0; i<2; ++i) {
    	priority_queue<int> pq;
    	for (int j=0; j<sums[i].size(); ++j) {
    		pq.push(sums[i][j]);
    		// cout << sums[i][j]<<endl;
    	}
    	// cout << endl;
    	for (int j=1; j<=K; ++j) {
    		int x =pq.top();
    		// cout << "x "<<x << endl;
    		dp[i][j] = dp[i][j-1] + x;
    		int ins = x - (i ? N*P : M*P);
    		// cout << ins << endl;
    		pq.pop();
    		pq.push(ins);
    	}
    	ans = max(ans, dp[i][K]);
    	// cout << endl;
    }
    // cout << ans << endl;
    for (int i=1; i<=K; ++i) {
    	ans = max(ans, dp[0][i] + dp[1][K-i] - 1LL*(K-i)*(i*P));
    	// printf("%d %d\n", i, ans);
    }
    cout << ans << endl;
}
