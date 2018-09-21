#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppii;

#define mp make_pair
#define pb push_back

const int MAXN=  200005;
ppii probs[MAXN];
int N, T;
vector<int> ans;
int val = 0;
bool cmp (ppii a, ppii b){ 
	return a.second.first < b.second.first;
}
bool can(int x) {
	vector<pii> s;
	for (ppii p : probs) {
		if (p.second.first < x) break;
		s.pb(mp(p.second.second, p.first));
	}
	sort(s.begin(), s.end());
	if (s.size() < x) return 0;
	int t =0 ;
	for (int i=0; i<x; ++i) {
		t+=s[i].first;
	
	}
	if (t<= T) {
		val = x;
		int i=0;
		for (;i<min((int)ans.size(), x);++i ) {
			ans[i]=s[i].second;
		}
		for (;i<x;++i) {
			ans.pb(s[i].second);
		}
		return 1;
	}
	return 0;
}
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin >> N >> T;
    for (int i=0; i<N; ++i) {
    	probs[i].first=i+1;
    	cin >> probs[i].second.first >> probs[i].second.second;
    }
    int lb = 0, ub = N;
    sort(probs, probs+N, cmp); reverse(probs, probs+N);
    while (lb < ub) {
    	int xs = (lb+ub+1)/2;
    	if (can(xs)) {
    		lb = xs;
    	}
    	else {
    		ub = xs-1;
    	}
    }
    cout << val << '\n' << val << '\n';
    for (int i=0; i<val; ++i) {
    	cout << ans[i] << ' ';
    }
    cout << '\n';

}
