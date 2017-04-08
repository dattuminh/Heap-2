#ifndef __HEAP_H__
#define __HEAP_H__
#include<assert.h>

#include <vector>
template <class T>
class Heap
{
public:
	Heap()
	{}

	Heap(T* a,size_t size)
	{
		size_t index = 0;
		while (index < size)
		{
			_a.push_back(a[index]);
			index++;
		}

		for (int i = (_a.size() - 2) / 2; i >= 0; i--)
			_AdjustDown(i);
	}

	void push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() -1);
	}

	void pop()
	{
		size_t size = _a.size();
		assert(size > 0);
		swap(_a[0], _a[size - 1]);
		_a.pop_back();
		size = _a.size();
		_AdjustDown(0);
	}

	size_t top()
	{
		assert(!_a.empty());

		return _a[0];
	}

	bool empty()
	{
		return _a.size() == 0;
	}

	size_t Size()
	{
		return _a.size();
	}

	void Print()
	{
		for (int i = 0; i < _a.size(); i++)
		{
			cout << _a[i] << " ";
		}
		cout << endl;
	}

protected:
	// rearrange the heap while adding new child from smallest to biggest
	void _AdjustUp(int child)
	{
		int parent = (child - 1) / 2;

		while (parent >= 0)
		{
			//找出孩子中的最大孩子
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}

	}
	// rearrange the heap while adding new child from biggest to smallest
	void _AdjustDown(size_t parent)
	{
		size_t child = 2 * parent + 1;

		while (child < _a.size())
		{
			//找出孩子中的最大孩子
			if (child + 1 < _a.size() && _a[child] < _a[child + 1])
			{
				++child;
			}
			//把
			if (_a[parent] < _a[child])
			{
				swap(_a[parent], _a[child]);
				parent = child;
				child = child * 2 + 1;
			}
			else
			{
				break;
			}
		}

	}
protected:
	vector<T> _a;
};



#endif //__HEAP_H__
