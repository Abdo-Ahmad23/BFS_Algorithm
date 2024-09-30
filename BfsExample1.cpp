/// حب الصحابة كلهم لي مذهبُ *** ومودة القربى بها أتوسلُ 
/// ولكلهم قدر وفضل ساطعُ *** لكنما الصديق منهم أفضلُ
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n,m;
vector<vector<int>>g;
bool vis[N];
queue<int>q;

void BFS(int src){
    memset(vis, false, sizeof vis);
    while(!q.empty())
        q.pop();
    
    q.push(src);
    int lvl=0;
    int size;
    while(!q.empty()){
        size=q.size();
        while(size-- !=0){
            int fr = q.front();
            q.pop();
            
            vis[fr] = true;

            for(int i = 0 ; i < g[fr].size() ; ++i)
                if(!vis[g[fr][i]])
                    q.push(g[fr][i]);
            
            
        }

        lvl++;
    }

}
int main(){
    cin>>n>>m;
    g.resize(n);
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int src = 0;
    BFS(src);

    return 0;
}