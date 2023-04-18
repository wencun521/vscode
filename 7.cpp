#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int g[N][N];//邻接矩阵
int dist[N];//每个点到原点的距离
bool st[N];
int n,m;
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;//原点到自身的距离是零。
    for(int i=0;i<n;i++)      //有n个点所以要进行n次 迭代
    {
        int t=-1;       //t存储当前访问的点

        for(int j=1;j<=n;j++)   //这里的j代表的是从1号点开始
             if(!st[j]&&(t==-1||dist[t]>dist[j])){//找到距离最近的点
                t=j;
            }

        st[t]=true;   

        for(int i =1;i<=n;i++){
                if(!st[i]){
                    dist[i]=min(dist[i],dist[t]+g[t][i]);
                }
            }
    }

    if(dist[n]==0x3f3f3f3f){
        return -1;
    }
    return dist[n];
}
int main()
{
  
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i = 0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=min(g[x][y],z);
    }
    cout<<dijkstra();
}