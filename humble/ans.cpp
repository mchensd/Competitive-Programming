/*
 ID: mchensd
 LANG: C++11
 TASK: humble
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int nums[105];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int K, N;
    cin >> K >> N;
    // auto t = clock();
    for (int i=0; i<K; ++i) {
        cin >> nums[i];
    }
    set<int> s;
    ++N;
    s.insert(1);
    ll itr = 0;
    for (int i=0; i<K; ++i ){
        auto it = s.begin();
        while (true){
        	// ++itr;
        	int mult = nums[i];
        	if (1LL*mult*(*it) > INT_MAX) break;
        	int next = mult*(*it);
        	if (s.size() == N) {
        		if (next >= *--s.end()) break;
        		s.erase(--s.end());
        	}
        	s.insert(next);

        	++it;
        }
    }
    // cout << itr << endl;
    cout << *--s.end() << endl;
    // cout << ((double)(clock()-t))/CLOCKS_PER_SEC << endl;
}
