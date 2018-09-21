#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 1005;
map<int, int> pos;
int nums[MAXN];
int best[MAXN][MAXN];

int ans =2;
void dfs(int f, int s) {
	int sum = nums[f] + nums[s];
	auto p = pos.find(sum);
	if (p == pos.end()) {
		best[f][s] = 2;
		best[s][f] = 2;
		return;
	}
	else {
		int ind = (*p).second;
		// printf("%d %d %d %d\n", f, s, ind, sum);
		if (!best[s][ind]) {
			dfs(s, ind);
		}
		best[f][s] = 1+best[s][ind];
		// if (best[f][s] == 3) printf("%d %d\n", f, s);
		ans = max(ans, best[f][s]);
	}
}

int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=0; i<N; ++i) {
    	int x; cin >> x;
    	pos[x] = i;
    	nums[i] = x;
    }
    for (int i=0; i<N; ++i) {
    	for (int j=0; j<N; ++j) {
    		if (i==j || best[i][j])continue;
    		dfs(i, j);
    	}
    }
    // for (int i=0; i<N; ++i) {
    // 	for (int j=0; j<N; ++j) {
    // 		cout << best[i][j] << ' ';
    // 	}
    // 	cout << endl;
    // }u
    cout << ans << endl;
}
