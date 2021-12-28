#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Utils
{
public:
    static std::ostream& Print(const std::string& content = "")
    {
        return std::cout << content;
    }

    static std::ostream& PrintLine(const std::string& content = "")
    {
        return Print(content) << std::endl;
    }

    static std::ostream& Error(const std::string& content = "")
    {
        return PrintLine("[Error] " + content);
    }

    static bool InRange(const std::vector<int>& nums, int min, int max)
    {
        return !std::any_of(nums.begin(), nums.end(), [&](const int& i) {return i >= min && i <= max; });
    }
};