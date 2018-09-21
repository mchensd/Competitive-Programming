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
    int N; cin >> N;
    vi path(N);
    for (int i=0; i<N; ++i)
    	cin >> path[i];
    int jump = 1;
    for (int i=0; i<N-1; ++i){ 
    	int tmp = abs(path[i]-path[i+1]);
    	if (jump != 1) {
    		if (jump != tmp && tmp != 1) {
    			// cout << jump << endl;
    			// cout << tmp << endl;
    			return 0*puts("NO");
    		}
    	}
    	else {
    		jump = tmp;
    	}
    }
    if (jump == 0) return 0*puts("NO");	
    // cout << jump << endl;
    for (int i=0; i<N-1; ++i){
    	if (abs(path[i]-path[i+1]) == jump) continue;
    	int r1 = (path[i]-1)/jump;
    	int r2 = (path[i+1]-1)/ jump;
    	if (r1 != r2) return 0 *puts("NO");
    }
    cout << "YES\n";
    cout << (int)1e9 << ' '<< jump << '\n';
}
