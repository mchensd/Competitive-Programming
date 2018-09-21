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
    int D;
    int N; cin >> N >> D;
    vector<int> nums(N);
    for (int i=0; i<N; ++i) 
    	cin >> nums[i];
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    if (nums.back() - nums[0] <= D) ans = 0;
	for (int i=0; i<N; ++i){
		for (int j=i; j<N; ++j) {
			if (nums[j] - nums[i] >D) {
				ans = min(ans, N-(j-i));
				break;
			}
		}
	}
	cout << ans << endl;
}
