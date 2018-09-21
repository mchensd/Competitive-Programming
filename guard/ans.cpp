#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

struct cow {
	int h,w,s;
	cow(){}
	cow (int h, int w, int s):h(h),w(w),s(s){}
};
const int MAXN = 21;
cow cows[MAXN];
int dp[1<<MAXN];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
 	int N, H;
 	cin >> N >> H;
 	for (int i=0; i<N; ++i){ 
 		int h,w,s;
 		cin >> h >> w >> s;
 		cows[i] = cow(h,w,s);
 	}   
 	memset(dp, -1, sizeof(dp));
 	dp[0] = INT_MAX;
 	int ans = -1;
 	for (int i=0; i<(1<<N); ++i){ 
 		if (dp[i] == -1)
 			continue;
 		int tmph = 0;
 		for (int j=0; j<N; ++j) {
 			if (!((i>>j) & 1)) {
 				if (cows[j].w < dp[i]) {
 					int nxt = min(cows[j].s, dp[i]-cows[j].w);
 					// printf("%d %d %d\n", cows[j].s, cows[j].w, dp[i]);
 					int nxtdp = i | (1<<j);
 					dp[nxtdp] = max(dp[nxtdp], nxt);
 				}
 			}
 			else {
 				tmph += cows[j].h;
 			}
 		}
 		if (tmph >= H) {
 			ans = max(ans, dp[i]);
 		}
 	}
 	if (ans>-1)
 		cout << ans << endl;
 	else {
 		cout <<"Mark is too tall\n";
 	}
}
