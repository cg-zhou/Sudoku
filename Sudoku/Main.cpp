#include "Sudoku.h"
#include "TestSudokus.h"



int main()
{
    std::string sudokuString = TestSudokuA;

    std::vector<int> sudokuData;
    for (size_t i = 0; i < sudokuString.size(); ++i)
    {
        sudokuData.push_back(sudokuString[i] - '0');
    }

    std::auto_ptr<Sudoku> sudoku(new Sudoku(sudokuData));
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