#ifndef DATA_ANALYSIS_H
#define DATA_ANALYSIS_H

#include <iostream>


class Data_Analysis
{
public:
    Data_Analysis(int num);
    ~Data_Analysis();
    void inputValues();
    float mean();
private:
    int num;
    float *arr[num];
};

#endif // DATA_ANALYSIS_H
