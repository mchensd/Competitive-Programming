#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
#define mp make_pair
#define pb push_back

const int MAXN = 200005;
const int MAXLOG = 20;
vector<vector<pil> > adj;
pil par[MAXN][MAXLOG];
int ans[MAXN];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("runaway.in", "r", stdin);
    freopen("runaway.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N, L;
    cin >> N >> L;
    adj.resize(N+1);
    for (int i=2;i<=N; ++i) {
    	int p; ll w;
    	cin >> p >> w;
    	adj[p].pb(i);
    	adj[i].pb(p);
    	par[i][0] = mp(p,w);
    }
    for (int i=1; i<=N; ++i){
    	for (int j=1; j<MAXLOG; ++j) {
    		ll w = par[i][j-1].second + par[par[i][j-1].first][j-1].second;
    		if (w > L) {
    				
    		}
    		par[i][j] = mp(par[par[i][j-1]][j-1].first, w);
    		if (w <= L) {

    		}
    	}
    }

}
