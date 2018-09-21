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
    int N, A, B; cin >> N >> A >> B;
    // cout << B << endl;
    int na=0, nb=0;
    for (int i=0; i<=N; ++i) {
        int tmp = N - (A*i);
        // cout << tmp << endl;
        // cout << tmp%B << endl << endl;
        if (tmp < 0) {
            return 0*puts("-1");
        }
        if (tmp % B == 0) {
            na = i;
            nb = tmp/B;
            break;
        }
    }
    vector<int> ans;
    // printf("%d %d\n", na,nb);
    int cur = 1;
    for (int x=0;x<na;++x) {
        int nxt = cur+1;
        for (int i=0; i<A-1; ++i){
            ans.pb(nxt);
            ++nxt;
        }
        ans.pb(cur);
        cur = ans.size()+1;
    }
    for (int x=0;x<nb;++x) {
        int nxt = cur+1;
        for (int i=0; i<B-1; ++i) {
            ans.pb(nxt);
            ++nxt;
        }
        ans.pb(cur);
        cur = ans.size() +1;
    }
    for (int i=0;i<ans.size();++i) {
        if (i)cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    
}
