#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN=  1000005;
int off[2*MAXN];
int on[2*MAXN];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    
    int n, m, k;

    cin >> n >> m >> k;
    for (int i=0; i<n ;++i) {
    	int x; cin >> x; ++on[x]; ++off[x+m];
    }
    int cur = 0;
    priority_queue<int> pq;
    int ans = 0;
    for (int i=1; i<MAXN; ++i) {
    	cur += on[i];
    	while (on[i]--) pq.push(i);
    	cur -= off[i];
    	// if (i < 20) printf("%d %d %d\n", cur, i, on[i]);
    	while (cur >= k) {
    		++ans;
    		off[pq.top()+m]--;
    		--cur;
    		// cout << pq.top() << endl;
    		pq.pop();
    	}
    }
    cout << ans << endl;
}
