#include <iostream>
#include <Windows.h>

int* fill_arr_count(int size) {
	int* arr_count = new int[size];
	for (int i = 0; i < size; i++) {
		arr_count[i] = 0;
	}
	return arr_count;
}

void count_sort(int *arr_count, int *arr_source, int size_source) {
	for (int i = 0; i < size_source; i++) {
		arr_count[arr_source[i]] += 1;
	}
}

void swift_arr_count_source(int* arr_count, int *arr_source, int size_source) {
	int temp = 10;
	for (int i = 0; i < size_source; i++) {
		while (arr_count[temp] == 0) {
			temp++;
		}
		arr_source[i] = temp;
		arr_count[temp] -= 1;
	}
}

void print_arr_source_sort(int* arr_source, int size_source) {
	for (int i = 0; i < size_source; i++) {
		std::cout << arr_source[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	const int size = 24;
	int* arr_count = fill_arr_count(size);
	
	int arr_source[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10,
		23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

	int size_source = sizeof(arr_source) / sizeof(arr_source[0]);

	count_sort(arr_count, arr_source, size_source);
	std::cout << "Исходный массив: ";
	print_arr_source_sort(arr_source, size_source);
	swift_arr_count_source(arr_count, arr_source, size_source);
	delete[] arr_count;
	std::cout << std::endl;
	std::cout << "Отсортированный массив: ";
	print_arr_source_sort(arr_source, size_source);

	return 0;
}