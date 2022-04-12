#ifndef CINTN0
#define CINTN0

#include "CIntN.h"

class CIntN0 : public CIntN
{
public:
    CIntN0(string file_name, size_t N, string num) :CIntN(file_name, N, num) {}//констурктор
    CIntN0() :CIntN() {}//конструктор по умолчанию
    CIntN0(const CIntN& other) :CIntN(other) {}//конструктор копирования

    using CIntN::operator=;

    void output() override final;

    friend CIntN0 operator+(const CIntN& first, const CIntN& second);// friend - может пользоваться приватными полями
    friend CIntN0 operator-(const CIntN& first, const CIntN& second);

    ~CIntN0();
};

#endif
