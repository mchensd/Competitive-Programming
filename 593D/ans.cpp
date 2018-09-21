#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define mp make_pair
#define pb push_back


const int MAXN = 200005;
vector<vector<pil> > adj;
int sz[MAXN];
int p[MAXN][19];
pil p1[MAXN], p2[MAXN];
int h[MAXN];
pii edges[MAXN];
int N, Q;
void dfs(int v) {
	h[v] = h[p[v][0]]+1;
	for (pil nei : adj[v]) {
		if (nei.first == p[v][0]) continue;
		p[nei.first][0] = v;
		p1[nei.first] = mp(v, nei.second);
		p2[nei.first] = mp(v, nei.second);
		if (nei.second == 1 && p2[v].second == 1) {
			p2[nei.first] = mp(p2[v].first, nei.second);
		}
		dfs(nei.first);
	}
}

void calcdp	() {
	for (int i=1; i<=N; ++i) {
		for (int j=1;j<19; ++j) {
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}
}

int lca(int a, int b) {
	if (h[a] > h[b]) swap(a, b);
	for (int i=18; i>=0; --i) {
		if (h[p[b][i]] >= h[a]) {
			b = p[b][i];
		}
	}
	if (a == b) return a;
	for (int i=18; i>=0; --i) {
		if (p[a][i] != p[b][i]) {
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);

    cin >> N >> Q;
    adj.resize(N+1);
    for (int i=0; i<N-1; ++i) {
    	int a, b;
    	ll w; 
    	cin >> a >> b >> w;
    	adj[a].pb(mp(b, w));
    	adj[b].pb(mp(a, w));
    	edges[i+1] = mp(a, b);
    }
    p1[1] = mp(0, 2);
    p2[1] = mp(0, 2);
    p[1][0] = 0;
    dfs(1);
    calcdp();
    // int cnt = 0;
    // int cnt =1;
    // cout << lca(4, 7) << lca(4, 8) << lca(5, 6) << lca(2, 5) << lca(1, 8) << endl;
    // if (N == 200000) cout << Q << endl;
    while(Q--){	
    	int t; cin  >> t;
    	// if (N == 200000) cout << "t " << t << '\n';
    	if(t==1) {
    		// ++cnt;
    		int a, b;
	    	ll y; cin >> a >> b >> y;
    		// if (N != 200000) {
    		int anc = lca(a, b);
    	 	while (h[p2[a].first] >= h[anc] && y) {
    	 		if (p2[a].second == 0) {
    	 			cout << a << ' ' << p2[a].first << endl;
    	 			return 0;
    	 		}
    			y /= p2[a].second;
    			a = p2[a].first;
    		}
    		while (h[p2[b].first] >= h[anc] && y){ 
    			y /= p2[b].second;
    			b = p2[b].first;
    		}
    		cout << y << '\n';
	    	// }
    	}
    	else {
    		// ++cnt;
	    	int e;
	    	ll val; cin >> e >> val;
    		// if (N!=200000) {
    		int a=edges[e].first, b=edges[e].second;
    		if (h[a] > h[b]) swap(a, b);
    		p2[b].second =val;
    		if (val == 1) {
    			if (p2[a].second == 1) {
    				p2[b].first = p2[a].first;
    			}
    			for (pil nei : adj[b]) {
    				if (p2[nei.first].first == b) {
    					if (nei.second == 1) {
    						p2[nei.first].first = p2[b].first;
    					}
    				}
    			}
	    		// }
	    	}
    	}
    }
    // if (N == 200000) {
    // 	cout 	<< cnt << endl;
    // 	cout << Q << endl;
    // }
    // for (int i=1; i<=N; ++i) {
    // 	for (int j=1; j<=N; ++j) {
    // 		if (i == j) continue;
    // 		printf("%d %d %d\n", i, j, lca(i, j));
    // 	}
    // }
    // for (int i=1; i<=N; ++i) {
    // 	printf("%d %d %d %d\n", i, p1[i].first, p2[i].first, p2[i].second);
    // }
}
