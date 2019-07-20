#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, S;
    cin >> N >> S;
    vi cost(N);
    for (int i=0; i<N; ++i) {
    	cin >> cost[i];
    }
    int ans = 0;
    for (int i=0; i<N; ++i) {
    	int target = S - cost[i];
    	int lo = i;
    	int hi = N-1;
    	if (cost[lo] > target) continue;
    	while (lo < hi) {
    		int mid = (lo+hi+1) / 2;
    		if (cost[mid] <= target) {
    			lo = mid;
    		}
    		else {
    			hi = mid-1;
    		}
    	}
    	ans += lo-i;
    }
    cout << ans << endl;
}
