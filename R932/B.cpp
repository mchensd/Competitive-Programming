#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
const int MAXN = 1000005;
int memo[1000005];

int calc(int x) {
	// cout << x << endl;
	if(memo[x])return memo[x];
	if (x < 10) {
		memo[x] = x;
		return memo[x];
	}
	int nxt = 1;
	for (char c : to_string(x)) {
		if (c != '0') nxt *= c-'0';
	}
	memo[x] = calc(nxt);
	return memo[x];
}
int cnt[MAXN][10];
int pref[MAXN][10];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("B.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=1; i<=MAXN; ++i) {
    	int v= calc(i);
    	++cnt[i][v];
    }
    for (int i=1; i<=MAXN; ++i) {
    	for (int j=1; j<10; ++j) {
    		pref[i][j] = pref[i-1][j] + cnt[i][j];
    	}
    }
    for (int i=0; i<N; ++i) {
    	int a, b, k;cin>>a>>b>>k;
    	cout << pref[b][k] - pref[a-1][k] << '\n'	;
    }
}
