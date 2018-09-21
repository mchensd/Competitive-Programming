#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("B.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    map<string, string> ma;

    for (int i=0; i<n; ++i) {
    	string a, b; cin >> a >> b;
    	ma[b] =a;
    }
    for (int i=0; i<m; ++i) {
    	string a, b; cin >> a >> b;
    	cout << a << ' ' << b << " #" << ma[b.substr(0, b.size()-1)] << '\n';
    }
}
