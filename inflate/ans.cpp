/*
 ID: mchensd
 LANG: C++11
 TASK: inflate
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int N, T;
pii classes[10005];
int dp[2][10005];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> T >> N;
    for (int i=0; i<N; ++i){
        cin >> classes[i].second >> classes[i].first;
    }
    int ans = 0;
    for (int j=0; j<=T; ++j) {
        if (j-classes[0].first < 0) continue;
        dp[0][j] = classes[0].second;
        dp[0][j] += dp[0][j-classes[0].first];
        ans = max(ans, dp[0][j]);
    }
    // cout << dp[0][300] << endl;
    for (int x=1; x<N; ++x) {
        int i = (x&1);
        for (int j=0;j<=T; ++j) {
            dp[i][j] = max(dp[i][j-1], dp[!i][j]);
            if (j-classes[x].first < 0) continue;
            dp[i][j] = max(dp[i][j], classes[x].second + dp[i][j-classes[x].first]);
//            cout << dp[i][j] << '\n';
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}

