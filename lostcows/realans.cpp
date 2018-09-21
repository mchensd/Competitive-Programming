#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define foreach(i, v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
const int MAXN = 205, MAXM = 205;

int n, m;

// previous[N][M] stores all farms which lead to farm N after following sign M
vector<int> previous[MAXN][MAXM];
// bfs_queue stores states as int pairs when doing the reverse BFS from the barn
queue< pair<int, int> > bfs_queue;
// sign_to_follow[X][Y] has the sign to folllow when merging X and Y
int sign_to_follow[MAXN][MAXN];
// simulate_merge[Z][X][Y] stores where Z will end up after merging X and Y
unsigned char simulate_merge[MAXN][MAXN][MAXN];
// sign[X][Y] stores where sign Y at pasture X points to
int sign[MAXN][MAXM];

// occupied[X] is true if pasture X is occupied at the current simulation step
bool occupied[MAXN], new_occupied[MAXN];

bool past[MAXN];
bool nxt[MAXN];
bool v[MAXN];
int main() {
    //   freopen("lostcows.in", "r", stdin);
    //   freopen("lostcows.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    freopen("lostcows_tests/lostcows.10.in", "r", stdin);
    // read input
    cin >> n >> m;
    int N = n;
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            cin >> sign[i][j];
            sign[i][j]--;
            previous[sign[i][j]][j].push_back(i);
        }
    
    // compute sign_to_follow using a BFS
    memset(sign_to_follow, 255, sizeof(sign_to_follow));
    
    // mark the barn as the end point
    sign_to_follow[0][0] = -2;
    bfs_queue.push(make_pair(0, 0));
    
    // the barn is the end state, so the cow at pasture i will stay there
    for (int i = 0; i < n; i++)
        simulate_merge[i][0][0] = i;
    
    while (!bfs_queue.empty()) {
        // a and b are currently occupied
        int a = bfs_queue.front().first;
        int b = bfs_queue.front().second;
        bfs_queue.pop();
        
        // consider all previously followed signs
        for (int prev_sign = 0; prev_sign < m; prev_sign++) {
            foreach(prev_a_iterator, previous[a][prev_sign])
            foreach(prev_b_iterator, previous[b][prev_sign]) {
                int prev_a = *prev_a_iterator;
                int prev_b = *prev_b_iterator;
                if (prev_a > prev_b)
                    swap(prev_a, prev_b);
                
                if (sign_to_follow[prev_a][prev_b] == -1) {
                    sign_to_follow[prev_a][prev_b] = prev_sign;
                    bfs_queue.push(make_pair(prev_a, prev_b));
                }
            }
        }
        
        // if we are not at the barn, precompute the merge simulation
        if (a != 0 || b != 0) {
            int move = sign_to_follow[a][b];
            int next_a = sign[a][move];
            int next_b = sign[b][move];
            if (next_a > next_b)
                swap(next_a, next_b);
            for (int i = 0; i < n; i++)
                simulate_merge[i][a][b] = simulate_merge[sign[i][move]][next_a][next_b];
        }
    }
    
    // now compute the actual synchronizing sequence
    bool first = true;
    fill(occupied, occupied + n, true);
    vector<int> chk;
    while (true) {
        // a and b will contain a pair to be merged
        int a = -1, b = -1;
        for (int i = 1; i < n; i++)
            if (occupied[i]) { 
                if (a == -1)
                    a = i;
                else if (b == -1)
                    b = i;
            }
        
        // if no pastures except the barn are occupied, we are done
        if (a == -1)
            break;
        // if only one other pasture is occupied, merge that with the barn
        if (b == -1)
            b = 0;
        
        // simulate the merge
        fill(new_occupied, new_occupied + n, false);
        for (int i = 0; i < n; i++)
            if (occupied[i])
                new_occupied[simulate_merge[i][a][b]] = true;
        copy(new_occupied, new_occupied + n, occupied);
        
        // and print the sequence to merge a and b
        while (a != 0 || b != 0) {
            if (a > b)
                swap(a, b);
            int now = sign_to_follow[a][b];
            chk.push_back(now+1);
            cout << (now + 1) << "\n";
            a = sign[a][now];
            b = sign[b][now];
        }
    }
    for (int dir : chk) {
      // dir=1;
      // dir=0;
      cout << dir << endl;
        for (int i=1; i<=N; ++i) {
          // cout << past[i] << ' ';
          // cout << path[i][dir] << ' ';
            if (past[i]) {
                if (!v[i]) nxt[i] = 0;
                nxt[path[i][dir]] = 1;
                v[path[i][dir]] = 1;
            }
        }
        // cout << endl;
        for (int i=1; i<=N; ++i) {past[i] = nxt[i]; v[i]=0;}//cout << past[i] << ' '; v[i]=0;}
        for (int i=1; i<=N; ++i){ 
          if (past[i]) {
            bool ok = false;
            for (int j=1; j<=N; ++j) {
              if (path[j][dir] == i) {ok =1;break;}
            }
            if (!ok) printf("BAD CHECK\n");
          }
        }
        // cout << '\n';
    }
    bool f=past[1];
    // cout << "asdf\n";
    // cout << past[1] << endl;
    for (int i=2; i<=N; ++i) {
      if (!f) break;
        f = !past[i];
        // cout << past[i] << endl;
    }
    printf("Checker: ");
    if (f) printf("OK\n");
    else printf("Wrong answer\n");
}
