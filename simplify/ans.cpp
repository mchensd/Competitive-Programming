#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppii;

#define mp make_pair
#define pb push_back

const int MAXN = 40005;
const ll MOD = (ll)1e9+7;

int N, M;
vector<vector<pii> > adj;
vector<ppii> edges;

int id[MAXN];
int numused[1000005], cnt[1000005];
vector<pii> edw[1000005];
bool done[1000005];
bool sub[1000005];
int find(int p) {return id[p] == p ? p : id[p]=find(id[p]);}
bool unite(int p, int q) {
	int a = find(p); int b = find(q);
	if (a == b)return false;
	id[a]=b;
	return true;
}
void vis(int w) {
	for (pii e : edw[w]){
		if (find(e.first) == find(e.second)) -- cnt[w]; 
	}
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    auto t = clock();
	// freopen("simplify_dataa/I.10","r", stdin);
    cin >>  N >> M;
    adj.resize(N+1);
    for (int i=0; i<M; ++i) {
    	int a, b, w;
    	cin >> a >> b >> w;
    	id[a]=a; id[b]=b;
    	adj[a].pb(mp(b, w));
    	adj[b].pb(mp(a, w));
    	edges.pb(mp(w,mp(a,b)));
    	edw[w].pb(mp(a, b));
    	++cnt[w];
    }
    sort(edges.begin(), edges.end());
    // freopen("simplify_dataa/O.10","r", stdin);
    // int xz, yz; cin >> xz >> yz; cout << xz << ' ' << yz << endl;
    int num = 0;
    int ind = 0;
    ll sum = 0;
    while (num < N-1) {
    	int v = edges[ind].second.first, u=edges[ind].second.second, w = edges[ind].first;
    	++ind;
    	if (!done[w]) {
    		vis(w);
    		done[w] = true;
    	}
    	if (unite(v, u)) {
    		++num;
    		++numused[w];
    		sum += w;
    		sum %= MOD;
    	}
    	else {
    		if (cnt[w] == 3) sub[w]=true;
    	}
    }
    ll ans = 1;
    for (int i=1; i<=1000000; ++i) {
    	if (cnt[i] == 2) {
    		if (numused[i] == 1) ans *= 2;
    		ans %= MOD;
    		// printf("%d %d\n", i, numused[i]);
    	}
    	else if (cnt[i] == 3) {
    		// printf("%d %d\n", i, numused[i]);
    		if (numused[i] == 1) ans *= 3;
    		if (numused[i] == 2) ans *= (3-sub[i]);
    		ans %= MOD;
    	}
    }
    cout << sum << ' ' << ans << endl;
    cout << ((double)(clock()-t))/CLOCKS_PER_SEC << endl;
}
