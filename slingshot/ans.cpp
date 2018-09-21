#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

struct ss {
    int l, r, t;
    ss (){}
    ss (int l, int r, int t): l(l), r(r), t(t) {}
    
    bool operator <(const ss& other) const {
        return r < other.r;
    }
};

struct request {
    int l,r,id;
    request(){}
    request(int l,int r, int id): l(l), r(r), id(id) {}
    bool operator < (const request& other) const {
        return l < other.l;
    }
};
const int MAXN=  100005;
int ans[MAXN];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("slingshot.in", "r", stdin);
    freopen("slingshot.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<ss> forw, backw;
    for (int i=0; i<N; ++i) {
        int a,b,w;
        cin >> a >> b >> w;
        if(a==b || abs(b-a) <= w) continue;
        if (b > a) forw.pb(ss(a,b,w));
        else backw.pb(ss(-a,-b,w));
    }
    
    vector<request> manf, manb;
    for (int i=0; i<M; ++i) {
        int a,b; cin >> a >> b;
        if (b > a) manf.pb(request(a,b,i));
        else manb.pb(request(-a,-b,i));
    }
    vector<ss>& shots = forw;
    vector<request>& req = manf;
    int tries = 65000;
    for (int k=0; k<2; ++k) {
        int start = 0;
        sort(shots.begin(), shots.end());
        sort(req.begin(), req.end());
        // printf("%d %d\n", shots[0].l, shots[0].r);
//        printf("%d %d\n", req[0].l, req[0].r);
        for (int i=0; i<req.size(); ++i) {
            int id = req[i].id;
            ans[id] = req[i].r - req[i].l;
            while (start < shots.size() && shots[start].r < req[i].l) {
                ++start;
            }
            for (int j=start; j<min((int)shots.size(), tries); ++j) {
                // if (k) printf("%d %d\n", shots[j].l, shots[j].r);
                // if (shots[j].l > req[i].r) break;
                ans[id] = min(ans[id], abs(req[i].l-shots[j].l) + shots[j].t + abs(req[i].r - shots[j].r));
            }
        }
        //reverse dir
        shots = backw;
        req = manb;
    }
    for (int i=0; i<M; ++i) {
        cout << ans[i] << '\n';
    }
}