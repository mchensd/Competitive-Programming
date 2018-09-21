#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN=  30005;
vector<vector<int> > adj;
bool rep[MAXN];
bool seen[MAXN];

int main() {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    adj.resize(N+1);
    for (int i=0; i<M; ++i) {
    	int a, b;cin >>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    int ans=N;
    for (int i=0;i<Q;++i){
    	int j; cin >> j;
    	rep[j]=true;
    }
    queue<int> q;
    q.push(1);
    seen[1] = true;
    while (q.size()) {
    	int next = q.front(); q.pop();
    	bool good=true;
    	for (int nei : adj[next]) {
    		if (rep[nei]) good=false;
    	}
    	if (!good) continue;
    	ans-=1;
    	for (int nei:adj[next]){
    		if (!seen[nei]){
    			seen[nei]=true;
    			q.push(nei);
    		}
    	}
    }
    cout << ans << endl;
}
