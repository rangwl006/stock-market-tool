#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "MovingAverage.h"

using Catch::Approx;
using namespace Catch::literals;

TEST_CASE("Test Simple Moving Average")
{
    std::vector<float> v{1,2,3,4,5};
    int windowSize = 3;
    auto smaCalculator = utils::SMACalculator<std::vector, float>();
    auto res = smaCalculator.CalculateSimpleMovingAverage(v, windowSize);
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

TEST_CASE("Test Exponential Moving Average")
{
    std::vector<float> v{1,2,3,4,5,6,7,8,9,10};
    int period = 3;
    auto emaCalculator = utils::EMACalculator<std::vector, float>();
    auto res = emaCalculator.CalculateExponentialMovingAverage(v, period);
    
    REQUIRE(res[0] == 1);
}