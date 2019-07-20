#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
int ans = INT_MAX;
int dp[4][30005];
int cow[30005];
int N;
void set_max() {
	for (int i=1;i<=3;++i) {
		for (int j=0;j <=N+3; ++j) {
			dp[i][j] = INT_MAX;
		}
	}
}
void run_dp() {
	dp[1][0] = 0;
	dp[2][0] = 0;
	dp[3][0] = 0;
	for (int i=0; i<N; ++i) {
			dp[1][i+1] = dp[1][i] + 1-(cow[i] == 1);
			dp[2][i+1] = min(dp[1][i], dp[2][i]) + 1 - (cow[i] == 2);
			dp[3][i+1] = min(min(dp[1][i], dp[2][i]), dp[3][i]) + 1 - (cow[i] == 3);
	}
	ans = min(ans, min(min(dp[1][N], dp[2][N]), dp[3][N]));
}
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; ++i) {
    	cin >> cow[i];
    }
    set_max();
    run_dp();
    for (int j=1; j<=3; ++j) {
    	for (int i=0; i<=N; ++i) {
    		cout << dp[j][i] << ' ';
    	}
    	cout << endl;
    }
    reverse(cow, cow+N);
    set_max();
    run_dp();
    cout << ans << endl;
}
