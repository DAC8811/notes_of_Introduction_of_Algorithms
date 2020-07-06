#pragma once
#include <iostream>
#include <vector>

#define LEFT(i) i*2;
#define RIGHT(i) i*2+1;
#define PARENT(i) i/2;

using namespace std;
//这个是最大优先队列
//模板类一定要记得声明和函数体必须在一个文件里！！！
template <typename T>
class heap_priority_queue {
private:
	vector<T> data;
	void MAX_HEAPIFY(int i);
	void BUILD_MAX_HEAP();
public:
	heap_priority_queue() {}
	heap_priority_queue(vector<T>);
	void insert(T);
	T maxium();
	T extract();
	void increase_key(int x, T k);
};




template <typename T>
heap_priority_queue<T>::heap_priority_queue(vector<T> v)
{
    data = v;
    BUILD_MAX_HEAP();
}

template<typename T>
void heap_priority_queue<T>::MAX_HEAPIFY(int i)
{
    T left = LEFT(i);
    T right = RIGHT(i);
    int max = i;
    if (left < data.size() && data[left] > data[i])
        max = left;
    if (right < data.size() && data[right] > data[max])
        max = right;
    if (max != i)
    {
        T temp = data[i];
        data[i] = data[max];
        data[max] = temp;
        MAX_HEAPIFY(max);
    }
}

template<typename T>
void heap_priority_queue<T>::BUILD_MAX_HEAP()
{
    int last = PARENT(data.size() - 1);
    for (int i = last; i >= 0; i--)
        MAX_HEAPIFY(i);
}

template<typename T>
void heap_priority_queue<T>::insert(T a)
{
    data.insert(data.begin(), a);
    MAX_HEAPIFY(0);
}

template<typename T>
T heap_priority_queue<T>::maxium()
{
    if (!data.empty())
        return data[0];
    else
        return 0;
}

template<typename T>
T heap_priority_queue<T>::extract()
{
    if (!data.empty())
    {
        T res = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        MAX_HEAPIFY(0);
        return res;
    }
    else
        return 0;
}

template<typename T>
void heap_priority_queue<T>::increase_key(int x, T k)
{
    if (x >= data.size() || data[x] >= k)
        return;
    else
    {
        data[x] = k;
        int parent = PARENT(x);
        while (x > 0 && data[parent] < data[x])
        {
            T temp = data[parent];
            data[parent] = data[x];
            data[x] = temp;
            x = parent;
            parent = PARENT(x);
        }
    }

}