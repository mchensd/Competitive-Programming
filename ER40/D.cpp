#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

const int MAXN = 1005;
bool path[MAXN][MAXN];
vector<vector<int> > adj;
int best[MAXN][MAXN];
bool vis[MAXN];
bool has[MAXN][MAXN];
void bfs(int v) {
	queue<pii> q;
    q.push(mp(v,0));
    memset(vis,0,sizeof(vis));
    vis[v]=1;
    while(q.size()) {
    	pii next = q.front();
    	q.pop();
    	for (int nei : adj[next.first]) {
    		if (!vis[nei] ){
    			vis[nei] = 1;
    			best[v][nei] = best[v][next.first] + 1;
    			q.push(mp(nei,best[v][nei]));
    		}
    	}
    }
}
int main() {
    #ifdef SUBLIME_RUN
    freopen("D.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, M, S, T;
    cin >> N>>M>>S>>T;
    adj.resize(N+1);
    for (int i=0; i<M; ++i) {
    	int a,b;cin >> a >> b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    	path[a][b] = true;
    	path[b][a] = true;
    }

    for (int i=1; i<=N; ++i) {
    	bfs(i);
    }
	int ans = 0;    
	// cout << best[5][6] << endl;
	// cout << best[S][T] << endl;
    for (int i=1; i<=N; ++i){ 
    	// if (i== S||i==T) continue;
    	for (int j=i+1; j<=N; ++j) {
    		if (i == j) continue;
    		if (path[i][j]) continue;
    		if (min(best[S][i] + 1 + best[j][T], best[S][j]+1+best[i][T]) >= best[S][T] && !has[i][j]) {
    			// printf("%d %d\n", i,j);
    			has[i][j] = 1; has[j][i] = 1;
    			++ans;
    		}
    	}
    	// for (int j=i+1; j<= N; ++j) {
    	// 	if (!path[i][j]) {
    	// 		// printf("%d %d\n", i, j);
    	// 		if (best[S][i] + best[j][T] + 1 >= best[S][T]) {
    	// 			printf("%d %d\n", i, j);
    	// 			++ ans;
    	// 		}
    	// 	}
    	// }
    }
    cout << ans << endl; 
}
