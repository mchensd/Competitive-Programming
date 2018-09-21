#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 100005;
int pers[MAXN];
int cost[MAXN];
int N, M, a;
int s = 0;
bool can(int x) {
	vector<int> tp;
	for (int i=max(N-x, 0); i<N; ++i) {
		tp.pb(pers[i]);
	}
	int ta = a;
	int used = 0;
	for (int i=0; i<x; ++i) {
		if (cost[i] > tp[i] ){
			ta -= (cost[i] - tp[i]);
			if (ta < 0) return false;
		}
		// printf("%d %d %d\n", x, pers[i], cost[i]);
		used += min(tp[i], cost[i]);
	}
	// printf("%d %d %d\n", x, used, ta);
	used = max(used-ta, 0);
	s = used;
	return true;
}	
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    cin >> N >> M >> a;
    for (int i=0; i<N; ++i)  {
    	cin >> pers[i];
    }
    sort(pers, pers+N);
    for(int i=0;i <M; ++i) {
    	cin >> cost[i];
    }
    sort(cost, cost+M);
    int lb = 0, ub = min(N, M);
    while (true) {
    	if (lb == ub) break;
    	int xs = (lb+ub+1)/2;
    	if (can(xs)) {
    		lb = xs;
    	}
    	else ub = xs-1;
    }
    printf("%d %d\n", lb, s);
}

