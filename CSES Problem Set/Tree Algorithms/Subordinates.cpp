#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <sstream> 
#include <map> 
#include <climits> 
#include <vector> 
#include <list> 
#include <set> 
#include <queue> 
#include <deque> 
#include <algorithm> 
#include <bitset> 
#include <cstring> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <memory.h> 
#include <queue> 
#include <stack> 
#include <cassert> 
using namespace std;      
#define V vector
#define vi vector<int> 
#define ll long long  
#define un unsigned 
#define pii pair<int, int> 
#define pb push_back 
#define mp make_pair 
#define rsz resize 
#define ft front() 
#define VAL(x) #x << " = " << x << "   " 
#define SQR(a) ((a) * (a)) 
#define sz(x) ((int) x.size()) 
#define ALL(x) x.begin(), x.end() 
#define CLR(x, a) memset(x, a, sizeof x) 
#define F0R(i, x) for(int i=0;i<x; i ++) 
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++) 
#define X first #define Y second 
#define PI (3.141592654) 
#define moder 1000000007 
const int MAXN = 3e5  + 20, INF = 1e9 + 10; const ll L_INF = LLONG_MAX /2; const int NUM = 2502; 
void _fake(){     ios_base::sync_with_stdio(false);     cin.tie(NULL);     cout.tie(NULL);     }
 
int counter[MAXN]={};
vector<int> adj[MAXN];
void dfs(int s, int e) {
   
    for (auto u : adj[s]) {
        if (u == e) continue;
        dfs(u, s);
        counter[s] += counter[u]+1;
    }
}
int main () 
{     
    int n;
        
    _fake();     
    cin>>n;
    
    for(int i=2; i<=n;i++)
    {
        int a;cin>>a;
        adj[a].pb(i);
    }
    dfs(1,0);
    for(int i=1; i<=n;i++)cout<<counter[i]<<" ";
 
}