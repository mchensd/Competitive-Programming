#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppii;
#define mp make_pair
#define pb push_back
#define ff first 
#define ss second 
const int MAXN = 10005;
vector<vector<pii> > adj;
bool done[MAXN];
int dist[MAXN];
int ans[MAXN];
pii possible[MAXN];
int par[MAXN];
int main() {
    #ifdef LOCAL
	freopen("a.in", "r", stdin);
    #endif
	ios::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	adj.resize(N+1);
	for (int i=0; i<M; ++i) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].pb(mp(b, w));
		adj[b].pb(mp(a, w));
		dist[a]=INT_MAX;
		dist[b]=INT_MAX;
		ans[a]=INT_MAX;
		ans[b] = INT_MAX;
		pii p = mp(ans[a], ans[b]);
		possible[a] = p;
		possible[b] = p;
	}

	priority_queue<ppii, vector<ppii>, greater<ppii> > pq;
	dist[1]=0;
	pq.push(mp(0, mp(1, 0)));
	while (pq.size()) {
		ppii next = pq.top();
		pq.pop();
		if (next.first != dist[next.ss.ff]) continue;
    	// done[next.second] = true;
    	par[next.ss.ff] = next.ss.ss;
		for (pii nei : adj[next.ss.ff]) {
    		// // if (done[nei.second]) {
    		// // 	ans[nei.first] = min(ans[nei.first], dist[next.second] + nei.second);
    		// // }
    		// else {
			printf("%d %d %d\n", next.ss.ff, par[next.ss.ff], nei.first);
			if (nei.first == par[next.ss.ff]) continue;
			int tmpw=  dist[next.ss.ff] + nei.second;
			if (tmpw <= possible[nei.first].first) {
				possible[nei.first].second = possible[nei.first].first;
				possible[nei.first].first = tmpw;
			}
			else if (tmpw < possible[nei.first].second) possible[nei.first].second = tmpw;
			// printf("%d %d %d %d %d\n", nei.first, next.ss.ff, tmpw, possible[nei.first].first, possible[nei.first].second);
			if (dist[nei.first] > dist[next.ss.ff]+nei.second) {
				dist[nei.first] = dist[next.ss.ff]+nei.second;
				pq.push(mp(dist[nei.first], mp(nei.first, next.ss.ff)));
			}

    		// }
		}
	}
	cout<<'\n';	 		
	for (int i=2; i<=N; ++i) {
		// cout << ((possible[i].second == INT_MAX) ? -1 : possible[i].second) << '\n';
		printf("%d %d\n", possible[i].second, dist[i]);
	}
}
