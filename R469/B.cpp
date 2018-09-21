#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("B.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int n, m; cin >> n>>m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i)
    	cin >> a[i];
    for (int i=0;i<m;++i)
    	cin >> b[i];
    int l =1,r =1;
    int ls = a[0], rs=b[0];
    int ans = 0;
    while (l<n && r < m) {
    	// printf("%d %d\n", ls,rs);
    	if (ls < rs) {
    		ls += a[l++];
    	}
    	else if (rs < ls) {
    		rs += b[r++];
    	}
    	else {
    		// cout << ls << endl;
    		++ans;
    		ls=a[l++];
    		rs=b[r++];
    	}
    }
    // precision()tf("%d %d\n", ls,rs);
    while (l < n) {
    	if (ls == rs) {
    		break;
    	}
    	ls += a[l++];
    }
    while (r<m) {
    	if (ls == rs) {
    		break;
    	}
    	rs += b[r++];
    }
    if (ls == rs) {
    	++ans;
    }
    cout << ans << endl;
}
