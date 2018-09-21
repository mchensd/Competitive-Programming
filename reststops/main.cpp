// greedY??
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define PI 3.14159265358979
#define inf 0x3f3f3f3f

typedef pair<int, int> PII;
int main() {
    // freopen("input.txt", "r", stdin);
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int L, N, rf, rb;
    cin >> L >> N >> rf >> rb;
    vector<PII> stops;
    for (int i=0; i<N; i++) {
    	int x, c;
    	cin >> x >> c;
    	stops.pb(make_pair(c, x));
    }
    sort(stops.begin(), stops.end());
    ll eat_time = 0;
    ll gain = rf - rb;
    int index = N-1;
    ll ans = 0;
    ll posb = 0, posf = 0;
    while (index >= 0) {
    	while (stops[index].second <= posb) {
    		index--;
    		if (index < 0) {
    			break;
    		}
    	}
    	if (index < 0) break;
    	eat_time += (stops[index].second - posb) * gain;
    	ans += eat_time * 1LL * stops[index].first;
    	eat_time = 0;
    	posb = stops[index].second;
    }
    cout << ans << endl;
}
