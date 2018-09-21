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
    ll N, K, A, B;
    cin >> N >> K >> A >>B;
    if (K==1) {
        cout << (N-1)*A << endl;
        return 0;
    }
    
    ll ans = 0;
    while (N != 1) {
       // cout << N << endl;
        if (N%K == 0) {
            ll nxt = N/K;
            if ((N-nxt)*A < B) {
                ans += (N-nxt)*A;
            }
            else {
                ans += B;
            }
            N = nxt;
        }
        else {
            ll nxt = max((N/K) * K, 1LL);
            ans += A*(N-nxt);
            N = nxt;
        }
    }
    cout << ans << endl;
}
