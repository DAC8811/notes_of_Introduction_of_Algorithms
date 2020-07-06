// heap_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

#define LEFT(i) i*2;
#define RIGHT(i) i*2+1;
#define PARENT(i) i/2;

using namespace std;


void MAX_HEAPIFY(vector<int>& A, int i, int heap_size)
{
    int left = LEFT(i);
    int right = RIGHT(i);
    int max = i;
    if (left < heap_size && A[left]>A[i])
        max = left;
    if (right < heap_size && A[right] > A[max])
        max = right;
    if (max != i)
    {
        int temp = A[i];
        A[i] = A[max];
        A[max] = temp;
        MAX_HEAPIFY(A, max, heap_size);
    }
}

void BUILD_MAX_HEAP(vector<int>& A)
{
    int last = PARENT(A.size() - 1);
    for (int i = last; i >= 0; i--)
        MAX_HEAPIFY(A, i, A.size());
}

int main()
{
    vector<int> A = { 16,14,10,8,7,9,3,2,4,1 };
    BUILD_MAX_HEAP(A);
    int heap_size = A.size();
    for (int i = A.size() - 1; i >= 1; i--)
    {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        heap_size--;
        MAX_HEAPIFY(A, 0, heap_size);
    }
    for (int num : A)
        cout << " " << num;
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
