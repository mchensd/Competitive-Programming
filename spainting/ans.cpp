#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
typedef ModInt<(int)1e9+7> mint;
const int MAXN = 1000005;
mint dp[2*MAXN][2];
mint pref[2*MAXN][2];


int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N, M, K;
    cin >> N >> M >>K;
    dp[1][0] =     M;
    pref[1][0] = M;
    for (int i=2; i<=N; ++i) {
        dp[i][0] = (pref[i-1][0]-pref[max(i-K, 0)][0])*(M-1);
        pref[i][0] = pref[i-1][0] + dp[i][0];
        if (i-K >= 0) {
            dp[i][1] = (dp[i-K][1] + dp[i-K][0])*M;
            dp[i][1] += (pref[i-1][1]-pref[i-K][1])*(M-1);
            pref[i][1] = pref[i-1][1] + dp[i][1];
        }
    }
    cout << (pref[N][1] - pref[N-K][1] + dp[N-K+1][0]).get() << endl;
}

