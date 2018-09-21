#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

const int MAXN = 100005;
map<string, int> wNums;
int cost[MAXN];
int best[MAXN];
int main() {
    #ifdef SUBLIME_RUN
    freopen("B.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, K, M;
    cin >> N >> K >> M;
    for (int i=1; i<=N; ++i) {
    	string s; cin >> s;
    	wNums[s] = i;
    }
    for (int i=1; i<=N; ++i) {
    	cin >> best[i];

    }
    vector<vi> costs(K);
    for (int i=0; i<K; ++i ){
    	int x; cin >> x;
    	costs[i].resize(x);
    	int mn = INT_MAX;
    	for (int j=0; j<x; ++j) {
    		cin >> costs[i][j];
    		mn = min(mn, best[costs[i][j]]);
    	}
    	for (int j=0; j<x; ++j ){
    		best[costs[i][j]] = mn;
    	}
    }
    ll ans = 0;
    for (int i=0; i<M; ++i) {
    	string s; cin >> s;
    	int x = wNums[s];
    	ans += best[x];
    }
    cout << ans << '\n';

}
