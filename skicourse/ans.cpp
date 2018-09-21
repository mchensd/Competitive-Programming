/*
 ID: mchensd
 LANG: C++11
 TASK: skicourse
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 105;
string pat[MAXN];
bool s[MAXN][MAXN], r[MAXN][MAXN];
int prefs[MAXN][MAXN], prefr[MAXN][MAXN];
int N, M;
bool can(int b) {
	bool stamped = true;
	while (stamped) {	
		stamped = false;
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				
			}
		}
	}
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("skicourse.in", "r", stdin);
    freopen("skicourse.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i=0; i<N; ++i){ 
    	string s; cin >> s;
    	pat[i] = s;
    	for (int j=0; j<M; ++j) {
    		if (s[j] == 'R')
    			r[i][j] = 1;
    		else
    			s[i][j] = 1;
    	}
   	}
   	int lb = 1, ub = min(N, M);
   	while (lb < ub) {
   		int xs = (lb + ub + 1) / 2;
   		if (can(xs)) 
   			lb = xs;
   		else
   			ub = xs-1;
   	}
}
