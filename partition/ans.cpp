#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
#define MAXN 17

int cows[MAXN][MAXN];
int pref[MAXN][MAXN];
int pref2[MAXN];
bool hasDiv[MAXN];
int dp[MAXN][MAXN];
int memo[MAXN][MAXN]; // max between two hasDivisions
int N, K;
int ans = INT_MAX;

void go(int sects) {
    int cursect = 0;
    for (int i=0; i<=N; ++i) {
        for (int j=0; j<=N; ++j) {
            dp[i][j] = INT_MAX;
        }
    }
    memset(memo, 0, sizeof(memo));
    memset(pref, 0, sizeof(pref));
    for (int i=1; i<=N; ++i) {
        if (hasDiv[i-1]) ++cursect;
        for (int j=1; j<=N; ++j) {
            if (j == 1) pref2[j] = cows[i][j];
            else pref2[j] = pref2[j-1] + cows[i][j];
            pref[cursect][j] += pref2[j];
        }
    }
    if (sects == K+1) { // 0 divisions
        int ret = 0;
        for (int i=0; i<sects; ++i) {
            ret = max(ret, pref[i][N]);
        }
        ans = min (ans, ret);
        return;
    }
    for (int i=1; i<N; ++i){
        int mx = 0;
        for (int j=0;j<sects; ++j) {
            mx = max(mx, pref[j][i]);
        }
        dp[1][i] = mx;
    }
    for (int i=0; i<=N; ++i ){
        for (int j=i+1; j<=N; ++j) {
            int mx = 0;
            for (int k=0; k<sects; ++k) {
                mx = max(mx, pref[k][j] - pref[k][i]);
            }
            memo[i][j] = mx;
            memo[j][i] = mx;
        }
    }
    for (int k=2; k<=K+1-sects; ++k) {
        for (int i=k; i<N; ++i) {
            for (int j=k-1; j<i; ++j) {
                dp[k][i] = min(dp[k][i], max(dp[k-1][j], memo[j][i]));
            }
        }
    }
    
    int tmp = INT_MAX;
    for (int i=K+1-sects; i<N; ++i) {
        tmp = min(tmp, max(dp[K+1-sects][i], memo[i][N]));
    }
    ans = min(ans, tmp);
}
void gencomb(int k, int cur, int last) {
    if (cur == k) {
        go(k+1);
        return;
    }
    for (int i=last+1; i<N; ++i) {
        if (!hasDiv[i]) {
            hasDiv[i] = true;
            gencomb(k, cur+1, i);
            hasDiv[i] = false;
        }
    }
}

int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for (int i=1; i<=N; ++i){
        for (int j=1;j<=N; ++j ){
            cin >> cows[i][j];
        }
    }
    
    for (int i=0; i<=K; ++i) {
        if (K-i > N-1) continue;
        gencomb(i, 0, 0);
    }
    cout << ans << endl;
}

