#include <vector>

class Sudoku
{
public:
	static bool set(const std::vector<int>& num);
	static const std::vector<int> get();
	static const std::vector<int> getResult();
	static void show(const std::vector<int>& num);
	static bool calc();

private:
	Sudoku(){};
	static bool isOK();
	static bool isOK(int index);
	static bool calc(int index);

	static int m_num[81];
	static int m_result[81];
};