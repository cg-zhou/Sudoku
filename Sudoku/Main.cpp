#include "Sudoku.h"

int main()
{
	std::string numA = "406002000000100002001090540094005010180026000502000070000060030710080900000900001";
	std::string numB = "710820904008006050240003010650049081470038092000100400120004060009007040830650709";

	std::vector<int> nums;
	for (size_t i = 0; i < numA.size(); ++i)
	{
		nums.push_back(numA[i] - '0');
	}

	std::auto_ptr<Sudoku> sudoku(new Sudoku(nums));
	sudoku->Show();

	Utils::PrintLine();

	if (!sudoku->Calculate())
	{
		Utils::PrintLine("Calculate sudoku failed.");
		return -1;
	}

	sudoku->ShowResult();

	return 0;
}