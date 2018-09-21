#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN= (int)1e6+4;
int nums[MAXN];
int l[MAXN];
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    
    int N;
    cin >> N; 
    for (int i=0; i<N; ++i){ 
    	cin >> nums[i];
 
    }
    ll ans = 0;
    for (int k=0;k<2;++k) {
    	for (int i=0; i<N; ++i) l[i] = -1;
    	stack<pii> st;
    	for (int i=0; i<N; ++i ){
    		while (st.size() && st.top().second > nums[i]) {
    			st.pop();
    		}
    		if (st.size()) {
    			l[i]=st.top().first;
    		}
    		st.push(mp(i, nums[i]));
    	}
    	while(st.size())st.pop();
    	for (int i=N-1; i>=0; --i ){
    		int r=N;
    		while (st.size() && st.top().second >= nums[i]) {
    			st.pop();
    		}
    		if (st.size()) {
    			r = st.top().first;
    		}
    		// printf("%d %d %d\n", i, i-l[i], r-i);
    		ans -= 1LL*((i-l[i]) * (r-i))*nums[i];
    		st.push(mp(i, nums[i]));
    	}
    	for (int i=0 ;i<N; ++i) {
    		nums[i] = -nums[i];
    	}
    	// cout << "a " << ans << endl;
    }
    cout << ans << endl;
}
