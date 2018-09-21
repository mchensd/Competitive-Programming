#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int dp[5005][5005];
int ans[5005];
int out[5005];
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    string s; cin >> s;
    int N =(int)s.size();
    for (int k=0; k<N; ++k) {
    	for (int i=0; i<N; ++i){ 
    		int j = i+k;
    		if (j>=N) break;
    		if (k/2==0) {
    			if (s[i] == s[j]) dp[i][j] = k+1;
    			++ans[dp[i][j]];
    		}
    		else {
    			if (s[i] == s[j]) {
    				if (dp[i+1][j-1]) {
    					dp[i][j]=dp[i][i+(k+1)/2-1]+1;
    					++ans[dp[i][j]];
    				}
    			}
    		}
    	}
    }
    for (int i=N-1; i>=1; --i){ 
    	out[i] = out[i+1] + ans[i];
    	// cout << ans[i] << endl;
    }
    for (int i=1; i<=N; ++i) {
    	cout << out[i] << ' ';
    }
    cout << '\n';
}
