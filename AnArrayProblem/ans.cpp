//https://dmoj.ca/problem/nccc2j3s1
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int nums[50];

int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> nums[i];
	}    
	sort(nums, nums+N);
	int ans = 0;
	for (int i=0; i<N-1;++i) {
		// cout << nums[i] << endl;
		for(int k=0; k<nums[i]; ++k) {
			pii mx = mp(-1, 0);
			for (int j=i+1; j<N; ++j) {
				mx = max(mx, mp(nums[j], j));
			}
			// cout << mx.first << mx.second << endl;
			--nums[mx.second];
			++ans;
		}
		sort(nums+i+1, nums+N);
	}
	cout << ans << endl;
}