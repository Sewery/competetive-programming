#include <bits/stdc++.h>
 
using namespace std;
#define int long long int 
 
#define Matrix vector<vector<int>>
const int mod = pow(10,9) + 7;
 
Matrix mul(Matrix A, Matrix B)
{
    Matrix W={{0,0},{0,0}};
  
    W[0][0]= (A[0][0] *B[0][0]) % mod  +(A[0][1]*B[1][0]) % mod ;
    W[0][1]= (A[0][0]* B[0][1])% mod  +(A[0][1]*B[1][1])% mod ;
    W[1][0]=(A[1][0] *B[0][0])% mod  +(A[1][1]*B[1][0])% mod ;
    W[1][1]=(A[1][0] *B[0][1]) % mod +(A[1][1]*B[1][1])% mod ;
    return W;
}
 
 
 
int find_pth_power( int n)
{
    Matrix arr={{1,1},{1,0}};
    Matrix A={{1,0},{0,1}};
    
    while(n)
    {
        if(n%2!=0)
        {
            A=mul(A,arr);
        }
        arr=mul(arr,arr);
        n/=2;
    }
    int a= A[0][0]* 1% mod ;
    return a;
}
    
    
    
signed main()
{
    int T;
    cin>>T;
 
    T==0?cout<<0:cout<<find_pth_power(T-1)<<"\n";
   
}