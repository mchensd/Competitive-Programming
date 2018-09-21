/*
 ID: mchensd
 LANG: C++11
 TASK: kimbits
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

bool ans[33];
ll choose[33][33];
ll pref[33][33];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N, L;
    ll I;
    cin >> N >> L >> I;
    for (int i=0;i<=32;++i)for(int j=0;j<=32;++j) choose[i][j] = pref[i][j]=1;
    for (int i=1; i<=32; ++i) {
        choose[i][0]= pref[i][0] = 1;
        for (int j=1; j<=i; ++j) {
            choose[i][j] = choose[i][j-1] * (i-j+1) / j;
            pref[i][j] = pref[i][j-1] + choose[i][j];
        }
    }
    ll cur = 1;
    if (I == 1) {
        for (int i=0;i<N;++i)
            cout << '0';
        cout << '\n';
        return 0;
    }
    int start = 0;
    for (int i=N-1; i>=0; --i){
        cur += pref[N-(i+1)][min(N-(i+1), L-1)];
        if (cur >= I) {
            start = i;
            cur -= pref[(N-(i+1))][min(N-(i+1), L-1)];
            ++cur;
            break;
        }
    }
    ans[start]=1;
    int cnt = 1;
    for (int i=start+1; i<N; ++i) {
        if (pref[N-(i+1)][min(N-(i+1), L-cnt)] + cur > I) {
            continue;
        }
        cur += pref[N-(i+1)][min(N-(i+1), L-cnt)];
        ++cnt;
        ans[i] = 1;
    }
//    cout << cur << endl;
    if (cur < I) ans[N-1]=1;
    for (int i=0;i<N; ++i) {
        cout << ans[i];
    }
    cout << '\n';
}

