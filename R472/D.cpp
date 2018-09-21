#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
#ifdef SUBLIME_RUN
    freopen("D.txt", "r", stdin);
#elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
#endif
    int N; cin >> N;
    vector<pii> segs;
    for (int i=0; i<N; ++i) {
        int a,b;
        cin >> a>>b;
        segs.push_back(make_pair(a,b));
    }
    sort(segs.begin(), segs.end());
    int l = segs[0].first;
    int r = segs[0].second;
    int ans = 0;
    for (int i=1; i<N; ++i) {
        if (segs[i].first <= r+1) {
            r = max(r, segs[i].second);
        }
        else {
            ans = max(ans, r-l+1);
            l = segs[i].first;
            r = segs[i].second;
        }
    }
    ans = max(ans, r-l+1);
    cout << ans << endl;
    return 0;
}
