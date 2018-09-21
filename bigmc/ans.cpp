#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
#define mp make_pair
#define pb push_back

vector<vector<pid> > adj;
const int MAXN = 2005;
double dist[MAXN];
int main() {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    #endif
    auto a = clock();
    ios::sync_with_stdio(0);
    int N, M, A, B;
    double V;
    cin >> N >> M >> V >>  A >> B;
    adj.resize(N+1);
    for (int i=0; i<M; ++i) {
    	int a, b;
    	double p;
    	cin >> a >> b >> p;
    	adj[a].pb(mp(b, p));
    }
    // memset(dist, -1, sizeof(dist));
    for (int i=1; i<=N; ++i) {
    	dist[i] = LLONG_MAX;
    }
    dist[B] = 1;
    cout << fixed;
    // cout << dist[A] << endl;
    // cout << dist[1] << endl;
    for (int i=0; i<N-1; ++i) {
    	for (int j=1; j<=N; ++j) {
    		for (pid nei : adj[j]) {
    			if (dist[nei.first] == 0) continue;
    			dist[j] = min(dist[j], nei.second * dist[nei.first]);
    			// printf("%d %f\n", j, dist[j]);
    		}
    	}
    }
    for (int i=1; i<=N; ++i) {
    	for (pid nei : adj[i] ) {
    		if (dist[nei.first] == 0) continue;
    		if (dist[i] > dist[nei.first]*nei.second) return 0*puts("0");
    	}
    }
    // cout << dist[A] << endl;
    // cout << V << endl;
    cout << setprecision(6) << (ll)(dist[A]*V) << endl;
    auto b = clock();
    // cout << ((double)(b-a))/CLOCKS_PER_SEC << endl;
}
