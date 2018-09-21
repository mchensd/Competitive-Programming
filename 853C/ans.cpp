#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 50;
bool board[MAXN][MAXN];
int pref[MAXN][MAXN];
int N, Q;
void init() {
	for (int i=1; i<=N; ++i) {
		for (int j=1; j<=N; ++j) {
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + board[i][j];
		}
	}
}
int query(int x1, int y1, int x2, int y2 ){
	return pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1];
}
int main() {
	ios::sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    cin >> N >> Q;
    for (int i=1; i<=N; ++i) {
    	int j; cin >> j;
    	board[i][j] = true;
    }
    init();
    while (Q--) {
    	int l,d,r,u; cin >> l >> d >> r >> u;
    	int num =query(l, u, r, d);
    	cout << 1LL*num*(num-1)/2 + 1LL*num*(N-num) <<'\n';
    }
}
