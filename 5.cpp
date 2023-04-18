#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int N = 1e6 + 10;
int q[N];
void quick_sort(int q[], int l, int r)
{
    // 边界条件
    if (l >= r)
        return;
    // 确定分界点， >> 1 表示除2
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    // 调整区间
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    // 递归调整左区间
    quick_sort(q, l, j);
    // 递归调整右区间
    quick_sort(q, j + 1, r);
}
int main()
{
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        q[i] = rand() % n;
    }
    // for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    LARGE_INTEGER nFreq;

    LARGE_INTEGER nBeginTime;

    LARGE_INTEGER nEndTime;

    double tim;

    QueryPerformanceFrequency(&nFreq);

    QueryPerformanceCounter(&nBeginTime);
    quick_sort(q, 0, n - 1);
    QueryPerformanceCounter(&nEndTime);

    tim = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;

    printf("%f\n", tim);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    system("pause");
    return 0;
}
