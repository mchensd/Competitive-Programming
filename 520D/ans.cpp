#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppii;
#define mp make_pair
#define pb push_back
#define X second.first
#define Y second.second
int N;
const int MAXN=  100005;
const int mod = (int)1e9+9;
ppii blocks[MAXN];
map<int, map<int, pair<bool, int> > > has;
set<int> curr;
vector<int> digs;
bool ok(int i) {
    int x = blocks[i].X, y = blocks[i].Y;
    for (int nx=x-1; nx<=x+1; ++nx) {
        if (has[nx][y+1].first) {
            bool f= false;
            for (int nnx=nx-1; nnx<=nx+1; ++nnx) {
//                cout << nnx << endl;
                if (nnx == x) {
                	continue;
                }
                if (has[nnx][y].first) f=true;
            }
            if (!f) return 0;
        }
    }
    return 1;
    // return !(has[x-1][y+1].first || has[x][y+1].first || has[x+1][y+1].first);
}
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    // ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    // cout << N << endl;
    for (int i=0; i<N; ++i) {
    	// cout << i << endl;
        int x, y; cin >> x >> y;
        blocks[i].X = x; blocks[i].Y= y;
        has[x][y] = mp(1, i);
    }
    for (int i=0; i<N; ++i) {
    	// cout << i << endl;
        if (ok(i)) {
            curr.insert(i);
        }
    }
    int turn=1;
    // has[0][0].first=0;
    // has[2][0].first=0;
   // cout << ok(2) << endl;
    while (curr.size()) {
        set<int>::iterator it;
        if (turn) {it = curr.end(); --it;}
        else it=curr.begin();
        if (!ok(*it)) {
        	curr.erase(it);
        	continue;
        }
        digs.pb(*it);
        // cout << *it << endl;
        int x=blocks[*it].X, y=blocks[*it].Y;
        has[x][y].first = false;
        // printf("%d %d\n", x, y);
        for (int nx=x-1; nx<=x+1; ++nx) {
            if (has[nx][y-1].first && ok(has[nx][y-1].second)) {
                curr.insert(has[nx][y-1].second);
            }
        }
        curr.erase(it);
        turn = !turn;
    }
    ll ans = 0;
    ll p=1;
    for (int i=N-1; i>=0; --i) {
        // cout << digs[i]*p <<  endl;
        ans += 1LL*digs[i]*p;
        ans %=mod;
        p*=N; p%=mod;
    }
    cout << ans << endl;
     // cout << 9236758041%mod << endl;
}

