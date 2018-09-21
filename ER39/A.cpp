#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("A.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int n; cin >> n;
   	vector<int>nums(n+1);
   	int r = 0, l = 0;
   	for (int i=0;i<n;++i) {
   		cin >> nums[i];
   		r += nums[i];
   	}
   	int ans = -r;
   	r-=nums[0];
   	l = nums[0];
   	for (int i=1; i<=n; ++i) {
   		ans = max(ans, l-r);
   		l += nums[i];
   		r -= nums[i];
   	}
   	cout << ans << endl;
}
