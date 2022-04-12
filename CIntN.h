#ifndef CINTN
#define CINTN

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
#include <vector>

class CIntN
{
protected:
    int* value;
    size_t N;
    string FileName;
    string num;
public:
    CIntN();//конструктор по умолчанию
    CIntN(string file_name, size_t N, string num);//конструктор 
    CIntN(const CIntN& other);//конструктор копирования

    //фции
    virtual void output() = 0; // pure virtual
    void print_num();

    size_t Get_N() const;
    string Get_FileName() const;
    string Get_num() const;
    int Get_val_i(int i) const;
    //операторы
    CIntN& operator=(const CIntN& other);

    virtual ~CIntN();//деструктор
};

#endif


