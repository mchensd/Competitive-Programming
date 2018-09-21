#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define PI 3.14159265358979
#define inf 0x3f3f3f3f
int main() {
	// freopen("input.txt", "r", stdin);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    int ans = abs(b-a);
    ans = min(ans, abs(y-a) + abs(b-x));
    ans = min(ans, abs(x-a) + abs(y-b));
    cout << ans << endl;
}
