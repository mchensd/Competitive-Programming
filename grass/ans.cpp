#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 100005;
vector<vector<int> > adj, rev, scc, srev;
vector<int> ord, top;
int comp[MAXN], tord[MAXN];
bool vis[MAXN];
int sz[MAXN];
int dp[MAXN];
int N, M;
int num=0;
void dfs(int v) {
    vis[v] =true;
    for (int nei : adj[v]) {
        if (!vis[nei]) {
            dfs(nei);
        }
    }
    ord.pb(v);
}

void dfs2(int v, int c) {
    comp[v] = c;
    ++sz[c];
    for (int nei : rev[v]) {
        if (!comp[nei]) {
            dfs2(nei, c);
        }
    }
}

void kosaraju() {
    for (int i=1; i<=N;++i) {
        if (!vis[i]) {
            // cout << i << endl;
            dfs(i);
        }
    }
    int cmpNum = 1;
    for (int i=(int)ord.size()-1; i>=0; --i) {
        // cout << ord[i] << endl;
        if (!comp[ord[i]]) {
            // cout << ord[i] << endl;
            ++num;
            dfs2(ord[i], cmpNum);
            ++cmpNum;
        }
    }
    for (int i=1; i<=N; ++i) {
        for (int nei : adj[i]) {
            if (comp[nei] != comp[i]) {
                scc[comp[i]].pb(comp[nei]);
                srev[comp[nei]].pb(comp[i]);
                // printf("%d %d\n", comp[i], comp[nei]);
            }
        }
    }
    
}

void dfs3(int v) {
    vis[v] =1;
    for (int nei : scc[v]) {
        if (!vis[nei]) {
            dfs3(nei);
        }
    }
    top.pb(v);
}
void topsort() {
    top.pb(0);
    for (int i=1; i<=num; ++i) {
        if (!vis[i]) {
            dfs3(i);
        }
    }
    for (int i=num; i>=1; --i) {
        tord[top[i]] = num+1-i;
    }
}

void dfs4(int v)  {
    vis[v]=  true;
    for (int nei : scc[v]) {
        // printf("%d %d %d %d\n", v, nei, tord[nei], tord[comp[1]]);
        if (tord[nei] > tord[comp[1]])continue;
        if (nei == comp[1]) {
            dp[v] = max(dp[v], sz[v]);
        }
        else {
            if (!vis[nei] ){
                dfs4(nei);
            }
            if (dp[nei] != 0)
            	dp[v]=max(dp[v], sz[v]+dp[nei]);
        }
    }
}
void dfs5(int v) {
    vis[v] = true;
    for (int nei : scc[v]) {
        // printf("%d %d\n", v, nei);
        if (!vis[nei]) {
            dfs5(nei);
        }
        if (dp[nei] != 0)
        	dp[v] = max(dp[v], sz[v]+dp[nei]);
    }
    for (int nei : srev[v]) {
        if (tord[nei] <= tord[comp[1]]) {
            // printf("rev %d %d\n", v, nei);
            if (nei == comp[1]) 
                dp[v] = max(dp[v], sz[v]);
            else if (dp[nei] != 0)
            	dp[v] = max(dp[v], sz[v] + dp[nei]);
        }
    }
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("grass.in", "r", stdin);
    freopen("grass.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> M;
    adj.resize(N+1);scc.resize(N+1);rev.resize(N+1);srev.resize(N+1);
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        rev[b].pb(a);
    }
    kosaraju();
    memset(vis, 0, sizeof(vis));
    topsort();
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=num;++i){
    	// cout << top[i] << endl;
// j    	cout << i << ' ' << tord[i] << endl;
    	if (tord[i] >= tord[comp[1]]) continue;
        if (!vis[i]) {
        	// cout <<i << endl;
            dfs4(i);
        }
    }
    // cout << num << endl;
    memset(vis, 0, sizeof(vis));
    dfs5(comp[1]);
    // cout << comp[5] << comp[4] << endl;
    // cout << comp[1] << sz[comp[1]] << endl;
    // cout << dp[2] << dp[3] << endl;
    // cout << sz[2] << endl; 
    // cout << sz[3] << endl;
    dp[comp[1]] = max(dp[comp[1]], sz[comp[1]]);
    cout << dp[comp[1]] << endl;
}
