#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef SUBLIME_RUN
    freopen("A.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int h, m;
    cin >> h >> m;
    int H, D, N; 
    double C;
    cin >>H>>D>>C>>N;
   	int days = H/N + ((H%N)>0);
   	double ans = 1.0*days * C;
   	if (h >= 20) {
   		ans *= .8;
   		cout << ans << endl;
   		return 0;
   	}
   	// cout << days << endl;
   	// cout << ans << endl;
   	while (h != 20) {
   		m += 1;
   		m %= 60;
   		if (m == 0) ++ h;
   		H += D;
   	}
   	// cout << H << endl;
   	days = H/N + ((H%N)>0);
   	// cout << days << endl;
   	ans = min(ans, days*.8*C);
   	cout << setprecision(6) << fixed << ans << endl;
}
