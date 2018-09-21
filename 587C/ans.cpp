#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int N, M, Q;
const int MAXN = 100005;
vector<vector<int> >adj;
vector<int> vals[MAXN];
vector<int> cities[MAXN];
int cityOf[MAXN];
int lev[MAXN];
int par[MAXN][20];
bool added[MAXN];
void dfs(int v, int p) {
    par[v][0] = p;
    lev[v] = lev[p]+1;
    for (int id : vals[p]) {
        vals[v].pb(id);
    }
    for (int id : cities[v]) {
        if (vals[v].size() == 10) break;
        vals[v].pb(id);
    }
    for (int nei: adj[v]) {
        if (nei == p) continue;
        dfs(nei, v);
    }
}
int lca(int v, int u) {
    if (lev[v] < lev[u]) swap(v, u);
    for (int i=19; i>=0; --i) {
        if (par[v][i] && lev[par[v][i]] >= lev[u]) {
            v = par[v][i];
        }
    }
    if (v == u) return v;
    for (int i=19;i>=0; --i){
        if (par[v][i] != par[u][i] && !(par[v][i] == 0 || par[u][i] == 0)) {
            v = par[v][i]; u=par[u][i];
        }
    }
    return par[v][0];
}
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> M >> Q;
    adj.resize(N+1);
    for (int i=0 ;i<N-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1; i<=M; ++i) {
        int c;cin>>c;
        cities[c].pb(i);
        cityOf[i] = c;
    }
    dfs(1, 0);
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<20; ++j) {
//            printf("%d %d\n", i, j);
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    while (Q--) {
        int v, u, a; cin >> v >> u >> a;
        int anc = lca(v, u);
//        printf("anc %d %d %d\n", v, u, anc);
        vector<int> out;
        for (int x : vals[v]) {
            if (lev[cityOf[x]] >= lev[anc]) {
                if (out.size() == a) break;
                out.pb(x);
                added[x] = true;
            }
        }
        for (int x : vals[u]) {
            if (added[x]) continue;
            if (lev[cityOf[x]] >= lev[anc]) {
                if (out.size() == a) break;
                out.pb(x);
            }
        }
        cout << out.size() << ' ';
        sort(out.begin(), out.end());
        for (int x : out) {
            cout << x << ' ';
            added[x] = false;
        }
        cout << '\n';
    }
    
}

