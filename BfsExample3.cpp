/// حب الصحابة كلهم لي مذهبُ *** ومودة القربى بها أتوسلُ 
/// ولكلهم قدر وفضل ساطعُ *** لكنما الصديق منهم أفضلُ
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
int t,n,m;
bool vis[N],prime[N];
queue<int>q;
vector<int>primes;
vector<vector<int>>g;
void seive(){
    memset(prime,true,sizeof prime);
    prime[0]=prime[1]=false;
    for(int i=2;i*i<N;i++)
        if(prime[i])
            for(int j=i*i;j<N;j+=i)
                prime[j]=false;
    for(int i=1000;i<N;i++)
        if(prime[i])
            primes.push_back(i);
}

int diff(int a,int b){
    int d=0;
    while(a){
        int aa=a%10;
        int bb=b%10;
        if(aa!=bb)
            d++;
    }
    return d;
}
void buildGraph(){
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            if(diff(primes[i],primes[j])==1)
            {
                g[primes[i]].push_back(primes[j]);
                g[primes[j]].push_back(primes[i]);
            }
        }
    }
}
int BFS(int n,int m){
    memset(vis, false, sizeof vis);
    while(!q.empty())
        q.pop();
    
    q.push(n);
    int lvl=0;
    int size;
    while(!q.empty()){
        size=q.size();
        while(size-- != 0){
            int fr = q.front();
            q.pop();
            
            vis[fr] = true;
            if(fr == m)
                return lvl;
            
            for(int i=0;i<g[fr].size();i++)
                if(!vis[g[fr][i]])
                    q.push(g[fr][i]);
        }

        lvl++;
    }
    return lvl;

}
int main(){
    seive();
    g.resize(N);
    buildGraph();
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout<< BFS(n,m);
    }
    return 0;
}