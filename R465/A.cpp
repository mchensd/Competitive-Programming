#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("A.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
	
	int N; cin >> N;
	int ans = 0;
	for (int i=1; i<N ;++i) {
		int tmp = N-i;
		if (tmp % i == 0) {
			++ ans;
		}
	}    	
	cout << ans << endl;
}
