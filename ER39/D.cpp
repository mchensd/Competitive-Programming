#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
int n, m, k;
vector<vector<int> > times;
const int MAXN = 515;
int best[MAXN][MAXN];
int pref[MAXN], suff[MAXN];
int dp[MAXN][MAXN];
void calc(int ind) {
	int sum = 0;
	memset(pref,0,sizeof(pref)); memset(suff,0,sizeof(suff));
	int sz = (int)times[ind].size();
	vector<int> v =  times[ind];
    if (sz==0) return;

	for (int i=0; i<sz; ++i) sum += v[i];
	pref[0] = v[0];
	for (int i=0; i<m-1; ++i) {
		if (i)pref[i] = pref[i-1] + v[i];
	}
	for (int i=sz-1; i>=0; --i) {
		suff[i] = suff[i+1] + v[i];
	}
	// cout << v.size() << endl;
	for (int i=0; i<sz; ++i) {
		if (i > min(k,(int)v.size())) break;
		int skip = i;
		for (int j=sz-1; j>=i-1; --j) {
			if (skip+sz-j-1 > min(k, (int)v.size())) break;
			skip += sz-j-1;
			best[ind][skip] = min(best[ind][skip],v[j]-v[i]+1);
			// printf("%d %d %d\n",ind,skip,best[ind][skip]);
			skip -= (sz-j-1);
		}

	}
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("D.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    times.resize(n);
    for (int i=0; i<n; ++i){
    	string s; cin >>s;
    	for (int j=0;j<m; ++j) {
    		if (s[j] == '1') times[i].pb(j);
    	}
    	if (times[i].size()) {
            for (int j=0; j<=k ;++j) {
        		best[i][j] = times[i].back() - times[i][0]+1;
        		dp[i][j] = INT_MAX;
        	}
        }
    	// printf("best %d %d %d\n", i, 1, best[i][1]);
    	calc(i);
    }
    int ans = INT_MAX;
    for (int i=0; i<n; ++i) {
    	for (int j=0; j<=k; ++j) {
    		if (!i) dp[i][j] = best[i][j];
    		else {
    			for (int r=0; r<=k; ++r) {
    				if (r+j > k) break;
    				dp[i][r+j] = min(dp[i][r+j], dp[i-1][r] + best[i][j]);
    				// cout << dp[i-1][r] << endl;
    				// cout << r+j << endl;
    				if (i == n-1){
                        cout << r+j << ' '  << dp[i][r+j] << endl;
                     ans = min(ans, dp[i][r+j]);
                    }
    			}    
    		}
    	}
    }
    cout << ans << endl;
}
