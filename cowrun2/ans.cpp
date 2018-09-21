#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pair<int, string> > state;
#define mp make_pair
#define pb push_back

int nums[15][8];
int main() {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, M, K;
    cin >> N >> M >> K;
    string bes; cin >> bes;
    for (int i=0; i<N; ++i) {
    	for (int j=0; j<8; ++j) {
    		cin >> nums[i][j];
    	}
    }
    queue<state> q;
    q.push(mp(0, mp(0, "")));
    string ans = "Z";
    while (q.size()) {
    	state next = q.front();
    	cout << next.first << endl;
    	q.pop();
    	if (next.second.first == N) {
    		// cout << next.second.first;
    		ans = min(ans, next.second.second);
    		continue;
    	}
    	int cur = next.second.first;
    	int starts[4] = {0,4, 4,6};
    	string move[4] = {"T", "B", "B", "B"};
    	for (int i=0; i<2; ++i) {
    		int ind = starts[i];
    		int ind2 = 2+ind;
    		string fj= move[i];
    		ll tmpd = next.first*nums[cur][ind];
    		tmpd += nums[cur][ind+1];
    		tmpd  %= M;
    		ll tmpd2 = next.first *nums[cur][ind2];
    		tmpd2+=nums[cur][ind2+1];
    		tmpd2 %= M;
    		if (min(tmpd, M-tmpd) <= K && min(tmpd2, M-tmpd2) <= K) {
    			q.push(mp(next.first+(bes[cur] == 'T' ? tmpd : tmpd2), mp(cur+1, next.second.second+fj)));
    		}
    	}
    }
    cout << ans << endl;
}
