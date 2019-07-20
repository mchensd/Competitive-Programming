#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
#if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int t; cin >> t;
    vi days(7);
    
    while (t--) {
//        cout << t<< endl;
        int ans = INT_MAX;
        int k; cin >> k;
        int ones = 0;
        for (int i=0; i<7; ++i) {
            cin >> days[i];
            ones += days[i];
        }
        
        int goal = k%ones;
//         cout << goal << endl;
        for (int start=0; start<7; ++start) {
            if (!days[start]) continue;
            
            int cur = 1;
            int ind = start;
            while (cur != goal) {
                ++ind;
//                cout << cur << endl;
                ind %= 7;
                if (days[ind]) {
                    ++cur;
                    cur %= ones;
                }
            }
            int end = ind;
           	// printf("%d %d\n", start, end);
            if (end < start) end += 7;
            ans = min(ans, 1+7*((k-1)/ones)+end-start);
        }
         cout << ans << endl;
    }
}

