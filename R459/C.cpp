#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
bool dp[5005][5005];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("C.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    string s; cin >> s;
    int n = (int)s.size();
    for (int i=0; i<n; ++i) {
    	if (s[i] == '?') {
    		for (int k=1; k<n; ++k) {
    			int j = i+k;
    			if (j >= n) break;
    			if (s[j] != '?') break;
    			if (k&1) dp[i][j]=1;
    		}
    	}
    	else {
    		if (s[i] == ')') continue;
    		int pref = 1;
    		for (int j=i+1; j<n; ++j) {
    			if (s[j] =='?') break;
    			if (s[j] == '(') ++ pref;
    			else -- pref;
    			if (pref == 0) dp[i][j] = 1;
    			else if (pref < 0) break;
    		}
    	}
    }
    int ans = 0;
    for(int k=1; k<n; k+=2) {
    	int opt = 0;	
    	for (int i=0; i<n; ++i) {
    		int j = i+k;
    		if (j >= n) break;
    		if (dp[i][j]) ++ans;
    		else {
    			if (s[i] == ')' || s[j] == '(') continue;
    			if (dp[i+1][j-1] || k == 1) {
    				dp[i][j]= 1;
    				++ans;
    			}
    			else {
    				while (opt < j-1 && !(dp[i][opt] && dp[opt+1][j])) {
    					++opt;
    				}
    				if (opt < j-1) {
    					printf("%d %d %d\n", i,j,opt);
    					dp[i][j] = 1;
    					ans ++;
    				}
    			}
    		}
    	}
    }
    for (int i=0; i<n; ++i){ 
    	for(int j=i; j<n; ++j) {
    		if (dp[i][j]) printf("%d %d\n", i, j);
    	}
    }
    cout << ans << '\n';
}
