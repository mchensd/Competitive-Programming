/*
 ID: mchensd
 LANG: C++11
 TASK: fracdec
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int seen[100005];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    if (!(a%b)) {
        cout << fixed << setprecision(1)<<1.0*a/b << endl;
        return 0;
    }
    string out = "";
    out += to_string(a/b); out += '.';
    if (a >= b) a -= (b*(a/b));
    vector<int> ans;
    memset(seen, -1, sizeof(seen));
    int ind = 0;
    int rep = -1;
    while (true) {
        if (seen[a] > -1) {
            rep = seen[a];
            break;
        }
        seen[a] = ind++;
        a *= 10;
        int c = a/b;
        ans.pb(c);
        a -= b*c;
        if (a == 0) {
            break;
        }
    }
    for (int i=0; i<ans.size(); ++i) {
        if (i == rep) out += '(';
        out += to_string(ans[i]);
    }
    if (rep>-1)out += ')';
    for (int i=0; i<out.size(); ++i) {
    	if (i%76 == 0 && i > 0) cout << '\n';
    	cout << out[i];
    }
    cout << '\n';
}

