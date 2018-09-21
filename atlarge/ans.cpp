#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int best[100005];
vector<vector<int> > adj;


int ans = 0;
void dfs(int v, int p) {
	if (adj[v].size() <= 1 && p != 0) return;
	best[v] = INT_MAX;
	for (int nei : adj[v]) {
		if (nei == p) continue;
		dfs(nei, v);
		best[v] = min(best[v], best[nei]+1);
	}
}
void dfs2(int v, int p, int cur) {
	if (adj[v].size() <= 1) ++ ans;
	for (int nei : adj[v]) {
		if (nei == p) continue;
		if (best[nei] <= cur+1) {
			++ans;
			continue;
		}
		dfs2(nei, v, cur+1);
	}
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N, K; cin >> N >>K;
    adj.resize(N+1);
    for (int i=0; i<N-1; ++i ){
    	int a, b; cin >> a >> b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    dfs(K, 0);
    dfs2(K, 0, 0);
    cout << ans << endl;
}

