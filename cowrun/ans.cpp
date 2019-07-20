#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int dp[10005][505];
int dist[10005];
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M; 
    for (int i=0; i<N; ++i) {
    	cin >> dist[i];
    }

    for (int i=N-1; i>=0; --i) {
    	for (int j=0; j<=M; ++j) {
    		if (i+j >= N+1) {
    			dp[i][j] = INT_MIN;
    			continue;
    		}
            if (i == N-1) continue;
            dp[i][j] = dp[i+j][0];
            if (j == 0) dp[i][j] = max(dp[i][j], dp[i+1][j]);
            if (j < M)
    		  dp[i][j] = max(dp[i][j], dist[i] + dp[i+1][j+1]);
            // printf("%d %d %d\n", i, j, dp[i][j]);
    	}
    }
    // cout << dp[7][1] << endl;
    cout << dp[0][0] << endl;

}
