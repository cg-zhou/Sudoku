#include "Sudoku.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string numA = "406002000000100002001090540094005010180026000502000070000060030710080900000900001";
	string numB = "710820904008006050240003010650049081470038092000100400120004060009007040830650709";

	vector<int> num;
	for (size_t i = 0; i < numA.size(); ++i)
		num.push_back(numA[i] - '0');

	Sudoku::show(num);
	cout << endl;

	if (!Sudoku::set(num))
	{
		cout << "Set number failed." << endl;
		return -1;
	}

	if (!Sudoku::calc())
	{
		cout << "The numbers are not sudoku." << endl;
		return -1;
	}

	vector<int> result = Sudoku::getResult();
	Sudoku::show(result);

	return 0;
}