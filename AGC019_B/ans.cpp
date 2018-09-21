#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int cnt[26];
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    string s; cin >> s;
    // cout << s << endl;
    int N = s.size();
    for (int i=0; i<N; ++i) {
    	++cnt[s[i]-'a'];
    }
    ll ans = 1LL*N*(N-1)/2;
    ++ans;
    // cout << N << endl;
    // cout << ans << endl;
    for (int i=0; i<26; ++i) {
    	ans -= 1LL*cnt[i]*(cnt[i]-1)/2;
    	// cout << ans << endl;
    }
    cout << ans << endl;
}
