#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int N, K;
string combos[21];
vector<string> prefs;
set<string> s;

int dp[1005][305];
pii  trans[305][3];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        cin >> combos[i];
    }
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<N; ++i) {
        string cur = combos[i].substr(0,1);
        // cout << cur << endl;
        if (!s.count(cur)) {
            // cout << cur << endl;
            s.insert(cur);
            prefs.pb(cur);
            // cout <<prefs.back() << endl;
        }
        for (int j=1; j<combos[i].size(); ++j) {
            cur += combos[i][j];
            if (!s.count(cur)) {
                s.insert(cur);
                prefs.pb(cur);
            }
        }
    }
    int cnt = (int)prefs.size();
    for (int i=0; i<cnt; ++i) {
        // cout << prefs[i] << endl;
        if (prefs[i].size() == 1) {
            int cnt = 0;
            for (int j=0; j<N; ++j) {
                // cout << combos[j] << endl;
                if (combos[j] == prefs[i]) ++ cnt;
            }
            dp[0][i] = cnt;
            // printf("%d %d\n", i, dp[0][i]);
            // cout << cnt << endl;
        }
        for (int x=0; x<3; ++x) {
            string suff = prefs[i];
            suff += ('A'+x);
            int add = 0;
            int len = 0;
            int nextind=-1;
            for (int j=0; j<N; ++j) { // check for number of complete matches with combos
                if (combos[j].size() <= suff.size()) {
                    if(suff.substr(suff.size()-combos[j].size(), combos[j].size()) == combos[j])
                        ++add;
                }
            }
            for (int k=1; k<=suff.size(); ++k) { // check for next longest common prefix
                string nex = suff.substr(suff.size()-k, k);
                for (int m=0; m<cnt; ++m) {
                    string s = prefs[m];
                    if (nex == s) {
                        nextind=m;
                        continue;
                    }
                }
            }
            trans[i][x] = mp(nextind, add);
            // cout << prefs[i] << ' ' << prefs[trans[i][x].first] << ' ';
            // printf("%d %d %d\n", x, trans[i][x].first, trans[i][x].second);
        }
    }
    // for (string s : prefs)
    //     cout << s << endl;
    int ans = 0;
    for (int i=0;i<K; ++i ){
        for (int j=0; j<cnt; ++j) {
            if (dp[i][j] > -1) {
                ans = max(ans, dp[i][j]);
                // cout << i << ' ' << prefs[j] << ' ' << dp[i][j] << endl;
                // printf("%d %d %d\n", i, j, dp[i][j]);
                for (int x=0; x<3; ++x) {
                    if (trans[j][x].first != -1)
                        dp[i+1][trans[j][x].first] = max(dp[i+1][trans[j][x].first], dp[i][j]+trans[j][x].second);
                }
            }
        }
    }
    cout << ans << endl;
}
