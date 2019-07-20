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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    int ans = 1;
	int ind = 0;
	while (ind < n) {
		int start = ind;
		while (ind < n && a[ind] != a[ind+1]) {
			++ind;
		}
		// printf("%d %d\n", start, ind);	
		ind = min(ind, n-1);
		ans = max(ans, ind-start+1);
		++ind;

	}
	cout << ans << endl;
}
