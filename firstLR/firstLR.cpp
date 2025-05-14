#include <iostream>
#include <vector>
#include <cstdlib> // для rand()
#include <ctime> // для time()
#include <chrono> // для измерения времени

using namespace std;


// Функция для генерации и заполнения массива необходимой длинны случайными числами
static vector<int> generateRandomArray(size_t size)
{
	vector<int> arr(size);
	for (size_t i = 0; i < size; ++i)
		arr[i] = rand() % 10000;
	return arr;
}


static void bubbleSort(vector<int>& arr) // Сортировка пузырьком: проходит по массиву и меняет местами соседние элементы, если они идут в неправильном порядке. Повторяет это, пока массив не отсортирован.
{
	size_t size = arr.size();
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}


static void insertionSort(vector<int>& arr) // Сортировка вставками: берет элементы один за другим и вставляет их в нужное место среди уже отсортированных элементов слева.
{
	size_t size = arr.size();
	for (int i = 1; i < static_cast<int>(arr.size()); ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

static void merge(vector<int>& arr, size_t left, size_t mid, size_t right) //Вспомогательная функция для сортироовки слиянием
{
	size_t i = left, j = mid + 1;
	vector<int> temp;

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j])
			temp.push_back(arr[i++]);
		else
			temp.push_back(arr[j++]);
	}

	while (i <= mid) temp.push_back(arr[i++]);
	while (j <= right) temp.push_back(arr[j++]);

	for (size_t k = 0; k < temp.size(); ++k)
		arr[left + k] = temp[k];
}

static void mergeSort(vector<int>& arr, size_t left, size_t right) // Сортировка слиянием: делит массив на две части, сортирует каждую часть отдельно (рекурсивно), а потом сливает их обратно в один отсортированный массив.
{
	if (left < right) {
		size_t mid = left + (right - left) / 2;
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
	srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел

	vector<size_t> sizes = { 100, 1000, 10000 }; // Размеры массивов

	for (size_t size : sizes) {
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