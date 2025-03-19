#include <iostream>
#include <chrono>
#include <string>
using namespace std;

constexpr bool Pre_compare_texts1(const char* Atext, const char* Btext, unsigned pos);
bool compare_texts1(const char* Atext, const char* Btext, unsigned pos);
bool compare_texts2(std::string Atext, std::string Btext, unsigned pos);
bool testfunc(bool (*compare_func)(const char*, const char*, unsigned));
bool testfunc2(bool (*compare_func)(std::string, std::string, unsigned));
int avg(int nums[], int size);
