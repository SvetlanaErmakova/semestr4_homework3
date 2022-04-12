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
    CIntN();//����������� �� ���������
    CIntN(string file_name, size_t N, string num);//����������� 
    CIntN(const CIntN& other);//����������� �����������

    //����
    virtual void output() = 0; // pure virtual
    void print_num();

    size_t Get_N() const;
    string Get_FileName() const;
    string Get_num() const;
    int Get_val_i(int i) const;
    //���������
    CIntN& operator=(const CIntN& other);

    virtual ~CIntN();//����������
};

#endif


