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
    int a, b; cin >> a >> b;
    if (a > b) swap(a,b);
    int m1 = (b-a)/2;
    int m2 = (b-a)/2;
    if((b-a)%2) ++ m1;
    cout << (m1*(m1+1))/2 + m2*(m2+1)/2 << endl;
}
