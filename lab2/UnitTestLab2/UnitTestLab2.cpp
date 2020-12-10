#include "pch.h"
#include "../lab2v2/lab2v2.cpp"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab2
{
	TEST_CLASS(UnitTestLab2)
	{
	public:
		
		TEST_METHOD(sort_int_constructor)
		{
			sort_int new_array(33);
			size_t Size = 33;
			for (int i = 0; i < 33; i++) Assert::AreEqual(new_array.get_int_array_element(i), NULL);
			Assert::AreEqual(new_array.get_size(), Size);
			
		}
		TEST_METHOD(sort_int_constructor_size_error)
		{
			try
			{
				sort_int new_array(0);
			}
			catch (out_of_range & exception)
			{
				Assert::AreEqual("Error in sort_int function: size = 0\n", exception.what());
			}
		}
		TEST_METHOD(sort_check)
		{
			sort_int new_array(4);
			new_array.set_int_array_element(-3, 0);
			new_array.set_int_array_element(0, 1);
			new_array.set_int_array_element(13, 2);
			new_array.set_int_array_element(16, 3);
			Assert::AreEqual(new_array.sort_check(), 1);
		}
		TEST_METHOD(sort_check_error)
		{
			sort_int new_array(4);
			new_array.set_int_array_element(-3, 0);
			new_array.set_int_array_element(0, 1);
			new_array.set_int_array_element(-13, 2);
			new_array.set_int_array_element(16, 3);
			Assert::AreEqual(new_array.sort_check(), 0);
		}
		TEST_METHOD(set_and_get_int_array_element)
		{
			sort_int new_array(5);
			new_array.randomize();
			new_array.set_int_array_element(-3, 4);
			new_array.set_int_array_element(3, 0);
			Assert::AreEqual(new_array.get_int_array_element(4), -3);
			Assert::AreEqual(new_array.get_int_array_element(0), 3);

		}
		TEST_METHOD(set_int_array_element_error)
		{
			try
			{
				sort_int new_array(5);
				new_array.set_int_array_element(33, 5);

			}
			catch (out_of_range & exception)
			{
				Assert::AreEqual("Error in set_int_array_element function: index >= size\n", exception.what());
			}
		}
		TEST_METHOD(get_int_array_element_error)
		{
			try
			{
				sort_int new_array(5);
				new_array.get_int_array_element(5);

			}
			catch (out_of_range & exception)
			{
				Assert::AreEqual("Error in get_int_array_element function: index >= size\n", exception.what());
			}
		}
		TEST_METHOD(get_size)
		{
			sort_int new_array(5);
			size_t Size = 5;
			new_array.get_size();
			Assert::AreEqual(new_array.get_size(), Size);
		}
		TEST_METHOD(randomize_int)
		{
			sort_int new_array(5);
			new_array.randomize(-33, 33);

			for (int i = 0; i < 5; i++)
				Assert::IsTrue((new_array.get_int_array_element(i) >= -33) && (new_array.get_int_array_element(i) <= 33));
		}
		TEST_METHOD(randomize_int_error)
		{
			try
			{
				sort_int new_array(5);
				new_array.randomize(66, 33);
			}
			catch (invalid_argument & exception)
			{
				Assert::AreEqual("Error randomize function: min > max\n", exception.what());
			}
		}
		TEST_METHOD(int_binary_search)
		{
			sort_int new_array(10);
			for (int i = 0; i < 10; i++)
				new_array.set_int_array_element(i * i, i);
			Assert::AreEqual(new_array.binary_search(25), 5);
			Assert::AreEqual(new_array.binary_search(81), 9);
		}
		TEST_METHOD(int_binary_search_sort_error)
		{
			try
			{
				sort_int new_array(5);
				new_array.randomize(-33, 33);
				new_array.set_int_array_element(-3, 4);
				new_array.set_int_array_element(3, 0);
				new_array.binary_search(3);
			}
			catch (runtime_error & exception)
			{
				Assert::AreEqual("Error in binary_search function: array is'n sorted\n", exception.what());
			}
		}

		TEST_METHOD(int_binary_search_element_error)
		{
			try
			{
				sort_int new_array(10);
				for (int i = 0; i < 10; i++)
					new_array.set_int_array_element(i * i, i);
				new_array.binary_search(100);
			}
			catch (runtime_error & exception)
			{
				Assert::AreEqual("Error in binary_search function: doesn't contain entered element\n", exception.what());
			}
		}
		TEST_METHOD(bogo_sort)
		{
			sort_int new_array(5);
			new_array.set_int_array_element(4, 0);
			new_array.set_int_array_element(-6, 1);
			new_array.set_int_array_element(0, 2);
			new_array.set_int_array_element(5, 3);
			new_array.set_int_array_element(-8, 4);
			new_array.bogo_sort();
			Assert::IsTrue(new_array.sort_check());

		}
		TEST_METHOD(bogo_sort_error)
		{
			try {
				sort_int new_array(5);
				for (int i = 0; i < 5; i++)
					new_array.set_int_array_element(i * i, i);
				new_array.bogo_sort();
			}
			catch (runtime_error & exception)
			{
				Assert::AreEqual("Error in bogo_sort function: array is already sorted\n", exception.what());
			}
		}

		TEST_METHOD(quick_sort)
		{
			sort_int new_array(5);
			new_array.set_int_array_element(4, 0);
			new_array.set_int_array_element(-6, 1);
			new_array.set_int_array_element(0, 2);
			new_array.set_int_array_element(5, 3);
			new_array.set_int_array_element(-8, 4);
			new_array.quick_sort();
			Assert::IsTrue(new_array.sort_check());
		}
		TEST_METHOD(quick_sort_error)
		{
			try {
				sort_int new_array(5);
				for (int i = 0; i < 5; i++)
					new_array.set_int_array_element(i * i, i);
				new_array.quick_sort();
			}
			catch (runtime_error & exception)
			{
				Assert::AreEqual("Error in quick_sort function: array is already sorted\n", exception.what());
			}
		}
		TEST_METHOD(bubble_sort)
		{
			sort_int new_array(5);
			new_array.set_int_array_element(4, 0);
			new_array.set_int_array_element(-6, 1);
			new_array.set_int_array_element(0, 2);
			new_array.set_int_array_element(5, 3);
			new_array.set_int_array_element(-8, 4);
			new_array.bubble_sort();
			Assert::IsTrue(new_array.sort_check());
		}
		TEST_METHOD(bubble_sort_error)
		{
			try {
				sort_int new_array(5);
				for (int i = 0; i < 5; i++)
					new_array.set_int_array_element(i * i, i);
				new_array.bubble_sort();
			}
			catch (runtime_error & exception)
			{
				Assert::AreEqual("Error in bubble_sort function: array is already sorted\n", exception.what());
			}
		}
		TEST_METHOD(sort_char_constructor)
		{
			sort_char new_array(33);
			size_t Size = 33;
			for (int i = 0; i < 33; i++) Assert::AreEqual(new_array.get_char_array_element(i), '?');
			Assert::AreEqual(new_array.get_size(), Size);
		}
		TEST_METHOD(sort_char_constructor_size_error)
		{
			try
			{
				sort_char new_array(0);
			}
			catch (out_of_range & exception)
			{
				Assert::AreEqual("Error in sort_char function: size = 0\n", exception.what());
			}
		}
		TEST_METHOD(sort_check_char_error)
		{
			sort_char new_array(4);
			new_array.set_char_array_element(65, 0);
			new_array.set_char_array_element(76, 1);
			new_array.set_char_array_element(67, 2);
			new_array.set_char_array_element(66, 3);
			Assert::AreEqual(new_array.sort_check(), 0);
		}
		TEST_METHOD(sort_check_char)
		{
			sort_char new_array(4);
			new_array.set_char_array_element(65, 0);
			new_array.set_char_array_element(66, 1);
			new_array.set_char_array_element(74, 2);
			new_array.set_char_array_element(80, 3);
			Assert::AreEqual(new_array.sort_check(), 1);
		}
		TEST_METHOD(set_and_get_char_array_element)
		{
			sort_char new_array(5);
			new_array.randomize();
			new_array.set_char_array_element(65, 4);
			new_array.set_char_array_element(68, 0);
			Assert::AreEqual(new_array.get_char_array_element(4), 'A');
			Assert::AreEqual(new_array.get_char_array_element(0), 'D');
		}
		TEST_METHOD(set_char_array_element_error)
		{
			try
			{
				sort_char new_array(5);
				new_array.set_char_array_element(65, 5);

			}
			catch (out_of_range & exception)
			{
				Assert::AreEqual("Error in set_char_array_element function: index >= size\n", exception.what());
			}
		}
		TEST_METHOD(get_char_array_element_error)
		{
			try
			{
				sort_char new_array(5);
				new_array.get_char_array_element(5);

			}
			catch (out_of_range & exception)
			{
				Assert::AreEqual("Error in get_char_array_element function: index >= size\n", exception.what());
			}
		}
		TEST_METHOD(get_size_char)
		{
			sort_char new_array(5);
			size_t Size = 5;
			new_array.get_size();
			Assert::AreEqual(new_array.get_size(), Size);
		}
		TEST_METHOD(randomize_char)
		{
			sort_char new_array(5);
			new_array.randomize();

			for (int i = 0; i < 5; i++)
				Assert::IsTrue((new_array.get_char_array_element(i) >= 65) && (new_array.get_char_array_element(i) <= 90));
		}
		TEST_METHOD(randomize_char_error)
		{
			try
			{
				sort_char new_array(5);
				new_array.randomize(90, 77);
			}
			catch (invalid_argument & exception)
			{
				Assert::AreEqual("Error randomize function: min > max\n", exception.what());
			}
		}
		TEST_METHOD(randomize_char_error_interval)
		{
			try
			{
				sort_char new_array(5);
				new_array.randomize(54, 77);
			}
			catch (invalid_argument & exception)
			{
				Assert::AreEqual("Error randomize function: min/max doesn't belong to 65...90 interval\n", exception.what());
			}
		}
		TEST_METHOD(counting_sort)
		{
			sort_char new_array;
			while (new_array.sort_check())
				new_array.randomize();

			new_array.counting_sort();

			Assert::AreEqual(new_array.sort_check(), 1);
		}
		TEST_METHOD(counting_sort_error)
		{
			try
			{
				sort_char new_array(4);
				new_array.set_char_array_element(65, 0);
				new_array.set_char_array_element(66, 1);
				new_array.set_char_array_element(74, 2);
				new_array.set_char_array_element(80, 3);
				new_array.counting_sort();
			}
			catch (runtime_error & exception)
			{
				Assert::AreEqual("Error in counting_sort function: array is already sorted\n", exception.what());
			}
		}
	};
}
