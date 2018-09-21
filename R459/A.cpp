#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int fib[1005];			
bool isfib[1005];
int genfib(int n) {

	if (fib[n] || n == 0) return fib[n];
	// cout << n << endl;
	fib[n] = genfib(n-2) + genfib(n-1);
	// cout << fib[n] << endl;
	if (fib[n] < 1001 && fib[n] > 0) isfib[fib[n]]=1;
	return fib[n];
}`
int main() {
    #ifdef USE_INPUT_FILE
    freopen("A.in", "r", stdin);
    #endif	
    ios::sync_with_stdio(0);
    int n; cin  >> n;
    isfib[1] = 1; isfib[2] = 1;
    fib[1] = 1; fib[2] = 1;
    genfib(n);
    int cur = 0;
    for (int i=1; i<=n; ++i) {
    	if(isfib[i]) cout<<'O';
    	else cout<<'o';
    }
    cout << '\n';
}
