#include <iostream>
using namespace std;
const int N = 10;
int n;
int path[N]; //收集一条路径，每次都会被覆盖
bool st[N];  //判断某个数字是否被用过
void DFS(int u)
{ // 0,1,2三个数，要等与n，即3才结束，因为u等于2之后，进入dfs(u+1)，才会去比较次数输出
    if (u == n)
    { // u表示使用的数字数加一，因为u等于2之后，进入dfs(u+1)，才会去比较次数输出
        for (int i = 0; i < n; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    { //因为数据是1---n
        if (!st[i])
        { //没有被用过
            path[u] = i;
            st[i] = true;
            DFS(u + 1);
            // path[u]=0;可以不用回溯，因为下面它还会被覆盖
            st[i] = false; //回溯
        }
    }
}
int main()
{
    cin >> n;
    DFS(0);//从第零层开始 
    system("pause");
    return 0;
}