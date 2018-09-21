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
    int ans = 0;
    int N; cin >> N;
    for (int a=1; a<=N;++a) {
    	for (int b =a; b<=N; ++b) {
    		int c = a^b;
    		if (c >= b && a+b > c && c <= N) {
    			++ans;
    			// printf("%d %d %d\n", a,b,c);
    		}
    	}
    }
    cout << ans << endl;
}
