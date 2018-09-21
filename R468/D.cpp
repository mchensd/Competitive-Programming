#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

vector<vector<int> > adj;
const int MAXN = 100005;
int cntdep[MAXN];
int dep[MAXN];

void dfs(int v, int p){ 
	dep[v] = dep[p]+1;
	cntdep[dep[v]]++;
	for (int nei : adj[v]){
		if (nei == p) continue;
		dfs(nei,v);
	}
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("D.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    adj.resize(N+1);
    for (int i=2; i<N+1; ++i) {
    	int p; cin >> p;
    	adj[i].pb(p);							
    	adj[p].pb(i);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i=1;i<MAXN; ++i) {
    	if (cntdep[i]&1) {
    		++ans;
    	}
    }
    cout << ans << endl;
	}
