#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef SUBLIME_RUN
    freopen("B.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    string s; cin >> s;
    int ans = N;
    for (int i=0; i<N; ++i) {
    	for (int sz=1; sz<=N; ++sz) {
    		if (sz+i > N) break;
    		int j = i+sz;
    		if (sz + j > N) break;
    		if (s.substr(i, sz) == s.substr(j,sz)) {
    			ans = min(ans, N-(sz-1));
    		}
    	}
    }
    cout << ans << endl;
}
