#include "Utils.h"

class Sudoku
{
public:
	Sudoku(const std::vector<int>& nums);

	bool Calculate();

	void Show() { Show(m_originNums); };
	void ShowResult() { Show(m_result); };

private:
	bool Calculate(int index);

	void Show(const std::vector<int>& nums);

	bool IsValid();
	bool IsValid(int index);

	std::vector<int> m_originNums;
	std::vector<int> m_result;
};