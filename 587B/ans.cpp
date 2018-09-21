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
int a[MAXN];
int sorted[MAXN];
unordered_map<int, int> dpind;
vector<int> addend;
mint dp[MAXN], pref[MAXN];
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int N,  K;
    ll L;
    cin >> N >> L >> K;
    for (int i=0; i<N; ++i) {
    	cin >> a[i];
    	sorted[i] = a[i];
    }
    sort(sorted, sorted+N);
    dpind[sorted[0]] = 0;
    pref[0] = 1 ;
    for (int i=1; i<N; ++i) {
    	pref[i] = 1;
    	if (sorted[i] != sorted[i+1]) {
    		dpind[sorted[i]] = i;
    	}
    }
    for (int i=0; i<(L%N); ++i) {
    	addend.pb(dpind[a[i]]);
    }
	mint ans = 0;
    ll mult = L/N;
    // cout << m
    // cout << mult.get() << endl;
    for (int k=1;k<=K; ++k) {
    	// cout << ans.get() << endl;
    	for (int x : addend) {
    		ans += pref[x];
    	}
    	if (mult	 == 0) break;
    	for (int i=0; i<N; ++i) {
    		dp[i] = (pref[dpind[sorted[i]]]);
    		// printf("%d %d\n", i, dp[i].get());
    		ans += dp[i]*mult;
    	}
    	pref[0] = dp[0];
    	for (int i=1; i<N; ++i){
    		pref[i] = pref[i-1]+dp[i];
    	}
    	mult -= 1;
    	// cout << endl;
    }
    cout << ans.get() << '\n';
}
