#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("A.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    string s; cin >> s;
    string ans = s;
    for (int i=s.size()-1; i>=0; --i) {
    	ans += s[i];
    }
    cout << ans << endl;
}
