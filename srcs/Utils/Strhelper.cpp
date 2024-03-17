#include "../../includes/webserv.hpp"

int checkStrEnd(const std::string& str, const std::string& end)
{
    size_t strl = str.size();
    size_t endl = end.size();

    while (endl > 0)
    {
        strl--;
        endl--;
        if (strl < 0 || str[strl] != end[endl])
            return 1;
    }
    return 0;
}
