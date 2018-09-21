#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N; 
    stack<int> lim;
    int speed = 301;
    int ans = 0;
    int ot = 0;
    for (int i=0; i<N; ++i) {
    	int q; cin >> q;
    	int a=0;
    	if (q == 1 || q == 3) {
    		cin >> a;
    		if (q == 1){ 
    			speed = a;
    			while (lim.size() && lim.top() < speed) {
    				lim.pop(); ++ ans;

    			}
    		}
    		else{ 
    			lim.push(a);
    			if (lim.top() < speed) {
    				lim.pop(); ++ans;
    			}
    		}
    	}
    	else if (q == 5) {while (lim.size()) lim.pop();}
    	else if (q==2) {
    		ans += ot;
    		ot=0;
    	}
    	else if ( q== 6) ++ot;
    	else if (q==4) ot=0;
    }
    cout << ans << endl;

}
