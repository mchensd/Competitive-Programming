#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXM = 1005;
vector<string> prefs;
int trans[MAXM][26];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("necklace.in", "r", stdin);
    freopen("necklace.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    int N = s.size(), M = t.size();

    for (int i=0; i<N; ++i)
    	s[i] -= 'a';
    for (int i=0; i<M; ++i)
    	t[i] -= 'a';

    string cur = "";
    prefs.pb(cur);
    for (int i=0; i<M-1; ++i) {
    	cur += t[i];
    	prefs.pb(cur);
    }
    trans[0][t[0]] = 1;
    for (int i=1; i<M; ++i) {
    	// trans[i-1][t[i-1]] = i;
    	for (int j=0; j<26; ++j) {
    		trans[i][j] = trans[trans[i-1][t[i-1]]][j];
    		printf("%d %d %d\n", i, j, trans[i][j]);
    	}
    	cout << '\n';
    }

}
