#include <iostream>
#include "sort.h"
using namespace std;

void sort_stopwatch()
{
	sort_int* new_array;
	int i;
	double quick_sort_time, quick_sort_avg_time, bubble_sort_time, bubble_sort_avg_time;
	for (i = 10; i <= 100000; i *= 10)
	{
		quick_sort_time = 0, quick_sort_avg_time = 0, bubble_sort_time = 0, bubble_sort_avg_time = 0;
		cout  << "sorting time for " << i << " elements" << endl;
		for (int j = 0; j < 10; j++)
		{
			new_array = new sort_int(i);
			new_array->randomize(-3333, 3333);
			quick_sort_time = new_array->quick_sort();
			new_array->randomize(-3333, 3333);
			bubble_sort_time = new_array->bubble_sort();
			cout << j + 1 << ") quick sort: " << quick_sort_time << " sec." << "|" << "bubble sort : " << bubble_sort_time << " sec." << endl;
			quick_sort_avg_time += quick_sort_time;
			bubble_sort_avg_time += bubble_sort_time;
		}
		cout << "average time of quick sorting: " << (quick_sort_avg_time / 10.0) << " sec." << endl << "average time of bubble sorting: " << bubble_sort_avg_time / 10 << " sec." << endl << endl;
	}
}
void arr_out(sort_int* new_array)	//prints array to console
{
	for (int i = 0; i < 10; i++) cout << new_array->get_int_array_element(i) << '|';
}
void arr_out(sort_char* new_array)	//prints array to console
{
	for (int i = 0; i < 10; i++) cout << new_array->get_char_array_element(i) << '|';
}

int main()
{
	for (int j = 0; j < 2; j++) 
	{
		sort_int* new_array;
		new_array = new sort_int(10);
		new_array->randomize();
		cout << "array: ";
		arr_out(new_array);
		new_array->bubble_sort();
		cout << endl << "bubble sort: ";
		arr_out(new_array);

		new_array->randomize();
		cout << endl << endl << "array: ";
		arr_out(new_array);
		new_array->quick_sort();
		cout << endl << "quick sort: ";
		arr_out(new_array);
		try
		{
			cout << endl << endl << "array: ";
			arr_out(new_array);
			int element;
			cout << endl << "Enter element: ";
			cin >> element;
			cout << "Index: " << new_array->binary_search(element);
		}
		catch (runtime_error & exception)
		{
			cout << exception.what();
		}

		new_array = new sort_int(7);
		new_array->randomize();
		cout << endl << endl << "array: ";
		for (int i = 0; i < 7; i++) cout << new_array->get_int_array_element(i) << '|';
		new_array->bogo_sort();
		cout << endl << "bogo sort: ";
		for (int i = 0; i < 7; i++) cout << new_array->get_int_array_element(i) << '|';

		sort_char* new_array2;
		new_array2 = new sort_char(10);
		new_array2->randomize();
		cout << endl << endl;
		arr_out(new_array2);
		new_array2->counting_sort();
		cout << endl;
		arr_out(new_array2);
		cout << endl << endl;
	}
	//sort_stopwatch();
}