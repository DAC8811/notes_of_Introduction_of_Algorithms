// quick_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

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

void quick_sort(vector<int>& A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}



int main()
{
    std::cout << "Hello World!\n";
    vector<int> test = { 2,8,7,1,3,5,6,4 };
    quick_sort(test,0,test.size()-1);
    for (int num : test)
        cout << num << " ";
    cout << endl;
}

