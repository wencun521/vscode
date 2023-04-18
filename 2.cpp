#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void dfs(vector<int> &nums, int startIndex)
{
    result.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
    if (startIndex >= nums.size())
    { // 终止条件可以不加
        return;
    }
    for (int i = startIndex; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();
    }
}
int main()
{
    dfs()
}