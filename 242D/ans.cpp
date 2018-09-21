#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN=  100005;
vector<vector<int> > adj;
int but[MAXN];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
	int N, M;
	cin >> N >> M; 
	adj.resize(N+1);
	for (int i=0; i<M; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	queue<int> q;
	vector<int> ans;
	for (int i=1; i<=N; ++i) {
		cin >> but[i];
		if (but[i] == 0) {
			q.push(i);
		}
	}
	while (q.size() ) {
		int next = q.front(); q.pop();
		if (but[next] != 0) continue;
		ans.pb(next);
		for (int nei : adj[next]) {
			// printf("%d %d\n", next, nei);
			--but[nei];
			if (but[nei] == 0)  {
				q.push(nei);
			}
		}
	}

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}
