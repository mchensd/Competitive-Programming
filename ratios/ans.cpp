/*
 ID: mchensd
 LANG: C++11
 TASK: ratios
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

struct triple {
    int x,y,z;
    triple(){}
    triple(int a, int b, int c):x(a),y(b),z(c) { }
};
triple goal;
vector<int> goalv;
triple rats[3];
int goals[3];
int can(vector<int> testv) {
    int a=0,b=0,c=0;
    goals[0]=0;
    goals[1]=0;
    goals[2]=0;
    for (int i=0; i<3; ++i) {
        goals[0] += rats[i].x*testv[i];
        goals[1] += rats[i].y*testv[i];
        goals[2]+=rats[i].z*testv[i];
    }
    int div = -1;
    for (int i=0; i<3; ++i) {
        if (goalv[i] == 0){
            if(goals[i] != 0) {
                return -1;
            }
        }
        else {
            if ((goals[i] % goalv[i])) return -1;
            int tmp = goals[i] / goalv[i];
            if (div == -1) div = tmp;
            else if (div != tmp) return -1;
        }
    }
    return div;
}
int vis[101][101][101];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >>goal.x >> goal.y >> goal.z;
    goalv.pb(goal.x); goalv.pb(goal.y); goalv.pb(goal.z);
    for (int i=0; i<3; ++i) {
        cin >> rats[i].x >> rats[i].y >> rats[i].z;
    }
//    auto t = clock();
    for (int i=0; i<100; ++i) {
        for (int j=0; j<100; ++j){
            for (int k=0;k<100;++k) {
                if (!i && !j && !k) continue;
                vector<int> t; t.pb(i);t.pb(j);t.pb(k);
                int check = can(t);
                if (check > -1) {
                    cout << i << ' ' << j << ' ' << k << ' ' << check << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "NONE\n";
//    cout << ((double)(clock()-t))/CLOCKS_PER_SEC;
}

