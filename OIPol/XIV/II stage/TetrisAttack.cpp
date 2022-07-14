#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define X first
#define Y second


int n;
int vis[50002]={}; 

deque<int> stos1;//stos niewizytowanych elementow
vector<int> changes;

void solve()
{
    deque<int> stos2;//stos nie powtarzajacych sie kolorow
    while(!stos1.empty())
    {
        int f= stos1.front();stos1.pop_front();
        if(vis[f]==0)
        {
            stos2.push_front(f);vis[f]++;
        }else
        {
            int w =stos2.size();
            
            int p = stos2.front(); stos2.pop_front();vis[p]--;
            if(p!=f)
            {//inwersja

                changes.push_back(w);
                stos1.push_front(p);stos1.push_front(f);
            }
           
           
            
        }
    }
    cout<<changes.size()<<"\n";
    for(auto h: changes)cout<<h<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for(int i=1; i<=2*n;i++)
    {
        int w;
        cin>>w;
        stos1.push_back(w);
    }
    solve();
    return 0;
}