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
#define PI (3.14159)
ll moder= pow(10,9)+7;
const int MAXN = 1000 * 1 + 10, INF = 1e9 + 10;
 
 
  void _fake(){
          ios_base::sync_with_stdio(false);
           cin.tie(NULL);
         
        }
ll get_digit_from_number(ll num, ll k)
{
    ll o =num;
    int digits=1;
    while(o/10)
    {
        o/=10;
        digits++;
    }
    while(k<digits)
    {
        num/=10;
        digits--;
    }
    ll p = (num/10) *10;
    return num-p;
}
ll power(ll a , ll v)
{
	int x=a;
	for(ll i =1;i<v;i++)
	{
		a*=x;
	}
	return v==0?1:a;
}
int main ()
{
 
_fake();
    int a;
   cin>>a;
   for(int i=0; i< a;i++)
   {
       ll x;
       cin>>x;
       ll ze =0;
       ll last=1;
       ll mod=0;
       while(true)
       {
           if(x>9 && x>(last+(9*power(10,ze)*(ze+1)))){
               ze++;
               last+= 9*power(10,ze-1)*ze;
           }else{
               mod= (x-last)%(ze+1);
               ll c = ((x-last)/(ze+1))+power(10,ze);
            
                cout<<get_digit_from_number(c,mod+1)<<'\n';
                break;
           }
               
 
       }
   }
   
  
}