﻿// counting_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> counting_sort(vector<int>& A, int k)
{
    vector<int> C(k+1,0);
    vector<int> B(A.size(),0);
    for (int num : A)
        C[num]++;//统计每个元素出现的次数
    for (int i = 1; i <= k; i++)
        C[i] += C[i - 1];//统计与某个元素相等或小于的元素出现次数
    for (int j = A.size() - 1; j >= 0; j--)
    {
        B[C[A[j]]-1] = A[j];//放置在相应位置
        C[A[j]]--;
    }
    return B;
}

int main()
{
    std::cout << "Hello World!\n";
    vector<int> test = {2,5,3,0,2,3,0,3};
    vector<int> res = counting_sort(test, 5);
    for (int num : res)
        cout << num << " ";
    cout << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
