/*
 ID: mchensd
 LANG: C++11
 TASK: stamps
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int vals[55];
int dp[2000005];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
	int K, N;
	cin >> K >> N;
	int x;
	int i  =0;
	while (cin >> x){
		vals[i++] = x;
	}    
	memset(dp, -1, sizeof(dp));
	dp[0]=0;
	for (int i=0; ;++i){
		if (dp[i] == -1){
			cout << i-1 << endl;
			return 0;
		}
		if(dp[i] == K) continue;
		for (int j=0;j<N; ++j){ 
			if (dp[i+vals[j]] == -1) dp[i+vals[j]] = dp[i]+1;
			dp[i+vals[j]]=min(dp[i+vals[j]], dp[i]+1);
		}
	}
}
