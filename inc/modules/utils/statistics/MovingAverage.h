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
      typename ValueType
    >
    std::vector<ValueType> CalculateSimpleMovingAverage(std::vector<ValueType> values, size_t windowSize)
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
    // template<template<typename Container> class Value>
    // Value CalculateExponentialMovingAverage(Container<Value> values, size_t windowSize);
}
