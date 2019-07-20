#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    int cur = 0;
    stack<pii> st;
    int lb=0, ub=0;
    for (int i=0; i<N; ++i){ 
    	char c;
    	int dist;
    	cin >> c >> dist;
    	int next = cur;
    	if (c == 'R') next += dist;
    	else next -= dist;
    	int l = min(next,cur);
    	int r = max(next,cur);
    	

    }
}
