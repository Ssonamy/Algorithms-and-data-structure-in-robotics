#include <iostream>
#include <vector>
#include <cstdlib> // для rand()
#include <ctime> // для time()
#include <chrono> // для измерения времени
#include <clocale>

using namespace std;


// Функция для генерации и заполнения массива необходимой длинны случайными числами
vector<int> generateRandomArray(const int size)
{
	vector<int> arr(size);
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 10000;
	return arr;
}


void bubbleSort(vector<int>& arr) // Сортировка пузырьком: проходит по массиву и меняет местами соседние элементы, если они идут в неправильном порядке. Повторяет это, пока массив не отсортирован.
{
	int size = arr.size();
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}


void insertionSort(vector<int>& arr) // Сортировка вставками: берет элементы один за другим и вставляет их в нужное место среди уже отсортированных элементов слева.
{
	int size = arr.size();
	for (int i = 1; i < size; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void merge(vector<int>& arr, const int left, const int mid, const int right) //Вспомогательная функция для сортироовки слиянием
{
	int i = left, j = mid + 1;
	vector<int> temp;

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j])
			temp.push_back(arr[i++]);
		else
			temp.push_back(arr[j++]);
	}

	while (i <= mid) temp.push_back(arr[i++]);
	while (j <= right) temp.push_back(arr[j++]);

	for (int k = 0; k < temp.size(); ++k)
		arr[left + k] = temp[k];
}

void mergeSort(vector<int>& arr, const int left, const int right) // Сортировка слиянием: делит массив на две части, сортирует каждую часть отдельно (рекурсивно), а потом сливает их обратно в один отсортированный массив.
{
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

template<typename Func>
long long measureTime(Func sortFunction, vector<int> arr) {
	auto start = chrono::high_resolution_clock::now();
	sortFunction(arr);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	return duration.count();
}

int firstLR()
{
	setlocale(LC_ALL, "ru_RU.utf8");

	srand(time(nullptr)); // Инициализация генератора случайных чисел

	vector<int> sizes = { 100, 1000, 10000 }; // Размеры массивов

	for (int size : sizes) {
		cout << "\nРазмер массива: " << size << "\n";

		auto base = generateRandomArray(size);

		// Bubble Sort
		long long t1 = measureTime(bubbleSort, base);
		cout << "Bubble Sort: " << t1 << " мс\n";

		// Insertion Sort
		long long t2 = measureTime(insertionSort, base);
		cout << "Insertion Sort: " << t2 << " мс\n";

		// Merge Sort (через лямбду)
		auto mergeWrapper = [&](vector<int> a) {
			mergeSort(a, 0, a.size() - 1);
			};
		long long t3 = measureTime(mergeWrapper, base);
		cout << "Merge Sort: " << t3 << " мс\n" << endl;
	}

	return 0;
}