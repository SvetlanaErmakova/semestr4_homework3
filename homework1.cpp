#include "CIntN.h"
#include "CIntN1.h"
#include "CIntN0.h"

#include <map>
#include "Factory.h"

#include "Autotest.h"

void parallel(int s1, size_t s2);

int main()
{
    if (Autotest() != 1)
        throw runtime_error("Error! Tests failed!");
    try
    {
        //распараллеливание
        int s1; 
        size_t s2;

        cout << "array size: ";
        cin >> s1;
        if (s1<1)
            throw runtime_error("Error! s1 should be >=1");

        cout << "number size: ";
        cin >> s2;
        if (s2<1)
            throw runtime_error("Error! s2 should be >=1");

        parallel(s1, s2);
        //


        cout << "Input file name: \n";
        string file_name;
        cin >> file_name;

        ifstream inp(file_name);
        if (!inp)
        {
            throw runtime_error("Error! Cannot open file!");
        }

        size_t strok=0;
        string line;
        while (getline(inp, line)) //сколько строк
            strok ++ ;
        inp.close();

        //CIntN** arr = (CIntN**)malloc(sizeof(CIntN*)*strok);
        vector<CIntN*> vec;

        string I;
        size_t N;
        string name_f, num;
        size_t i = 0;

        inp.open(file_name);

        map<string, Factory*> factoryMap;
        factoryMap["hori"] = new Factory_hori;
        factoryMap["vert"] = new Factory_vert;

        while (!inp.eof())
        {
            inp >> I;
            inp >> name_f;
            inp >> N;
            inp >> num;

            auto Creator = factoryMap.find(I);
            if (Creator == factoryMap.end())
                throw runtime_error("There is no such class!");
            vec.push_back(Creator->second->create(name_f, N, num));

            i++;
        }
        inp.close();

        for (auto i : vec)
        {
            i->output();
            i->print_num();
        }

        CIntN0 v1("data_out1.txt", 3, "101");
        CIntN1 v2("data_out2.txt", 3, "-555");
        CIntN0 v3 = v1 + v2;
        CIntN0 v4 = v1 - v2;
        v3.print_num();
        v4.print_num();

        for (auto i : vec)
            delete i;

        return 0;
    }
    catch (const exception& e) 
    {
        cerr << e.what() << '\n';
        return 1;
    }
}



