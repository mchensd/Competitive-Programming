#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXDP = 1001;
int dp[MAXDP];
int splits[MAXDP];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    #endif
    // ios::sync_with_stdio(0);
    dp[1] = 1;
    for (int i=2;i<=MAXDP; ++i) {
    	dp[i] = i;
    	for (int j=1; j<i; ++j) {
    		dp[i] = min(dp[i], 1+ max(dp[j], dp[i-j]));
    	}
    	if (i < 50) cout << i << ' ' << dp[i] << endl;
    }
    int t; scanf("%d", &t);
    for (int test=1; test<=t; ++test) {
    	int N; 
    	scanf("%d",&N);
    	int ans = 0;
    	for (int i=0;i<N;++i){ 
    		int p;
    		scanf("%d", &p);
    		ans =max(ans, dp[p]);
    	}
    	printf("Case #%d: %d\n", test,ans);
    }
}
