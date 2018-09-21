#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef USE_INPUT_FILE
    freopen("C.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    ll R, x1,y1,x2,y2;
    cin >> R >> x1 >> y1 >> x2 >>y2;
    cout << fixed << setprecision(7);
    double d = sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
    if (d >= R) {
    	cout << 1.0*x1 << ' ' << 1.0*y1 << ' ' << R << endl;
    	return 0;
    }
   	double D = 2.0*R-abs(R-sqrt(1.0*(x2-x1)*(x2-x1) + 1.0*(y2-y1)*(y2-y1)));
   	double ra =D/2;
   	// double m = (1.0*y2-y1)/(1.0*x2-x1);
   	ll dx = x1-x2;
   	ll dy = y1-y2;
   	if (dx == 0 && dy == 0) {
   		double xa = 1.0*(x1+x1+R)/2;
   		double ya = 1.0*y1;
   		cout << xa << ' ' << ya << ' ' <<  ra << endl;
   		return 0;
   	}
   	double mag = sqrt(1.0*(dx*dx + dy*dy));
   	double ux = 1.0*dx/ mag;
   	double uy = 1.0*dy / mag;
   	// cout << mag << endl;
   	// cout << ux << endl;
   	ux *= ra;
   	uy *= ra;
   	double xa = x2 + ux;
   	double ya = y2+uy;
   	cout << xa << ' ' << ya << ' ' <<  ra << endl;
}
