#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 100005;
int cuts[MAXN];

int cnt[MAXN];
int N;
bool gets(int cow) {
	if (cow == 1) return true;
	memset(cnt, 0, sizeof(cnt));
	for (int i=1; i<cow; ++i) {
		// printf("%d %d\n", i, cuts[i]);
		++cnt[cuts[i]];
	}
	int req = 1; int cur = 0;
	for (int i=N-1; i>=1; --i) {
		if (req == cow) break;
		cur += cnt[i];
		// printf("%d %d %d %d\n", cow, i, cnt[i], req);
		if (cur >= req) {
			return false;
		}
		++req;
	}
	return true;
}
int main() {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    #else
    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; ++i) {
    	cin >> cuts[i+1];
    }
    int lb = 1, ub = N;
    while (lb < ub) {
    	int xs = (lb+ub+1)/2;
    	if (gets(xs)) {
    		// printf("gets %d\n", xs);
    		lb = xs;
    	}
    	else {
    		ub = xs-1;
    	}
    }
    cout << N-lb << '\n';
}
