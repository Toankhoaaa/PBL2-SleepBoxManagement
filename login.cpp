#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "login.h"
using namespace std;
login::login(){

}

login::~login(){
    
}

int login::authenticate(string u, string p){
    ifstream in_file ("password.txt");
    if(in_file.is_open()){
        string line;
        while(getline(in_file,line)){
            if(line.find(u) != string::npos){
                istringstream ss(line);
                string token;
                getline (ss,token,'|');
                this->username = token;
                getline (ss,token,'|');
                this->password = token;
            }
        }
    }
    in_file.close();
    if(u == this->username && p == this->password){
        if(u.find("QL-") != string::npos){
            return 1;
        }
        else if (u.find("NV-") != string::npos){
            return 2;
        }
        else if (u.find("KH-") != string::npos){
            return 3;
        }
    }else{
        return 0;
    }
}