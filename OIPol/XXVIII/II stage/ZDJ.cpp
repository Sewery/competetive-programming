#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define X first
#define Y second
#define  up_limit 100002
#define maxer 500002
#define INF 1000000007
#define ll long long


vector<int> graph[maxer]={};
vector<int> directed[maxer]={};
vector<int> in_edges[maxer]={};
vector<int> out_edges[maxer]={};

int visited[maxer]={};
int in[maxer]={};
int out[maxer]={};
int n,m;

 void direct_graph()
 {
     
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        visited[x]=1;
        for(auto w: graph[x])
        {
            if(visited[w])continue;
            out_edges[x].pb(w);
            in_edges[w].pb(x);
            directed[x].pb(w);
            if(in[w]==in_edges[w].size())    
                q.push(w);
        }
    }
    
 }

int topo[maxer]={};
bool topological_sorting()
{
    int p=0;
    for(int v=1; v<=n;v++)
    {
        if(in[v]==0)
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
       for(auto u : directed[v])
       {
           in[u]-=1;
           if(in[u]==0)
           {
               p++;
               topo[p]=u;
           }
       } 
    }

    return true;

}
int main()
{
    cin.tie(); ios_base::sync_with_stdio(0);
      
    cin>>n>>m;
    for(int i=1; i<=m;i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    } 
    vector<int> counter(n+1);
   
    if( (graph[1].size()==0 || graph[2].size()==0) && m>0 )
        goto bad;
    out[1]=graph[1].size(); in[2]=graph[2].size(); 
     for(int i=3; i<=n;i++)
         out[i]=in[i]=graph[i].size()/2; 
    direct_graph();
    int c;
    for(int i=3;i<=n;i++)
    {
        if(in_edges[i].size()!=out_edges[i].size())
            goto bad;
            
    }
  
    if(!topological_sorting())  goto bad;

    for(int i=1;i<=n;i++)
    {
        if(topo[i]>0)
          counter[topo[i]]=i;

    }
     c =*max_element(counter.begin(),counter.end()) +1;
    for(int i=1;i<=n;i++)
        if(counter[i]==0)
            counter[i]=c++;
    cout<<"TAK\n";
    for(int i=1;i<=n;i++)
        cout<<counter[i]<<" ";
    return 0;
    bad:
    cout<<"NIE";
    return 0;
}