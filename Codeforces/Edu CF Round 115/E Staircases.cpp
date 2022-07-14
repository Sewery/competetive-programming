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
    #define moder 1000000007; const int MAXN = 2e5  + 20, INF = 1e9 + 10; const ll L_INF = LLONG_MAX /2; const int NUM = 2502; 
    void _fake(){     ios_base::sync_with_stdio(false);     cin.tie(NULL);     cout.tie(NULL);     }
     
     
    int main () 
    {     
        int n,m,q;     
        _fake();     
        cin>>n>>m>>q;
        int ans=0;
        int grid[n][m]={1};
        for(int i=0; i<n;i++)
        {
            for(int j= 0; j <m;j++)
            {
                grid[i][j]=1;
                if(i==0)
                {
                    for(int k =1; ;k++)
                    {
                        int x = i + k/2;
                        int y=  j + (k+1)/2;
                        if(x==n || y==m)break;
                        ans+=k;
                    }
                }
                if(j==0)
                {
                    for(int k =1; ;k++)
                    {
                        int x = i + (k+1)/2;
                        int y=  j + k/2;
                        if(x==n || y==m)break;
                        ans+=k;
                    }
                }
            }
        }     
        ans+=n*m;
        for(int r=0; r<q;r++)
        {
     
            int var=0;
            int i,j;  cin>>i>>j;i--;j--;
            int a =1, b=1;
            while(1)
            {
                int x= i + (a+0)/2;
                int y= j+ (a+1)/2;
                if(x==n || y==m || grid[x][y]==0)break;
                a++;
                
            }
             while(1)
            {
                int x= i - (b+1)/2;
                int y= j -  (b+0)/2;
                if(x<0 || y<0 || grid[x][y]==0)break;
                b++;
                
            }
            var+=a*b; a=b=1;
             while(1)
            {
               int x= i + (a+1)/2;
                int y= j+ (a+0)/2;
                if(x==n || y==m || grid[x][y]==0)break;
                a++;
                
            }
     
             while(1)
            {
                int x= i - (b+0)/2;
                int y= j -  (b+1)/2;
                if(x<0 || y<0 || grid[x][y]==0)break;
                b++;
                
            }
            var+=a*b; a=b=1;
            ans+=grid[i][j];
            if(grid[i][j]==1){
                ans-=var;
            }else ans+=var;
            grid[i][j]^=1;
            ans -= grid[i][j];
            cout<<ans<<"\n";
     
     
        
        }
    }