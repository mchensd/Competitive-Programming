// #include <iostream>
// #include <vector>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// #define MAXN (1 << 17)

// struct node {
//   int covers;
//   int coverables;
//   int points;
// };

// node comb(node x, node y) {
//   node r;
//   int ep = min(x.coverables, y.covers);
//   r.points = x.points + y.points + ep;
//   r.covers = x.covers + y.covers - ep;
//   r.coverables = x.coverables + y.coverables - ep;
//   return r;
// }

// node H[MAXN * 2];

// void fix(int x) {
//   while (x != 1) {
//     x /= 2;
//     H[x] = comb(H[x * 2 + 0], H[x * 2 + 1]);
//   }
// }

// vector<int> solve(const vector<int>& A, const vector<int>& B) {
//   int N = A.size();
//   vector<int> R(N + 1);
//   memset(H, 0, sizeof(H));

//   for (int i = 0; i < N; i++) {
//     H[MAXN + B[i]].covers = 1;
//     H[MAXN + A[i]].coverables = 1;
//     fix(MAXN + B[i]);
//     fix(MAXN + A[i]);
//     printf("bes %d fj %d points %d\n", B[i], A[i], H[1].points);
//     R[i + 1] = H[1].points;
//   }

//   return R;
// }

// int main() {
//   freopen("a.in", "r", stdin);
//   freopen("b.out", "w", stdout);

//   ios_base::sync_with_stdio(false);
//   int N; cin >> N;

//   vector<bool> used(2 * N);
//   vector<int> A(N);
//   for (int i = 0; i < N; i++) {
//     cin >> A[i];
//     A[i]--;
//     used[A[i]] = true;
//   }

//   vector<int> B;
//   for (int i = 2 * N - 1; i >= 0; i--) {
//     if (!used[i]) {
//       B.push_back(i);
//     }
//   }
//   //sort(A.begin(), A.end()); //sort(B.begin(), B.end());
//   vector<int> r0 = solve(A, B);
//   reverse(A.begin(), A.end());
//   reverse(B.begin(), B.end());
//   for (int i = 0; i < N; i++) {
//     A[i] = 2 * N - 1 - A[i];
//     B[i] = 2 * N - 1 - B[i];
//   }
//   vector<int> r1 = solve(A, B);

//   int res = 0;
//   for (int i = 0; i <= N; i++) {
//     res = max(res, r0[i] + r1[N - i]);
//     printf("%d %d %d\n", r0[i], r1[N-i], r0[i] + r1[N-i]);
//   }
//   cout << res << endl;

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
struct state{
    int points;
    int covers;
    int coverables;
};

const int MAXN = 50005;
int has[2*MAXN], bes[MAXN], fj[MAXN];
int pref[MAXN], suff[MAXN];
state seg[8*MAXN];

// void updNode(int node) {
//     if (seg[node].L && seg[node].R) {
//         int sub = min(seg[node].L, seg[node].R);
//         seg[node].L -= sub; seg[node].R -= sub;
//         seg[node].points += sub;
//     }
// }
void update(int node, int l, int r, int x, bool bes) {
    if (l == x && r == x) {
        if (bes) ++seg[node].covers;
        else ++seg[node].coverables;
        return;
    }
    int mid = (l+r)/2;
    if (x <= mid) {
        update(2*node, l, mid, x, bes);
    }
    else
        update(2*node+1, mid+1, r, x, bes);
    
    int add = min(seg[2*node].coverables, seg[2*node+1].covers);
    seg[node].points = seg[2*node].points + seg[2*node+1].points + add;
    seg[node].covers = seg[2*node].covers + seg[2*node+1].covers - add;
    seg[node].coverables = seg[2*node].coverables + seg[2*node+1].coverables - add;
}
int N;
void init(){
    memset(seg, 0, sizeof(seg));
    // cout << 'p' << seg[1].points << endl;
}
int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#else
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> fj[i];
        has[fj[i]] = true;
    }
    int d =0;
    for (int i=2*N; i>=0; --i){
        if (!has[i]) {
            bes[d++]=i;
        }
    }
    // sort(bes,bes+N);
    // sort(fj,fj+N);
    int* a=pref;
    for (int k=0; k<2; ++k) {
        for(int i=0; i<N; ++i) {
            // if (!k) printf("%d %d\n", bes[i], fj[i]);
            update(1, 1, 2*N, fj[i], 0);
            update(1, 1, 2*N, bes[i], 1);
            // if (k == 1) printf("%d %d\n", fj[i], bes[i]);
            // printf("bes %d fj %d points %d\n", bes[i], fj[i], seg[1].points);
            a[i+1] = seg[1].points;
        }
        init();
        reverse(bes,bes+N); reverse(fj,fj+N);
        for (int i=0;i<N;++i){
            bes[i] = (2*N+1)-bes[i];
            fj[i] = (2*N+1)-fj[i];
        }

        a=suff;
    }
    // reverse(suff, suff+N);
    
    int ans = suff[0];
    // cout << suff[0] << endl;	
    for (int i=0; i<=N; ++i) {
    	// printf("%d %d %d\n", pref[i], suff[N-i], pref[i] + suff[N-i]);
        ans = max(ans, pref[i] + suff[N-i]);
    }
    cout << ans << endl;
}
