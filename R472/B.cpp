#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back


const int MAXN = 55;
bool paint[MAXN][MAXN];
bool taken[MAXN];
bool done[MAXN];
int main() {
    #ifdef SUBLIME_RUN
    freopen("B.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<vi> cols(N);
    for (int i=0 ;i<N; ++i) {
    	string s; cin >> s;
    	for (int j=0; j<M; ++j) {
    		if (s[j] == '#') {
    			paint[i][j] = 1;
    			cols[i].pb(j);
    		}
    	}
    }
    for (int i=0; i<N; ++i) {
    	if (done[i]) continue;
    	for (int j=i+1; j<N; ++j) {
    		if (cols[j].size() == cols[i].size()) {
   				bool can = 1;
    			for (int k=0; k<cols[j].size(); ++k) {
    				if (cols[i][k] != cols[j][k]) {
    					can = 0;
    				}
    			}
    			if (can) {
    				done[j] = 1;
    			}
    		}
    	}
    	for (int k : cols[i]) {
    		if (taken[k]) return 0*puts("No");
    		taken[k] = 1;
    	}
    }
    puts("Yes");
}
