#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
int nums[1005];
int main() {
    #ifdef LOCAL
    freopen("A.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=0; i<N; ++i){
    	cin >> nums[i];
    }
    sort(nums,nums+N);
    for (int i=N-1; i>=0; --i) {
    	int root = round(sqrt(nums[i]));
    	if (root*root != nums[i]) {
    		cout << nums[i] << endl;
    		return 0;
    	}
    }
}
