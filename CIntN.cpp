#include "CIntN.h"

CIntN::CIntN()//конструктор по умолчанию
{
    N = 0;
    value = NULL;
    FileName = "f";
    num = " ";
}

CIntN::CIntN(string file_name, size_t N_, string num_)//конструктор
{
    if(num_[0]=='-' && num_.size() != N_+1 || num_[0] != '-' && num_.size()!= N_)
        throw - 1;

    N = N_;
    num = num_;
    FileName = file_name;

    value = (int*)malloc(N * sizeof(int));
    int fl = 1;
    for (size_t i = 0; i < N; i++)
    {
        if (i == 0)
            if (num[i] == '-')
                fl = -1;
        if (fl == -1)
        {
            if (num[i + 1] >= '0' && num[i + 1] <= '9')//цифра ли
            {
                if (i == 0)
                    value[i] = -1 * (num[i + 1] - '0');
                else
                    value[i] = num[i + 1] - '0';
            }
            else
                throw - 1;
        }
        else
        {
            if (num[i] >= '0' && num[i] <= '9')//цифра ли
            {
                value[i] = num[i] - '0';
            }
            else
                throw runtime_error("It's not a number!");
        }
    }
}

CIntN::CIntN(const CIntN& other)//конструктор копирования
{
    N = other.Get_N();
    num = other.Get_num();
    FileName = other.Get_FileName();

    value = (int*)malloc(N * sizeof(int));
    for (size_t i = 0; i < N; i++)
    {
        value[i] = other.Get_val_i(i);
    }
}

CIntN::~CIntN()//деструктор
{
    delete[] value;
}

//операторы
CIntN& CIntN::operator=(const CIntN& other)
{
    N = other.Get_N();
    num = other.Get_num();
    FileName = other.Get_FileName();

    value = (int*)malloc(N * sizeof(int));
    for (size_t i = 0; i < N; i++)
    {
        value[i] = other.Get_val_i(i);
    }
    return *this;
}

//функции
size_t CIntN::Get_N() const
{
    return N;
}

string CIntN::Get_FileName() const
{
    return FileName;
}

string CIntN::Get_num() const
{
    return num;
}

int CIntN::Get_val_i(int i) const
{
    return value[i];
}

void CIntN::print_num()
{
    for (size_t i = 0; i < N; i++)
    {
        cout << value[i];
    }
    cout << "\n";
}



