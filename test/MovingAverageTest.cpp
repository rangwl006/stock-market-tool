#include <catch2/catch_test_macros.hpp>
#include "MovingAverage.h"

TEST_CASE("Test Catch2")
{
    std::vector<float> v{1,2,3,4,5};
    int windowSize = 3;
    auto res = utils::CalculateSimpleMovingAverage(v, windowSize);
    float x = (1 + 2 + 3) / 3;
    float y = (2 + 3 + 4) / 3;
    float z = (3 + 4 + 5) / 3;
    INFO("x = " << x);
    INFO("res size: " << res.size());
    INFO("res[0] = " << res[0]);
    INFO("res[1] = " << res[1]);
    INFO("res[2] = " << res[2]);
    INFO("res[3] = " << res[3]);
    INFO("res[4] = " << res[4]);
    REQUIRE(x == res[2]);
    REQUIRE(y == res[3]);
    REQUIRE(z == res[4]);

}