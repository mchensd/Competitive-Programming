#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int >ppii;
#define mp make_pair
#define pb push_back
const int MAXN=300005;
int N;
#define L first.first
#define R first.second
int fen[2*MAXN];
ppii seg[MAXN];
map<int, int> cmp;
int out[MAXN];
void upd(int ind, int val) {
    for (; ind<=2*N; ind += ind&(-ind)){
        // cout << ind << endl;
        fen[ind] += val;
    }
}
int get(int ind) {
    int ret = 0;
    for (; ind>=1;ind -= ind&(-ind)){
        // cout << "i " << ind << endl;
        ret += fen[ind];
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin >> N;
    vector<int> coords;
    for (int i=0; i<N; ++i)  {
        seg[i].second= i;
        cin >> seg[i].L >> seg[i].R;
        coords.pb(seg[i].L); coords.pb(seg[i].R);
    }
    sort(coords.begin(), coords.end());
    for (int i=0; i<coords.size(); ++i) {
        // cout << coords[i] << endl;
        cmp[coords[i]] = i+1;
    }
    sort(seg, seg+N);
    for (int i=N-1; i>=0; --i) {
        ppii c = seg[i];
        out[c.second] = get(cmp[c.R]);
         // printf("%d %d %d %d\n", c.L, c.R, cmp[c.L], cmp[c.R]);
        upd(cmp[c.R], 1);
        // out[c.second] = get(cmp[c.R]);// - get(cmp[c.L]);
    }
    for (int i=0; i<N; ++i){
        cout << out[i] << '\n';
    }
    
}


