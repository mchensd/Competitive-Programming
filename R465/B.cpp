#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("B.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N;
    string s ;
    cin >> N >> s;
    pii cur = mp(0,0);
    int ans = 0;
    map<char, pii> dirs;
    dirs['U'] = mp(0,1);
    dirs['R'] = mp(1, 0);
    cur.first += dirs[s[0]].first;
    cur.second += dirs[s[0]].second;
    int k = cur.first > cur.second;
    for (int i=1; i<N; ++i) {
    	cur.first += dirs[s[i]].first;
    	cur.second += dirs[s[i]].second;
    	bool tmp = cur.first > cur.second;
    	if (cur.first == cur.second) continue;
    	if (tmp != k) {
    		k = tmp;
    		++ans;
    	}
    }
    cout << ans << endl;
}
