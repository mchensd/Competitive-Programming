#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

char b[100005];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    int N;
    scanf("%d", &N);
    vi a(N);
    for (int i=0; i<N; ++i) {
    	cin >> a[i];
    }
    scanf("%s", &b);
    int l = (int)-1e9;
    int r = (int)1e9;
    char prev = '0';
    multiset<int> ms;
    for (int i=0; i<4; ++i) {
    	ms.insert(a[i]);
    }

    for (int i=4; i<N; ++i) {
    	ms.insert(a[i]);
    	if (b[i] != prev){ 
    		if (b[i] == '1' ){
    			l = max(l, *ms.rbegin()+1);
    		}
    		else {
    			r = min(r, *ms.begin()-1);
    		}
    		prev = b[i];
    	}
    	ms.erase(ms.find(a[i-4]));
    }
    printf("%d %d\n", l,r);
}
