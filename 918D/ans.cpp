#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int N, M;
vector<vector<pii> > adj;
int dp[105][105][27][3];

int dfs(int v, int u, int last, int turn) {
//    printf("%d %d %d %d %d\n", v, u, last, turn, dp[v][u][last][turn]);
    if (dp[v][u][last][turn]) return dp[v][u][last][turn];
    int cur = ((turn==1) ? v : u);
    dp[v][u][last][turn] = 3-turn;
    for (pii nei : adj[cur]) {
        if (nei.second >= last) {
//            cout << nei.second << endl;
            int a=v, b=u;
            if (turn == 1) a = nei.first;
            else b = nei.first;
            int tmp = dfs(a, b, nei.second, 3-turn);
            if (tmp == turn) {
                dp[v][u][last][turn] = tmp;
                break;
            }
        }
    }
//    cout << dp[v][u][last][turn] << endl;
    return dp[v][u][last][turn];
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> M;
    adj.resize(N+1);
    for (int i=0; i<M; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        // cout << c << endl;
        c = c-'a'+1;
        // cout << (int)c << endl;
        adj[a].pb(mp(b, c));
    }
    for (int i=1;i<=N; ++i) {
        for (int j=1; j<=N; ++j){
            if (i == j) cout << 'B';
            else {
                int ans = dfs(i, j, 0, 1);
//                cout << '\n';
                 cout << (ans == 1 ? 'A' : 'B');
            }
        }
         cout << '\n';
    }
    
}

