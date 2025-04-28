#ifndef RUNNING_AVERAGE_H
#define RUNNING_AVERAGE_H

class RunningAverage
{
public:
    RunningAverage();
    void addValue(double value);
    double getAverage() const;

private:
    double sum; // Sum of all values added
    int count;  // Number of values added
};

#endif