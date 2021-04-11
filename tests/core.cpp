#include "include/catch.hpp"
#include "../includes/Core.hpp"

TEST_CASE("Core", "core")
{
    Core *core = new Core("SFML");

    SECTION("Core getName()")
    {
        std::cout << core->_stateMenu << std::endl;
    }
}