#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

bool vis[1005];
int fun[1005];
vector<vector<pii> > adj;
double ans = 0;
void dfs(int orig, int v, int f, int t){
	vis[v] = true;
	for (pii nei : adj[v]) {
		if (nei.first ==orig) {
			ans = max(ans, (1.0*t+nei.second)/(1.0*f));
		}
		else if (!vis[nei.first]) {
			dfs(orig, nei.first, f+)
		}

	}
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i){
    	cin >> fun[i+1];
    }
    adj.resize(n+1);
    for (int i=0; i<m; ++i) {
    	int a, b, w; cin >> a >> b >> w;
    	if (a == b) continue;
    	adj[a].pb(mp(b, w));
    }

    for (int i=1;i <=N; ++i) {
    	dfs(i, i, fun[1], 0);
    	memset(vis, 0, sizeof(vis));
    }
}
