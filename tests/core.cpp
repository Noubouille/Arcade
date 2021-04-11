#include "include/catch.hpp"
#include "../includes/Core.hpp"
//#include <filesystem>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

TEST_CASE("Core", "core")
{
    Core *core = new Core("SFML");

    SECTION("Core getName()")
    {
        std::cout << core->_stateMenu << std::endl;
    }
}