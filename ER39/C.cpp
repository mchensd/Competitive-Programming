#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("C.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    string s; cin >> s;
    char min = 'a';
    for (int i=0; i<s.size(); ++i){
    	if (s[i] <= min) {
    		s[i] = min;
    		++min;
    		if (min > 'z') break;
    	}
    }
    if (min <= 'z') cout << -1 << endl;
    else cout << s << endl;
}
