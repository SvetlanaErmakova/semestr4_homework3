#ifndef CINTN1
#define CINTN1

#include "CIntN.h"

class CIntN1 : public CIntN
{
public:
    CIntN1(string file_name, size_t N, string num) : CIntN(file_name, N, num) {}
    CIntN1() :CIntN() {}
    CIntN1(const CIntN& other) :CIntN(other) {}

    using CIntN::operator=;

    void output() override final;

    ~CIntN1();
};

#endif