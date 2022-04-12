#include "CIntN0.h"

CIntN0::~CIntN0()//деструктор
{}

void CIntN0::output()
{
    ofstream fout(FileName);
    for (size_t i = 0; i < N; i++)
    {
        fout << value[i]; // запись строки в файл
    }
    fout.close();
}
//операторы наследника0
CIntN0 operator+(const CIntN& first, const CIntN& second)
{
    if (first.Get_N() != second.Get_N())//только меж объектами одного типа
        throw runtime_error("Error! Addition is only possible between objects of the same type!");

    string s1 = first.Get_num();
    string s2 = second.Get_num();
    int N = first.Get_N();//size_t

    string s3, vr, ss;
    int t1, t2, t3, flag = 0, flag_ = 0, minus = 0;

    if (s1[0] != '-' && s2[0] == '-') //2 + -3
    {
        ss = s1;
        s1 = s2;
        s2 = ss;
    }
    if (s1[0] == '-' && s2[0] != '-')//-2 + 3 
    {
        if (s1[1] > s2[0])//-3+2=-1 <0
        {
            for (int i = N; i > 0; i--)
            {
                t1 = int(s1[i] - '0');
                t2 = int(s2[i - 1] - '0');
                if (t1 - t2 + flag_ < 0)
                {
                    t3 = (t1 + 10 + flag_) - t2;
                    flag_ = -1;
                }
                else
                {
                    t3 = t1 - t2 + flag_;
                    flag = 0;
                }
                if (t3 == 0 && i == 0)// 533-509=24
                    throw runtime_error("The result is a number not of this class!");

                auto ss = to_string(t3);//t3 типа инт в string
                s3.insert(0, ss);
            }
            s3.insert(0, "-");
        }
        else//-2+3=1 >0
        {
            for (int i = N; i > 0; i--)
            {
                t1 = int(s1[i] - '0');
                t2 = int(s2[i - 1] - '0');
                if (t2 - t1 + flag_ < 0)
                {
                    t3 = (t2 + 10 + flag_) - t1;
                    flag_ = -1;
                }
                else
                {
                    t3 = t2 - t1 + flag_;
                    flag = 0;
                }
                if (t3 == 0 && i == 0)// 533-509=24
                    throw runtime_error("The result is a number not of this class!");

                auto ss = to_string(t3);//t3 типа инт в string
                s3.insert(0, ss);
            }
        }

    }
    if (s1[0] == '-' && s2[0] == '-')//-2-3=-5 один знак -
    {
        for (int i = N; i > 0; i--)
        {
            t1 = int(s1[i] - '0');
            t2 = int(s2[i] - '0');
            if (t1 + t2 + flag > 9)
            {
                t3 = (t1 + t2 + flag) % 10;
                flag = 1;
            }
            else
            {
                t3 = t1 + t2 + flag;
                flag = 0;
            }
            if (flag == 1 && i == 0)// 85+16=101
                throw runtime_error("The result is a number not of this class!");

            auto ss = to_string(t3);//t3 типа инт в string
            s3.insert(0, ss);
        }
        s3.insert(0, "-");
    }
    if (s1[0] != '-' && s2[0] != '-')//2+3=5 один знак +
    {
        for (int i = N - 1; i >= 0; i--)
        {
            t1 = int(s1[i] - '0');
            t2 = int(s2[i] - '0');
            if (t1 + t2 + flag > 9)
            {
                t3 = (t1 + t2 + flag) % 10;
                flag = 1;
            }
            else
            {
                t3 = t1 + t2 + flag;
                flag = 0;
            }
            if (flag == 1 && i == 0)// 85+16=101
                throw runtime_error("The result is a number not of this class!");

            auto ss = to_string(t3);//t3 типа инт в string
            s3.insert(0, ss);
        }
    }

    CIntN0 v(first.Get_FileName(), N, s3);
    return v;
}

CIntN0 operator-(const CIntN& first, const CIntN& second)
{
    if (first.Get_N() != second.Get_N())//только меж объектами одного типа
        throw runtime_error("The result is a number not of this class!");

    string s1 = first.Get_num();
    string s2 = second.Get_num();
    int N = first.Get_N();

    string s3, vr, ss;
    int t1, t2, t3, flag = 0, flag_ = 0, minus = 0;

    if (s1[0] != '-' && s2[0] != '-') //2 - +3
        s2.insert(0, "-");
    else if (s1[0] == '-' && s2[0] == '-')//-2 - -3
        s2.erase(0, 1);
    else if (s1[0] == '-' && s2[0] != '-')//-2 - +3 
        s2.insert(0, "-");
    else if (s1[0] != '-' && s2[0] == '-')//2 - -3 
        s2.erase(0, 1);

    CIntN0 ob(second.Get_FileName(), second.Get_N(), s2);

    return first + ob;
}

