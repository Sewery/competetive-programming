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
 
void _fake(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
         
}
 
 
int grid[7][7];
int number =0;
string path;
const int steps =48;
bool helper(int i ,int j)
{
    return i>-1&&i<7&&j>-1&&j<7&&!grid[i][j];
}
void find( int row, int col,  int co)
{
    
    if(co==steps &&row == 6&& col == 0  )
    {
        number++;
        return;
    }
    if(row == 6 && col == 0 )
        return;
    grid[row][col]=1;
    char c = path[co];
    if(c=='U'  || c=='?')
    {
            if(helper(row-1,col) && !(  !helper(row-2,col) && helper(row-1,col-1) && helper(row-1,col+1)))
                find(row-1,col,co+1);
    }
      
    if(c=='D' || c=='?')  
    {
            if(helper(row+1,col) && !(  !helper(row+2,col) && helper(row+1,col-1) && helper(row+1,col+1)))
                find(row+1,col,co+1);
    }
    
    if(c=='L' || c=='?')
    {
            if(helper(row,col-1) &&!(!helper(row,col-2) &&helper(row+1,col-1) && helper(row-1,col-1)))
                find(row,col-1,co+1);       
    }
      
    if(c=='R' || c=='?' )
    {
            if(helper(row,col+1)&& !( !helper(row,col+2) && helper(row-1,col+1) && helper(row+1,col+1)))
                find(row,col+1,co+1);
   
    }
    grid[row][col]=0; 
}
 
int main ()
{
    _fake();
    cin>>path;
    find(0,0,0);
    cout<<number;
   
 
}