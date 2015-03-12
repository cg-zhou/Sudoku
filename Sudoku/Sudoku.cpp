#include "Sudoku.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Sudoku::m_num[81] = {0};
int Sudoku::m_result[81] = {0};

bool Sudoku::set(const vector<int>& num)
{
	if (num.size() != 81)
		return false;

	if (any_of(num.begin(), num.end(), [](const int& i){return i > 9 || i < 0;}))
		return false;

	for (int i = 0; i < 81; ++i)
	{
		m_num[i] = num[i];
		m_result[i] = num[i];
	}

	return true;
}

bool Sudoku::calc()
{
	return calc(80) && isOK();
}

const vector<int> Sudoku::get()
{
	return vector<int>(m_num, m_num + sizeof(m_num) / sizeof(int));
}

const vector<int> Sudoku::getResult()
{
	return vector<int>(m_result, m_result + sizeof(m_result) / sizeof(int));
}

void Sudoku::show(const vector<int>& num)
{
	for (size_t i = 0; i < num.size(); ++i)
	{
		cout << num.at(i) << " ";
		if (i % 9 == 8)
			cout << endl;
	}
}

bool Sudoku::isOK(int index)
{
	int row = index / 9;
	int col = index % 9;
	int blockRow = row / 3 * 3;
	int blockCol = col / 3 * 3;
	int cmpIndex = 0;

	for (int i = 0; i < 9; ++i)
	{
		cmpIndex = row * 9 + i;
		if (cmpIndex != index && m_result[index] == m_result[cmpIndex])
			return false;

		cmpIndex = i * 9 + col;
		if (cmpIndex != index && m_result[index] == m_result[cmpIndex])
			return false;

		cmpIndex = (i / 3 * 9 + blockRow * 9) + (i % 3 + blockCol);
		if (cmpIndex != index && m_result[index] == m_result[cmpIndex])
			return false;
	}

	return true;
}

bool Sudoku::isOK()
{
	if (any_of(m_result, m_result + 81, [](const int& i){return i > 9 || i < 1;}))
		return false;

	for (size_t index = 0; index < 81; ++index)
		if (!isOK(index))
			return false;

	return true;
}

bool Sudoku::calc(int index)
{
	while (index >= 0 && m_num[index] != 0)
		--index;

	if (index < 0)
		return true;

	//Try from 1~9.
	for (int i = 1; i < 10; ++i)
	{
		m_result[index] = i;
		if (isOK(index))
			if (calc(index - 1))
				return true;
	}

	m_result[index] = 0;
	return false;
}
