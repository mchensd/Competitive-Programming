#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int N, M;

const int MAXN = 10;
int cap[MAXN];
pii segs[MAXN];
vector<pii> beg[MAXN], end[MAXN];

struct rightcomp {
    bool operator() (pii a, pii b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
        
    }
};
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i=1; i<=N; ++i) {
        cin >> cap[i];
    }
    for (int i=0; i<M; ++i) {
        cin >> segs[i].first >> segs[i].second;
        beg[segs[i].first].pb(segs[i]);
    }
    sort(segs, segs+M);
    int ans = M;
    multiset<pii, rightcomp> active;
    for (int i=1; i<=N; ++i) {
        for (pii a : beg[i])
            active.insert(a);
        while (active.size() && (*active.begin()).second < i) {
            active.erase(active.begin());
        }
        
        while (active.size() > cap[i]) {
            --ans;
            auto it = active.end();
            --it;
            active.erase(it);
        }
    }
    cout << ans << endl;
}

