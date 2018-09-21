#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

vector<vector<pii> > adj;
int t[405];
int N;
bool vis[405];
int ans = 0;
int best[405];
void dfs(int v, int curt, int num) {
    ans = max(ans, num);
    vis[v] = true;
    best[v] = 1;
    for (pii nei : adj[v]) {
        if (nei.second+curt <= t[nei.first]) {
//            printf("v %d %d %d %d\n", v, nei.first, nei.second, curt);
            if (!vis[nei.first]) {
                dfs(nei.first, t[nei.first], num+1);
            }
            best[v] = max(best[v], best[nei.first]+1);
            ans = max(ans, best[v]);
        }
    }
    // printf("%d %d\n", v, best[v]);
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=1; i<=N; ++i) {
        cin >> t[i];
    }
    adj.resize(N+1);
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            int w; cin >> w; if (i==j)continue;
            adj[i].pb(mp(j, w));
        }
    }
    dfs(1,t[1], 1);
    for (pii nei : adj[1]){
        if (!vis[nei.first] && nei.second <= t[nei.first])dfs(nei.first, t[nei.first], 1);
    }
    cout << ans << endl;
}

