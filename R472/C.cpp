#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef SUBLIME_RUN
    freopen("C.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, U;
    cin >> N>>U;
    vi nums(N);
    multiset<int> st;
    for (int i=0; i<N; ++i){
    	cin >>nums[i];
    	st.insert(nums[i]);
    }
    double ans = -1;
    auto it1 = st.begin();
    ++it1;++it1;
    for (; it1!=st.end(); ++it1) {
    	auto it2 = st.lower_bound(*it1-U);
    	if (it2 == st.end()) continue;
    	auto nxt = ++it2;
    	--it2;
    	if(nxt == it1) continue;
    	ans = max(ans, (1.0*(*it1-*nxt))/(*it1-*it2));
    }
    if (ans == -1) return 0*puts("-1");
    cout << setprecision(10) << fixed << ans << endl;
}
