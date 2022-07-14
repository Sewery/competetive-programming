#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <climits>
#include <vector>
#include <list>
 #include <numeric>
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
#include <unordered_set>
#include <unordered_map>
using namespace std;
 
#define f first 
#define s second 
#define ll long long int
#define un unsigned
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << x << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define PI (3.141592654)
#define sz long unsigned int
const ll moder= pow(10,9)+7;
const int MAXN = 1000 * 1 + 10, INF = 1e9 + 10;
const int N = pow(10,6)+2;
 
void _fake(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
         
}
 
ll n,m ;
ll dp[1005][1040];
 
void solve(ll x , ll y, ll mask  ,ll mask_on_the_next_column )
{
 
        if(y>=m){
            (dp[x+1][mask_on_the_next_column]+=dp[x][mask])%=moder;
            return;
        }
            
        ll y_mask= 1<<y;
        if(y_mask & mask){
            solve(x,y+1,mask,mask_on_the_next_column);
        }    
        else
        {
            solve(x,y+1,mask,mask_on_the_next_column|y_mask);
            if(y+1<m && !( (1<<(y+1)) & mask))
                solve(x,y+2,mask,mask_on_the_next_column);
        } 
  
}
int main ()
{
    _fake();
    cin>>m>>n;
    dp[0][0]=1;
    for(int i=0; i< n;i++)
    {
        for(int j= 0; j< (1<<m);j++)
        {
            solve(i,0,j,0);
        }
    }
    cout<<dp[n][0];
}    