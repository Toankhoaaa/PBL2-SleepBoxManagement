#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "Room.h"
using namespace std;

Room::Room(){

}

Room::~Room(){

}

int Room::getDate01(){
    return date01;
}

int Room::getMonth01(){
    return month01;
}

int Room::getYear01(){
    return year01;
}

void Room::Date_of_end(int date,int month,int year,int n){
    ofstream o ("PHG.txt", ios::app);
    time_t now = time(nullptr);
    struct tm* tm_now = localtime(&now);
    // Lấy ngày
    int day1 = tm_now->tm_mday;
    // Lấy tháng
    int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
    // Lấy năm
    int year1 = tm_now->tm_year + 1900; // Năm bắt đầu từ 1900

    date01 = date;
    month01 = month;
    year01 = year;
    for (int j=0;j<n;j++){
        for (int i=0;i<30;i++){
            if (month01 == 4 || month01 == 6 || month01 == 9 || month01 == 11){
                if (date01==30){
                    date01=1;
                    month01++;
                }
            }
            else if (month01==1||month01==3||month01==5||month01==7||month01==8||month01==10){
                if (date01==31){
                    date01=1;
                    month01++;
                }
            }
            else if (month01==2){
                if (year01 % 4 == 0){
                    if (date01==29){
                        date01=1;
                        month01++;
                    }
                }else{
                    if (date01 == 28){
                        date01=1;
                        month01++;
                    }
                }
            }
            else if (month01==12){
                if (date01 == 31){
                    date01=1;
                    month01=1;
                    year01++;
                }
            }
            else {
                cout << "Ban da nhap sai ngay thang nam!!!" << endl;
            }
            date01++;
        }
    }

    try{
        if(year01 > year1){
            cout << "Date_of_end: ";
            cout << date01 << "/" << month01 << "/" << year01 << endl;
        }
        else if(year01 == year1){
            if (month01 > month1){
                cout << "Date_of_end: ";
                cout << date01 << "/" << month01 << "/" << year01 << endl;
            }
            else if (month01 == month1){
                if (date01 > day1){
                    cout << "Date_of_end: ";
                    cout << date01 << "/" << month01 << "/" << year01 << endl;
                }else{
                    throw invalid_argument ("Phong cua ban da het han");
                }
            }else{
                throw invalid_argument ("Phong cua ban da het han");
            }
        }else{
           throw invalid_argument ("Phong cua ban da het han");
        }
    }
    catch(invalid_argument e){
        cout << e.what() << endl;
    }
}

long Room::gia01(int n){
    return 2000000 * n;
}

void Room::Input(){
    ofstream o ("PHG.txt", ios::app);
    time_t now = time(nullptr);
    struct tm* tm_now = localtime(&now);
    // Lấy ngày
    int day1 = tm_now->tm_mday;
    // Lấy tháng
    int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
    // Lấy năm
    int year1 = tm_now->tm_year + 1900; // Năm bắt đầu từ 1900
    Vector<string> idp;
    ifstream inr ("IDP.txt");
    if (inr.is_open()){
        string line1;
        while(inr >> line1){
            idp.push_back(line1);
        }
    }
    inr.close();
    if(!idp.empty()){
        IDP = idp.back();
        cout << "IDP: " << IDP << endl;
        int count = 0;
        do{
            cout << "Date of Begin (dd/mm/yyyy): ";
            cin >> date; cin.ignore(); cin >> month; cin.ignore(); cin >> year;
            try{
                if ((date <= 0 || month <= 0 || date > 31 || month > 12 || year > 2100) || (year < year1 || (year == year1 && month < month1) || (year == year1 && month == month1 && date < day1))){
                    count++;
                    throw invalid_argument ("! Error !");
                }else{
                    break;
                }
            }
            catch(invalid_argument e){
                cout << e.what() << endl;
            }
        }while(date <= 0 || month <= 0 || date > 31 || month > 12 || count != 0 || year > 2100);

        int dk;
        do{
            cout << "+-----Cac goi cho thue phong-------+" << endl;
            cout << "|     1. 1 thang                   |" << endl;
            cout << "|     2. 3 thang + Voucher (15%)   |" << endl;
            cout << "|     3. 6 thang + Free 1 thang    |" << endl;
            cout << "+----------------------------------+" << endl;
            cout << "Ban muon thue goi : ";
            cin >> dk;
            if (dk == 1){
                Date_of_end(date,month,year,1);
                if (day1 == month1){
                    voucher = gia01(1) * 0.05;
                }
                else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                    voucher = gia01(1) * 0.1;
                }
                else {
                    voucher = 0;
                }
                giaphong = gia01(1) - voucher;
                nm = 1;
            }
            else if (dk == 2){
                Date_of_end(date,month,year,3);
                if (day1 == month1){
                    voucher = gia01(3) * 0.2;
                }
                else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                    voucher = gia01(3) * 0.25;
                }
                else {
                    voucher = gia01(3) * 0.15;
                }
                giaphong = gia01(3) - voucher;
                nm = 3;
            }
            else{
                Date_of_end(date,month,year,7);
                if (day1 == month1){
                    voucher = gia01(6) * 0.05 + gia01(1);
                }
                else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                    voucher = gia01(6) * 0.1 + gia01(1);
                }
                else {
                    voucher = gia01(1);
                }
                giaphong = gia01(7) - voucher;
                nm = 7;
            }
        }while(dk != 1 && dk != 2 && dk != 3);

        ofstream onr ("IDP.txt",ios::out);
        idp.pop_back();
        for (size_t i = 0; i< idp.Size();++i){
            string IdpEntry = idp[i];
            onr << IdpEntry << endl;
        }
        onr.close();
    }else {
        IDP = "0";
        cout << "Hien tai khong con phong cho ban . Xin Cam On" << endl;
    }
}

ostream& operator << (ostream& o, Room& a){
    o << a.getDate01() << "/" << a.getMonth01() << "/" << a.getYear01() << endl;
    return o;
}