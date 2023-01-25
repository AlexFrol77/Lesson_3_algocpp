#include <iostream>
#include <vector>
#include <Windows.h>

void merge(std::vector <int> vecTarget, std::vector <int> vecLeft, std::vector <int> vecRight) {
	int minVecLeftIndex = 0;
	int minVecRightIndex = 0;
	int minVecTargetIndex = 0;

	while ((minVecLeftIndex < vecLeft.size() - 1) || (minVecRightIndex < vecRight.size() - 1))
		if (vecLeft[minVecLeftIndex] <= vecRight[minVecRightIndex]) {
			vecTarget[minVecTargetIndex] = vecLeft[minVecLeftIndex];
			minVecLeftIndex++;
			minVecTargetIndex++;
		}
		if (vecLeft[minVecLeftIndex] >= vecRight[minVecRightIndex]) {
			vecTarget[minVecTargetIndex] = vecLeft[minVecRightIndex];
			minVecRightIndex++;
			minVecTargetIndex++;
		}
	while ((minVecLeftIndex == vecLeft.size() - 1) && (minVecRightIndex < vecRight.size() - 1)) {
		vecTarget[minVecTargetIndex] = vecRight[minVecRightIndex];
		minVecRightIndex++;
		minVecTargetIndex++;
	}
	while ((minVecRightIndex == vecRight.size() - 1) && (minVecLeftIndex < vecLeft.size() - 1)) {
		vecTarget[minVecTargetIndex] = vecLeft[minVecLeftIndex];
		minVecLeftIndex++;
		minVecTargetIndex++;
	}
}

void sortMerge(std::vector <int> vecNoSorting) {
	
	if (vecNoSorting.size() < 2) {
		return;
	}
	int middle = (vecNoSorting.size() / 2);
	std::vector <int> vecLeft;
	std::vector <int> vecRight;
	for (int i = 0; i < middle - 1; i++) {
		vecLeft.push_back(vecNoSorting[i]);
	}
	for (int i = middle; i < vecNoSorting.size() - 1; i++) {
		vecRight.push_back(vecNoSorting[i]);
	}
	sortMerge(vecLeft);
	sortMerge(vecRight);
	for (int i : vecLeft) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i : vecRight) {
		std::cout << i << " " << std::endl;
	}
	std::cout << std::endl;
	//merge(vecNoSorting, vecLeft, vecRight);
}


int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector <int> vecNoSorting = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};

	sortMerge(vecNoSorting);
	/*for (int i : vecNoSorting) {
		std::cout << i << " ";
	}*/
	return 0;
}