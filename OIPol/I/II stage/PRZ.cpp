#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define pii pair<ll,ll>
#define pb push_back
#define  X  first
#define  Y second
#define INF 1000000007
#define MAXN 100002

vector<int> out[MAXN]={};
vector<int> in[MAXN]={};
int out_c[MAXN]={};
int in_c[MAXN]={};
int val[MAXN]={};
int n;

int topo[MAXN]={};
//sprawdza czy jest acykliczny i sortuje topologicznie
bool topological_sorting()
{
    int p=0;
    for(int v=1; v<=n;v++)
    {
        if(in_c[v]==0)
        {
            p++;
            topo[p]=v;
        }
    }
    for(int i=1; i<=n;i++)
    {
       if(i>p)
        return false;
       int v=topo[i];
       for(auto u : out[v])
       {
           in_c[u]-=1;
           if(in_c[u]==0)
           {
               p++;
               topo[p]=u;
           }
       } 
    }

    return true;
}
//najkrótszy czas--- jednocześnie najdłuższa sciezka w grafie
ll max_after[MAXN]={};
ll max_to[MAXN]={};
ll time()
{
    ll sol =0;
    for(int i=1;i<=n;i++)
    {
        int v = topo[i];
        for(auto u : in[v])
            max_to[v]=max(max_to[v],max_to[u]);
         max_to[v]+=(ll)val[v];
        sol=max(sol,max_to[v]);
    }
    for(int i=n;i>=1;i--)
    {
        int v = topo[i];
        for(auto u: out[v])
        {
            max_after[v]=max(max_after[v],max_after[u]+(ll)val[u]);
        }
    }
    return sol;
}

int q;
int main()
{
    cin.tie(0);ios_base::sync_with_stdio(0);
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
        int a;cin>>a;
        in_c[i]=a;
        for(int j=0;j<a;j++)
        {
            int k; cin>>k;
            in[i].pb(k);
            out[k].pb(i);
            out_c[k]++;

        }

    }
    cin>>q;
    if(topological_sorting()==false){cout<<"CYKL"; return 0;}
    ll sol =time();
    cout<< sol<<"\n";
    for(int i=0; i<q;i++)
    {
        int a,d; cin>>a>>d;
       
        if( (sol-max_to[a]-max_after[a] )<d)    
            cout<<"TAK\n";
        else 
            cout<<"NIE\n";    
    }
    return 0;
}