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
 
 
int n,m;
int main () 
{     
        
    _fake();     
    cin>>n>>m;
   multiset<int> in_set;
    in_set.insert(n);
   map<int,int> maper;
   maper[n]=n;
   for(int i=0; i<m;i++)
   {
        int a; cin>>a;
        auto it =maper.upper_bound(a);
        int val =it->second;
        it->second=it->first-a;
        maper[a]=val-it->second;
        in_set.erase(in_set.lower_bound(val));
        in_set.insert(it->second);
        in_set.insert(maper[a]);
        cout<<*in_set.rbegin()<<"\n";
   }
}