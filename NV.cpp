#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "NV.h"

using namespace std;

nv::nv(){

}
nv::~nv(){
    
}

int stringToInt(const string& str) {
    int result;
    istringstream iss(str);
    return result;
}

void nv::nhap(){ 
    Vector<string> mnv;
    Person::input();
    do{
        cout << "Office: ";
        getline(cin,chucdanh);
        try{
            if (chucdanh == "Phuc Vu" || chucdanh == "phuc vu" || chucdanh == "Quan Ly" || chucdanh == "quan ly" || chucdanh == "pha che" || chucdanh == "Pha Che"){
                break;
            }else{
                throw invalid_argument (" => Ban da nhap sai office! ");
            }
        }
        catch(invalid_argument e){
            cout << e.what() << endl;
        }
    }while(chucdanh != "Phuc Vu" || chucdanh != "phuc vu" || chucdanh != "Quan Ly" || chucdanh != "quan ly"|| chucdanh != "pha che" || chucdanh != "Pha Che");

    if (chucdanh == "Phuc Vu" || chucdanh == "phuc vu"){
        ifstream ins ("MaNV.txt");
        if (ins.is_open()){
            string line;
            while(getline(ins,line)){
                mnv.push_back(line);
            }
        }
        ins.close();
    }
    else if (chucdanh == "Pha Che"||chucdanh == "pha che"){
        ifstream inp ("MaPC.txt");
        if (inp.is_open()){
            string line1;
            while(getline(inp,line1)){
                mnv.push_back(line1);
            }
        }
        inp.close();
    }
    else{
        ifstream inq ("MaQL.txt");
        if (inq.is_open()){
            string line3;
            while(getline(inq,line3)){
                mnv.push_back(line3);
            }
        }
        inq.close();
    }
    if(!mnv.empty()){
        manv = mnv.back();
        cout << "MANV: " << manv << endl;
        if (chucdanh == "Phuc Vu" || chucdanh == "phuc vu"){
            ofstream ons ("MaNV.txt",ios::out);
            mnv.pop_back();
            for (size_t i = 0; i< mnv.Size();++i){
                string manvEntry = mnv[i];
                ons << manvEntry << endl;
            }
            ons.close();
        }
        else if (chucdanh == "Pha Che"||chucdanh == "pha che"){
            ofstream onp ("MaPC.txt",ios::out);
            mnv.pop_back();
            for (size_t i = 0; i< mnv.Size();++i){
                string manvEntry = mnv[i];
                onp << manvEntry << endl;
            }
            onp.close();
        }
        else{
            ofstream onq ("MaQL.txt",ios::out);
            mnv.pop_back();
            for (size_t i = 0; i< mnv.Size();++i){
                string manvEntry = mnv[i];
                onq << manvEntry << endl;
            }
            onq.close();
        }
        cout << "Salary: " << Caculator_Salary () << endl;
        ofstream outfile("NhanVien.txt", ios::app);
        outfile << setw(4) << age << setw(3) << "|" << setw(6) << gender << setw(4) << "|" << setw(20)  << name <<setw(4) << "|" << setw(9)  << manv << setw(4) << "|" << setw(10)  << salary << setw(4) << "|" << setw(10) << chucdanh << setw(4) << "|" << endl;
        outfile.close();
    }else {
        cout << "Da du so luong nhan vien" << endl;
    }
}

long long nv::Caculator_Salary(){
    if (chucdanh == "Phuc Vu" || chucdanh == "phuc vu"){
       
       salary = 5000000;
    }
    else if ( chucdanh == "Quan Ly" || chucdanh == "quan ly"){
        salary = 10000000;
    }
    else {
        salary = 5000000;
    }
    return salary;
}
