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
    int N; cin >> N; string s; cin  >>s;
    int cnt = (s[N-1] == '?');
    s = "0"+s+"0";
    bool can = 0;
    for (int i=1; i<=N; ++i){
    	// cout << s[i] << endl;
    	if (s[i] == s[i+1] && s[i] != '?') {
    		return cout << "No\n", 0;
    	}
    	if (s[i]  == '?') {
    		if (i == 1 || i == N) can = 1;
    		else if (s[i-1] == s[i+1]) can = 1;
    		else if (s[i+1] == '?' || s[i-1] == '?') can = 1;
    	}
    }
    if (can)puts("Yes");
    else puts("No");

}
	