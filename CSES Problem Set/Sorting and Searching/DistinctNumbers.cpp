#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
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
#define PI (3.141592654)
ll mod= pow(10,9)+7;
const int MAXN = 1000 * 1 + 10, INF = 1e9 + 10;
 
 
  void _fake(){
          ios_base::sync_with_stdio(false);
           cin.tie(NULL);
         
        }
int main ()
{
    _fake();
   	int a;
	cin>>a;
	set<int> s;
    while(cin>>a)
        s.insert(a);
    cout<<s.size();
   