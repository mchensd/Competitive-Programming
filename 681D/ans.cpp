#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
int N, M;
const int MAXN = 100005;
vector<vector<int> > adj;
vector<int> ans;
int p[MAXN];
int gift[MAXN];
bool added[MAXN];
void dfs(int v, int p, int cur) {
	if (gift[v] != cur && gift[v] != v) {
		// printf("%d %d\n", v, cur);
		cout <<-1<<endl;
		exit(0);
	}
	cur = gift[v];
	if (!added[cur]) {
		added[cur] = true;
		ans.pb(cur);
	}
	for (int nei : adj[v]) {
		if (nei != p) {
			dfs(nei, v, cur);
		}
	}
}
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    adj.resize(N+1);
    for (int i=0; i<M; ++i){
    	int a, b; cin >> a >> b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    	p[b] = a;
    }
    for (int i=1;i<=N; ++i) {
    	cin >> gift[i];
    }
    for (int i=1; i<=N; ++i) {
    	if (!p[i]) {
    		dfs(i, 0, i);
    	}
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int x : ans){
    	cout << x << endl;
    }
}

