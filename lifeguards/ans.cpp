#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 10;
const int MAXK = 9;
set<pii> segs;
int dp[MAXN][MAXK][2];
int uniqueCover(pii a, pii b) {
    return a.second - max(b.second, a.first);
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        int a, b;
        cin >> a >> b;
        segs.insert(mp(a,b));
    }
    
    if (N == 1) {
        cout << (*segs.begin()).second - (*segs.begin()).first << '\n'; return 0;
    }
    
    int r = (*segs.begin()).first;
    auto it = segs.begin(); ++it;
    for(;it!=segs.end(); ++it) {
        pii seg = *it;
        if (seg.second < r) {
            it = segs.erase(it);
            --K;
        }
        else {
            r = seg.second;
        }
    }
    if (K) {
        auto cur = segs.begin();
        if (segs.size() >= 3) {
            auto nxt = segs.begin();
            ++nxt;
            while (nxt != segs.end()) {
                if ((*nxt).first > (*cur).second) {
                    while ((*nxt).first > (*cur).second)
                        ++cur;
                }
                else {
                    auto er = prev(nxt, 1);
                    if (er != cur) {
                        --K;
                        segs.erase(er);
                    }
                }
                ++nxt;
            }
        }
    }
    vector<pii> vsegs;
    for (auto it : segs) {
        vsegs.pb(it);
        // printf("%d %d\n", it.first, it.second);
    }
    int nk = vsegs.size();
    K = max(K, 0);
    for (int i=0; i<nk; ++i) {
        if (i == 0) {
            dp[i][0][1] = vsegs[i].second - vsegs[i].first;
        }
        else {
            dp[i][0][1] = dp[i-1][0][1] + uniqueCover(vsegs[i], vsegs[i-1]);
        }
        // printf("%d %d\n", vsegs[i].first, vsegs[i].second);
        // cout << dp[i][0][1] << endl;;
    }
    for (int j=1; j<=K; ++j){
        for (int i=j; i<nk; ++i) {
            dp[i][j][1] = uniqueCover(vsegs[i], vsegs[i-1]) + dp[i-1][j][1];
            dp[i][j][1] = max(dp[i][j][1], vsegs[i].second - vsegs[i].first + dp[i-1][j][0]);
            dp[i][j][0] = max(dp[i-1][j-1][1], dp[i-1][j-1][0]);
        }
    }
    cout << max(dp[nk-1][K][1], dp[nk-1][K][0]) << endl;
}

