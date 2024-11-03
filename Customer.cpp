#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <limits>
#include "Customer.h"
using namespace std;

Customer::Customer(){

}

Customer::~Customer(){
    
}

bool Customer::KtraNV(string MAQL){
    ifstream fileN("NhanVien.txt");
    if (fileN.is_open()){
        string line1;
        while (getline(fileN, line1)) {
            if (line1.find(MAQL) != std::string::npos) {
                return true;
            }
        }
    }
    fileN.close();
}

void Customer::Input(){
    time_t now = time(nullptr);
    struct tm* tm_now = localtime(&now);
    // Lấy ngày
    int day1 = tm_now->tm_mday;
    // Lấy tháng
    int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
    // Lấy năm
    int year1 = tm_now->tm_year + 1900; // Năm bắt đầu từ 1900
    Vector<string> mkh;
    ifstream in ("MaKH.txt");
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            mkh.push_back(line);
        }
    } else {
        cout << "FILE Khong Ton Tai" << endl;
    }
    in.close();
    Person::input();
    if (age >= 18){
        do{
            cout << "Ma Nhan Vien Dang Ki: ";
            getline(cin,MAQL);
        }while (MAQL.length() != 6 && MAQL.substr(0, 3) != "NV-");
            if (KtraNV(MAQL)){
                int sdt,mail;
                if(!mkh.empty()){
                    makh = mkh.back();
                    cout << "MAKH: " << makh << endl;
                    do{
                        ifstream fileF ("SDT.txt");
                        if (fileF.is_open()){
                            cout << "SDT: ";
                            getline(cin,SDT);
                            try{
                                if (SDT.size()!=10){
                                    throw invalid_argument ("=> So dien thoai can du 10 so ");
                                }else{
                                    sdt = 0;
                                    string line3;
                                    while (getline(fileF, line3)){
                                        if (line3.find(SDT) != std::string::npos){
                                            sdt = 1;
                                            cout << "SDT nay da duoc dang ki" << endl;
                                            break;
                                        }
                                    }
                                }
                            } 
                            catch (invalid_argument e){
                                cout << e.what() << endl;
                            }
                        }
                        fileF.close();
                    }while (SDT.size()!=10 || sdt == 1);
                                
                    do{
                        ifstream fileG ("Gmail.txt");
                        if (fileG.is_open()){
                            mail= 0;
                            cout << "MAIL: ";
                            getline(cin,MAIL);
                            try{
                                if (MAIL.find("@gmail.com") != string::npos && MAIL.find("@gmail.com") == MAIL.length() - 10){
                                    string line4;
                                    while (getline(fileG, line4)){
                                        if (line4.find (MAIL) != std::string::npos){
                                            mail= 1;
                                            cout << "MAIL nay da duoc dang ki" << endl;
                                            break;
                                        }
                                    }
                                }else{
                                    throw invalid_argument ("=> MaiL hop le co duoi :  @gmail.com ");
                                }
                            } 
                            catch (invalid_argument e){
                                cout << e.what() << endl;
                            }
                        }
                        fileG.close();
                    }while ((MAIL.find("@gmail.com") == string::npos && MAIL.find("@gmail.com") != MAIL.length() - 10) || mail == 1);


                    do{
                        cout << "Birthday (dd/mm/yyyy): ";
                        cin >> datebirthday; cin.ignore(); cin >> monthbirthday; cin.ignore(); cin >> yearbirthday;
                        try{
                            if (datebirthday <= 0 || monthbirthday <= 0 || (year1 - yearbirthday) < 18 || datebirthday > 31 || monthbirthday > 12 || yearbirthday > year1){
                                throw invalid_argument ("=> Ngay sinh cua ban sai dinh dang hoac nam sinh va tuoi cua ban khong khop . Vui Long nhap lai (dd/mm/yyyy) ");
                            }else{
                                break;
                            }
                        }
                        catch(invalid_argument e){
                            cout << e.what() << endl;
                        }
                    }while (datebirthday <= 0 || monthbirthday <= 0 || yearbirthday > year1 || datebirthday > 31 || monthbirthday > 12 || (year1 - yearbirthday) < 18);
                    Room::Input();
                    if (IDP != "0"){
                        cout << "+---------------------------------------------+" << endl;
                        cout << "|             HOA DON THANH TOAN              |" << endl;
                        cout << "|                                             |" << endl;
                        cout << "|      Name  : " << setw(31) << left << name << "|" << endl;
                        cout << "|      Age   : " << setw(31) << left << age << "|" << endl;
                        cout << "|      Gender: " << setw(31) << left << gender << "|" << endl;
                        cout << "|      MAKH  : " << setw(31) << left << makh << "|" << endl;
                        cout << "|      IDP   : " << setw(31) << left << IDP << "|" << endl;
                        cout << "|      Tong Tien Phong : " << setw(15) << right << gia01(nm) <<" VND  |" << endl;
                        cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                        cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                        cout << "|                                             |" << endl;
                        cout << "+---------------------------------------------+" << endl;
                        ofstream os ("MaKH.txt",ios::out);
                        ofstream out("SDT.txt",ios::app);
                        ofstream outG ("Gmail.txt",ios::app);
                        mkh.pop_back();
                        for (size_t i = 0; i < mkh.Size(); ++i) {
                            string makhEntry = mkh[i];
                            os << makhEntry << endl;
                        }
                        out << SDT << endl;
                        outG << MAIL << endl;
                        os.close();
                        out.close();
                        outG.close();
                        mkh.clear();
                        ofstream outK ("KhachHang.txt", ios::app);
                        ofstream oP ("PHG.txt", ios::app);
                        ofstream osE ("HoaDon.txt",ios::app);
                        ofstream tt ("ThanhToan.txt",ios::app);
                        outK << setw(5) << age << setw(4) << "|" << setw(20) << name << setw(4) << "|" << setw(10) << gender <<  setw(8) << "|" << setw(8) << IDP <<   setw(6) << "|" << setw(10) << makh << setw(5) << "|" << setw(13)<< SDT <<  setw(4) << "|" << setw(25) << MAIL << setw(4) << "|" << setw(5) << datebirthday << "/" << setw(2) << monthbirthday << "/" << yearbirthday << setw (4) << "|" << setw(8) << MAQL << setw(2) << "|" << endl;
                        oP << setw(8)<< makh << setw(2) << "|" << setw(8) << MAQL << setw(2) << "|" << setw(6) << IDP << setw(4) << "|" << setw(5) << date << "/" << setw(2) << month <<  "/" << year << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                        osE << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << makh << setw(2) << "|" << setw(10) << giaphong << setw(4) << "|" << setw(15) << "Dang Ki Phong" << setw(3) << "|" << endl;
                        tt << setw(9) << makh << setw(4) << "|" << setw(12) << giaphong << setw(4) << "|" << endl;
                        outK.close();
                        oP.close();
                        osE.close();
                    }
                }else{
                    cout << "=> Het Phong Cho Thue . Xin Cam On Quy Khach . Hen Gap Lai Quy Khach" << endl;
                }
            }
    }else{
        cout << "Do tuoi cua ban chua duoc phep thue phong. Xin Cam On" << endl;
    }
    
}
