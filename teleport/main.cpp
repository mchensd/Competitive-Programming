#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define PI 3.14159265358979
#define inf 0x3f3f3f3f
int main() {
	// freopen("input.txt", "r", stdin);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int N;
    cin >> N;
    int cur = 0;
    for (int i=0; i<N; ++i){ 
    	int a,b;
    	cin >> a >> b;
    	int dist = abs(b-a);
    	cur += dist;
    	if (dist <= abs(a)) continue;
    	
    }

}
