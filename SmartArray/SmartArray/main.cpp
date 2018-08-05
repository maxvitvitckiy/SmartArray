#include "iostream"
using namespace std;

class SmartDoubleArray 
{
private:
	double *arr;
	int capacity;
	int size;
public:
	SmartDoubleArray()
	{
		arr = new double[5];
		capacity = 5;
		size = 0;
		
	}
	SmartDoubleArray(int cap) 
	{
		arr = new double[cap];
		capacity = cap;
		size = 0;
	}
	SmartDoubleArray(double *arr)
	{
		int size = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arr[i];
		}
		this->size = size;
		this->capacity = size;
	}

	SmartDoubleArray(double *arr, int cap) 
	{
		int size = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arr[i];
		}
		this->size = size;
		this->capacity = cap;
	}

	void Add(double value) 
	{
		if (size < capacity) 
		{
			size++;
			arr[size - 1] = value;
		}
		else
		{
			capacity++;
			double *newarr = new double[capacity];
			for (int i = 0; i < size; i++)
			{
				newarr[i] = arr[i];
			}
			newarr[size] = value;
			size++;
			delete[]arr;
			arr = new double[capacity];
			arr = newarr;
			delete[] newarr;
		}
	}

	void Insert(double value, int index)
	{
		if (index >= size - 1)
		{
			cout << "Wrong index.";
			return;
		}
		if (size < capacity)
		{
			size++;
			double temp;
			temp = arr[index + 1];
			arr[index + 1] = value;
			double temp2;
			for (int i = index + 2; i < size; i++)
			{
				temp2 = arr[i];
				arr[i] = temp;
				temp = temp2;
			}
		}
		else
		{
			capacity++;
			size++;
			double *newarr = new double[capacity];
			for (int i = 0; i <= index; i++)
			{
				newarr[i] = arr[i];
			}
			newarr[index + 1] = value;
			for (int i = index + 2; i < size; i++)
			{
				newarr[i] = arr[i - 1];
			}
			delete[]arr;
			arr = new double[capacity];
			arr = newarr;
		}
	}

	void Remove(int index) 
	{
		for (int i = index; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}

	double GetAt(int index) 
	{
		return arr[index];
	}

	int Count(double value) 
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value) count++;
		}
		return count;
	}

	int FindNext(double value, int index)
	{
		for (int i = index + 1; i < size; i++)
		{
			if (arr[i] == value) return i;
		}
		return -1;
	}

	int GetSize() 
	{
		return size;
	}

	int GetCapacity()
	{
		return capacity;
	}

	// []
	
	// predicate

	~SmartDoubleArray() 
	{
		delete [] arr;
	}
};

void main()
{

}