#include "data_analysis.h"

Data_Analysis::Data_Analysis(int num)
{
    this->num = num;
}
Data_Analysis::~Data_Analysis() {
    delete arr[];
}

void Data_Analysis::inputValues() {
    for(int i = 0; i < this->num; i++) {
        std::cout << "Enter value " << i+1 << ": ";
        std::cin >> this->arr[i];
    }
}
void Data_Analysis::mean() {
    float res;
    for(int i = 0; i < this->num; i++) {
        res += this->arr[i];
    }
    return res;
}
