#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 10005;
vector<vector<int> > adj;
int dep[MAXN], times[MAXN];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    adj.resize(N+1);
    for (int i=1;i<=N;++i)cin>>times[i];
    for (int i=0; i<M; ++i) {
    	int a,b;cin >> a >> b;
    	adj[a].pb(b);
    	++dep[b];
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i=1; i<=N; ++i) {
    	if (dep[i] == 0)
    		pq.push(mp(times[i], i));
    }
    int ans = 0;
    while (pq.size()) {
    	pii next = pq.top();
    	pq.pop();
    	ans = max(ans, next.first);
    	for (int nei : adj[next.second]) {
    		--dep[nei];
    		if (dep[nei] == 0)
    			pq.push(mp(next.first+times[nei], nei));
    	}
    }
    cout << ans << endl;

}
