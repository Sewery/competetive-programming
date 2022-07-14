#include <bits/stdc++.h>                                                                                                            
                                                                               
using namespace std;                                                            
#define ll long long                                                            
#define pii pair<ll,ll>                                                         
#define pb push_back                                                            
#define  X  first                                                               
#define  Y second                                                               
#define INF 1000000007                                                          
#define MAXN 100002                                                             
int n;                                                                          
                                                                                

bool warunek(double k , double a, double b ,double c, double d)                 
{                                                                               
      if((int)ceil(a/k)<=(int)floor(b/k) && (int)ceil(c/k)<=(int)floor(d/k))
          return true;                                                                    
      return 0;                                                                   
}                                                                               
void sol(int a, int b, int c, int d)                                            
{                                                                               
    int m =  floor(sqrt(  max(b,d)));                                           
    int roz=1;                                                                  
    for(int k=2;k<=m;k++)                                                       
    {                                                                           
        if(warunek(k,a,b,c,d))                                                  
            roz=k;                                                              
    }                                                                           
    for(int l =1; l<=m;l++)                                                     
    {                                                                           
        int k1=b/l, k2=d/l;                                                     
          if(warunek(k1,a,b,c,d))                                               
            roz=max(roz,k1);                                                    
        if(warunek(k2,a,b,c,d))                                                 
            roz=max(roz,k2);                                                    
                                                                                
    }                                                                           
    cout<<roz<<'\n';                                                            
}                                                                               
int main()                                                                      
{                                                                               
    cin.tie(0);ios_base::sync_with_stdio(0);                                    
    cin>>n;                                                                     
    for(int i=0; i<n;i++)                                                       
    {                                                                           
        int a, b, c,d;                                                          
        cin>>a>>b>>c>>d;                                                        
        sol(a,b,c,d);                                                           
    }                                                                           
                                                                                
                                                                                
    return 0;                                                                   
}         