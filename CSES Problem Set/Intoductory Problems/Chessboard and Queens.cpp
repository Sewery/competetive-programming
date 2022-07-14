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
#define PI (3.141592654)
ll moder= pow(10,9)+7;
const int MAXN = 1000 * 1 + 10, INF = 1e9 + 10;
 
 
 
int col[8];
int diag1[15];
int diag2[15];
int checker[8][8];
int n=8;
int counter=0;
void _fake(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
         
}
void solve(int row)
{
    if(row==n)
    {
        counter++;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(col[i] || diag1[i+row] || diag2[i+n-row-1] || checker[row][i])
            continue;
        col[i] = diag1[i+row] = diag2[i+n-row-1] =1;
        solve(row +1);
        col[i] = diag1[i+row] = diag2[i+n-row-1] =0;
    }
}
 
int main ()
{
    _fake();
    char a;
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
            cin>>a;
            a=='.'?checker[i][j]=0:checker[i][j]=1;
        }
    }
    solve(0);
    cout<<counter;
   
 
}