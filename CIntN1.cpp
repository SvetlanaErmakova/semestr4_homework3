#include "CIntN1.h"

CIntN1::~CIntN1()//деструктор
{}
void CIntN1::output()
{
    ofstream fout(FileName);
    for (size_t i = 0; i < N; i++)
    {
        fout << value[i] << '\n'; // запись столбца в файл
    }
    fout.close();
}
