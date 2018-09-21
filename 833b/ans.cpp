#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN =  35005;
int cake[MAXN];
bool seen[MAXN];
int dp[MAXN][55];
set<int> pos[MAXN];

int cur[4*MAXN], nxt[4*MAXN];
int lazy1[4*MAXN], lazy2[4*MAXN];

void updNode(int seg[], int lazy[], int node, int val) {
	seg[node] += val;
	lazy[node] += val;
}

void down(int seg[], int lazy[], int node) {
	updNode(seg, lazy, 2*node, lazy[node]);
	updNode(seg, lazy, 2*node+1, lazy[node]);
	lazy[node] = 0;
}

void upd(int seg[], int lazy[], int node, int l, int r, int a, int b, int val) {
	if (a <= l && r <= b) {
		updNode(seg, lazy, node, val);
		return;
	}
	if (lazy[node]) {
		down(seg, lazy, node);
	}
	int mid = (l+r)/2;
	if (a <= mid) {
		upd(seg, lazy, 2*node, l, mid, a, b, val);
	}
	if (b >= mid+1) {
		upd(seg, lazy, 2*node+1, mid+1, r, a, b, val);
	}
	seg[node] = max(seg[2*node], seg[2*node+1]);
}

int query(int seg[], int node, int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		return seg[node];
	}
	int ret = 0;
	int mid = (l+r)/2;
	if (lazy1[node]) down(seg, lazy1, node);
	if (a <= mid) {
		ret=  max(ret, query(seg, 2*node, l, mid, a, b));
	}
	if (b >= mid+1) {
		ret = max(ret, query(seg, 2*node+1, mid+1, r, a, b));
	}
	return ret;
}
int main() {
    #ifdef USE_INPUT_FILE
	freopen("input.txt", "r", stdin);
    #endif
	ios::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	int ans = 0;
	for (int i=1; i<=N; ++i) {
		cin >> cake[i];
		pos[cake[i]].insert(i);
		dp[i][1] = dp[i-1][1] + !seen[cake[i]];
		ans = max(ans, dp[i][1]);	
		seen[cake[i]] = true;
		upd(cur, lazy1, 1, 1, N, i, i, dp[i-1][1]);
	}
	for (int k=2; k<=K; ++k) {
		for (int i=1; i<=N; ++i) {
			int lef = 1;
			auto it = pos[cake[i]].lower_bound(i);
			if (it != pos[cake[i]].begin()) {
				--it;
				lef = (*it) + 1;
			}
			upd(cur, lazy1, 1, 1, N, lef, i, 1);
			dp[i][k] = query(cur, 1, 1, N, 1, i);
			// cout << dp[i][k] << ' ';
			ans = max(ans, dp[i][k]);
			if (dp[i][k] == 7) {
				// printf("%d %d\n", i, k);
			}
			upd(nxt, lazy2, 1, 1, N, i, i, dp[i-1][k]); 
			// if (i == 1) cout << dp[i-1][k] << endl;
		}
		// cout << endl;
		for (int i=1; i<=4*N; ++i) {
			cur[i] = nxt[i];
			lazy1[i] = 0;
			nxt[i] = 0;
		}	
		// if ( k == 2) cout << query(cur, 1, 1, N, 1, 1) << endl;
	}
	cout << ans << endl;
}
