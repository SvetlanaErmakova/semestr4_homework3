#include "CIntN1.h"

CIntN1::~CIntN1()//����������
{}
void CIntN1::output()
{
    ofstream fout(FileName);
    for (size_t i = 0; i < N; i++)
    {
        fout << value[i] << '\n'; // ������ ������� � ����
    }
    fout.close();
}
