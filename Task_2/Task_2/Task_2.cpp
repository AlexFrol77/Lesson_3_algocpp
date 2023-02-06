#include <iostream>

void quick_sort(int* arr, int size) {
	int start = 0,
		temp = 0,
	    finish = size - 1,
		middle = arr[finish / 2];
	while (arr[start] <= middle) {
			start++;
	}
	while (middle >= arr[finish]) {
			finish--;
	}
	temp = arr[start];
	arr[start] = arr[finish];
	arr[finish] = temp;
	if (start <= finish) {
		quick_sort(arr, size);
	}
}

void print(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Rus");
	
	int arr[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Исходный массив: ";
	print(arr, size);

	quick_sort(arr, size);

	std::cout << "Отсортированный массив: ";
	print(arr, size);

	return 0;
}