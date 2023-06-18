#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <iostream>
#include <vector>
#include <algorithm>

class Data
{
public:
    Data();
    ~Data();

    void add(float val);
    void add(std::vector<float> values);
    float mean();
    float median();
    int length();
    float mode();
    void print() const;

private:
    std::vector<float> data;
    std::vector<float> sort(const std::vector<float> arr);
    std::vector<float> *sort_freq_table(std::vector<float> arr, std::vector<float> freq_table);
};

#endif // DATA_H
