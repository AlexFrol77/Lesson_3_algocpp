#include <iostream>
#include <Windows.h>

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int* arr, int left, int right) {
    int pivot = arr[right - 1];
    int i = left;
  
    for (int j = left; j < right - 1; j++) {
        if (arr[j] <= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[right - 1];
    arr[right - 1] = temp;
    return i;
}

void quick_sort(int* arr, int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quick_sort(arr, left, pi);
        quick_sort(arr, pi + 1, right);
    }
}

int main(int argc, char** argv) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    print(arr, size);

    quick_sort(arr, 0, size);

    std::cout << "Отсортированный массив: ";
    print(arr, size);

    return 0;
}
