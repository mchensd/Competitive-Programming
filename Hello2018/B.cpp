#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

vector<vector<int> > adj;
bool leaf[1005];
void dfs(int v, int p) {
	int cnt=0;
	for (int nei:adj[v]) {
		if (nei == p) continue;
		if (leaf[nei])++cnt;
		dfs(nei, v);
	}
	if (!leaf[v] && cnt < 3) {
		// cout << /v << endl;
		puts("No");
		exit(0);
	}
}
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int N;
    cin >> N;
    adj.resize(N+1);
    for(int i=1;i<=N;++i)leaf[i]=true;
    for (int i=2; i<=N; ++i ){
    	int p; cin >> p;
    	adj[i].pb(p);
    	adj[p].pb(i);
    	leaf[p] =false;
    }
    dfs(1, 0);
    puts("Yes");
}
