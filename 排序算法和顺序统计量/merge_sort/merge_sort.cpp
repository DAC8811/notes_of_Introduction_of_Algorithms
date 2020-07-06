// merge_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& A, int p, int q, int r)
{
    int len1 = q - p + 1;
    int len2 = r - q;
    vector<int> L;
    vector<int> R;
    for (int i = p; i < p+len1; i++)
        L.push_back(A[i]);
    for (int i = q + 1; i <= r; i++)
        R.push_back(A[i]);
    L.push_back(INT_MAX);//手动加上底部，不需要每次操作判断是否到底
    R.push_back(INT_MAX);
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] > R[j])//如果某一边到底了，则为无穷大，一定放另外一边
        {
            A[k] = R[j];
            j++;
        }
        else
        {
            A[k] = L[i];
            i++;
        }
    }
}

void merge_sort(vector<int>& A,int p,int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    std::cout << "Hello World!\n";
    vector<int> test = {2,4,5,7,1,2,3,6};
    merge_sort(test, 0, test.size() - 1);
    for (int num : test)
        cout << num << " ";
    cout << endl;
}


