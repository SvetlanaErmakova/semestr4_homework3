#include "CIntN.h"
#include "CIntN0.h"

#include <chrono>
#include <omp.h>

void parallel(int s1, size_t s2)
{
	vector<CIntN0> vec1;
	vector<CIntN0> vec2;
    vector<CIntN0> vec_rez;

    string b, num1, num2;
    for(int i=0; i<s1; i++)
    {
        num1 = "", num2 = "";
        for (int j = 0; j < s2; j++)
        {
            b = to_string(rand() % (4));
            num1 = num1 + b;
            num2 = num2 + b;
        }

        vec1.push_back(CIntN0("data1", s2, num1));
        vec2.push_back(CIntN0("data2", s2, num2));
    }

    //без омп
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < s1; i++)
    {
        vec_rez.push_back(vec1[i] + vec2[i]);
    }
    auto end = std::chrono::system_clock::now();
    int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    std::cout<< "Addition operator without parallelization runtime is "<< elapsed_ms <<" ms\n";

    //с омп
    auto start1 = std::chrono::system_clock::now();
    //omp_set_dynamic(0); // запретить библиотеке openmp менять число потоков во время исполнения
    //omp_set_num_threads(6);
    int d = 0;
#pragma omp parallel for shared(vec1, vec2, vec_rez) private(d)
    for (d = 0; d < s1; d++)
    {
        vec_rez[d] = vec1[d] + vec2[d];
    }
    auto end1 = std::chrono::system_clock::now();
    int elapsed_ms1 = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count());
    std::cout << "Addition operator with parallelization runtime is " << elapsed_ms1 << " ms\n";

    //
    vec1.clear(); 
    vec2.clear();
    vec_rez.clear();
}