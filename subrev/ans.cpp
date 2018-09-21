#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 51;
int nums[MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int best(int i, int j) {
    int ret = 0;
    for (int a=1; a<=50; ++a) {
        for (int b=a; b<=50; ++b) {
            ret = max(ret, dp[i][j][a][b]);
        }
    }
    for (int a=1; a<=50; ++a) {
        for (int b=a; b<=50; ++b) {
            if (dp[i][j][a][b] == ret) printf("%d %d\n", a, b);
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#else
    freopen("subrev.in", "r", stdin);
    freopen("subrev.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> nums[i];
        dp[i][i][nums[i]][nums[i]] = 1;
    }

    for (int i=0;i<N-1; ++i) {
        int j = i+1;
        dp[i][j][min(nums[i], nums[j])][max(nums[i], nums[j])] = 2;
    }

    for (int k=2; k<N; ++k) {
        for (int i=0; i<N; ++i) {
            int j = i+k;
            if (j >= N) break;
            int x = nums[i], y=nums[j];
            if (x > y) swap(x, y);
            for (int a=1; a<=50; ++a) {
                for (int b=a; b<=50; ++b) {
                    dp[i][j][a][b] = max(dp[i][j][a][b], max(dp[i+1][j][a][b], dp[i][j-1][a][b]));
                    if (a >= nums[i]) dp[i][j][nums[i]][b] = max(dp[i][j][nums[i]][b], dp[i+1][j][a][b]+1);
                    if (b <= nums[j]) dp[i][j][a][nums[j]] = max(dp[i][j][a][nums[j]], dp[i][j-1][a][b]+1);
                    if (x >= b) dp[i][j][a][x] = max(dp[i][j][a][x], dp[i+1][j-1][a][b]+1);
                    if (y >= b) dp[i][j][a][y] = max(dp[i][j][a][y], dp[i+1][j-1][a][b] +1);
                    if (x <= a) dp[i][j][x][b] = max(dp[i][j][x][b], dp[i+1][j-1][a][b] + 1);
                    if (y <= a) dp[i][j][y][b] = max(dp[i][j][y][b], dp[i+1][j-1][a][b]+1);

                    if (a >= x && b <= y) {
                        dp[i][j][x][y] = max(dp[i][j][x][y], dp[i+1][j-1][a][b]+2);
                    }
                }
            }
        }
    }
    int ans = 0;
    // cout << best(0, 6) << endl;
    // cout << dp[0][2][1][3] << endl;  
    // cout << dp[3][4][4][5] << endl;
    // cout << dp[0][3][1][5] << endl;
    // cout << dp[2][3][4][5] << endl;
    // cout << '\n';

    for (int a=1; a<=50; ++a) {
        for (int b=a; b<=50; ++b) {
            ans = max(ans, dp[0][N-1][a][b]);
            // if (dp[0][N-1][a][b] == 7) printf("%d %d\n", a, b);
        }
    }
    cout << ans << endl;        
}

