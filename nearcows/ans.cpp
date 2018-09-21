#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

vector<vector<int> > adj;
ll dp[100005][21];
int num[100005];
int mx[100005];
void dfs(int v, int p){
	if (adj[v].size()<=1&&p!=0)return;
	for(int nei:adj[v]){if(nei==p)continue;dfs(nei,v); mx[v]=max(mx[v]+1, mx[nei]);}
}
int main() {
    #ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
    #endif
	ios::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	adj.resize(N+1);
	for (int i=0; i<N-1; ++i){ 
		int a, b; cin >> a >> b;
		adj[a].pb(b); adj[b].pb(a);
	}
	for (int i=1; i<=N; ++i) {
		cin >> dp[i][0];
	}
	for (int i=1; i<=N; ++i) {
		for (int nei : adj[i]) {
			dp[i][1] += dp[nei][0];
		}
	}
	dfs(1,0);
	for(int i=1;i<=N;++i)cout<<mx[i]<<endl;
	printf("%d %d\n", dp[1][0], dp[1][1]);
	for (int i=2; i<=K; ++i){
		printf("\n");
		for (int j=1; j<=N; ++j) {
			if (i > mx[j]) continue;
			dp[j][i] = -(adj[j].size())*dp[j][i-2];
			if (j ==1) printf("%d %d %lld %lld %lld\n", i, j, dp[j][i], dp[j][i-2], adj[j].size());
			for (int nei : adj[j]) {
				if (j==1)printf("%d %lld\n", nei, dp[nei][i-1]);
				dp[j][i] += dp[nei][i-1];
			}
			if (j==1) printf("%lld\n", dp[j][i]);
		}
	}

	for (int i=1; i<=N; ++i) {
		// printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
		ll ans = 0;
		for (int j=0; j<=K; ++j) {
			ans += dp[i][j];
		}
		cout << ans << '\n';
	}
}
