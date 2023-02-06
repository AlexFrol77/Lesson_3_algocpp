#include <iostream>
#include <vector>
#include <Windows.h>

void merge(std::vector <int> vec, int left, int right) {
	std::vector <int> merge;
	if (vec[left] > vec[right]) {
		int temp = vec[left];
		vec[left] = vec[right];
		vec[left] = vec[right];
	}
}

void sort_merge(std::vector <int> vec, int left, int right) {
	if ((right - left) < 2) {
		return;
	}
	int middle = (right - left) / 2;
	int l_st = left,
		l_fin = middle;
	sort_merge(vec, l_st, l_fin);
	sort_merge(vec, l_fin - 1, right);
	merge(vec, l_st, l_fin);
	
}

int main(int argc, char** argv) {
	
	std::vector <int> vec = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int size = vec.size();
	int left = 0;
	int right = size - 1;

	/*for (int i = 0; i != vec.size(); i++) {
		std::cout << vec[i] << " ";
	}*/
	//std::cout << std::endl;

	sort_merge(vec, left, right);

	/*for (int i = 0; i != vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;*/
	
	return 0;
}