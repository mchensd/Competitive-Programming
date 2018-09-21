#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    //testcase
    // freopen("output.txt", "w", stdout);
    // cout << 100000 << ' ' << 1000000000 << '\n';
    // int cur = 1;
    // for (int i=0; i<100000; ++i) {
    //     cout << cur << ' ' << cur+5 << '\n';
    //     cur += 10;
    // }
    
    int N, E; cin >> N >> E;
    vector<pii> segs(N);
    for (int i=0;i<N;++i) cin >> segs[i].first >> segs[i].second;
    int cur = 0;
    int ans = 0;
    for (int i=0; i<N; ++i) {
        ans = max(ans, segs[i].first - cur);
        cur = segs[i].second+1;
    }
    ans = max(ans, E+1-cur);
    cout << cur << endl;
    cout << ans << endl;

}
