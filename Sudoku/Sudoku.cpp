#include "Sudoku.h"

Sudoku::Sudoku(const std::vector<int>& nums)
{
	if (nums.size() != 81)
	{
		Utils::Error("The length of sudoku is not 81.");
		return;
	}

	if (Utils::InRange(nums, 0, 9))
	{
		Utils::Error("Valid Sudoku number range is 0 ~ 9(0's meaning is empty).");
		return;
	}

	m_originNums = nums;
	m_result = nums;
}

bool Sudoku::Calculate()
{
	return Calculate(80) && IsValid();
}

bool Sudoku::IsValid(int index)
{
	int row = index / 9;
	int col = index % 9;
	int blockRow = row / 3 * 3;
	int blockCol = col / 3 * 3;

	int value = m_result[index];
	for (int i = 0; i < 9; ++i)
	{
		// Compare by row
		int cmpIndex = row * 9 + i;
		if (cmpIndex != index && value == m_result[cmpIndex])
		{
			return false;
		}

		// Compare by column
		cmpIndex = i * 9 + col;
		if (cmpIndex != index && value == m_result[cmpIndex])
		{
			return false;
		}

		// Compare by 3*3 block
		cmpIndex = (i / 3 * 9 + blockRow * 9) + (i % 3 + blockCol);
		if (cmpIndex != index && value == m_result[cmpIndex])
		{
			return false;
		}
	}

	return true;
}

bool Sudoku::IsValid()
{
	if (Utils::InRange(m_result, 1, 9))
	{
		return false;
	}

	for (size_t index = 0; index < 81; ++index)
	{
		if (!IsValid(index))
		{
			return false;
		}
	}

	return true;
}

bool Sudoku::Calculate(int index)
{
	while (index >= 0 && m_originNums[index] != 0)
	{
		--index;
	}

	if (index < 0)
	{
		return true;
	}

	//Try from 1~9.
	for (int i = 1; i < 10; ++i)
	{
		m_result[index] = i;
		if (IsValid(index) && Calculate(index - 1))
		{
			return true;
		}
	}

	m_result[index] = 0;
	return false;
}

void Sudoku::Show(const std::vector<int>& nums)
{
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
		{
			std::cout << "_ ";
		}
		else
		{
			std::cout << nums[i] << " ";
		}

		if (i % 3 == 2)
		{
			Utils::Print(" ");
		}

		if (i % 9 == 8)
		{
			Utils::PrintLine();
		}

		if (i % 27 == 26)
		{
			Utils::PrintLine();
		}
	}
}
