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
const int MOD = (int)1e9+7;
const int MAXN=1005;
int num[MAXN];
int dp[MAXN][MAXN][2][2];
string s;
int digitdp(int ind, int k, int cnt, bool tight){
    if (ind == s.size()-1) {
        if (cnt == k) return 1;
        if (cnt > k) return 0;
        if ((tight && s[ind] == '1') || (!tight)) {
            return cnt+1 == k;
        }
        return 0;
    }
    if (dp[ind][cnt][tight][0] > -1 && dp[ind][cnt][tight][1] > -1) {
        return dp[ind][cnt][tight][0] + dp[ind][cnt][tight][1];
    }
    if (tight) {
        if (s[ind] == '0') {
            dp[ind][cnt][tight][0] = digitdp(ind+1, k, cnt, tight);
            return dp[ind][cnt][tight][0];
        }
    }
    
    if (dp[ind][cnt][tight][0] == -1)
        dp[ind][cnt][tight][0] = digitdp(ind+1, k, cnt, 0);
    
    if (dp[ind][cnt][tight][1] == -1)
        dp[ind][cnt][tight][1] = digitdp(ind+1, k, cnt+1, tight);
    return (dp[ind][cnt][tight][0] +dp[ind][cnt][tight][1])%MOD;
}
int main() {
   #ifdef LOCAL
	freopen("C.in", "r", stdin);
	// freopen("C.out", "w", stdout);
	#endif
    ios::sync_with_stdio(0);
    auto a = clock();
    cin >> s;
    int K;
    cin >> K;
    // cout << s.size() << '\n';
    for (int i=1; i<=s.size(); ++i) {
        memset(dp, -1, sizeof(dp));
        num[i] = digitdp(0, i, 0, 1);
       // cout << num[i] << endl;
        if (num[i] == 0) break;
    }
    for (int i=1; i<K; ++i) {
    	// cout << num[1].get() << endl;
        for (int j=1; j<=s.size(); ++j ){
            if (num[j] == 0) break;
            int sz=__builtin_popcount(j);
            num[sz] += num[j];
            num[sz] %= MOD;
            num[j] = 0;
        }
    }
    cout << num[1] << endl;
    auto b = clock();
    cout << (double)(b-a) / (CLOCKS_PER_SEC) << endl;
}

