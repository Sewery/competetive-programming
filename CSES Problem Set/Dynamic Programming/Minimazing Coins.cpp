#include iostream
#include iomanip
#include fstream
#include sstream
#include map
#include climits
#include vector
#include list
 #include numeric
#include set
#include queue
#include deque
#include algorithm
#include bitset
#include cstring
#include cstdio
#include cstdlib
#include cctype
#include cmath
#include memory.h
#include map
#include unordered_map
using namespace std;
 
#define f first 
#define s second 
#define ll long long int
#define un unsigned
#define pii pairint, int
#define pb push_back
#define mp make_pair
#define VAL(x) #x   =   x     
#define SQR(a) ((a)  (a))
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define X first
#define Y second
#define PI (3.141592654)
const ll moder= pow(10,9)+7;
const int MAXN = 1000  1 + 10, INF = 1e9 + 10;
 
void _fake(){
    ios_basesync_with_stdio(false);
    cin.tie(NULL);
         
}
void solve(int N, vectorint coins){
 
    vectorll vv(N+1,INT_MAX);
    sort(coins.begin(),coins.end());
    vv[0]=0;
    for(int i=1; i=N;i++)
    {
        for(auto x coins)
        {
            if(i-x-1)
                vv[i]=min(vv[i],vv[i-x]+1);
        }
    }
    int w =vv[N]==INT_MAX-1vv[N]%moder;
    coutw;
}
int main ()
{
   
    _fake();
    int t,m;
    cintm;
    vectorint coins(t);
    for(int i=0; it;i++)
        cincoins[i];
    solve(m,coins);
 
   
    
    
}    
    