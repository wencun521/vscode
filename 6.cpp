#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N = 1e7 + 10;
int n;
int a[N];
void insert_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;

        while (j >= 0 && x < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
int main()
{
    cin>>n;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
    // for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    LARGE_INTEGER nFreq;

    LARGE_INTEGER nBeginTime;

    LARGE_INTEGER nEndTime;

    double tim;

    QueryPerformanceFrequency(&nFreq);

    QueryPerformanceCounter(&nBeginTime);
    insert_sort(a, n);
    QueryPerformanceCounter(&nEndTime);

    tim = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;

    printf("%f\n", tim);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    system("pause");
    return 0;
}