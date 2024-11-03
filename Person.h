#pragma once
#include <string>
#include "Vector.cpp"
using namespace std;

class Person{
    protected:
        int age;
        string name;
        string gender;
    public:
        Person();
        ~Person();
        int getAge();
        void setAge(int);
        string getName();
        void setName (string);
        void input();
};