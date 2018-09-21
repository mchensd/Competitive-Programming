#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, pii> > ppii;
typedef pair<int, pii> piip;
#define mp make_pair
#define pb push_back

const int MAXN = 100005;
int dist[MAXN];
vector<vector<pii> > adj;
vector<vector<pii> > adj2;
pii p[MAXN];
int p2[MAXN][20];
int vis[MAXN];
int seen[MAXN];
int ans[MAXN];
int h[MAXN];
priority_queue<piip, vector<piip>, greater<piip> > pq2;
bool ancestor(int u, int v) {
	// u ancestor of v?
	for (int i=19; i>=0; --i){ 
		if (h[p2[v][i]] >= h[u]) {
			v = p2[v][i];
		}
	}
	return v == u;
}
void dfs(int v, int par) {
	// printf("dfs %d %d\n", v, par);
	vis[v] = true;
	// printf("\nv %d\n", v);
	for (pii nei  : adj[v]) {
		if (vis[nei.first] || (p[nei.first].first == v && p[nei.first].second == nei.second)) continue;
		ans[nei.first] = min(ans[nei.first], dist[v] + nei.second);
		pq2.push(mp(ans[nei.first], mp(nei.first, v)));
		seen[nei.first] = true;
	}
	for (pii nei : adj2[v]) {						
		if (nei.first == par) continue;
		// printf("w %d\n", nei.second);
		// printf("    %d ", nei.first);
		dfs(nei.first, v);
	}
	// printf("\n");
	vis[v] = false;
}
int main() {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	adj.resize(N+1);
	adj2.resize(N+1);
	for (int i=0; i<M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].pb(mp(b, w));
		adj[b].pb(mp(a, w));				
		dist[a] = INT_MAX;
		dist[b] = INT_MAX;
		ans[a] = INT_MAX; ans[b] = INT_MAX;
	}
	priority_queue<ppii, vector<ppii>, greater<ppii> > pq;
	dist[1] = 0;
	pq.push(mp(0, mp(1, mp(0, 0))));

	while (pq.size()) {
		ppii next = pq.top();
		pq.pop();
		if(next.first != dist[next.second.first]) continue;
		adj2[next.second.first].pb(mp(next.second.second.first, next.second.second.second));
		adj2[next.second.second.first].pb(mp(next.second.first, next.second.second.second));
		p[next.second.first] = mp(next.second.second.first, next.second.second.second);
		p2[next.second.first][0] = next.second.second.first;
		h[next.second.first] = h[p2[next.second.first][0]]+1;
		for (pii nei : adj[next.second.first]) {
			if(dist[nei.first] > dist[next.second.first] + nei.second) {
				dist[nei.first] = dist[next.second.first] + nei.second;
				pq.push(mp(dist[nei.first], mp(nei.first, mp(next.second.first, nei.second))));
			}
		}
	}
	dfs(1, 0);
	for (int i=1; i<=N; ++i){
		for(int j=1; j<20; ++j){
			p2[i][j] = p2[p2[i][j-1]][j-1];
		}
	}
	while (pq2.size()) {
		piip next = pq2.top() ;
		pq2.pop();
		printf("%d %d %d\n", next.second.first, next.second.second, next.first);
		if (ans[next.second.first] != next.first)continue;
		for (pii nei : adj[next.second.first]) {
			// printf("%d %d\n", nei.first, nei.second)
			// if (ancestor(nei.first, next.second.first)) printf("%d %d\n", nei.first, next.second.first);
			if ((p[nei.first].first == next.second.first && p[nei.first].second == nei.second) || ancestor(nei.first, next.second.second	)) continue;
			if (ans[nei.first] > ans[next.second.first] + nei.second){ 
				ans[nei.first] = ans[next.second.first] + nei.second;
				// printf("%d %d %d\n", ans[nei.first],nei.first, next.second.first);
				pq2.push(mp(ans[nei.first], mp(nei.first, next.second.second)));
			}
		}
	}
	// for (int i=2; i<=N; ++i) {
	// 	if (seen[i]) {
	// 		// cout << i << endl;
	// 		int cur = p[i].first;
	// 		int d = ans[i]+p[i].second;
	// 		// printf("%d 	%d %d %d\n", cur, d, p[i].first, p[i].second);
	// 		while (cur != 1 && !seen[cur]) {
	// 			ans[cur]=min(ans[cur], d);
	// 			cur = p[cur].first;
	// 			d += p[cur].second;
	// 		}
	// 	}
	// }
	// cout << ancestor(6, 3) << endl;
	for (int i=2; i<=N; ++i) {
		cout << (ans[i] == INT_MAX ? -1 : ans[i]) << '\n';//endl;
		// cout << dist[i] << endl;
	}
}
