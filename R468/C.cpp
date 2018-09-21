#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
int cnt[3];
int main() {
#ifdef USE_INPUT_FILE
    freopen("C.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    set<int>nums;
    for (int i=0;i<n;++i) {
        cin >> v[i];
        nums.insert(v[i]);
    }
    if (*nums.rbegin()-*nums.begin() <= 1){
        cout << n << '\n';
        for (int i=0; i<n; ++i) {
            if (i) cout << ' ';
            cout << v[i];
        }
        cout << '\n';
        return 0;
    }
    vector<int> ans;
    auto it = nums.begin(); ++it;
    int sub = *it;
    int sum = 0;
    for (int i=0; i<n ;++i){
        v[i] -= sub;
        ++ cnt[v[i]+1];
        sum += v[i];
    }
    int cur = 0;
    int eq = 0;
    while (cur != sum) {
        if (cur < sum) {
            if (cnt[2]) {
                ++eq;
                --cnt[2];
            }
            ans.pb(1);++cur;
        }
        else {
            if (cnt[0]) {
                ++eq;
                --cnt[0];
            }
            ans.pb(-1);
            --cur;
        }
    }
    if ((v.size()-ans.size())&1) {
        ans.pb(0);
        if (cnt[1]) {
            ++eq;
            --cnt[1];
        }
    }
    int ins0 = min(cnt[1], (int)(v.size()-ans.size()));
    int tmpsz = (v.size()-ans.size());
    int ins1=0;
//    cout << tmpsz <<endl;
    while(tmpsz) {
        if (cnt[0]) {
            --cnt[0];++ins1;
        }
        if (cnt[2]) {
            --cnt[2];++ins1;
        }
        tmpsz-=2;
    }
    if (ins0 <= ins1) {
        eq += ins0;
        while (ans.size() < v.size()) ans.pb(0);
    }
    else {
        eq += ins1;
        while (ans.size() < v.size()) {ans.pb(-1);ans.pb(1);}
    }
    cout << eq << '\n';
    for (int i=0; i<ans.size(); ++i) {
        if (i)cout << ' ';
        cout << ans[i]+sub;
    }
    cout << '\n';
    
}
