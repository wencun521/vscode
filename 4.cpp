// #include <algorithm>
// #include <iostream>
// #include <vector>

// using namespace std;

// int n;

// void get_divisors(int n)
// {
//     vector<int> res;

//     for (int i = 1; i <= n / i; i++) {
//         if (n % i == 0) {
//             res.push_back(i);

//             if (i != n / i) {  // 避免 i==n/i, 重复放入 （n是完全平方数
//                 res.push_back(n / i);
//             }
//         }
//     }

//     sort(res.begin(), res.end());
//     for (auto item : res) {
//         cout << item << " ";
//     }
//     puts("");
// }

// int main()
// {
//     cin >> n;
//     while (n--) {
//         int x;
//         cin >> x;
//         get_divisors(x);
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n;
vector <int> get_divisorts(int n){ //求约数函数
    vector <int> res; //用了存n的所有约数
    for(int i = 1;i <= n / i;i ++){ //因为n的约数个数小于n / i
        if(n % i == 0){ //如果可以整除
            res.push_back(i); //把i压入vector
            if(i != n / i) res.push_back(n / i); //如果n不是i的平方，那n / i就是一个新的约数，把n / i压入vector（比如说6 * 6 = 36，那么只需要压一个6就可以了）
        }
    }
    sort(res.begin(),res.end()); //因为题目要求约数要从小到大排序，所以在最后需要排一次序
    return res; //返回这个数的所有约数
}
int main(){
    scanf("%d",&n); //需要求约数的数的个数
    while(n --){
        int x; //需要求约数的数
        scanf("%d",&x); //读入
        auto res = get_divisorts(x);
        //大概的讲一下auto，用来定义变量时，它表示让计算机来猜这个数的类型，在这里就表示vector <int>
        for(auto i : res) printf("%d ",i);
        //这里的for循环表示遍历res数组，i是遍历到的哪一位的数字
        printf("\n"); //记得要输出回车哦
    }
    return 0;
}