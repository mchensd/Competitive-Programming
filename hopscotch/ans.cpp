// BIT with dynamic size (compressed integers)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 755;
vector<int> bits[MAXN*MAXN];
vector<int> conv[MAXN*MAXN]; // column of the index of a number's bit
map<int, int> cmp[MAXN*MAXN];
int cur[MAXN*MAXN];
vector<int> cols[MAXN*MAXN];
const int MOD = (int)1e9+7;
int nums[MAXN][MAXN];
void upd(int num, int col, int val) {
	int lb = 1, ub = conv[num].size()-1;
	// binary search for first index whose column is greater than or equal col
	while (lb < ub) {
		int xs = (lb+ub+1)/2;
		if (conv[num][xs] >= col) lb = xs;
		else ub = xs-1;
	}
	while (lb < bits[num].size()) {
		bits[num][lb] += val;
		lb += lb & (-lb);
	}
}

int get(int num, int col) {
	int lb = 1, ub = conv[num].size()-1;
	//binary search for first index whose column is less than or equal to col
	while (lb < ub) {
		int xs = (lb+ub)/2;
		if (conv[num][xs] <= col) ub = xs;
		else lb = xs+1;
	}
	int ret = 0;
	while (lb >= 1) {
		ret += bits[num][lb];
		ret %= MOD;
		lb -= lb & (-lb);
	}
	return ret;
}
int dp[MAXN][MAXN];
int pref[MAXN][MAXN];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i=0 ;i<N; ++i) {
    	for (int j=0; j<M; ++j) {
    		cin >> nums[i][j];
    		cols[nums[i][j]].pb(j);
    	}
    }
    for (int i=1; i<=K; ++i){
    	sort(cols[i].begin(), cols[i].end());
    	int cur = 0;
    	conv[i].pb(0); // 1 index
    	for (int j=0;j<cols[i].size();++j) {
    		if (j > 0 && cols[j] == cols[j-1])continue;
    		conv[i].pb(cols[j]);
    		++cur;
    	}
    	bits[i].resize(cur+1);
    }
    pref[0][0] = 1;
    upd(nums[0][0], 1, 1);
    for (int i=1; i<N; ++i) {
    	for (int j=1; j<M; ++j) {
    		pref[i][j] = ((pref[i-1][j] + pref[i][j-1])%MOD) - pref[i-1][j-1];
    		while (pref[i][j] < 0) pref[i][j] += MOD;
    		pref[i][j] -= get(nums[i][j], j);
    		while (pref[i][j] < 0) pref[i][j] += MOD;
    		upd(nums[i][j], j, pref[i][j]):
    	}
    }
    cout << pref[N-1][M-1] << endl;
}
