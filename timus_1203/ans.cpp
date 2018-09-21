#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 100005;
int dp[30005];
pii segs[MAXN];
int main() {
    // freopen("out.txt", "w", stdout);
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=0; i<N; ++i) {
    	cin >> segs[i].first >> segs[i].second;
    }
    sort(segs, segs+N);
    int ans = 0;
    for (int i=0; i<N; ++i) {
    	dp[segs[i].second+1] = max(dp[segs[i].second+1], dp[segs[i].first]+1);
    	ans = max(ans, dp[segs[i].second+1]);
    }
    cout << ans << endl;

}
