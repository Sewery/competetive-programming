#include <bits/stdc++.h>
#include "ckollib.h"

using namespace std;
#define ll long long 
#define pii pair<ll,ll>
#define pb push_back
#define  X  first
#define  Y second
#define INF 1000000007
#define MAXN 100002

int arr[32]={};
int roz[32]={};
int p1=0,p2=0;
int p[3]={};
void rozklad(int k)
{
    for(int i=31;i>=0;i--)
    {
       if(k&(1<<i))
        arr[i]+=1;
    }
}
void rozwiaz()
{
    int dzielnik = max(p[1],p[2]);
    if(p[2]==0 || p[2]>p[1] )
    {
        odpowiedz(p1); return;
    }
    if(p[2]<p[1])
    {
        odpowiedz(p2); return;
    }
    int sol=0;
    for(int i=31;i>=0;i--)
    {
       if(arr[i]%dzielnik>0)
       {
            sol+=roz[i];
       }    
    }
    odpowiedz(sol);
}
void preprocess()
{
    roz[0]=1;
    for(int i=1;i<=31;i++)
        roz[i]= 2*roz[i-1];
}
int p2_ind;
int main()
{
    cin.tie(0);ios_base::sync_with_stdio(0);
    preprocess();
    int it=1;
    while(1)
    {
        int k= karta();
        if(k==0)
        {
            rozwiaz();
            return 0;
        }    
        if(it==1)
            p1=k;
        if(it>=2 && p1!=k && p2==0)  
        {
              p2=k; p2_ind=it;
             // cout<<p2;
        }
          
        if(p1==k)
            p[1]++;
        if(p2==k)
            p[2]++;     
         rozklad(k);      
        it++;
    }
   
    return 0;
}