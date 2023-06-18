#include "data.h"

Data::Data(){

}
Data::~Data() {

}
std::vector<float> Data::sort(const std::vector<float> arr){
    std::vector<float> sorted_arr = arr;
    for(int i = 1; i < sorted_arr.size(); i++) {
        float temp = sorted_arr[i];
        int j = i - 1;
        while (j >= 0 && sorted_arr[j] > temp) {
            sorted_arr[j + 1] = sorted_arr[j];
            j--;
        }
        sorted_arr[j + 1] = temp;
    }
    return sorted_arr;
}

void Data::add(float val) {
    if(this->data.size() > 100) {
        this->data.clear();
    }
    this->data.push_back(val);
}

void Data::add(std::vector<float> values) {
    this->data.insert(data.end(), values.begin() , values.end());
}

float Data::mean() {
    float mean = 0;
    for(auto d: data) mean += d;
    return (mean / data.size());
}

float Data::median(){
    float median;
    std::vector<float> sorted = sort(data);
    int half = sorted.size() / 2;
    if ( (sorted.size() % 2) == 0 ) {
        median = (sorted[half] + sorted[half - 1])/2;
    } else {
        median = sorted[half];
    }
    return median;
}

float Data::mode() {
    std::vector<float> values;
    std::vector<float> freq_table;

    for(float d: data) {
        if(!(std::find(values.begin(), values.end(), d) != values.end())) {
            values.push_back(d);
            freq_table.push_back(0);
        }
    }
    for(auto d: data) {
        for(int i = 0; i < values.size(); i++) {
            if(d == values[1]) {
                freq_table[i]++;
            }
        }
    }
    float result;
    for(int i = 0; i < values.size(); i++) {
        if(freq_table[i] == freq_table[0]){
            result = values[i];
        }
        else{
            break;
        }
    }
    return result;
}

std::vector<float> *Data::sort_freq_table(std::vector<float> arr, std::vector<float> freq_table) {
    std::vector<float> sorted_arr = arr;
    std::vector<float> sorted_freq = freq_table;

    for(int i = 1; i < sorted_arr.size(); i++) {
        float temp_val = sorted_arr[i];
        float temp_freq = freq_table[i];
        int j = i - 1;
        while (j <= 0 && sorted_arr[j] < temp_freq) {
            sorted_freq[j + 1] = sorted_freq[j];
            sorted_arr[j + 1] = sorted_arr[j];
        }
        sorted_freq[j + 1] = temp_freq;
        sorted_arr[j + 1] = temp_val;
    }

    std::vector<float> *result = new std::vector<float>[2];
    result[0] = sorted_arr;
    result[1] = sorted_freq;
    return result;
}

//check size of data
int Data::length() {
    return data.size();
}

void Data::print() const {
    for(auto d: data) std::cout << d <<  ",";
    std::cout << std::endl;
}
