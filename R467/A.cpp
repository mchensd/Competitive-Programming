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
    int n;
    cin >> n;
    set<int> s;
    for (int i=0; i<n; ++i){
    	int x; cin >> x;
    	if (x == 0) continue;
    	s.insert(x);
    }
    cout << s.size() << endl;
}
