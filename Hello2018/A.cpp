#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int N, M;
    cin >> N >> M;
    int m = 1;
    for (int i=0; i<N; ++i){ 
    	m*=2;
    	if (m > M) {
    		cout << M << endl;
    		return 0;
    	}
    }
    cout << M%m << endl;
}
