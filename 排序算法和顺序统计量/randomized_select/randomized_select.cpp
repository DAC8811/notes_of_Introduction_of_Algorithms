// randomized_select.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
void exchange(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& A, int p, int r)
{
    if (p == r) return p;
    int i = p - 1;//记录左边数组的边界位置
    int mid = A[r];
    for (int j = p; j < r; j++)
    {
        if (A[j] < mid)
        {
            i++;
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    i++;
    int temp = A[i];
    A[i] = mid;
    A[r] = temp;
    return i;
}

int randomized_partition(vector<int>& A, int p, int r)
{
    int i = rand() % (r - p + 1) + p;
    exchange(A[r], A[i]);
    return partition(A, p, r);
}

int randomized_select(vector<int>& A,int p,int r,int i)
{
    if (p == r)
        return A[p];
    int q = randomized_partition(A, p, r);
    int k = q - p + 1;
    if (k == i)
        return A[q];
    else if (k < i)
        return randomized_select(A, q + 1, r, i - k);
    else
        return randomized_select(A, p, q - 1, i);
}

int main()
{
    std::cout << "Hello World!\n";
    srand((int)time(0));
    vector<int> test = { 10,9,8,7,6,5,4,3,2,1 };
    cout << randomized_select(test, 0, test.size() - 1, 4) << endl;
}

