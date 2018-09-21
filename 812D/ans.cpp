#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 100005;
int toy[MAXN];
int p[MAXN];
vector<vector<int> >adj;
int sz[MAXN];
int id[MAXN];
void dfs(int v, int p) {
	sz[v] = 1;
	for (int nei : adj[v]) {
		if (nei == p) continue;
		dfs(nei, v);
		sz[v] += sz[nei];
	}
	// printf("%d %d\n", v, sz[v]);
}
int find(int p) {
	return (id[p] == p ? p : id[p] = find(id[p]));
}
void join(int p, int q) {
	int a= find(p), b=find(q);
	if(a!=b)id[a]=id[b];
} 

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(NULL);
    int N, M, k, q;
    cin >> N >> M >> k >> q;
    adj.resize(N+1);
    for (int i=1;i<=N;++i)id[i]=i;
    for (int i=0; i<k; ++i) {
    	int a, b; cin >> a >> b;
    	if (toy[b] != 0) {
    		p[a] = toy[b];
    		adj[a].pb(toy[b]); adj[toy[b]].pb(a);
    	}
    	// printf("par %d %d\n", a, p[a]);
    	toy[b] = a;
    	if (p[a]) join(a, p[a]);
    }
    for (int i=1;i<=N; ++i) {
    	if (p[i] == 0) {
    		dfs(i, 0);
    	}
    }
    for (int i=0; i<q; ++i) {
    	int a, b; cin >> a >> b;
    	int p = a, q = toy[b];
    	// printf("%d %d\n", toy[b], a);
    	if (find(p) != find(q) || sz[q] > sz[a] || q == 0) cout << 0 << '\n';
    	else cout << sz[a] << '\n';
    }
}
