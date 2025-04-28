#include "running_avg.h"

RunningAverage::RunningAverage() : sum(0.0), count(0)
{
}

void RunningAverage::addValue(double value)
{
    sum += value;
    count++;
}

double RunningAverage::getAverage() const
{
    if (count == 0)
    {
        return 0.0; // Avoid division by zero
    }
    return sum / count;
}
