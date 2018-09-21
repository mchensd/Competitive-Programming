#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
string s, p;
ll cnt[26], cnt2[26], req[26], rans[26];
ll q = 0;
bool can(int x) {
	ll tmp=0;
	for (int i=0; i<26; ++i) {
		req[i] = max(1LL*x*cnt2[i]-cnt[i], 0LL);
		// printf("%d %d %d\n", x, i, req[i]);
		tmp += req[i];
	}
	if (tmp <= q) {
		for (int i=0; i<26; ++i) rans[i]=req[i];
	}
	return tmp <= q;
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin >> s >> p;
    for (char c : s) {
    	if (c == '?') ++q;
    	else ++cnt[c-'a'];
    }
    for (char c : p) ++cnt2[c-'a'];

    int lb =0, ub=s.size();
    while (lb < ub) {
    	int xs = (lb+ub+1)/2;
    	if (can(xs)) lb = xs;
    	else ub = xs-1;
    }
    vector<char> ans;
    int cur = 0;
    for (char c : s) {
    	if (c != '?') ans.pb(c);
    	else {
    		while (rans[cur] == 0 && cur < 26) ++ cur;
    		if (cur < 26)
    			ans.pb(cur+'a');
    		else {
    			ans.pb('z');
    			--rans[cur];
    		}
    	}
    }
    // cout << lb << endl;
    for (char c : ans) {
    	cout << c;
    }
    cout << '\n';

}
