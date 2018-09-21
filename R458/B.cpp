#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int  cards[100005];
int main() {
    #ifdef LOCAL
    freopen("B.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=0; i<N; ++i ){
    	cin >> cards[i];
    }
    sort(cards,cards+N);
    int x = cards[N-1];
    int ind =N-1; int cnt = 0;
    while (ind>=0) {
    	while (ind >= 0 && cards[ind] == x) {
    		++cnt;
    		--ind;
    	}
    	if (cnt%2) {
    		puts("Conan");return 0;
    	}
    	cnt = 0; 
    	if(ind>=0) x=cards[ind];
	}
	puts("Agasa");
    
}
