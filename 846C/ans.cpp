#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

ll nums[5005];
ll pref[5005];
pair<ll, int> optr[5005];

ll sum(int l, int r) {
	return pref[r-1] - pref[l-1];
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=1; i<=N; ++i) {
    	cin >> nums[i];
    	pref[i] = pref[i-1] + nums[i];
    }
    for (int i=1; i<=N+1; ++i){
    	ll mx = LLONG_MIN;
    	int ind = 1;
    	for (int j=i; j<=N+1; ++j) {
    		if (sum(i, j) - sum(j, N+1) > mx) {
    			mx = sum(i,j)-sum(j,N+1);
    			ind = j;
    		}
    	}
    	optr[i] = mp(mx, ind);
    }
    ll ans = LLONG_MIN;
    int d1=0,d2=0,d3=0;
    for (int i=1; i<=N+1; ++i){ 
    	for (int j=i; j<=N+1; ++j) {
    		if (sum(1, i) - sum(i, j) + optr[j].first > ans) {
    			ans = sum(1, i) - sum(i, j) + optr[j].first;
    			d1=i; d2=j; d3=optr[j].second;
    		}
    	}
   	}
   	--d1; --d2; --d3;
   	cout << d1 << ' ' << d2 << ' ' << d3 << '\n';
}
