#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

struct cow {
    int x, y;
    char br;
    cow(int x,int y, char br):x(x), y(y), br(br){}
    bool operator < (cow other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("cowrect.in", "r", stdin);
    freopen("cowrect.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
	set <int> a;
	for (int i=0; i<10; ++i) a.insert(i);
	auto it1=  a.begin();
	auto it2 = a.begin();
	advance(it2,3);
	auto it3 = a.begin();
	advance(it3, 5);
	cout << *it3 << endl;
	cout << *it2 << endl;
	a.erase(it2);
	cout << *it3 << endl;
	cout << *it2 << endl;
	cout << *it1 << endl;
	cout << a.size() << endl;
	cout << (it3 == it1) << endl;
}

