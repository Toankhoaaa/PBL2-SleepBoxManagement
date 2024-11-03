#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Room {
    protected:
        string IDP;
        int date;
        int month;
        int year;
        int date01;
        int month01;
        int year01;
        long giaphong;
        int voucher;
        int nm;
    public:
        Room();
        ~Room();
        void Input();
        int getDate01();
        int getMonth01();
        int getYear01();
        void Date_of_end(int,int,int,int); 
        long gia01(int n);
        friend ostream& operator << (ostream& , Room&);
};