#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, C;
    cin >> N >> C;
    vector<ll> nums(N), dp(N, LLONG_MAX), seg;
    for (int i=0; i<N; ++i) {
    	cin >> nums[i];
    }
    int l = 0;
	ll sum = 0;
    multiset<ll>cur;
    for (int i=0; i<min(C-1, N); ++i) {
    	cur.insert(nums[i]);
    	sum += nums[i];
    }
    int r = C-1;
    if (C > N) r = N;
    while (r < N) {
    	sum += nums[r];
    	cur.insert(nums[r]);
    	++r;
    	seg.pb(sum - *cur.begin());
    	sum -= nums[l];
    	cur.erase(cur.find(nums[l]));
    	++l;
    }
	for (;l<N; ++l) {
		seg.pb(sum);
		sum -= nums[l];
	}
	dp[0] = nums[0];
	C = min(C, N);
	dp[C-1] = min(dp[C-1], seg[0]);
	for (int i=1; i<N; ++i) {
		int nxt = min(i+C-1, N-1);
		dp[i] = min(dp[i], dp[i-1] + nums[i]);
		dp[nxt] = min(dp[nxt], dp[i-1] + seg[i]);

	}
	cout << dp[N-1] << endl;	

}
