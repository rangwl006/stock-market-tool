#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
namespace utils
{
    // Use a policy-based design for other classes to calculate moving averages
    template
    <
      template <typename> class Container = std::vector,
      typename ValueType = double
    >
    struct SMACalculator
    {
        static std::vector<ValueType> CalculateSimpleMovingAverage(std::vector<ValueType> values, size_t windowSize)
        {
            std::vector<ValueType> output(windowSize - 1);
            assert(output.size() == windowSize - 1);
            std::cout << "Created output with default window size: " << output.size() << std::endl;
            int left = 0;
            ValueType currSum = 0;

            for_each(values.begin(), values.begin() + windowSize, [&currSum](ValueType v){ currSum += v; } );
            output.push_back(currSum / windowSize);

            for(int right = windowSize; right < values.size(); right++)
            {
                currSum -= values[left];
                currSum += values[right];
                output.push_back(currSum / windowSize);
                left++;
            }
            return output;
        };
    };

    /**
     * Formula: EMA = K * (Current price - Previous EMA) + Previous EMA
     * where K = 2 / (n + 1) is the weighting factor, n = time period
    */
    template
    <
      template <typename> class Container = std::vector,
      typename ValueType = double
    >
    struct EMACalculator
    {
        std::vector<ValueType> CalculateExponentialMovingAverage(std::vector<ValueType>& values, int period)
        {
            // calculate the weighting 
            double k = 2.0 / ( period + 1 );
            std::cout << "k: " << k << std::endl;

            // set initial ema to first value
            ValueType currEma = values[0];
    
            std::vector<ValueType> output{};
            output.push_back(currEma);

            for(int i = 1; i < values.size(); i++)
            {
                currEma = currEma + k * (values[i] - currEma);
                std::cout << "values[" << i << "]: " << values[i] << std::endl;
                std::cout << "ema(" << i << "): " << currEma << std::endl;
                output.push_back(currEma);
            }

            return output;
        };
    };
}
