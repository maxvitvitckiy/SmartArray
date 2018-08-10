#include "iostream"
#include "time.h"
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
		size = 5;
		
		srand(time(NULL));

		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
		}
	}
	SmartDoubleArray(int cap) 
	{
		srand(time(NULL));
		arr = new double[cap];
		capacity = cap;
		size = cap;
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
		}
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

	void Add(double value)   // вставить элемент со значением value в конец массива
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
			delete [] arr;
			arr = new double[capacity];
			for (int i = 0; i < size; i++)
			{
				arr[i] = newarr[i];
			}
			delete [] newarr;
		}
	}

	void Insert(double value, int index)   // вставить элемент со значением value после индекса index
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

			for (int i = 0; i < size; i++)
			{
				arr[i] = newarr[i];
			}
			delete[] newarr;
		}
	}

	void Remove(int index)  // удалить элемент с индексом index
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

	int Count(double value) // посчитать количество элементов со значением value
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value) count++;
		}
		return count;
	}
	
	int FindNext(double value, int index)  // найти след. значение value после индекса index
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

	void ShowArray() 
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	double &operator[](int j) // перегрузка []     
	{
		return arr[j];
	}

	~SmartDoubleArray() 
	{
		delete [] arr;
	}
};

bool IsEmpty(SmartDoubleArray arr)
{
	return arr.GetSize() == 0;
}

void Menu(SmartDoubleArray arr);

void main()
{
	SmartDoubleArray *My_Smart_Array = new SmartDoubleArray();
	Menu(*My_Smart_Array);

	system("Pause");
}



void Menu(SmartDoubleArray arr) 
{
	int ch;
	double value;
	int index;
	do {
		cout
			<< "1 - Add element" << endl
			<< "2 - Insert element after index" << endl
			<< "3 - Get element by index" << endl
			<< "4 - Get count of some element in the array" << endl
			<< "5 - Find next element" << endl
			<< "6 - Get size" << endl
			<< "7 - Get capacity" << endl
			<< "8 - Show array" << endl
			<< "9 - Check if array is empty" << endl
			<< "0 - Exit" << endl;
		cin >> ch;
		cout << endl;
		switch (ch)
		{
		case 1: 
			cout << "Value: ";
			cin >> value;
			arr.Add(value);
			break;
		case 2: 
			cout << "Value: ";
			cin >> value;
			cout << "Index: ";
			cin >> index;
			arr.Insert(value, index);
			break;
		case 3:
			cout << "Index: ";
			cin >> index;
			cout << arr[index] << endl;
			break;
		case 4:
			cout << "Value: ";
			cin >> value;
			cout << "Count of elements: " << arr.Count(value) << endl;
			break;
		case 5: 
			cout << "Value: ";
			cin >> value;
			cout << "Index: ";
			cin >> index;
			cout << "Next element index: " << arr.FindNext(value, index) << endl;
			break;
		case 6:
			cout << "Size: " <<arr.GetSize() << endl;
			break;
		case 7:
			cout << "Capacity: " << arr.GetCapacity() << endl;
			break;
		case 8: 
			cout << "Array: ";
			arr.ShowArray();
			break;
		case 9: 
			if (IsEmpty(arr) == true) cout << "Empty is empty." << endl;
			else cout << "Empty is not empty." << endl;
			break;
		}
		cout << endl;
	} while (ch != 0);
}

