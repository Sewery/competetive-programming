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
#include <map>
#include <unordered_map>
using namespace std;
 
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
#define X first
#define Y second
#define PI (3.141592654)
ll moder= 1000000007;
const int MAXN = pow(10,5)  *2+ 10, INF = 1e9 + 10;
 
void _fake(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
         
}
struct Segtree
{
    const ll N = MAXN;
    ll n;
    vector<ll> seg;
 
    void init(vector<ll> arr)
    {
        n=arr.size();
        seg.assign(n * 2, 0);
      
    }
    void update( ll a , ll u)
    {
        seg[a+=n]+=u;
        for (a /= 2; a>0; a /= 2) 
        {
            seg[a]=seg[a*2]+seg[a*2+1];
 
		}
    }
    ll query(ll l , ll r)
    {
        ll ra=0 , rb=0;
        for(l += n, r += n + 1; l < r; l /= 2, r /= 2)
        {
            if (l&1) ra += seg[l++];
		    if (r&1) rb += seg[--r];
        }
        return ra+rb;
    }
 
};
 
 
 
ll e, q;
 
int main ()
{
    _fake();
    cin>>e>>q;
    vector<ll> arr(e+1);
    for(int i=1; i<=e ;i++)
        cin>>arr[i];
    Segtree seg;
    seg.init(arr);
   for(int i=0; i<q;i++)
   {
       ll w;
       cin>>w;
       if(w==1)
       {
           ll a ,b ,c;
           cin>>a>>b>>c;
           seg.update(a, c);  seg.update(b+1, -c); 
       }else
       {
           ll a;
           cin>>a;
           cout<<arr[a] + seg.query(1,a)<<'\n';
       }
   }
    
    
}    