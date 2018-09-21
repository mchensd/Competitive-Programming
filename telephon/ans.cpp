#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN= 100005;
vector<vector<int> > adj;
int num[MAXN];
int dp[MAXN];
bool has[MAXN];
void dfs(int v, int p) {
	if (adj[v].size() <= 1 && p != 0) {
		has[v] = true;
		return;
	}	
	for (int nei : adj[v]){ 
		if (nei == p) continue;
		dfs(nei, v);
	}

	int cnt= 0 ;
	for (int nei : adj[v]) {
		dp[v] += dp[nei];
		if (has[nei] ){
			++cnt;
			if (cnt == 2) {
				if (num[v]) {
					--num[v];
					++dp[v];
				}
				cnt=0;
			}
		}
	}
	has[v] = num[v] && cnt;

}
int main() {
    #ifdef LOCAL
	freopen("a.in", "r", stdin);
    #endif
	ios::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	adj.resize(N+1);
	int s = 1;
	for (int i=0; i<N-1; ++i) {
		int a, b; cin >> a >>b;
		adj[a].pb(b);
		if (adj[a].size()>1)s=a;
		adj[b].pb(a);
		if (adj[b].size()>1)s=b;
		num[a] = K;
		num[b] = K;
	}


// cout<<s;
	dfs(s, 0);
	cout << dp[s] << endl;
}
