#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef SUBLIME_RUN
    freopen("A.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    string s; cin >> s;
    int i = 0; 
    int ans = N;
    while (i < N-1) {
    	if (s[i] != s[i+1]) {
    		--ans;
    		i += 1;
    	}
    	++i;
    }
    cout << ans << endl;

}
