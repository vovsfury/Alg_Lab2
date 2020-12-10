#ifndef sort_h
#define sort_h
#include <iostream>
#include <stdexcept>
#include <random>
#include <chrono>
using namespace std;
class randomizer
{
public:
	int random_int(int min, int max) //returns random int element
	{
		random_device rd;   // non-deterministic generator
		default_random_engine gen(rd()); 
		uniform_int_distribution<int> dist(min, max);
		return dist(gen);
	}
};

class sort_int :public randomizer
{
	int* A;
	size_t size;

public:

	sort_int(size_t Size = 10) 
	{
		if (Size == 0)
			throw out_of_range("Error in sort_int function: size = 0\n");
		A = new int[Size];
		size = Size;
		for (int i = 0; i < size; i++)
			A[i] = NULL;
	}

	int sort_check() // checks if array is sorted
	{
		for (int i = 0; i < (size - 1); i++)
		{
			if (A[i] > A[i + 1])
				return 0;
		}
		return 1;
	}

	void set_int_array_element(int element, size_t index) // sets a value for an element with an index
	{
		if (index >= size)
			throw out_of_range("Error in set_int_array_element function: index >= size\n");
		A[index] = element;
	}

	int get_int_array_element(size_t index) // returns element with an index
	{
		if (index >= size)
			throw out_of_range("Error in get_int_array_element function: index >= size\n");
		return A[index];
	}

	size_t get_size() // returns array size
	{ 
		return size; 
	}
	void randomize(int min = -100, int max = 100)  // randomizes value from a specific range to the array
	{
		if (min >= max)
			throw invalid_argument("Error randomize function: min > max\n");
		for (int i = 0; i < size; i++)
		{
			A[i] = random_int(min, max);
			//cout << A[i] << "|";
		}
	} 

	double bubble_sort() // standart bubble sort, returns working time of sort
	{
		if (sort_check())
			throw runtime_error("Error in bubble_sort function: array is already sorted\n");
		chrono::system_clock::time_point start = chrono::system_clock::now();
		//auto begin = std::chrono::steady_clock::now();
		int temp;
		for (int i = 0; i < size - 1; i++) 
		{
			for (int j = 0; j < size - i - 1; j++) 
			{
				if (A[j] > A[j + 1]) 
				{
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}
		//auto end = std::chrono::steady_clock::now();
		//auto elapsed_ms = std::chrono::duration_cast<std::chrono::seconds>(end - begin);

		chrono::system_clock::time_point end = chrono::system_clock::now();
		chrono::duration<double> sec = end - start;
		return sec.count();

		// prints sorted array to console 
		//for (int i = 0; i < size; i++) {
		//	cout << A[i] << " ";
		//}
	}

	void qs(int first, int last)	// quick sort recursive
	{
		int pivot = last;
		int temp;
		for (int i = first; i < pivot; i++)
		{
			if (A[i] > A[pivot])
			{
				for (int j = i; j < pivot; j++)
				{
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
				pivot -= 1;
				i -= 1;
			}
		}
		if (first < (pivot - 1))
			qs(first, pivot - 1);
		if ((pivot + 1) < last)
			qs(pivot + 1, last);
	}
	double quick_sort()	// standart quick sort, returns working time of sort
	{
		if (sort_check())
			throw runtime_error("Error in quick_sort function: array is already sorted\n");
		int first = 0, last = size - 1;
		chrono::system_clock::time_point start = chrono::system_clock::now();
		//auto begin = std::chrono::steady_clock::now();

		qs(first, last);

		//auto end = std::chrono::steady_clock::now();
		//auto elapsed_ms = std::chrono::duration_cast<std::chrono::seconds>(end - begin);

		chrono::system_clock::time_point end = chrono::system_clock::now();
		chrono::duration<double> sec = end - start;
		return sec.count();

		// prints sorted array to console
		//for (int i = 0; i < size; i++)
		//{
		//	cout << A[i] << " ";
		//}
	}

	void bogo_sort()	// standart bogo sort
	{
		if (sort_check())
			throw runtime_error("Error in bogo_sort function: array is already sorted\n");
		while (!sort_check())
		{
			for (int i = 0; i < size; i++)
			swap(A[i], A[random_int(0, size - 1)]);
		}

		// prints sorted array to console
		//for (int i = 0; i < size; i++) 
		//{
		//		cout << A[i] << " ";
		//}
	}

	int binary_search(int key)	// standart binary search, returns index of the required element
	{
		if (!sort_check())
			throw runtime_error("Error in binary_search function: array is'n sorted\n");
		if (key<A[0] || key>A[size - 1])
			throw runtime_error("Error in binary_search function: doesn't contain entered element\n");
		int left = 0, right = size - 1, mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (key < A[mid]) right = mid - 1;
			else if (key > A[mid]) left = mid + 1;
			else return mid;
		}
		throw runtime_error("Error in binary_search function: doesn't contain entered element\n");
		return -1;
	}

	~sort_int()
	{
		delete[] A;
	}
};

class sort_char :public randomizer
{
	char* A;
	size_t size;

public:

	sort_char(size_t Size = 10)
	{
		if (Size == 0)
			throw out_of_range("Error in sort_char function: size = 0\n");
		A = new char[Size];
		size = Size;
		for (int i = 0; i < size; i++)
			A[i] = '?';
	}

	int sort_check()
	{
		for (int i = 0; i < (size - 1); i++)
		{
			if (A[i] > A[i + 1])
				return 0;
		}
		return 1;
	}

	void set_char_array_element(int element, size_t index)
	{
		if (index >= size)
			throw out_of_range("Error in set_char_array_element function: index >= size\n");

		A[index] = element;
	}

	char get_char_array_element(size_t index)
	{
		if (index >= size)
			throw out_of_range("Error in get_char_array_element function: index >= size\n");
		return A[index];
	}

	size_t get_size()
	{
		return size;
	}
	void randomize(int min = 65, int max = 90) 
	{
		if (min >= max)
			throw invalid_argument("Error randomize function: min > max\n");
		if (min < 65 || max > 90)
			throw invalid_argument("Error randomize function: min/max doesn't belong to 65...90 interval\n");
		for (int i = 0; i < size; i++)
		{
			A[i] = random_int(min, max);
			//cout << A[i] << "|";
		}
	}

	void counting_sort()	// standart counting sort
	{
		if (sort_check())
			throw runtime_error("Error in counting_sort function: array is already sorted\n");
		char* B = new char[size];
		size_t n = size;
		int k = 0;
		for (int i = 1; i <= n; i++)
		{
			if (A[i] > k)
			{
				k = A[i];
			}
		}

		char* C = new char[k];

		for (int i = 0; i < k + 1; i++)
		{
			C[i] = 0;
		}
		for (int j = 0; j <= n; j++)
		{
			C[A[j]]++;
		}
		for (int i = 1; i <= k; i++)
		{
			C[i] += C[i - 1];
		}
		for (int j = n; j >= 0; j--)
		{
			B[C[A[j]]] = A[j];
			C[A[j]] = C[A[j]] - 1;
		}
		for (int i = 0; i <= n-1; i++)
		{
			A[i] = B[i+1];
			//cout << A[i] << " ";
		}
	}

	~sort_char()
	{
		delete[] A;
	}
};

#endif