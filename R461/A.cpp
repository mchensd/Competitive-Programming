#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("A.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int a, b;cin >> a >> b;
    if (a == 0 && b == 1) return 0*puts("Yes");
    ll x= b-1;
    ll clone = x;
    if (b>0 && clone != 0 && clone <= a && (a-clone) % 2 == 0) puts("Yes");
    else puts("No");
}
