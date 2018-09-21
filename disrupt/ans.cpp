#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

const int MAXN = 50005;
const int MAXLOG = 20;

vector<vector<pii> > adj;
vector<vi> poss;
multiset<int> cur;
vector<vi> done;

int p[MAXN][MAXLOG]
int h[MAXN];
int N;
void dfs(int v) {
	h[v] = h[p[v][0]] + 1;
	for (pii nei : adj[v]) {
		if (nei.first == p[v][0]) continue;
		p[nei.first][0] = v;
		dfs(nei.first);
	}
}
void calcp() {
	for (int i=1; i<=N; ++i) {
		for (int j=1; j<MAXLOG; ++j) {

		}
	}
}

void dfsans(int v, int p, int edge) {
	for (pii nei : adj[v]) {
		if (nei.first == p) continue;

	}
}

int main() {
#if defined(USE_INPUT_FILE) || defined(SUBLIME_RUN)
	freopen("input.txt", "r", stdin);    
#else
    freopen("disrupt", "r", stdin);
    freopen("disrupt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int M;
    cin >> N >> M;
    adj.resize(N+1);
    for (int i=0 ;i<N-1; ++i ){
    	int a, b; 
    	cin  >> a >> b;
    	adj[a].pb(mp(b, i));
    	adj[b].pb(mp(a, i));
    }
    dfs(1);
    calcp();
    poss.resize(N+1);
    dfsans(1,0,-1);
}
