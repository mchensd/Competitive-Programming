#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
#ifdef USE_INPUT_FILE
    freopen("C.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    int pref=0;
    set<int> p0, p1;
    for(int i=0;i<N;++i){
        if (s[i] == '0') {
            p0.insert(i);
            ++pref;
        }
        else {
            --pref;
            p1.insert(i);
        }
        if (pref < 0) return cout<<-1<<endl, 0;
    }
    if (s[N-1] == '1') return cout <<-1<<endl,0;
    vector<vector<int> > ans;
    while (p0.size() || p1.size()) {
        vector<int> v;
        int pos = *p0.begin();
        v.pb(pos);
        p0.erase(p0.begin());
        bool which = 1;
        set<int>* cur = &p1;
        auto it = cur->upper_bound(pos);
        while (it != cur->end()) {
            pos = *it;
            v.pb(*it);
            cur->erase(it);
            if (which) {
                cur = &p0;
            }
            else {
                cur = &p1;
            }
            which = !which;
            it = cur->upper_bound(pos);
        }
        if (!which)return cout << -1 << '\n', 0;
        ans.pb(v);
    }
     cout << ans.size() << '\n';
     for (int i=0; i<ans.size(); ++i) {
         cout << ans[i].size() << ' ';
         for (int j=0; j<ans[i].size(); ++j) {
             if (j) cout << ' ';
             cout << ans[i][j]+1;
         }
         cout << '\n';
     }
    
}

