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
    int l, r, a; cin>>l>>r>>a;
    while (a) {
    	if (l < r) ++ l;
    	else ++ r;
    	--a;
    }
    cout << min(l,r)*2 << endl;
}
