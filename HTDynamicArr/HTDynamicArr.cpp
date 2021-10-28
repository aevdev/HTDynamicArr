#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Домашнее задание объемное, пришлось скачать СodeBlocks чтобы проверить работоспособность программы.

void printArr(const int* arr, size_t size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << '\t';
}

int sumArr(const int* arr, size_t size)
{
	int sum = 0;

	for (int i = 0; i < size; ++i)
		sum += arr[i];

	return sum;
}

long long productArr(const int* arr, size_t size)
{
	long long product = 1;

	for (int i = 0; i < size; ++i)
		product *= arr[i];

	return product;
}

int findMin(const int* arr, size_t size)
{
	int min = arr[0];

	for (int i = 1; i < size; ++i)
	{
		if (min > arr[i])
			min = arr[i];
	}
	
	return min;
}

int findMax(const int* arr, size_t size)
{
	int max = arr[0];

	for (int i = 1; i < size; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

int meanArr(const int* arr, size_t size)
{
	int mean = 0;

	for (int i = 0; i < size; ++i)
		mean += arr[i];

	return mean / size;
}

int findIndex(const int* arr, size_t size, int num)
{
	int index = -1;

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == num)
			index = i;
	}

	return index;
}

bool isExist(const int* arr, size_t size, int num)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == num)
			return true;
	}

	return false;
}

void bubbleSort(int* arr, size_t size)
{
	int temp;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int* arr, size_t size)
{
	int min, temp;
	for (int i = 0; i < size; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void insertionSort(int* arr, size_t size)
{
	int temp;
	for (int i = 1; i < size; ++i)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}
	}
}

void insertInArray(int* arr1, size_t size, int* arr2, int value, size_t index)
{
	for (int i = 0; i < index; ++i)
		arr2[i] = arr1[i];

	arr2[index] = value;

	for (int i = index; i < size; ++i)
		arr2[i + 1] = arr1[i];
}

void deleteFromArray(int* arr, size_t size, size_t index)
{
	for (int i = index; i < size - 1; ++i)
		arr[i] = arr[i + 1];
}

int main()
{
	size_t SIZE;
	int choose, num;
	int value;		//для вставки/удаления
	size_t index;	//для вставки/удаления
	srand(time(0));

	cout << "Please, enter array size: ";
	cin >> SIZE;
	int* arr = new int[SIZE];

	cout << "\nPlease, enter how you want to fill array?\n1 - Manual input.\n2 - Randomly (from -100 to 100)\nOther - exit\nEnter: ";
	cin >> choose;
	if (choose == 1)
	{
		for (int i = 0; i < SIZE; ++i)
		{
			cout << "\nPlease enter " << i + 1 << " array element: ";
			cin >> arr[i];
		}
	}
	else if (choose == 2)
	{
		for (int i = 0; i < SIZE; ++i)
			arr[i] = rand() % (100 + 100) - 100;
	}
	else
	{
		delete[] arr;
		return 0;
	}
	
	cout << "\nYour arr:\n";
	printArr(arr, SIZE);

	cout << "\nSumm of arr elements: " << sumArr(arr, SIZE);
	cout << "\nProduct of arr elements: " << productArr(arr, SIZE);
	cout << "\nMin element: " << findMin(arr, SIZE);
	cout << "\nMax element: " << findMax(arr, SIZE);
	cout << "\nArithmetic mean: " << meanArr(arr, SIZE);

	cout << "\nPlease, enter number you want to find the index of: ";
	cin >> num;
	cout << "\nIndex of your element: " << findIndex(arr, SIZE, num);
	cout << "\n(if it\'s -1, then there is NO your element in the array)";

	cout << "\nPlease, enter number you want to check if it\'s exist: ";
	cin >> num;
	isExist(arr, SIZE, num) ? cout <<  "Your number EXIST" : cout << "Your number DOES NOT EXIST";

	cout << "\nPlease, enter how you want to sort array?\n1 - Insertion sort.\n2 - Selection sort\nOther - Bubble sort\nEnter: ";
	cin >> choose;
	if (choose == 1)
		insertionSort(arr, SIZE);
	else if (choose == 2)
		selectionSort(arr, SIZE);
	else
		bubbleSort(arr, SIZE);

	cout << "\nSorted array:\n";
	printArr(arr, SIZE);

	int* arrM = (int*)malloc(SIZE + 1); //это же вроде функция еще из стандартного C. Она вроде устаревшая и ненадежная (собственно как и new, в современных реалиях, когда существуют вектора)
										//P.S.в коллекцию к синтаксису malloc еще можно добавить calloc (ни разу ее не использовал, не знаю даже зачем она существует) и realloc, если я их правильно запомнил.
	cout << "\nEnter value to insert: ";
	cin >> value;
	cout << "\nEnter index you want to insert in: ";
	cin >> index;

	insertInArray(arr, SIZE, arrM, value, index);

	cout << "\nInserted array:\n";
	printArr(arrM, SIZE + 1);

	cout << "\nEnter index you want to delete from: ";
	cin >> index;
	deleteFromArray(arrM, SIZE + 1, index); //пытался использовать realloc после удаления элемента из массива, чтобы уменьшить размер массива на 1 элемент, но функция не работает как я хотел бы. Но в целом я задание выполнил.
	//arrM = (int*) realloc(arrM, SIZE * sizeof(int));
	cout << "\nDeleted array:\n";
	printArr(arrM, SIZE);

	delete[] arr;
	free(arrM);
	return 0;
}