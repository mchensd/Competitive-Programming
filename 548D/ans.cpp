#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN=  200005;
int nums[MAXN];
int ltl[MAXN], ltr[MAXN];
int out[MAXN];
int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    #endif
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; ++i) {
		scanf("%d", &nums[i]);
		// l.insert(mp(nums[i], i));
	}
	stack<pii> st;
	for (int i=0; i<N; ++i) {
		ltl[i] = -1;
		while(st.size() && st.top().first >= nums[i]) {
			st.pop();
		}
		if (st.size()) ltl[i] = st.top().second;
		st.push(mp(nums[i], i));
	}
	while(st.size())st.pop();
	for (int i=N-1; i>=0; --i) {
		ltr[i] = N;
		while(st.size() && st.top().first >= nums[i]) {
			st.pop();
		}
		if (st.size()) ltr[i] = st.top().second;
		st.push(mp(nums[i], i));
	}
	vector<pii> ans;
	for (int i=0 ;i<N; ++i) {
		ans.pb(mp(ltr[i]-ltl[i]-1, nums[i]));
	}
	sort(ans.begin(), ans.end());

	int cur = N;
	int o = 0;
	for (int i=ans.size()-1; i>=0; --i) {
		// printf("%d %d\n", ans[i].first, ans[i].second);	
		while (ans[i].first < cur) {
			// printf("ans[i].first cur %d %d\n", ans[i].first, cur);
			out[cur--] = o;

		}
		o = max(o, ans[i].second);
	}
	while (cur >= 1) out[cur--]= o;
	for (int i=1; i<=N; ++i) {
		// printf("%d %d\n", ltr[i], ltl[i]);
		cout << out[i] << " ";
	}
	cout << endl;
}