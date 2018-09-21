/*
 ID: mchensd
 LANG: C++11
 TASK: humble2
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int nums[105];

int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int K, N; cin >> K >> N;
    vector<int> p;
    for (int i=0; i<K; ++i) {cin >> nums[i]; p.pb(nums[i]);}
    ++N;
	int ind = 0;
	while (p.size() < N) {
		int cur = p[ind];
		// cout << cur << endl;
		int next = INT_MAX;
		for (int j=0; j<K; ++j) {
			int mult = nums[j];
			// cout << cur*mult << endl;
			while (cur*mult <= p.back()) {
				mult *= nums[j];
			}
			next = min(next, cur*mult);
		}
		printf("%d %d\n", cur, next);
		p.pb(next);
		++ind;
	}
	cout << p.size() << endl;
	cout << p.back() << endl;
}
