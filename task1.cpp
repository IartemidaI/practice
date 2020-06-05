	#include <iostream> 
	#include <cstdlib> 
	#include <ctime> 
	using namespace std;
	void SelectSort(int arr[], int SIZE);
	void BubleSort(int arr[], int SIZE);
	void InsertSort(int arr[], int SIZE);
	int main()
	{
		setlocale(LC_ALL, "ukrainian");
		srand(time(nullptr));
		const int SIZE = 10;
		int arr[SIZE];
		cout << "Початковий масив:\n";
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = rand() % 101 - 50;
			cout << arr[i] << "\t";
		}
		cout << "\n";
		InsertSort(arr, SIZE);
		BubleSort(arr, SIZE);
		SelectSort(arr, SIZE);
		system("pause");
		return 0;
	}
	void InsertSort(int arr[],int SIZE)
	{
		int *arrayToSort = new int[SIZE];
		arrayToSort = arr;
		clock_t start = clock();
		int j;
		for (int i = 0; i < SIZE; ++i)
		{
			int temp = arrayToSort[i];
			for (j = i - 1; j >= 0 && arrayToSort[j] > temp; --j)
				arrayToSort[j + 1] = arrayToSort[j];
			arrayToSort[j + 1] = temp;
		}
		clock_t end = clock();
		cout << "Результат сортування вставками:\n";
		for (int i = 0; i < SIZE; i++)
			cout << arrayToSort[i] << "\t";
		cout << "\n";
		cout << "Час, витрачений на сортування вставками " << end - start << " мс\n";
	}
	void SelectSort(int arr[], int SIZE)
	{
		int *arrayToSort = new int[SIZE];
		arrayToSort = arr;
		clock_t start = clock();
		for (int i = 0; i < SIZE; ++i)
		{
			int minIndex = i, minValue = arrayToSort[i];
			for (int j = i + 1; j < SIZE; ++j)
				if (arrayToSort[j] < minValue)
				{
					minValue = arrayToSort[j];
					minIndex = j;
				}
			arrayToSort[minIndex] = arrayToSort[i];
			arrayToSort[i] = minValue;
		}
		clock_t end = clock();
		cout << "Результат сортування вибором:\n";
		for (int i = 0; i < SIZE; i++)
			cout << arrayToSort[i] << "\t";
		cout << "\n";
		cout << "Час, витрачений на сортування вибором " << end - start << " мс\n";
	}
	void BubleSort(int arr[], int SIZE)
	{
		int *arrayToSort = new int[SIZE];
		arrayToSort = arr;
		cout << "Результат сортування булькою:\n";
		clock_t start = clock();
		for (int i = 0; i < SIZE; ++i)
		{
			for (int j = SIZE - 1; j > i; --j)
				if (arrayToSort[j] < arrayToSort[j - 1])
				{
					int temp = arrayToSort[j];
					arrayToSort[j] = arrayToSort[j - 1];
					arrayToSort[j - 1] = temp;
				}
		}
		clock_t end = clock();
		for (int i = 0; i < SIZE; i++)
			cout << arrayToSort[i] << "\t";
		cout << "\n";
		cout << "Час, витрачений на сортування булькою " << end - start << " мс\n";
	}
