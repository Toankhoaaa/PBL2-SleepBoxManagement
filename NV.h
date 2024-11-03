#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class nv : public Person{
    protected:
        string manv;
        long salary;
        string chucdanh;
    public:
        nv();
        ~nv();
        int getMANV();
        void setMANV(string MANV);
        long long Caculator_Salary();
        void nhap();
};