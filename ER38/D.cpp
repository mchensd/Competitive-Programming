#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
#define mp make_pair
#define pb push_back

ll ans[200005];
ll best[200005];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("D.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pil> > adj;adj.resize(n+1);
    for (int i=0; i<m; ++i){ 
    	int a,b;
    	ll w;
    	cin >> a >> b >> w;
    	w *= 2;
    	adj[a].pb(mp(b,w));
    	adj[b].pb(mp(a,w));
    }
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    for (int i=1; i<=n; ++i) {
    	ll cost; cin >> cost;
    	pq.push(mp(cost,i));
    	best[i]=cost;
	}
	while (pq.size()) {
		pli next = pq.top(); pq.pop();
		if (best[next.second] != next.first) continue;
		ans[next.second] = next.first;
		for (pil nei : adj[next.second]) {
			if (best[nei.first] > nei.second + next.first) {
				best[nei.first] = nei.second+next.first;
				pq.push(mp(best[nei.first], nei.first));
			}
		}
	}
	for (int i=1; i<=n;++i) {
		if (i>1) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
}
