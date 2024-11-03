#include <iostream>
#include <fstream>
#include <iomanip>
#include "Person.h"
using namespace std;

Person::Person(){

}

Person::~Person(){
    
}

int Person::getAge(){
    return age;
}

void Person::setAge(int age){
    this->age = age;
}

string Person::getName(){
    return name;
}

void Person::setName (string name){
    this->name = name;
}

void Person::input(){
    cout << "Age: ";
    cin >> age;
    do{
        cout << "Name: ";
        cin.ignore();
        getline (cin,name);
        try{
            if (name.size() >= 5 && name.size() <= 37){
                break;
            }else{
                throw invalid_argument ("Ten cua ban chua chinh xac!");
            }
        } 
        catch (invalid_argument e){
            cout << e.what() << endl;
        }
    }while (name.size() < 5 || name.size() > 37 );
    
    do{
        cout << "Gender: ";
        getline(cin, gender);    
        try{
            if (gender == "nam" || gender == "nu" || gender == "Nam" || gender == "Nu"){
                break;
            }
            else{
                throw invalid_argument("Gioi Tinh Ban Nhap Khong Hop Le");
            }
        }
        catch (invalid_argument e){
            cout << e.what() << endl;
        }
    }while (gender != "nam" || gender != "nu" || gender != "Nam" || gender != "Nu");
}