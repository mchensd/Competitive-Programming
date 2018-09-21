#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back


vector<vector<pii> > adj;
vector<vector<int> > dp;


int N,M,K;
void merge(vector<vector<int> > vals, int ind) {
    vector<int> inds(vals.size(), 0);
    for (int i=0; i<K; ++i) {
        int nxt = INT_MAX;
        int minind = 0;
        for (int j=0;j<vals.size();++j) {
            if (inds[j] != vals[j].size()){
                if (nxt > vals[j][inds[j]]) {
                    minind = j;
                    nxt = vals[j][inds[j]];
                }
            }
        }
        if (nxt == INT_MAX)return;
        ++inds[minind];
        
        dp[ind].pb(nxt);
    }
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> M >> K;
    adj.resize(N+1);
    for (int i=0;i<M; ++i) {
        int a,b,w;cin>>a>>b>>w;
        if(a<b)swap(a,b);
        adj[a].pb(mp(b,w));
    }
    dp.resize(N+1);
    dp[1].pb(0);
    for (int i=2; i<=N; ++i){
        vector<vector<int> > nxt;
        for (pii nei : adj[i]) {
            // printf("%d %d\n", i, nei.first);
            vector<int> add;
            for (int j=0;j<dp[nei.first].size();++j) {
                add.pb(dp[nei.first][j]+nei.second);
            }
            nxt.pb(add);
        }
        merge(nxt, i);
    }
    int i;
    for (i=0; i<dp[N].size(); ++i) {
        cout << dp[N][i] << '\n';
    }
    for (;i<K;++i) {
        cout  << -1 <<'\n';
    }
}

