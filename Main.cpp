#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 
#include <sstream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include "login.h"
#include "mylib.cpp"
#include "Customer.h"
#include "NV.h"
using namespace std;
//Tạo Menu NV
void DrawMenuNV(){    
    cout << "*****************************************   MENU   *********************************************" << endl;
    cout << "**                                                                                            **" << endl;
    cout << "**       1.Nhap Thong Tin Nhan Vien                   7.Danh Sach Phong Ma NV Quan Ly         **" << endl;
    cout << "**       2.Danh Sach Thong Tin Nhan Vien              8.Khoi Phuc DL Tu RecyleBin             **" << endl;
    cout << "**       3.Thong Ke Nhan Vien                         9.Doanh Thu - Loi Nhuan                 **" << endl; 
    cout << "**       4.Xoa Thong Tin Nhan Vien                    10.Phan Hoi Tu Khach Hang               **" << endl;
    cout << "**       5.Them Thong Tin Nhan Vien                   11.Danh Sach Khach Hang                 **" << endl;
    cout << "**       6.Tim Thong Tin Nhan Vien                    12.Danh Sach Phong                      **" << endl;
    cout << "**                                     13.Doi Mat Khau                                        **" << endl;
    cout << "**                                         0.Thoat                                            **" << endl;
    cout << "************************************************************************************************" << endl;
}
//Tạo Menu Khach Hang
void DrawMenuKH(){
    cout << "*****************************************   MENU   ****************************************" << endl;
    cout << "**                                                                                       **" << endl;
    cout << "**       1.Nhap Thong Tin Khach Hang                   6.Reset Khach Hang                **" << endl;
    cout << "**       2.Danh Sach Thong Tin Khach Hang              7.Tra Phong                       **" << endl;
    cout << "**       3.Thong Ke Thong Tin Khach Hang               8.Gia Han Phong                   **" << endl; 
    cout << "**       4.Them Thong Tin Khach Hang                   9.Dang Ki KH Da Thue Truoc Do     **" << endl;
    cout << "**       5.Tim Thong Tin Khach Hang                    10.Kiem Tra Phong Trong           **" << endl; 
    cout << "**                                     11.Thanh Toan                                     **" << endl;
    cout << "**                                     12.Doi Mat Khau                                   **" << endl;
    cout << "**                                        0.Thoat                                        **" << endl;
    cout << "*******************************************************************************************" << endl;
}
//Đảo Trạng Thái Cho MANV
void ParseDataNV4 (const string& line){
    istringstream ss(line);
    string token;
    getline(ss, token, '|');
    int age = stoi(token);
    getline(ss, token, '|');
    string gender = token;
    getline(ss, token, '|');
    string name = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    string manv = token;
    getline(ss, token, '|');
    int salary = stoi(token);
    getline(ss, token, '|');
    string chucdanh = token;
    if (chucdanh == "   Pha Che   "){
        ofstream on ("MaPC.txt",ios::app);
        on << manv << endl;
        on.close();
    }
    else if (chucdanh == "   Quan Ly   "){
        ofstream out ("MaQL.txt",ios::app);
        out << manv << endl;
        out.close();
    }else{
        ofstream on ("MaNV.txt",ios::app);
        on << manv << endl;
        on.close();
    }
}
//Đảo Trạng Thái Cho MAKH
void ParseDataKH4 (const string& line){
    string name, birthday, gender, sdt,mail,idp,makh,maql;
    int age;
    istringstream ss(line);
    string token;
    getline(ss, token, '|');
    age = stoi(token);
    getline(ss, token, '|');
    name = token;
    getline(ss, token, '|');
    gender = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    idp = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    makh = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    sdt = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    mail = token;
    getline(ss,token,'|');
    birthday = token;
    getline(ss, token, '|');
    maql = token;
    ofstream out ("MaKH.txt",ios::app);
    ofstream out_file ("IDP.txt",ios::app);
    out << makh << endl;
    out_file << idp << endl;
    out.close();
    out_file.close();
    
}
//Đảo Trạng Thái Phòng
void ParseKHout4 (const string& line){
    string name, birthday, gender, sdt,mail,idp,makh,maql;
    int age;
    istringstream ss(line);
    string token;
    getline(ss, token, '|');
    age = stoi(token);
    getline(ss, token, '|');
    name = token;
    getline(ss, token, '|');
    gender = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    idp = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    makh = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    sdt = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    mail = token;
    getline(ss,token,'|');
    birthday = token;
    getline(ss, token, '|');
    maql = token;
    ofstream out_file ("KhachHangout.txt",ios::app);
    out_file << setw(5) << age << setw(4) << "|" << name <<  "|" << gender << "|" << setw(13)<< sdt <<  setw(4) << "|" << setw(25) << mail << setw(4) << "|" << setw(13) << birthday << "|" << endl;
    out_file.close();
}
//Đọc Dữ Liệu Từ File
bool readLinesFromFile(const string& filename){
    Vector<string> s;
    int count = 0;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            count++;
            s.push_back(line);
        }
        if (count == 0){
            cout << "Du Lieu Rong" << endl;
            return false;
        }else{
            cout << s;
        }
    } else {
        cout << "FILE Khong Ton Tai" << endl;
    }
    file.close();
}
//Vector lưu trữ dữ liệu trong file
Vector<string> readLinesFromFile1(const string& filename) {
    Vector<string> lines;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        cout << "FILE Khong Ton Tai" << endl;
    }

    return lines;
}
//Vector lưu trữ dữ liệu trong file dựa trên dữ liệu cho vào
Vector<string> readLinesFromFilesWithIf(const string& filename,string a){
    Vector<string> lines;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(a) != string::npos && (line.find("AGE") == string::npos && line.find("--------")== string::npos && line.find("MAKH") == string::npos)){
                lines.push_back(line);
            }
        }
        file.close();
    } else {
        cout << "FILE Khong Ton Tai" << endl;
    }

    return lines;
}
//Đọc Dữ Liệu Từ File Trừ Mục 
Vector<string> readVallueFromFile(const string& filename){
    Vector<string> data;
    Vector<string> datasub;
    ifstream in (filename);
    if (in.is_open()){
        string line;
        while(getline(in,line)){
            if (line.find("AGE") == string::npos && line.find("--------")== string::npos && line.find("MAKH") == string::npos){
                data.push_back(line);
            }
        }
    }else{
        cout << "File Error" << endl;
    }
    in.close();
    for (int i = 0 ; i < data.Size();i++){
        if (filename == "NhanVien.txt" && data[i] != "  AGE | GENDER  |          NAME         |    MANV    |    SALARY   |   OFFICE    |" && data[i] != "------+---------+-----------------------+------------+-------------+-------------+"){
            datasub.push_back(data[i]);
        }
        else if (filename == "KhachHang.txt" && data[i] != "   AGE  |         NAME          |     GENDER      |     IDP     |     MaKH     |       SDT      |            MAIL            |    BIRTHDAY    |   MAQL  |" && data[i] != "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+"){
            datasub.push_back(data[i]);
        }
        else if (filename == "PHG.txt" && data[i] != "   MAKH  |  MAQL   |   IDP   |      Begin     |      End       |  GIA PHONG  |" && data[i] != "---------+---------+---------+----------------+----------------+-------------+"){
            datasub.push_back(data[i]);
        }
        // else if (filename == "KhachHangout.txt" && data[i] != "   AGE  |         NAME          |     GENDER      |       SDT      |            MAIL            |    BIRTHDAY    |" && data[i] != "--------+-----------------------+-----------------+----------------+----------------------------+----------------+"){
        //     datasub.push_back(data[i]);
        // }
    }
    return datasub;
}
//Tìm Kiếm Dữ Liệu Trong File Dựa Trên Dữ Liệu Cho Vào
bool FindLinesFromFiles(const string& filename,string a){
    int count1;
    ifstream file(filename);
    if (file.is_open()) {
        count1 = 0;
        if (filename == "NhanVien.txt" || filename == "RecycleBinNV.txt"){
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            string line;
            while (getline(file, line)){
                if (line.find(a) != string::npos) {
                    count1++;
                    cout << line << endl;
                    cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                }
            }
        }
        else if (filename == "KhachHang.txt" || filename == "RecycleBinKH.txt"){
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            string line;
            while (getline(file, line)){
                if (line.find(a) != string::npos) {
                    count1++;
                    cout << line << endl;
                    cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                }
            }
        }else if (filename == "PHG.txt" || filename == "RecycleBinRoom.txt"){
            cout << "---------+---------+---------+----------------+----------------+-------------+" << endl;
            cout << setw(7) <<"MAKH" << setw(3) << "|" << setw(6) << "MAQL" << setw(4) << "|" << setw(6) << "IDP" << setw(4) << "|" << setw(11) << "Begin" << setw(6) << "|" << setw(9) << "End" << setw(8) << "|" << setw(11) << "GIA PHONG" << setw(3) << "|" << endl;
            cout << "---------+---------+---------+----------------+----------------+-------------+" << endl;
            string line;
            while (getline(file, line)) {
                if (line.find(a) != std::string::npos) {
                    count1 ++;
                    cout << line << endl;
                    cout << "---------+---------+---------+----------------+----------------+-------------+" << endl;
                }
            }
        }else{
            cout << "File Khong Ton Tai" << endl;
        }
        if (count1 == 0){
            cout << "Du Lieu Khong Ton Tai" << endl;
            return false;
        }else{
            return true;
        }
    }
    file.close();
}
//Xóa Dữ Liệu Trong File Dựa Trên Dữ Liệu Cho Vào
bool DeleteLinesFromFiles(const string& filename,string a){
    Vector <string> p;
    ifstream in(filename);
    int count1 = 0;
    string lineDelete9;
    if (in.is_open()) {
        string line3;
        while (getline(in, line3)) {
            p.push_back(line3);
            if (line3.find (a) != std::string::npos) {
                count1 ++;
                lineDelete9 = line3;
            }
        }
        if (count1 == 0){
            cout << "Du Lieu Khong Ton Tai" << endl;
            return false;
        }
    } else {
        cout << "FILE Khong Ton Tai" << endl;
    }
    in.close();

    ofstream on(filename, ios::out);
    for (size_t i = 0; i < p.Size(); ++i){
        if(lineDelete9 != p[i]){
            string idpEntry = p[i];
            on << idpEntry << endl;
        }
    }
    on.close();
}
//Xóa Dữ Liệu Trong File Và Cho Vào Thùng Rác Dựa Trên Dữ Liệu Cho Vào 
bool DeleteLinesFromFiles1(const string& filename,const string& filename1,string a){
    Vector <string> p;
    ifstream in(filename);
    string lineDelete9;
    if (in.is_open()) {
        string line3;
        while (getline(in, line3)) {
            p.push_back(line3);
            if (line3.find (a) != string::npos) {
                lineDelete9 = line3;
            }
        }
    } else {
        cout << "FILE Khong Ton Tai" << endl;
    }
    in.close();

    ofstream on(filename, ios::out);
    ofstream oo1(filename1,ios::app);
    for (size_t i = 0; i < p.Size(); ++i){
        if(lineDelete9 != p[i]){
            string idpEntry = p[i];
            on << idpEntry << endl;
        }
    }
    oo1 << lineDelete9 << endl;
    oo1.close();
    on.close();
}
//Chức Năng Xóa Dữ Liệu Mục 4 Trong MeNu
bool DeleteLinesFromFiles2(const string& filename,const string& filename1,string a){
    Vector <string> k;
    ifstream file(filename);
    int count = 0;
    string lineDelete1;
    if (file.is_open()) {
        if (filename == "KhachHang.txt"){
            string line2;
            while (getline(file, line2)) {
                k.push_back(line2);
                if (line2.find (a) != std::string::npos) {
                    count++;
                    lineDelete1 = line2;
                }
            }
        }else{
            string line3;
            while (getline(file, line3)) {
                k.push_back(line3);
                if (line3.find(a) != std::string::npos) {
                    count++;
                    lineDelete1 = line3;
                }
            }
        }
        if (count == 0){
            cout << "Du Lieu Khong Ton tai" << endl;
            return false;
        }else{
            if(filename == "KhachHang.txt"){
                cout << "Thong Tin Khach Hang:" << endl;
                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                cout << lineDelete1 << endl;
                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            }else if (filename == "NhanVien.txt"){
                cout << "Thong Tin Nhan Vien:" << endl;
                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                cout << lineDelete1 << endl;
                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            }
        }
    } else {
        cout << "FILE Khong Ton Tai" << endl;
    }
    file.close();

    int tick;
    do{
        cout << "+-----------------------------------------+" << endl;
        cout << "|       Ban chac chan muon xoa khong?     |" << endl; 
        cout << "|          1.Yes            2.No          |" << endl;
        cout << "+-----------------------------------------+" << endl;
        cout << "Nhap Y/N de xac nhan: "; 
        cin >> tick;
        if (tick == 1){
            ofstream outfile(filename, ios::out);
            ofstream oo (filename1,ios::app);
            for (size_t i = 0; i < k.Size(); ++i){
                if(lineDelete1 != k[i]){
                    string makhEntry = k[i];
                    outfile << makhEntry << endl;
                }
            }
            oo << lineDelete1 << endl;
            oo.close();
            outfile.close();
            if (filename == "KhachHang.txt"){
                ParseDataKH4(lineDelete1);
                ParseKHout4 (lineDelete1);
                DeleteLinesFromFiles1("PHG.txt","RecycleBinRoom.txt",a);
                cout << "       COMPLETE       " << endl;
            }else if (filename == "NhanVien.txt"){
                ParseDataNV4(lineDelete1);
                DeleteLinesFromFiles1("NhanVien.txt","RecycleBinNV.txt",a);
                cout << "       COMPLETE       " << endl;
            }
        }
        else if (tick == 2){
            ofstream o (filename,ios::out);
            for (size_t i = 0; i < k.Size(); ++i){
                string makhEntry1 = k[i];
                o << makhEntry1 << endl;
            }
            o.close();
        }
        else{
            cout << "Nhap 1 or 2" << endl;
        }
    }while(tick!=1 && tick!=2);
}
//Đảo Trạng Thái MANV Khi Nhan Viên Được Khôi Phục Từ Thùng Rác
void DeleteMaNV (const string& line){
    istringstream ss(line);
    string token;
    getline(ss, token, '|');
    int age = stoi(token);
    getline(ss, token, '|');
    string gender = token;
    getline(ss, token, '|');
    string name = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    string manv = token;
    getline(ss, token, '|');
    int salary = stoi(token);
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    string chucdanh = token;
    Vector<string> nv = readLinesFromFile1("MaNV.txt");
    Vector<string> pc = readLinesFromFile1("MaPC.txt");
    Vector<string> ql = readLinesFromFile1("MaQL.txt");
    if (chucdanh == "PhucVu" || chucdanh == "phucvu"){
        ofstream on_file ("MaNV.txt",ios::out);
        for (int i=0;i<nv.Size();++i){
            if (manv != nv[i]){
                on_file << nv[i] << endl;
            }
        }
        on_file.close();
    }
    else if (chucdanh == "PhaChe"||chucdanh == "phache"){
        ofstream os ("MaPC.txt",ios::out);
        for (int i=0;i<pc.Size();++i){
            if(manv != pc[i]){
                os << pc[i] << endl;
            }
        }
        os.close();
    }
    else {
        ofstream on ("MaQL.txt",ios::out);
        for (int i=0;i<ql.Size();++i){
            if (manv != ql[i]){
                on << ql[i] << endl;
            }
        }
        on.close();
    }
}
//Đảo Trạng Thái MAKH Khi Khách Hàng Được Khôi Phục Từ Thùng Rác
void DeleteMaKH (const string& line){
    string name, birthday, gender, sdt,mail,idp,makh,maql;
    int age;
    istringstream ss(line);
    string token;
    getline(ss, token, '|');
    age = stoi(token);
    getline(ss, token, '|');
    name = token;
    getline(ss, token, '|');
    gender = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    idp = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    makh = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    sdt = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    mail = token;
    getline(ss,token,'|');
    birthday = token;
    getline(ss, token, '|');
    maql = token;
    Vector<string> kh = readLinesFromFile1("MaKH.txt");
    Vector<string> room = readLinesFromFile1("IDP.txt");
    ofstream out_file ("MaKH.txt",ios::out);
    for (int i = 0; i < kh.Size(); ++i){
        if (makh != kh[i]){
            out_file << kh[i] << endl;
        }
    }
    out_file.close();

    ofstream os_file ("IDP.txt",ios::out);
    for (int i = 0; i < room.Size();++i){
        if (idp != room[i]){
            os_file << room[i] << endl;
        }
    }
    os_file.close();
    DeleteLinesFromFiles("KhachHangout.txt",sdt);
}
//Khôi Phục Dữ Liệu Nhân Viên Từ Thùng Rác
bool recoverLinesFromFileNV(const string& filename,const string& filename1,string a){
    int count1;
    string linesub;
    ifstream file(filename1);
    if (file.is_open()) {
        if(filename == "NhanVien.txt"){
            count1 =0;
            string line1;
            while (getline(file, line1)) {
                if (line1.find(a) != string::npos) {
                    count1++;
                    linesub = line1;
                }
            }
        }else{
            cout << "Tep Khong Duoc Ho Tro" << endl;
        }

        if (count1 == 0){
            cout << "Du Lieu Khong Ton Tai" << endl;
            return false;
        }else{
            cout << "Thong Tin Nhan Vien:" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << linesub << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
        }
    }
    file.close();

    int yn;
    do{
        cout << "+-------------------------------------------+" << endl;
        cout << "|     Ban muon khoi phuc du lieu khong?     |" << endl; 
        cout << "|       1.Yes                  2.No         |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "Nhap Y/N de xac nhan: "; 
        cin >> yn;
        try{
            if (yn == 1){
                Vector<string> kh;
                ifstream fileI (filename);
                if (fileI.is_open()) {
                    string line9;
                    while (getline(fileI, line9)){
                        kh.push_back(line9);
                    }
                } else {
                    cout << "FILE Khong Ton Tai" << endl;
                }
                fileI.close();
                ofstream od (filename,ios::out);
                for (int i = 0; i < kh.Size(); ++i) {
                    od << kh[i] << endl;
                    if(i == kh.Size()-1){
                        od << linesub << endl;
                    }
                }
                DeleteLinesFromFiles(filename1,a);
                DeleteMaNV(linesub);
                od.close();
                cout << "       COMPLETE       " << endl;
            }
            else{
                throw invalid_argument("Hay nhap 1 or 2");
            }
        }
        catch (invalid_argument e){
            cout << e.what() << endl;
        }
    }while ( yn!=2 && yn!=1);
}
//Đọc Dữ Liệu Phục Vụ Cho Mục 8 Trong Menu Nhan Vien
void ParseDataPHG8 (const string& line){
    istringstream ss(line);
    string token;
    // Biến lưu trữ các giá trị
    string makh, maql, idp;
    int date, month, year;
    int date01, month01, year01;
    int giaphong;

    // Trích xuất các giá trị từ chuỗi
    if (getline(ss, makh, '|') && getline(ss, maql, '|') && getline(ss, idp, '|')) {
        // Trích xuất ngày, tháng, năm từ chuỗi
        if (getline(ss, token, '/')) {
            date = stoi(token);
            if (getline(ss, token, '/')) {
                month = stoi(token);
                if (getline(ss, token, '|')) {
                    year = stoi(token);

                    // Trích xuất ngày, tháng, năm từ chuỗi
                    if (getline(ss, token, '/')) {
                        date01 = stoi(token);
                        if (getline(ss, token, '/')) {
                            month01 = stoi(token);
                            if (getline(ss, token, '|')) {
                                year01 = stoi(token);

                                // Trích xuất giá trị giaphong
                                if (getline(ss, token)) {
                                    giaphong = stoi(token);
                                    cout << setw(7) << makh << "|" << setw(6) << idp << "|" << setw(5) << date << "/" << setw(2) << month <<  "/" << year << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                                    cout << "---------+---------+----------------+----------------+-------------+" << endl;
                                } else {
                                    cerr << "Error: Missing giaphong." << endl;
                                }
                            } else {
                                cerr << "Error: Invalid input format (year01)." << endl;
                            }
                        } else {
                            cerr << "Error: Invalid input format (month01)." << endl;
                        }
                    } else {
                        cerr << "Error: Invalid input format (date01)." << endl;
                    }
                } else {
                    cerr << "Error: Missing year separator (|) after year." << endl;
                }
            } else {
                cerr << "Error: Invalid input format (month)." << endl;
            }
        } else {
            cerr << "Error: Invalid input format (date)." << endl;
        }
    } else {
        cerr << "Error: Missing separator (|) after idp." << endl;
    }
}
//Thống Kê , Sắp Xếp Dữ Liệu Nhân Viên 
bool ParseDataNV3string (const string& filename,string a){
    Vector<string> data;
    Vector<int> DataAge;
    Vector<int> sa;
    Vector<int> Manv;
    string gt;
    int count1 = 0;
    string gender,name,dmanv,chucdanh;
    int age,cmanv,salary;
    ifstream in (filename);
    if (in.is_open()){
        string line;
        while(getline(in,line)){
            if (line.find(a) != std::string::npos) {
                count1++;
                data.push_back(line);
            }
        }
        if (count1 == 0){
            cout << "Du Lieu Rong" << endl;
            return false;
        }
    }else{
        cout << "File Error" << endl;
    }
    in.close();
    int check = 0;
    for (size_t i = 0 ; i < data.Size(); ++i) {
        istringstream ss(data[i]);
        string token;
        getline(ss, token, '|');
        age = stoi(token);
        getline(ss, token, '|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        gender = token;
        getline(ss, token, '|');
        name = token;
        getline(ss, token, '|');
        string employeeCode = token;
        size_t hyphenPos = employeeCode.find('-');
        string dmanv = employeeCode.substr(0, hyphenPos);
        int cmanv = stoi(employeeCode.substr(hyphenPos + 1));
        getline(ss, token, '|');
        salary = stoi(token);
        getline(ss, token, '|');
        chucdanh = token;
        if (gender == a){
            check++;
            DataAge.push_back(age);
            sa.push_back(salary);
            Manv.push_back(cmanv);
        }else if (name.length() - a.length() == 23 - a.length()){
            DataAge.push_back(age);
            sa.push_back(salary);
            Manv.push_back(cmanv);
        }
        else if(chucdanh.length() - a.length() == 13 - a.length()){
            DataAge.push_back(age);
            sa.push_back(salary);
            Manv.push_back(cmanv);
        }
            
    }
    cout << "Tong So: " << count1 << " people" << endl;
    int tick , lc;
    do{
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Sap Xep Theo Tuoi   |" << endl;
        cout << "|                        2. Sap Xep Theo Luong  |" << endl;
        cout << "|                        3. Sap Xep Theo MaNV   |" << endl;
        cout << "|                        0. Thoat               |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> tick;

        if (tick == 0){
            break;
        }
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Tang Dan            |" << endl;
        cout << "|                        2. Giam Dan            |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> lc;
        if (tick == 1 && lc == 1){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] > DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
        
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(DataAge[i])) != string::npos && line.find(a) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 1 && lc == 2){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] < DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(DataAge[i])) != string::npos && line.find(a) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 1){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] > sa[j]){
                        int tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i]==sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(sa[i])) != string::npos && line.find(a) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 2){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] < sa[j]){
                        int tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i] == sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(sa[i])) != string::npos && line.find(a) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 1){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] > Manv[j]){
                        int tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(Manv[i])) != string::npos && line.find(a) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 2){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] < Manv[j]){
                        int tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(Manv[i])) != string::npos && line.find(a) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else{
            cout << "Cu Phap Nhap Vao Khong Hop Le" << endl;
        }

    }while ((tick != 1 && lc != 1) || (tick != 2 && lc != 1) || (tick != 3 && lc != 1) || (tick != 1 && lc != 2) || (tick != 2 && lc != 2) || (tick != 3 && lc != 2));
}
//Thống Kê , Sắp Xếp Dữ Liệu Nhân Viên
bool ParseDataNV3int (const string& filename,int a,string e){
    Vector<string> datasub = readVallueFromFile(filename);
    Vector<int> DataAge;
    Vector<int> sa;
    Vector<int> Manv;
    string gt;
    string gender,name,dmanv,chucdanh;
    int age,cmanv,salary;
    for (size_t i = 0 ; i < datasub.Size(); ++i) {
        istringstream ss(datasub[i]);
        string token;
        getline(ss, token, '|');
        age = stoi(token);
        getline(ss, token, '|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        gender = token;
        getline(ss, token, '|');
        name = token;
        getline(ss, token, '|');
        string employeeCode = token;
        size_t hyphenPos = employeeCode.find('-');
        string dmanv = employeeCode.substr(0, hyphenPos);
        int cmanv = stoi(employeeCode.substr(hyphenPos + 1));
        getline(ss, token, '|');
        salary = stoi(token);
        getline(ss, token, '|');
        chucdanh = token;
        if (salary == a && e == "="){
            DataAge.push_back(age);
            sa.push_back(salary);
            Manv.push_back(cmanv);
        }
        else if(salary < a && e == "<"){
            DataAge.push_back(age);
            sa.push_back(salary);
            Manv.push_back(cmanv);
        }
        else if(salary > a && e == ">"){
            DataAge.push_back(age);
            sa.push_back(salary);
            Manv.push_back(cmanv);
        }
    }
    cout << "Tong So: " << DataAge.Size() << " people" << endl;
    int tick , lc;
    do{
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Sap Xep Theo Tuoi   |" << endl;
        cout << "|                        2. Sap Xep Theo Luong  |" << endl;
        cout << "|                        3. Sap Xep Theo MaNV   |" << endl;
        cout << "|                        0. Thoat               |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> tick;

        if (tick == 0){
            break;
        }
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Tang Dan            |" << endl;
        cout << "|                        2. Giam Dan            |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> lc;
        if (tick == 1 && lc == 1){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] > DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(DataAge[i])) != string::npos) {
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            string employeeCode = token;
                            size_t hyphenPos = employeeCode.find('-');
                            string dmanv = employeeCode.substr(0, hyphenPos);
                            int cmanv = stoi(employeeCode.substr(hyphenPos + 1));
                            getline(ss, token, '|');
                            salary = stoi(token);
                            if (salary == a && e == "="){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;   
                            }
                            else if(salary < a && e == "<"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;   
                            }
                            else if(salary > a && e == ">"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;   
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 1 && lc == 2){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] < DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(DataAge[i])) != string::npos) {
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            string employeeCode = token;
                            size_t hyphenPos = employeeCode.find('-');
                            string dmanv = employeeCode.substr(0, hyphenPos);
                            int cmanv = stoi(employeeCode.substr(hyphenPos + 1));
                            getline(ss, token, '|');
                            salary = stoi(token);
                            if (salary == a && e == "="){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;   
                            }
                            else if(salary < a && e == "<"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;   
                            }
                            else if(salary > a && e == ">"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;   
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 1){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] > sa[j]){
                        int tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i]==sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(sa[i])) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 2){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] < sa[j]){
                        int tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i] == sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(sa[i])) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 1){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] > Manv[j]){
                        int tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(Manv[i])) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 2){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] < Manv[j]){
                        int tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(Manv[i])) != string::npos) {
                            cout << line << endl;
                            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else{
            cout << "Cu Phap Nhap Vao Khong Hop Le" << endl;
        }

    }while ((tick != 1 && lc != 1) || (tick != 2 && lc != 1) || (tick != 3 && lc != 1) || (tick != 1 && lc != 2) || (tick != 2 && lc != 2) || (tick != 3 && lc != 2));
}
//Thống Kê , Sắp Xếp Dữ Liệu Khách Hàng
bool ParseDataKH3string (const string& filename, int th){
    Vector<string> data;
    Vector<int> DataAge;
    Vector<string> sa;
    Vector<string> Manv;
    string gt;
    int count1 = 0;
    int sum = 0;
    int date, month, year;
    int date01, month01, year01;
    int giaphong;
    string name, birthday, gender, sdt,mail,idp,makh,maql;
    int age;
    ifstream in (filename);
    if (in.is_open()){
        string line;
        while(getline(in,line)){
            if (line.find("MAKH") == std::string::npos && line.find("-----") == string::npos) {
                count1++;
                data.push_back(line);
            }
        }
        if (count1 == 0){
            cout << "Du Lieu Rong" << endl;
            return false;
        }
    }else{
        cout << "File Error" << endl;
    }
    in.close();
    for (size_t i = 0 ; i < data.Size(); ++i){
        istringstream ss(data[i]);
        string token;
        if (getline(ss, makh, '|') && getline(ss, maql, '|') ) {
            if(getline(ss, token, '|')){
                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                idp = token;
                // Trích xuất ngày, tháng, năm từ chuỗi
                if (getline(ss, token, '/')) {
                    date = stoi(token);
                    if (getline(ss, token, '/')) {
                        month = stoi(token);
                        if (getline(ss, token, '|')) {
                            year = stoi(token);

                            // Trích xuất ngày, tháng, năm từ chuỗi
                            if (getline(ss, token, '/')) {
                                date01 = stoi(token);
                                if (getline(ss, token, '/')) {
                                    month01 = stoi(token);
                                    if (getline(ss, token, '|')) {
                                        year01 = stoi(token);

                                        // Trích xuất giá trị giaphong
                                        if (getline(ss, token)) {
                                            giaphong = stoi(token);
                                        } else {
                                            cerr << "Error: Missing giaphong." << endl;
                                        }
                                    } else {
                                        cerr << "Error: Invalid input format (year01)." << endl;
                                    }
                                } else {
                                    cerr << "Error: Invalid input format (month01)." << endl;
                                }
                            } else {
                                cerr << "Error: Invalid input format (date01)." << endl;
                            }
                        } else {
                            cerr << "Error: Missing year separator (|) after year." << endl;
                        }
                    } else {
                        cerr << "Error: Invalid input format (month)." << endl;
                    }
                } else {
                    cerr << "Error: Invalid input format (date)." << endl;
                }
            } else {
                cerr << "Error: Missing separator (|) after idp." << endl;
            }
        }
        sum = (30-date) + (30*(month01-month-1)) + date01;
        if (sum == th){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
    }

    for (int i =0; i < sa.Size();++i){
        ifstream ins ("KhachHang.txt");
        if(ins.is_open()){
            string line;
            while(getline(ins,line)){
                if(line.find(sa[i]) != string::npos){
                    istringstream ss(line);
                    string token;
                    getline(ss, token, '|');
                    age = stoi(token);
                    DataAge.push_back(age);
                }
            }
        }
        ins.close();
        cout << DataAge[i] << " " << sa[i] << endl;
    }
    int tick , lc;
    do{
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Sap Xep Theo Tuoi   |" << endl;
        cout << "|                        2. Sap Xep Theo IDP    |" << endl;
        cout << "|                        3. Sap Xep Theo MaKH   |" << endl;
        cout << "|                        0. Thoat               |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> tick;

        if (tick == 0){
            break;
        }
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Tang Dan            |" << endl;
        cout << "|                        2. Giam Dan            |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> lc;
        if (tick == 1 && lc == 1){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] > DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            cout << DataAge;
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while(getline(in_file,line)){
                        if (line.find(to_string(DataAge[i])) != string::npos) {
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            idp = token;
                            for(int j=0;j<sa.Size();++j){
                                if (idp == sa[j] && age == DataAge[i]){
                                    cout << line << endl;
                                    cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                                }
                            }
                        }
                    }
                }
                in_file.close();
            }
        }

        else if (tick == 1 && lc == 2){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] < DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(DataAge[i])) != string::npos) {
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            idp = token;
                            for(int j=0;j<sa.Size();++j){
                                if (idp == sa[j] && age == DataAge[i]){
                                    cout << line << endl;
                                    cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                                }
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 1){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] > sa[j]){
                        string tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i]==sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(sa[i]) != string::npos) {
                            cout << line << endl;
                            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 2){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] < sa[j]){
                        string tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i] == sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(sa[i]) != string::npos) {
                            cout << line << endl;
                            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 1){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] > Manv[j]){
                        string tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(Manv[i]) != string::npos) {
                            cout << line << endl;
                            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 2){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] < Manv[j]){
                        string tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(Manv[i]) != string::npos) {
                            cout << line << endl;
                            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else{
            cout << "Cu Phap Nhap Vao Khong Hop Le" << endl;
        }

    }while ((tick != 1 && lc != 1) || (tick != 2 && lc != 1) || (tick != 3 && lc != 1) || (tick != 1 && lc != 2) || (tick != 2 && lc != 2) || (tick != 3 && lc != 2));
}
//Thống Kê , Sắp Xếp Theo Giới Tính
bool ParseDataNV3gender (const string& filename){    Vector<string> data = readVallueFromFile(filename);
    Vector<int> DataAge;
    Vector<int> sa;
    Vector<int> Manv;
    Vector<int> DataAge1;
    Vector<int> sa1;
    Vector<int> Manv1;
    string gt;
    int count1 = 0;
    string gender,name,dmanv,chucdanh;
    int age,cmanv,salary;
    ifstream in (filename);
    
    for (size_t i = 0 ; i < data.Size(); ++i) {
        istringstream ss(data[i]);
        string token;
        getline(ss, token, '|');
        age = stoi(token);
        getline(ss, token, '|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        gender = token;
        getline(ss, token, '|');
        name = token;
        getline(ss, token, '|');
        string employeeCode = token;
        size_t hyphenPos = employeeCode.find('-');
        string dmanv = employeeCode.substr(0, hyphenPos);
        int cmanv = stoi(employeeCode.substr(hyphenPos + 1));
        getline(ss, token, '|');
        salary = stoi(token);
        getline(ss, token, '|');
        chucdanh = token;
        if (gender == "Nam" || gender == "nam"){
            DataAge.push_back(age);
            sa.push_back(salary);
            Manv.push_back(cmanv);
        }
        else if (gender == "Nu" || gender == "nu"){
            DataAge1.push_back(age);
            sa1.push_back(salary);
            Manv1.push_back(cmanv);
        }
    }
    cout << "Tong so Nam: " << DataAge.Size() << " People" << endl;
    cout << "Tong so Nu: " << DataAge1.Size() << " People" << endl;
    int tick , lc;
    int max = 0;
    do{
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Sap Xep Theo Tuoi   |" << endl;
        cout << "|                        2. Sap Xep Theo Luong  |" << endl;
        cout << "|                        3. Sap Xep Theo MaNV   |" << endl;
        cout << "|                        0. Thoat               |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> tick;

        if (tick == 0){
            break;
        }
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Tang Dan            |" << endl;
        cout << "|                        2. Giam Dan            |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> lc;
        if (tick == 1 && lc == 1){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] > DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{ 
                        ++j;
                    }
                }
            }
            for (int i = 0; i < DataAge1.Size(); ++i){
                for(int j = i+1; j < DataAge1.Size();){
                    if (DataAge1[i] > DataAge1[j]){
                        int tmp = DataAge1[i];
                        DataAge1[i]=DataAge1[j];
                        DataAge1[j]=tmp;
                    }
                    else if (DataAge1[i]==DataAge1[j]){
                        DataAge1.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find("AGE") == string::npos && line.find("------") == string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if ((gender == "Nam" || gender == "nam") && age == DataAge[i]){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
    
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < DataAge1.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find("AGE") == string::npos && line.find("------") == string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if ((gender == "Nu" || gender == "nu") && age == DataAge1[i]){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }
            in_file.close();
            }
        }

        else if (tick == 1 && lc == 2){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] < DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            for (int i = 0; i < DataAge1.Size(); ++i){
                for(int j = i+1; j < DataAge1.Size();){
                    if (DataAge1[i] < DataAge1[j]){
                        int tmp = DataAge1[i];
                        DataAge1[i]=DataAge1[j];
                        DataAge1[j]=tmp;
                    }
                    else if (DataAge1[i]==DataAge1[j]){
                        DataAge1.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find("AGE") == string::npos && line.find("------") == string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if ((gender == "Nam" || gender == "nam") && age == DataAge[i]){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < DataAge1.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find("AGE") == string::npos && line.find("------") == string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if ((gender == "Nu" || gender == "nu") && age == DataAge1[i]){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 1){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] > sa[j]){
                        int tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i]==sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            for (int i = 0; i < sa1.Size(); ++i){
                for(int j = i+1; j < sa1.Size();){
                    if (sa1[i] > sa1[j]){
                        int tmp = sa1[i];
                        sa1[i]=sa1[j];
                        sa1[j]=tmp;
                    }
                    else if (sa1[i]==sa1[j]){
                        sa1.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(sa[i])) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nam" || gender == "nam"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < sa1.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find(to_string(sa1[i])) != string::npos ){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nu" || gender == "nu"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 2){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] < sa[j]){
                        int tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i] == sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            for (int i = 0; i < sa1.Size(); ++i){
                for(int j = i+1; j < sa1.Size();){
                    if (sa1[i] < sa1[j]){
                        int tmp = sa1[i];
                        sa1[i]=sa1[j];
                        sa1[j]=tmp;
                    }
                    else if (sa1[i]==sa1[j]){
                        sa1.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(sa[i])) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nam" || gender == "nam"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < sa1.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find(to_string(sa1[i])) != string::npos ){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nu" || gender == "nu"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 1){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] > Manv[j]){
                        int tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }

            for (int i = 0; i < Manv1.Size(); ++i){
                for(int j = i+1; j < Manv1.Size(); ++j){
                    if (Manv1[i] > Manv1[j]){
                        int tmp = Manv1[i];
                        Manv1[i]=Manv1[j];
                        Manv1[j]=tmp;
                    }
                    if (Manv1[i]==Manv1[j]){
                        Manv1.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(Manv[i])) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nam" || gender == "nam"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find(to_string(Manv[i])) != string::npos ){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nu" || gender == "nu"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 2){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] < Manv[j]){
                        int tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            for (int i = 0; i < Manv1.Size(); ++i){
                for(int j = i+1; j < Manv1.Size(); ++j){
                    if (Manv1[i] < Manv1[j]){
                        int tmp = Manv1[i];
                        Manv1[i]=Manv1[j];
                        Manv1[j]=tmp;
                    }
                    if (Manv1[i]==Manv1[j]){
                        Manv1.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(Manv[i])) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nam" || gender == "nam"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
            cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("NhanVien.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find(to_string(Manv[i])) != string::npos ){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nu" || gender == "nu"){
                                cout << line << endl;
                                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else{
            cout << "Cu Phap Nhap Vao Khong Hop Le" << endl;
        }

    }while ((tick != 1 && lc != 1) || (tick != 2 && lc != 1) || (tick != 3 && lc != 1) || (tick != 1 && lc != 2) || (tick != 2 && lc != 2) || (tick != 3 && lc != 2));
}
//Thống kê , sắp xếp khách hàng theo giới tính
bool ParseDataKH3gender (const string& filename){
    Vector<string> data = readVallueFromFile(filename);
    Vector<int> DataAge;
    Vector<string> sa;
    Vector<string> Manv;
    Vector<int> DataAge1;
    Vector<string> sa1;
    Vector<string> Manv1;
    string gt;
    int count1 = 0;
    string name, birthday, gender, sdt,mail,idp,makh,maql;
    int age;
    
    for (int i = 0 ; i < data.Size(); ++i) {
        istringstream ss(data[i]);
        string token;
        getline(ss, token, '|');
        age = stoi(token);
        getline(ss, token, '|');
        name = token;
        getline(ss, token, '|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        gender = token;
        getline(ss, token, '|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        idp = token;
        getline(ss, token, '|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        makh = token;
        getline(ss, token, '|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        sdt = token;
        getline(ss, token, '|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        mail = token;
        getline(ss,token,'|');
        birthday = token;
        getline(ss, token, '|');
        maql = token;
        if(gender == "Nam" || gender == "nam"){
            DataAge.push_back(age);
            sa.push_back(idp);
            Manv.push_back(makh);
        }else if (gender == "Nu" || gender == "nu"){
            DataAge1.push_back(age);
            sa1.push_back(idp);
            Manv1.push_back(makh);
        }
    }
    cout << "Tong so Nam: " << DataAge.Size() << " People" << endl;
    cout << "Tong so Nu: " << DataAge1.Size() << " People" << endl;
    int tick , lc;
    int max = 0;
    do{
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Sap Xep Theo Tuoi   |" << endl;
        cout << "|                        2. Sap Xep Theo IDP    |" << endl;
        cout << "|                        3. Sap Xep Theo MaKH   |" << endl;
        cout << "|                        0. Thoat               |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> tick;

        if (tick == 0){
            break;
        }
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Tang Dan            |" << endl;
        cout << "|                        2. Giam Dan            |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> lc;
        if (tick == 1 && lc == 1){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] > DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{ 
                        ++j;
                    }
                }
            }
            for (int i = 0; i < DataAge1.Size(); ++i){
                for(int j = i+1; j < DataAge1.Size();){
                    if (DataAge1[i] > DataAge1[j]){
                        int tmp = DataAge1[i];
                        DataAge1[i]=DataAge1[j];
                        DataAge1[j]=tmp;
                    }
                    else if (DataAge1[i]==DataAge1[j]){
                        DataAge1.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            cout << DataAge;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            
            for (int i = 0; i<DataAge.Size(); ++i){
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find("AGE") == string::npos && line.find("-----") == string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if ((gender == "Nam" || gender == "nam") && age == DataAge[i]) {
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                        
                    }
                }
                in_file.close();
            }
    
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i<DataAge1.Size(); ++i){
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find("AGE") == string::npos && line.find("-----") == string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if ((gender == "Nu" || gender == "nu") && age == DataAge1[i]) {
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                        
                    }
                }
                in_file.close();
            }
        }

        else if (tick == 1 && lc == 2){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] < DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            for (int i = 0; i < DataAge1.Size(); ++i){
                for(int j = i+1; j < DataAge1.Size();){
                    if (DataAge1[i] < DataAge1[j]){
                        int tmp = DataAge1[i];
                        DataAge1[i]=DataAge1[j];
                        DataAge1[j]=tmp;
                    }
                    else if (DataAge1[i]==DataAge1[j]){
                        DataAge1.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i<DataAge.Size(); ++i){
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find("AGE") == string::npos && line.find("-----") == string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if ((gender == "Nam" || gender == "nam") && age == DataAge[i]) {
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                        
                    }
                }
                in_file.close();
            }

            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i<DataAge1.Size(); ++i){
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find("AGE") == string::npos && line.find("-----") == string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if ((gender == "Nu" || gender == "nu") && age == DataAge1[i]) {
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                        
                    }
                }
                in_file.close();
            }
        }

        else if (tick == 2 && lc == 1){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] > sa[j]){
                        string tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i]==sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            for (int i = 0; i < sa1.Size(); ++i){
                for(int j = i+1; j < sa1.Size();){
                    if (sa1[i] > sa1[j]){
                        string tmp = sa1[i];
                        sa1[i]=sa1[j];
                        sa1[j]=tmp;
                    }
                    else if (sa1[i]==sa1[j]){
                        sa1.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(sa[i]) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nam" || gender == "nam"){
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < sa1.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find(sa1[i]) != string::npos ){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nu" || gender == "nu"){
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 2){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] < sa[j]){
                        string tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i] == sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            for (int i = 0; i < sa1.Size(); ++i){
                for(int j = i+1; j < sa1.Size();){
                    if (sa1[i] < sa1[j]){
                        string tmp = sa1[i];
                        sa1[i]=sa1[j];
                        sa1[j]=tmp;
                    }
                    else if (sa1[i]==sa1[j]){
                        sa1.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(sa[i]) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nam" || gender == "nam"){
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < sa1.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find(sa1[i]) != string::npos ){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nu" || gender == "nu"){
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 1){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] > Manv[j]){
                        string tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }

            for (int i = 0; i < Manv1.Size(); ++i){
                for(int j = i+1; j < Manv1.Size(); ++j){
                    if (Manv1[i] > Manv1[j]){
                        string tmp = Manv1[i];
                        Manv1[i]=Manv1[j];
                        Manv1[j]=tmp;
                    }
                    if (Manv1[i]==Manv1[j]){
                        Manv1.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(Manv[i]) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nam" || gender == "nam"){
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < Manv1.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find(Manv1[i]) != string::npos ){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nu" || gender == "nu"){
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 2){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] < Manv[j]){
                        string tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            for (int i = 0; i < Manv1.Size(); ++i){
                for(int j = i+1; j < Manv1.Size(); ++j){
                    if (Manv1[i] < Manv1[j]){
                        string tmp = Manv1[i];
                        Manv1[i]=Manv1[j];
                        Manv1[j]=tmp;
                    }
                    if (Manv1[i]==Manv1[j]){
                        Manv1.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(Manv[i]) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nam" || gender == "nam"){
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }

            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < Manv1.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (getline(in_file, line)) {
                        if (line.find(Manv1[i]) != string::npos ){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            if (gender == "Nu" || gender == "nu"){
                                cout << line << endl;
                                cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else{
            cout << "Cu Phap Nhap Vao Khong Hop Le" << endl;
        }

    }while ((tick != 1 && lc != 1) || (tick != 2 && lc != 1) || (tick != 3 && lc != 1) || (tick != 1 && lc != 2) || (tick != 2 && lc != 2) || (tick != 3 && lc != 2));
}
//Thống kê , sắp xếp theo ngày tháng thuê
bool ParseDataKH3int (const string& filename,int d, int m , int y,string e){
    Vector<string> datasub = readVallueFromFile(filename);
    Vector<int> DataAge;
    Vector<string> sa;
    Vector<string> Manv;
    Vector<string> data1;
    int count = 0;
    string makh, maql, idp;
    int date, month, year;
    int date01, month01, year01;
    string name, birthday, gender, sdt,mail;
    int age;
    int giaphong;
    for (size_t i = 0 ; i < datasub.Size(); ++i) {
        count++;
        istringstream ss(datasub[i]);
        string token;
        if (getline(ss, makh, '|') && getline(ss, maql, '|') && getline(ss, idp, '|')) {
        // Trích xuất ngày, tháng, năm từ chuỗi
            if (getline(ss, token, '/')) {
                date = stoi(token);
                if (getline(ss, token, '/')) {
                    month = stoi(token);
                    if (getline(ss, token, '|')) {
                        year = stoi(token);

                        // Trích xuất ngày, tháng, năm từ chuỗi
                        if (getline(ss, token, '/')) {
                            date01 = stoi(token);
                            if (getline(ss, token, '/')) {
                                month01 = stoi(token);
                                if (getline(ss, token, '|')) {
                                    year01 = stoi(token);

                                    // Trích xuất giá trị giaphong
                                    if (getline(ss, token)) {
                                        giaphong = stoi(token);
                                    } else {
                                        cerr << "Error: Missing giaphong." << endl;
                                    }
                                } else {
                                    cerr << "Error: Invalid input format (year01)." << endl;
                                }
                            } else {
                                cerr << "Error: Invalid input format (month01)." << endl;
                            }
                        } else {
                            cerr << "Error: Invalid input format (date01)." << endl;
                        }
                    } else {
                        cerr << "Error: Missing year separator (|) after year." << endl;
                    }
                } else {
                    cerr << "Error: Invalid input format (month)." << endl;
                }
            } else {
                cerr << "Error: Invalid input format (date)." << endl;
            }
        } else {
            cerr << "Error: Missing separator (|) after idp." << endl;
        }
        if (e == "=" && d == date && m == month && y == year){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
        else if (e == "m=" && d == 0 && m == month && y == year){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
        else if (e == "y=" && d == 0 && m == 0 && y == year){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
        else if( e == "<" && (y > year || ( y == year && m > month)||(y == year && m == month && d > date))){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
        else if( e == ">" && (y < year ||(y == year && m < month)||(y == year && m == month && d < date))){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
        else if( e == "m>" && (y < year ||(y == year && m < month)||(y == year && m == month && d == 0))){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
        else if( e == "m<" && (y > year ||(y == year && m > month)||(y == year && m == month && d == 0))){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
        else if( e == "y>" && ( y < year ||(y == year && m == 0 && d == 0))){
            sa.push_back(idp);
            Manv.push_back(makh);
        }else if( e == "y<" && ( y > year ||(y == year && m == 0 && d == 0))){
            sa.push_back(idp);
            Manv.push_back(makh);
        }
    } 
    for (int i = 0; i < Manv.Size(); ++i){
        ifstream ins ("KhachHang.txt");
        if (ins.is_open()) {
            string line;
            while (getline(ins, line)) {
                if (line.find(Manv[i]) != string::npos) {
                    istringstream ss(line);
                    string token;
                    getline(ss, token, '|');
                    age = stoi(token);
                    getline(ss, token, '|');
                    name = token;
                    getline(ss, token, '|');
                    gender = token;
                    getline(ss, token, '|');
                    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                    idp = token;
                    getline(ss, token, '|');
                    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                    makh = token;
                    getline(ss, token, '|');
                    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                    sdt = token;
                    getline(ss, token, '|');
                    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                    mail = token;
                    getline(ss,token,'|');
                    birthday = token;
                    getline(ss, token, '|');
                    maql = token;
                    DataAge.push_back(age);
                    data1.push_back(makh);
                }
            }
        }
        ins.close();
    }
    int tick , lc;
    do{
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Sap Xep Theo Tuoi   |" << endl;
        cout << "|                        2. Sap Xep Theo IDP    |" << endl;
        cout << "|                        3. Sap Xep Theo MaKH   |" << endl;
        cout << "|                        0. Thoat               |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> tick;

        if (tick == 0){
            break;
        }
        cout << "+-----------------------------------------------+" << endl;
        cout << "|   Lua Chon Cua Ban :   1. Tang Dan            |" << endl;
        cout << "|                        2. Giam Dan            |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Lua Chon Cua Ban: ";
        cin >> lc;
        if (tick == 1 && lc == 1){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] > DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(DataAge[i])) != string::npos) {
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            gender = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            idp = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            makh = token;
                            for (int j=0;j<data1.Size();++j){
                                if(makh == data1[j] && age == DataAge[i]){
                                    cout << line << endl;
                                    cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                                }
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 1 && lc == 2){
            for (int i = 0; i < DataAge.Size(); ++i){
                for(int j = i+1; j < DataAge.Size();){
                    if (DataAge[i] < DataAge[j]){
                        int tmp = DataAge[i];
                        DataAge[i]=DataAge[j];
                        DataAge[j]=tmp;
                    }
                    else if (DataAge[i]==DataAge[j]){
                        DataAge.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
             cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < DataAge.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(to_string(DataAge[i])) != string::npos) {
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            gender = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            idp = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            makh = token;
                            for (int j=0;j<data1.Size();++j){
                                if(makh == data1[j] && age == DataAge[i]){
                                    cout << line << endl;
                                    cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                                }
                            }
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 1){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] > sa[j]){
                        string tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i]==sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }
            
            bool continueLoop = true;
             cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(sa[i]) != string::npos) {
                            cout << line << endl;
                            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 2 && lc == 2){
            for (int i = 0; i < sa.Size(); ++i){
                for(int j = i+1; j < sa.Size();){
                    if (sa[i] < sa[j]){
                        string tmp = sa[i];
                        sa[i]=sa[j];
                        sa[j]=tmp;
                    }
                    else if (sa[i] == sa[j]){
                        sa.erase(j);
                    }
                    else{
                        ++j;
                    }
                }
            }

            bool continueLoop = true;
             cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < sa.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(sa[i]) != string::npos) {
                            cout << line << endl;
                            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 1){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] > Manv[j]){
                        string tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
             cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(Manv[i]) != string::npos) {
                            cout << line << endl;
                            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else if (tick == 3 && lc == 2){
            for (int i = 0; i < Manv.Size(); ++i){
                for(int j = i+1; j < Manv.Size(); ++j){
                    if (Manv[i] < Manv[j]){
                        string tmp = Manv[i];
                        Manv[i]=Manv[j];
                        Manv[j]=tmp;
                    }
                    if (Manv[i]==Manv[j]){
                        Manv.erase(j);
                    }
                }
            }
            
            bool continueLoop = true;
             cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
            for (int i = 0; i < Manv.Size(); ++i) {
                ifstream in_file("KhachHang.txt");
                if (in_file.is_open()) {
                    string line;
                    while (continueLoop && getline(in_file, line)) {
                        if (line.find(Manv[i]) != string::npos) {
                            cout << line << endl;
                            cout << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                        }
                    }
                }

            in_file.close();
            }
        }

        else{
            cout << "Cu Phap Nhap Vao Khong Hop Le" << endl;
        }

    }while ((tick != 1 && lc != 1) || (tick != 2 && lc != 1) || (tick != 3 && lc != 1) || (tick != 1 && lc != 2) || (tick != 2 && lc != 2) || (tick != 3 && lc != 2));
}
//Đọc Dữ Liệu Khách Hàng Phục Vụ Cho Mục 8 Trong Menu Nhân Viên
void ParseDataKH8 (const string& line){
    istringstream ss(line);
    string token;
    getline(ss, token, '|');
    int age = stoi(token);
    getline(ss, token, '|');
    string name = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    string gender = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    string idp = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    string makh = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    string sdt = token;
    getline(ss, token, '|');
    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
    string mail = token;
    getline(ss, token, '|');
    string birthday = token;
    getline(ss, token, '|');
    string maql = token;
    cout << setw(5) << age << setw(4) << "|" << setw(20) << name << "|" << setw(10) << gender <<  setw(8) << "|" << setw(13)<< sdt <<  setw(4) << "|" << setw(25) << mail << setw(4) << "|" << birthday << "|" << endl;
    cout << "--------+-----------------------+-----------------+----------------+----------------------------+----------------+" << endl;

}
//Tính Doanh Thu Theo Thang
long calculateRevenueMonth (int n,int m){
    Vector<string> valluePHG;
    ifstream input_line ("PHG.txt");
    if(input_line.is_open()){
        string line;
        while(getline(input_line,line)){
            if (line.find("MAKH") == string::npos && line.find("----") == string::npos){
                valluePHG.push_back(line);
            }
        }
    }
    input_line.close();
    int RevenueAggregate = 0;
    for(int i = 0; i<valluePHG.Size(); ++i){
        istringstream ss(valluePHG[i]);
        string token;
        // Biến lưu trữ các giá trị
        string makh, maql, idp;
        int date, month, year;
        int date01, month01, year01;
        int giaphong;

        // Trích xuất các giá trị từ chuỗi
        if (getline(ss, makh, '|') && getline(ss, maql, '|') && getline(ss, idp, '|')) {
            // Trích xuất ngày, tháng, năm từ chuỗi
            if (getline(ss, token, '/')) {
                date = stoi(token);
                if (getline(ss, token, '/')) {
                    month = stoi(token);
                    if (getline(ss, token, '|')) {
                        year = stoi(token);

                        // Trích xuất ngày, tháng, năm từ chuỗi
                        if (getline(ss, token, '/')) {
                            date01 = stoi(token);
                            if (getline(ss, token, '/')) {
                                month01 = stoi(token);
                                if (getline(ss, token, '|')) {
                                    year01 = stoi(token);

                                    // Trích xuất giá trị giaphong
                                    if (getline(ss, token)) {
                                        giaphong = stoi(token);
                                        if (month == n && year == m){
                                            RevenueAggregate += giaphong;
                                        }
                                    } else {
                                        cerr << "Error: Missing giaphong." << endl;
                                    }
                                } else {
                                    cerr << "Error: Invalid input format (year01)." << endl;
                                }
                            } else {
                                cerr << "Error: Invalid input format (month01)." << endl;
                            }
                        } else {
                            cerr << "Error: Invalid input format (date01)." << endl;
                        }
                    } else {
                        cerr << "Error: Missing year separator (|) after year." << endl;
                    }
                } else {
                    cerr << "Error: Invalid input format (month)." << endl;
                }
            } else {
                cerr << "Error: Invalid input format (date)." << endl;
            }
        } else {
            cerr << "Error: Missing separator (|) after idp." << endl;
        }
    }
    ifstream in_file ("HoaDon.txt");
    if (in_file.is_open()){
        string line;
        while(getline(in_file,line)){
            istringstream ss(line);
            string token;
            getline (ss,token,'/');
            int dayy = stoi(token);
            getline (ss,token,'/');
            int monnth = stoi(token);
            getline (ss,token,'|');
            int yeaar = stoi(token);
            getline (ss,token,'|');
            string makkh = token;
            getline (ss,token,'|');
            int no = stoi(token);
            getline (ss,token,'|');
            string tt = token;
            if (monnth == n && yeaar == m){
                RevenueAggregate += no;
            }
        }
    }
    in_file.close();
    return RevenueAggregate;
}
//Tính Doanh Thu Theo Ngay
long calculateRevenueDay (int n,int m , int q){
    Vector<string> valluePHG;
    ifstream input_line ("PHG.txt");
    if(input_line.is_open()){
        string line;
        while(getline(input_line,line)){
            if (line.find("MAKH") == string::npos && line.find("----") == string::npos){
                valluePHG.push_back(line);
            }
        }
    }
    input_line.close();
    int RevenueAggregate = 0;
    for(int i = 0; i<valluePHG.Size(); ++i){
        istringstream ss(valluePHG[i]);
        string token;
        // Biến lưu trữ các giá trị
        string makh, maql, idp;
        int date, month, year;
        int date01, month01, year01;
        int giaphong;

        // Trích xuất các giá trị từ chuỗi
        if (getline(ss, makh, '|') && getline(ss, maql, '|') && getline(ss, idp, '|')) {
            // Trích xuất ngày, tháng, năm từ chuỗi
            if (getline(ss, token, '/')) {
                date = stoi(token);
                if (getline(ss, token, '/')) {
                    month = stoi(token);
                    if (getline(ss, token, '|')) {
                        year = stoi(token);

                        // Trích xuất ngày, tháng, năm từ chuỗi
                        if (getline(ss, token, '/')) {
                            date01 = stoi(token);
                            if (getline(ss, token, '/')) {
                                month01 = stoi(token);
                                if (getline(ss, token, '|')) {
                                    year01 = stoi(token);

                                    // Trích xuất giá trị giaphong
                                    if (getline(ss, token)) {
                                        giaphong = stoi(token);
                                        if (date == n && month == m && year == q){
                                            RevenueAggregate += giaphong;
                                        }
                                    } else {
                                        cerr << "Error: Missing giaphong." << endl;
                                    }
                                } else {
                                    cerr << "Error: Invalid input format (year01)." << endl;
                                }
                            } else {
                                cerr << "Error: Invalid input format (month01)." << endl;
                            }
                        } else {
                            cerr << "Error: Invalid input format (date01)." << endl;
                        }
                    } else {
                        cerr << "Error: Missing year separator (|) after year." << endl;
                    }
                } else {
                    cerr << "Error: Invalid input format (month)." << endl;
                }
            } else {
                cerr << "Error: Invalid input format (date)." << endl;
            }
        } else {
            cerr << "Error: Missing separator (|) after idp." << endl;
        }
    }
    ifstream in_file ("HoaDon.txt");
    if (in_file.is_open()){
        string line;
        while(getline(in_file,line)){
            istringstream ss(line);
            string token;
            getline (ss,token,'/');
            int dayy = stoi(token);
            getline (ss,token,'/');
            int monnth = stoi(token);
            getline (ss,token,'|');
            int yeaar = stoi(token);
            getline (ss,token,'|');
            string makkh = token;
            getline (ss,token,'|');
            int no = stoi(token);
            getline (ss,token,'|');
            string tt = token;
            if (dayy== n && monnth == m && yeaar == q){
                RevenueAggregate += no;
            }
        }
    }
    in_file.close();
    return RevenueAggregate;
}
//Tính Doanh Thu Theo Nam
long calculateRevenueYear (int n){
    Vector<string> valluePHG;
    ifstream input_line ("PHG.txt");
    if(input_line.is_open()){
        string line;
        while(getline(input_line,line)){
            if (line.find("MAKH") == string::npos && line.find("----") == string::npos){
                valluePHG.push_back(line);
            }
        }
    }
    input_line.close();
    int RevenueAggregate = 0;
    for(int i = 0; i<valluePHG.Size(); ++i){
        istringstream ss(valluePHG[i]);
        string token;
        // Biến lưu trữ các giá trị
        string makh, maql, idp;
        int date, month, year;
        int date01, month01, year01;
        int giaphong;

        // Trích xuất các giá trị từ chuỗi
        if (getline(ss, makh, '|') && getline(ss, maql, '|') && getline(ss, idp, '|')) {
            // Trích xuất ngày, tháng, năm từ chuỗi
            if (getline(ss, token, '/')) {
                date = stoi(token);
                if (getline(ss, token, '/')) {
                    month = stoi(token);
                    if (getline(ss, token, '|')) {
                        year = stoi(token);

                        // Trích xuất ngày, tháng, năm từ chuỗi
                        if (getline(ss, token, '/')) {
                            date01 = stoi(token);
                            if (getline(ss, token, '/')) {
                                month01 = stoi(token);
                                if (getline(ss, token, '|')) {
                                    year01 = stoi(token);

                                    // Trích xuất giá trị giaphong
                                    if (getline(ss, token)) {
                                        giaphong = stoi(token);
                                        if (year == n){
                                            RevenueAggregate += giaphong;
                                        }
                                    } else {
                                        cerr << "Error: Missing giaphong." << endl;
                                    }
                                } else {
                                    cerr << "Error: Invalid input format (year01)." << endl;
                                }
                            } else {
                                cerr << "Error: Invalid input format (month01)." << endl;
                            }
                        } else {
                            cerr << "Error: Invalid input format (date01)." << endl;
                        }
                    } else {
                        cerr << "Error: Missing year separator (|) after year." << endl;
                    }
                } else {
                    cerr << "Error: Invalid input format (month)." << endl;
                }
            } else {
                cerr << "Error: Invalid input format (date)." << endl;
            }
        } else {
            cerr << "Error: Missing separator (|) after idp." << endl;
        }
    }
    ifstream in_file ("HoaDon.txt");
    if (in_file.is_open()){
        string line;
        while(getline(in_file,line)){
            istringstream ss(line);
            string token;
            getline (ss,token,'/');
            int dayy = stoi(token);
            getline (ss,token,'/');
            int monnth = stoi(token);
            getline (ss,token,'|');
            int yeaar = stoi(token);
            getline (ss,token,'|');
            string makkh = token;
            getline (ss,token,'|');
            int no = stoi(token);
            getline (ss,token,'|');
            string tt = token;
            if (yeaar == n){
                RevenueAggregate += no;
            }
        }
    }
    in_file.close();
    return RevenueAggregate;
}
//Kiểm tra tồn tại của phong
void KtraRoom (){
    Vector<string> room0 = readLinesFromFile1("IDP.txt");
    Vector<string> room1 = readVallueFromFile("PHG.txt");
    Vector<string> room;
    Vector<string> roomOFF;
    string makh,maql,idp,begin,end,giaphong;
    for (int i = 0 ; i < room1.Size(); ++i){
        istringstream ss(room1[i]);
        string token;
        getline(ss,token,'|');
        makh = token;
        getline(ss,token,'|');
        maql = token;
        getline(ss,token,'|');
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        idp = token;
        getline(ss,token,'|');
        begin = token;
        getline(ss,token,'|');
        end = token;
        getline(ss,token,'|');
        giaphong = token;
        room.push_back(idp);
        roomOFF.push_back(idp);
    }
    for(int i = 0; i < room0.Size();++i){
        room.push_back(room0[i]);
    }
    for(int i = 0; i < room.Size(); ++i){
        for(int j = i + 1; j < room.Size(); ++j){
            if (room[i] > room[j]){
                string tmp = room[i];
                room[i] = room[j];
                room[j] = tmp;
            }
        }
    }
    for(int i = 0; i < room.Size(); ++i){
        for (int j = 0; j < room0.Size(); ++j){
            if (room[i] == room0[j]){
                cout << room[i] << " : Con Trong" << endl;
            }
        }
    }
    for(int i = 0; i < room.Size(); ++i){
        for (int j = 0; j < roomOFF.Size(); ++j){
            if (room[i] == roomOFF[j]){
                cout << room[i] << " : Da Thue" << endl;
            }
        }
    }

}
//Kiem tra tồn tại của các dữ liệu
bool KtraTonTai (const string& filename,const string& line){
    ifstream in(filename);
    int count1 = 0;
    if (in.is_open()) {
        string line3;
        while (getline(in, line3)) {
            if (line3.find (line) != std::string::npos) {
                count1 ++;
            }
        }
        if (count1 == 0){
            cout << "Du Lieu Khong Ton Tai" << endl;
            return false;
        }else{
            return true;
        }
    } else {
        cout << "FILE Khong Ton Tai" << endl;
    }
    in.close();
}

void DoiMatKhau(string username,string password){
    string passold,passnew;
    do{
        cout << "Mat Khau Cu: ";
        cin.ignore();
        getline(cin,passold);
    }while(passold != password);
    cout << "Mat Khau Moi: ";
    cin.ignore();
    getline(cin,passnew);
    string user,pass;
    ifstream in_file("password.txt");
    ofstream out_file("password.txt",ios::app);
    if(in_file.is_open()){
        string line;
        while(getline(in_file,line)){
            if (line.find(username) != string::npos){
                istringstream ss(line);
                string token;
                getline(ss,token,'|');
                user = token;
                getline(ss,token,'|');
                pass = token;
                DeleteLinesFromFiles("password.txt",line);
                out_file << username << "|" << passnew << endl;
            }
        }
    }
    out_file.close();
    in_file.close();
}

int main() { 
    cout << " __________________________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                                  |" << endl;
    cout << "|                                                PBL2 : QUAN LY SLEEP_BOX                                          |" << endl;
    cout << "|                                                                                                                  |" << endl;
    cout << "|                                                 GVHD: DO THI TUYET HOA                                           |" << endl;
    cout << "|                                                                                                                  |" << endl;
    cout << "|                                              SINH VIEN THAM GIA : LE DINH TOAN                                   |" << endl;
    cout << "|                                                                   DOAN CONG TUAN VU                              |" << endl;
    cout << "|                                                                                                                  |" << endl;
    cout << "|__________________________________________________________________________________________________________________|" << endl;

    int lc;
    string username,password;
    login tk;
    do{
        cout << "UserName: "; cin >> username;
        cout << "Password: "; cin >> password;
    }while(tk.authenticate(username,password) == 0);
/*--------------------------------MENU OF NHANVIEN---------------------------------------------*/        
    if (tk.authenticate(username,password) == 1){
        while(1){
            DrawMenuNV();
            cout << "Nhap Lua Chon Cua Ban: ";
            cin >> lc;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            if (lc == 0){
                cout << "Hen Gap Lai" << endl;
                break;
            }

            else if (lc == 1){
                ofstream outfile("NhanVien.txt", ios::out);
                int n;
                cout << "So Nhan Vien: ";
                cin >> n;
                nv a[n];
                outfile << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                outfile << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
                outfile << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                for (int i=0;i<n;i++){
                    cout << " * NHAN VIEN THU " << i+1 << ":" << endl; 
                    a[i].nhap();
                }
                outfile.close();
            }

            else if (lc == 2){
                readLinesFromFile ("NhanVien.txt");
            }

            else if (lc == 3){
                string data;
                int data1;
                int tick,yn;
                do{
                    cout << "+----------------------------------------------------+" << endl;
                    cout << "|                        1. Thong Ke Theo Gioi Tinh  |" << endl;
                    cout << "|   Lua Chon Cua Ban :   2. Thong Ke Theo Luong      |" << endl;
                    cout << "|                        3. Thong Ke Theo Chuc Vu    |" << endl;
                    cout << "+----------------------------------------------------+" << endl;
                    cout << "Lua Chon Cua Ban: ";
                    cin >> tick;
                    if(tick == 1){
                        ParseDataNV3gender ("NhanVien.txt");
                    }
                    else if(tick == 2){
                        do{
                            cout << "+----------------------------------------------------+" << endl;
                            cout << "|   Lua Chon Cua Ban :   1. Thong Ke Luong =         |" << endl;
                            cout << "|                        2. Thong Ke Luong <         |" << endl;
                            cout << "|                        3. Thong Ke Luong >         |" << endl;
                            cout << "+----------------------------------------------------+" << endl;
                            cout << "Lua Chon Cua Ban: ";
                            cin >> yn;
                            if (yn == 1){
                                cout << "Salary Statistics: ";
                                cin >> data1;
                                ParseDataNV3int ("NhanVien.txt",data1,"=");
                            }
                            else if(yn == 2){
                                cout << "Salary Statistics < : ";
                                cin >> data1;
                                ParseDataNV3int ("NhanVien.txt",data1,"<");
                            }
                            else if (yn == 3){
                                cout << "Salary Statistics > : ";
                                cin >> data1;
                                ParseDataNV3int ("NhanVien.txt",data1,">");
                            }
                        }while (yn != 1 && yn != 2 && yn != 3);
                    }
                    else if(tick == 3){
                        cout << "Office Statistics: ";
                        cin.ignore();
                        getline (cin,data);
                        ParseDataNV3string ("NhanVien.txt",data);
                    }
                }while(tick !=1 && (tick != 2 && lc != 1) && (tick != 2 && lc != 2) && (tick != 2 && lc != 3)&&tick!=3);
            }

            else if (lc == 4){
                readLinesFromFile("NhanVien.txt");
                string MANV;
                do{
                    cout << "Ma Nhan Vien: ";
                    cin >> MANV;
                }while (MANV.length() != 6 && MANV.find ("NV-") == string::npos);
                DeleteLinesFromFiles2("NhanVien.txt","RecycleBinNV.txt",MANV);

            }

            else if (lc == 5){
                ofstream outfile("NhanVien.txt", ios::app);
                int n;
                cout << "So Nhan Vien: ";
                cin >> n;
                nv a[n];
                for (int i=0;i<n;i++){
                    cout << " * NHAN VIEN THU " << i+1 << ":" << endl; 
                    a[i].nhap();
                }
                outfile.close();
            }
            
            else if (lc == 6){
                int tick;
                string MANV;
                string name;
                do{
                    cout << "+------------------------------------+" << endl;
                    cout << "|                SEARCH              |" << endl;
                    cout << "|    1.MANV                 2.NAME   |" << endl;
                    cout << "+------------------------------------+" << endl;
                    cout << "Lua Chon: "; cin >> tick;
                    if(tick == 1){
                        do{
                            cout << "Ma Nhan Vien: ";
                            cin.ignore();
                            getline (cin,MANV);
                        }while (MANV.length() != 6 && MANV.substr(0, 3) != "NV-");
                        FindLinesFromFiles("NhanVien.txt", MANV);
                    }
                    else if(tick == 2){
                        cout << "Name Search: ";
                        cin.ignore();
                        getline (cin,name);
                        FindLinesFromFiles("NhanVien.txt",name);
                    }
                }while(tick !=1 || tick != 2);
            }

            else if (lc == 7){
                Vector<string> vallue;
                int count1 = 0;
                ifstream file("PHG.txt");
                string MANV;
                if(file.is_open()){
                    do{
                        cout << "Ma Nhan Vien: ";
                        cin.ignore();
                        getline (cin,MANV);
                    }while (MANV.length() != 6 && MANV.substr(0, 3) != "NV-");
                    string line;
                    while (getline(file, line)) {
                        if (line.find(MANV) != std::string::npos) {
                            count1 ++;
                            vallue.push_back(line);
                        }
                    }
                }
                if (count1 != 0){
                    cout << "---------+---------+----------------+----------------+-------------+" << endl;
                    cout << setw(7) << "MAKH" << setw(3) << "|" << setw(6) << "IDP" << setw(4) << "|" << setw(11) << "Begin" << setw(6) << "|" << setw(9) << "End" << setw(8) << "|" << setw(11) << "GIA PHONG" << setw(3) << "|" << endl;
                    cout << "---------+---------+----------------+----------------+-------------+" << endl;
                }else{
                    cout << "Du Lieu Rong" << endl;
                }
                for (int i = 0 ; i < vallue.Size(); ++i){
                    ParseDataPHG8(vallue[i]);
                }
                if(count1 != 0){
                    int yn;
                    do{
                        cout << "+-------------------------------------------+" << endl;
                        cout << "|  Ban muon xem chi tiet khach hang khong?  |" << endl; 
                        cout << "|       1.Yes                  2.No         |" << endl;
                        cout << "+-------------------------------------------+" << endl;
                        cout << "Nhap Y/N de xac nhan: "; cin >> yn;
                        try{
                            if (yn == 1){
                                string mkh;
                                do{
                                    cout << "MAKH: ";
                                    cin >> mkh;
                                }while (mkh.length() != 6 && mkh.substr(0, 3) != "KH-");
                                cout << "--------+-----------------------+-----------------+----------------+----------------------------+----------------+" << endl;
                                cout << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << endl;
                                cout << "--------+-----------------------+-----------------+----------------+----------------------------+----------------+" << endl;
                                ifstream file ("KhachHang.txt");
                                if (file.is_open()){
                                    string line;
                                    while (getline(file, line)){
                                        if (line.find(mkh) != string::npos) {
                                            ParseDataKH8(line);
                                        }
                                    }
                                }
                                file.close();
                            }
                            else if (yn == 2){
                                break;
                            }
                            else {
                                throw invalid_argument("=> Nhap 1 hoac 2 !");
                                break;
                            }
                        }
                        catch (invalid_argument e){
                            cout << e.what() << endl;
                        }
                    }while ( yn != 1 || yn != 2);
                }
            }

            else if (lc == 8){
                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                cout << setw(5) << "AGE" << setw(2) << "|" << setw(7) << "GENDER" << setw(3) << "|" << setw(14)  << "NAME" << setw(10) << "|" << setw(8)  << "MANV"  << setw(5) << "|" << setw(10)  << "SALARY" << setw(4) << "|" << setw(9) << "OFFICE" << setw(5) << "|" << endl;
                cout << "------+---------+-----------------------+------------+-------------+-------------+" << endl;
                readLinesFromFile("RecycleBinNV.txt");
                string MANV;
                do{
                    cout << "Ma Nhan Vien Can Khoi Phuc Du Lieu: ";
                    cin >> MANV;
                }while (MANV.length() != 6 && MANV.substr(0, 2) != "NV-");
                recoverLinesFromFileNV("NhanVien.txt","RecycleBinNV.txt",MANV);
            }

            else if(lc == 9){ 
                time_t now = time(nullptr);
                struct tm* tm_now = localtime(&now);
                // Lấy ngày
                int day1 = tm_now->tm_mday;
                // Lấy tháng
                int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
                // Lấy năm
                int year1 = tm_now->tm_year + 1900;
                int tick;
                int d,m,y;
                do{
                    cout << "+-------------------------------------------------+" << endl;
                    cout << "|   Lua Chon Cua Ban :   1. Doanh Thu Theo Ngay   |" << endl;
                    cout << "|                        2. Doanh Thu Theo Thang  |" << endl;
                    cout << "|                        3. Doanh Thu Theo Nam    |" << endl;
                    cout << "|                        0. Thoat                 |" << endl;
                    cout << "+-------------------------------------------------+" << endl;
                    cout << "Lua Chon Cua Ban: ";
                    cin >> tick;
                    if (tick == 0){
                        break;
                    }
                    else if (tick == 1){ 
                        do{
                            cout << "Doanh Thu Ngay (dd/mm/yyyy): ";
                            cin >> d;cin.ignore();cin >> m;cin.ignore();cin>>y;
                            try{
                                if (d <= 0 || m <= 0 || d > 31 || m > 12 || y > 2100){
                                    throw string ("a");
                                }else{
                                    cout << "Doanh Thu Ngay "<< d << "/" << m << "/" << y << " : "<< calculateRevenueDay(d,m,y) << " VND" <<endl;
                                    break;
                                }
                            }
                            catch(string e){
                                cout << "Cu Phap Sai Dinh Dang!" << endl;
                            }
                        }while(d <= 0 || m <= 0 || d > 31 || m > 12 || y > 2100);
                    }
                    else if (tick == 2){
                        do{
                            cout << "Doanh Thu Thang (mm/yyyy): ";
                            cin >> m;cin.ignore();cin>>y;
                            try{
                                if (m <= 0 || m > 12 || y > 2100){
                                    throw string ("a");
                                }else{
                                    cout << "Doanh Thu Thang " << m << "/" << y << " : "<< calculateRevenueMonth(m,y) << " VND" <<endl;
                                    break;
                                }
                            }
                            catch(string e){
                                cout << "Cu Phap Sai Dinh Dang!" << endl;
                            }
                        }while(m <= 0 || m > 12 || y > 2100);
                    }
                    else if (tick == 3){
                        do{
                            cout << "Doanh Thu Nam (yyyy): ";
                            cin >> y;
                            try{
                                if ( y > 2100){
                                    throw string ("a");
                                }else{
                                    cout << "Doanh Thu Nam " << m << "/" << y << " : "<< calculateRevenueMonth(m,y) << " VND" <<endl;
                                    break;
                                }
                            }
                            catch(string e){
                                cout << "Cu Phap Sai Dinh Dang!" << endl;
                            }
                        }while(y > 2100);
                    }
                    else{
                        cout << "Cu Phap Sai Dinh Dang" << endl;
                    }
                }while(tick != 1 || tick != 2 || tick != 3);
            }

            else if(lc == 10){
                readLinesFromFile ("DanhGia.txt");
            }

            else if(lc == 11){
                readLinesFromFile ("KhachHang.txt");
            }

            else if(lc == 12){
                readLinesFromFile ("PHG.txt");
            }

            else if(lc == 13){
                DoiMatKhau(username,password);
            }

            else {
                cout << "Khong Ton Tai Yeu Cau" << endl;
            }

            char input = _getch();
        }
    }
/*--------------------------------MENU OF CUSOMER---------------------------------------------*/
    else if (tk.authenticate(username,password) == 2 ){
        while(1){
            DrawMenuKH();
            cout << "Nhap Lua Chon Cua Ban: ";
            cin >> lc;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            
            if (lc == 0){
                cout << "Hen Gap Lai" << endl;
                break;
            }

            else if (lc == 1){
                ofstream out ("KhachHang.txt", ios::out);
                ofstream os ("PHG.txt", ios::out);
                Customer b[100];
                int m;
                cout << "So Khach Hang: ";
                cin >> m;
                out << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                out << setw(6) << "AGE" << setw(3) << "|" << setw(13) << "NAME" << setw(11) << "|" << setw(11) << "GENDER" <<  setw(7) << "|" << setw(8) << "IDP" <<   setw(6) << "|" << setw(9) << "MaKH" <<  setw(6) << "|" << setw(10)<< "SDT" <<  setw(7) << "|" << setw(16) << "MAIL" << setw(13) << "|" << setw(12)<< "BIRTHDAY" << setw(5) << "|" << setw(7) << "MAQL" << setw(3) << "|" << endl;
                out << "--------+-----------------------+-----------------+-------------+--------------+----------------+----------------------------+----------------+---------+" << endl;
                os << "---------+---------+---------+----------------+----------------+-------------+" << endl;
                os << setw(7) <<"MAKH" << setw(3) << "|" << setw(6) << "MAQL" << setw(4) << "|" << setw(6) << "IDP" << setw(4) << "|" << setw(11) << "Begin" << setw(6) << "|" << setw(9) << "End" << setw(8) << "|" << setw(11) << "GIA PHONG" << setw(3) << "|" << endl;
                os << "---------+---------+---------+----------------+----------------+-------------+" << endl;
                for (int i=0;i<m;i++){
                    cout << " * KHACH HANG THU " << i+1 << ":" << endl; 
                    b[i].Input();
                }
                out.close();
                os.close();
            }

            else if (lc == 2){
                readLinesFromFile ("KhachHang.txt");
            }

            else if (lc == 3){
                string data;
                int data1;
                int tick,yn,lc3,lc2;
                do{
                    cout << "+-------------------------------------------------------+" << endl;
                    cout << "|                        1. Thong Ke Theo Gioi Tinh     |" << endl;
                    cout << "|   Lua Chon Cua Ban :   2. Thong Ke Loai Phong         |" << endl;
                    cout << "|                        3. Thong Ke Kh Thue Tu         |" << endl;
                    cout << "+-------------------------------------------------------+" << endl;
                    cout << "Lua Chon Cua Ban: ";
                    cin >> tick;
                    
                    if(tick == 1){
                        ParseDataKH3gender ("KhachHang.txt");
                    }

                    else if(tick == 2){
                        do{
                            cout << "+----------------------------------------------------+" << endl;
                            cout << "|   Lua Chon Cua Ban :   1. Thong Ke Phong 6th       |" << endl;
                            cout << "|                        2. Thong Ke Phong 3th       |" << endl;
                            cout << "|                        3. Thong Ke Phong 1th       |" << endl;
                            cout << "+----------------------------------------------------+" << endl;
                            cout << "Lua Chon Cua Ban: ";
                            cin >> yn;
                            if (yn == 1){
                                ParseDataKH3string ("PHG.txt",210);
                            }
                            else if(yn == 2){
                                ParseDataKH3string ("PHG.txt",92);
                            }
                            else if (yn == 3){
                                ParseDataKH3string ("PHG.txt",30);
                            }
                        }while (yn != 1 && yn != 2 && yn != 3);
                    }

                    else if(tick == 3){
                        int date,month,year;
                        do{
                            cout << "+----------------------------------------------------+" << endl;
                            cout << "|   Lua Chon Cua Ban :   1. Tu Ngay                  |" << endl;
                            cout << "|                        2. Tu Thang                 |" << endl;
                            cout << "|                        3. Tu Nam                   |" << endl;
                            cout << "+----------------------------------------------------+" << endl;
                            cout << "Lua Chon Cua Ban: ";
                            cin >> lc2;
                                cout << "+----------------------------------------------------+" << endl;
                                cout << "|   Lua Chon Cua Ban :   1. Tro Ve Truoc             |" << endl;
                                cout << "|                        2. Tro Ve Sau               |" << endl;
                                cout << "|                        3. Tai Thoi Diem Do         |" << endl;
                                cout << "+----------------------------------------------------+" << endl;
                                cout << "Lua Chon Cua Ban: ";
                                cin >> lc3;
                                if (lc2 == 1 && lc3 == 1){
                                    cout << "Khach Thue Tu ";
                                    cin >> date;cin.ignore();cin>>month;cin.ignore();cin>>year;
                                    ParseDataKH3int("PHG.txt",date,month,year,"<");
                                }
                                else if(lc2 == 1 && lc3 == 2){
                                    cout << "Khach Thue Tu: ";
                                    cin >> date;cin.ignore();cin>>month;cin.ignore();cin>>year;
                                    ParseDataKH3int("PHG.txt",date,month,year,">");
                                }
                                else if (lc2 == 1 && lc3 == 3){
                                    cout << "Khach Thue Tu: ";
                                    cin >> date;cin.ignore();cin>>month;cin.ignore();cin>>year;
                                    ParseDataKH3int("PHG.txt",date,month,year,"=");
                                }
                                else if(lc2 == 2 && lc3 == 1){
                                    cout << "Khach Thue Tu: ";
                                    cin>>month;cin.ignore();cin>>year;
                                    ParseDataKH3int("PHG.txt",0,month,year,"m<");
                                }
                                else if (lc2 == 2 && lc3 == 2){
                                    cout << "Khach Thue Tu: ";
                                    cin>>month;cin.ignore();cin>>year;
                                    ParseDataKH3int("PHG.txt",0,month,year,"m>");
                                }
                                else if (lc2 == 2 && lc3 == 3){
                                    cout << "Khach Thue Tu: ";
                                    cin>>month;cin.ignore();cin>>year;
                                    ParseDataKH3int("PHG.txt",0,month,year,"m=");
                                }
                                else if (lc2 == 3 && lc3 == 1){
                                    cout << "Khach Thue Tu: ";
                                    cin>>year;
                                    ParseDataKH3int("PHG.txt",0,0,year,"y<");
                                }
                                else if (lc2 == 3 && lc3 == 2){
                                    cout << "Khach Thue Tu: ";
                                    cin>>year;
                                    ParseDataKH3int("PHG.txt",0,0,year,"y>");
                                }
                                else if (lc2 == 3 && lc3 == 3){
                                    cout << "Khach Thue Tu: ";
                                    cin>>year;
                                    ParseDataKH3int("PHG.txt",0,0,year,"y=");
                                }
                        }while(lc2 != 1 && lc2 != 2 && lc2 != 3 && lc3 != 1 && lc3 != 2 && lc3 != 3);
                    }
                }while(tick != 1 && (tick != 2 && lc != 1) && (tick != 2 && lc != 2) && (tick != 2 && lc != 3) && tick!=3);
            }

            else if (lc == 4){
                ofstream out ("KhachHang.txt", ios::app);
                ofstream o ("PHG.txt", ios::app );
                Customer b[100];
                int m;
                cout << "So Khach Hang: ";
                cin >> m;
                for (int i=0;i<m;i++){
                    cout << " * KHACH HANG THU " << i+1 << ":" << endl; 
                    b[i].Input();
                }
                out.close();
                o.close();
            }

            else if (lc == 5){
                int search;
                do{
                    cout << "+----------------------------------------+" << endl;
                    cout << "|                  SEARCH                |" << endl;
                    cout << "|              1.Name Search             |" << endl;
                    cout << "|              2.MAKH Search             |" << endl;
                    cout << "|              3.IDP Search              |" << endl;
                    cout << "+----------------------------------------+" << endl;
                    cout << "Search: "; cin >> search;
                    if (search == 1){
                        string name;
                        cout << "Name Search: ";
                        cin.ignore();
                        getline (cin,name);
                        FindLinesFromFiles("KhachHang.txt",name);
                    }
                    else if (search == 2){
                        string MAKH;
                        do{
                            cout << "MaKH: ";
                            cin >> MAKH;
                        }while (MAKH.length() != 6 && MAKH.substr(0, 3) != "KH-");
                        FindLinesFromFiles("KhachHang.txt",MAKH);
                    }
                    else if (search == 3){
                        string idp;
                        do{
                            cout << "IDP Search: ";
                            cin.ignore();
                            getline (cin,idp);
                        }while (idp.length() != 4 && (idp.substr(0, 1) != "A" || idp.substr(0, 1) != "B" || idp.substr(0, 1) != "C"));
                        FindLinesFromFiles("KhachHang.txt",idp);

                        int yn;
                        do{
                            cout << "+--------------------------------------------------+" << endl;
                            cout << "|  Ban muon xem thong tin KH Thue phong nay khong? |" << endl; 
                            cout << "|      1.Yes                          2.No         |" << endl;
                            cout << "+--------------------------------------------------+" << endl;
                            cout << "Nhap Y/N de xac nhan: "; cin >> yn;
                            try{
                                if (yn == 1){
                                    FindLinesFromFiles("PHG.txt",idp);
                                }
                                else{
                                    throw invalid_argument("=>Hay nhap 1 or 2");
                                }
                            }
                            catch (invalid_argument e){
                                cout << e.what() << endl;
                            }
                        }while ( yn != 1 && yn != 2);
                    }
                }while (search != 1 && search != 2 && search != 3);
            }

            else if (lc == 6){
                time_t now = time(nullptr);
                struct tm* tm_now = localtime(&now);
                // Lấy ngày
                int day1 = tm_now->tm_mday;
                // Lấy tháng
                int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
                // Lấy năm
                int year1 = tm_now->tm_year + 1900;
                Vector<string> KH;
                string makh, maql, idp;
                int date, month, year;
                int date01, month01, year01;
                string name, birthday, gender, sdt,mail;
                int age;
                int giaphong;
                ifstream in ("PHG.txt");
                if (in.is_open()){
                    string line;
                    while (getline(in,line)){
                        if(line.find("MAKH") == string::npos && line.find("-----") == string::npos){
                            istringstream ss(line);
                            string token;
                            if (getline(ss, makh, '|') && getline(ss, maql, '|') && getline(ss, idp, '|')) {
                            // Trích xuất ngày, tháng, năm từ chuỗi
                                if (getline(ss, token, '/')) {
                                    date = stoi(token);
                                    if (getline(ss, token, '/')) {
                                        month = stoi(token);
                                        if (getline(ss, token, '|')) {
                                            year = stoi(token);

                                            // Trích xuất ngày, tháng, năm từ chuỗi
                                            if (getline(ss, token, '/')) {
                                                date01 = stoi(token);
                                                if (getline(ss, token, '/')) {
                                                    month01 = stoi(token);
                                                    if (getline(ss, token, '|')) {
                                                        year01 = stoi(token);

                                                        // Trích xuất giá trị giaphong
                                                        if (getline(ss, token)) {
                                                            giaphong = stoi(token);
                                                        } else {
                                                            cerr << "Error: Missing giaphong." << endl;
                                                        }
                                                    } else {
                                                        cerr << "Error: Invalid input format (year01)." << endl;
                                                    }
                                                } else {
                                                    cerr << "Error: Invalid input format (month01)." << endl;
                                                }
                                            } else {
                                                cerr << "Error: Invalid input format (date01)." << endl;
                                            }
                                        } else {
                                            cerr << "Error: Missing year separator (|) after year." << endl;
                                        }
                                    } else {
                                        cerr << "Error: Invalid input format (month)." << endl;
                                    }
                                } else {
                                    cerr << "Error: Invalid input format (date)." << endl;
                                }
                            } else {
                                cerr << "Error: Missing separator (|) after idp." << endl;
                            }
                            if(year01 < year1 || (year01 == year1 && month01 < month1) || (year01 == year1 && month01 == month1 && date01 < day1)){
                                KH.push_back(makh);
                            }
                        }
                    }
                }
                in.close();
                
                for(int i=0; i<KH.Size();++i){
                    ifstream in_file ("KhachHang.txt");
                    ofstream out_file ("KhachHangout.txt",ios::app);
                    ofstream o("IDP.txt",ios::app);
                    ofstream o1("MaKH.txt",ios::app);
                    if (in_file.is_open()){
                        string line;
                        while(getline(in_file,line)){
                            if(line.find(KH[i]) != string::npos && (line.find("MAKH") == string::npos && line.find("-----") == string::npos)){
                                istringstream ss(line);
                                string token;
                                getline(ss, token, '|');
                                age = stoi(token);
                                getline(ss, token, '|');
                                name = token;
                                getline(ss, token, '|');
                                gender = token;
                                getline(ss, token, '|');
                                idp = token;
                                getline(ss, token, '|');
                                makh = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                sdt = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                mail = token;
                                getline(ss,token,'|');
                                birthday = token;
                                getline(ss, token, '|');
                                maql = token;
                                out_file << setw(5) << age << setw(4) << "|" << name <<  "|" << gender << "|" << setw(13)<< sdt <<  setw(4) << "|" << setw(25) << mail << setw(4) << "|" << setw(13) << birthday << "|" << endl;
                                o << idp << endl;
                                o1 << makh << endl;
                            }
                        }
                    }
                    o1.close();
                    o.close();
                    out_file.close();
                    in_file.close();
                    DeleteLinesFromFiles("KhachHang.txt",KH[i]);
                    DeleteLinesFromFiles("PHG.txt",KH[i]);
                }
            }

            else if (lc == 7){
                string MaKH;
                int count=0;
                // Biến lưu trữ các giá tri
                string makh, maql, idp;
                do{
                    cout << "MaKH: ";
                    cin >> MaKH;
                }while (MaKH.length() != 6 && MaKH.substr(0, 3) != "KH-");
                if (KtraTonTai("PHG.txt",MaKH)){
                    ifstream output("PHG.txt");
                    string line;
                    if(output.is_open()){
                        while(getline(output,line))
                        {
                            if(line.find(MaKH)!=string::npos){
                                istringstream ss (line);
                                string token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                makh = token;
                                getline(ss, token, '|');
                                maql = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                idp = token;
                                getline(ss, token, '|');
                                string begin = token;
                                getline(ss, token, '|');
                                string end = token;
                                getline(ss, token, '|');
                                int giaphong = stoi(token);
                            }    
                        }
                        ofstream o("IDP.txt",ios::app);
                        o << idp << endl;
                        o.close();
                        ofstream o1("MaKH.txt",ios::app);
                        o1 << makh << endl;
                        o1.close();
                        string name, birthday, gender, sdt,mail;
                        int age;
                        DeleteLinesFromFiles("PHG.txt",MaKH);
                        ifstream file("KhachHang.txt");
                        if (file.is_open()) {
                            string line;
                            while (getline(file, line)) {
                                if(line.find(MaKH) != string::npos){
                                    istringstream ss(line);
                                    string token;
                                    getline(ss, token, '|');
                                    age = stoi(token);
                                    getline(ss, token, '|');
                                    name = token;
                                    getline(ss, token, '|');
                                    gender = token;
                                    getline(ss, token, '|');
                                    idp = token;
                                    getline(ss, token, '|');
                                    makh = token;
                                    getline(ss, token, '|');
                                    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                    sdt = token;
                                    getline(ss, token, '|');
                                    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                    mail = token;
                                    getline(ss,token,'|');
                                    birthday = token;
                                    getline(ss, token, '|');
                                    maql = token;
                                }
                            }
                            file.close();
                        } 
                        else {
                            cout << "FILE Khong Ton Tai" << endl;
                        }
                        DeleteLinesFromFiles("KhachHang.txt",MaKH);
                        ofstream out_file ("KhachHangout.txt",ios::app);
                        out_file << setw(5) << age << setw(4) << "|" << name <<  "|" << gender << "|" << setw(13)<< sdt <<  setw(4) << "|" << setw(25) << mail << setw(4) << "|" << setw(13) << birthday << "|" << endl;
                        out_file.close();
                    }
                }
            }

            else if (lc == 8){
                time_t now = time(nullptr);
                struct tm* tm_now = localtime(&now);
                // Lấy ngày
                int day1 = tm_now->tm_mday;
                // Lấy tháng
                int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
                // Lấy năm
                int year1 = tm_now->tm_year + 1900;
                string MaKH;
                int count=0;
                // Biến lưu trữ các giá trị
                string makh, maql, idp, name, gender, sdt, mail;
                int date, month, year;
                int date01, month01, year01;
                int giaphong,age;
                do{
                    cout << "MaKH: ";
                    cin >> MaKH;
                }while (MaKH.length() != 6 && MaKH.substr(0, 3) != "KH-");
                ifstream output("PHG.txt");
                if(output.is_open()){
                    string line;
                    while(getline(output,line)){
                        if(line.find(MaKH)!=string::npos){
                            count++;
                            istringstream ss(line);
                            string token;

                            // Trích xuất các giá trị từ chuỗi
                            if (getline(ss, makh, '|') && getline(ss, maql, '|') && getline(ss, idp, '|')) {
                                // Trích xuất ngày, tháng, năm từ chuỗi
                                if (getline(ss, token, '/')) {
                                    date = stoi(token);
                                    if (getline(ss, token, '/')) {
                                        month = stoi(token);
                                        if (getline(ss, token, '|')) {
                                            year = stoi(token);

                                            // Trích xuất ngày, tháng, năm từ chuỗi
                                            if (getline(ss, token, '/')) {
                                                date01 = stoi(token);
                                                if (getline(ss, token, '/')) {
                                                    month01 = stoi(token);
                                                    if (getline(ss, token, '|')) {
                                                        year01 = stoi(token);

                                                        // Trích xuất giá trị giaphong
                                                        if (getline(ss, token)) {
                                                            giaphong = stoi(token);
                                                            
                                                        } else {
                                                            cerr << "Error: Missing giaphong." << endl;
                                                        }
                                                    } else {
                                                        cerr << "Error: Invalid input format (year01)." << endl;
                                                    }
                                                } else {
                                                    cerr << "Error: Invalid input format (month01)." << endl;
                                                }
                                            } else {
                                                cerr << "Error: Invalid input format (date01)." << endl;
                                            }
                                        } else {
                                            cerr << "Error: Missing year separator (|) after year." << endl;
                                        }
                                    } else {
                                        cerr << "Error: Invalid input format (month)." << endl;
                                    }
                                } else {
                                    cerr << "Error: Invalid input format (date)." << endl;
                                }
                            } else {
                                cerr << "Error: Missing separator (|) after idp." << endl;
                            }
                        }        
                    }
                }
                if (count != 0){
                    DeleteLinesFromFiles("PHG.txt",MaKH);
                    Room A;
                    int datenew,monthnew,yearnew;
                    datenew = date01;
                    monthnew = month01;
                    yearnew = year01;
                    cout << "Date of Begin (dd/mm/yyyy): " << datenew << "/" << monthnew << "/" << yearnew << endl;
                    ofstream o ("PHG.txt",ios::app);
                    ifstream in ("KhachHang.txt");
                    if (in.is_open()){
                        string line;
                        while (getline (in, line)){
                            if(line.find(MaKH) != string::npos){
                                istringstream ss(line);
                                string token;
                                getline(ss, token, '|');
                                age = stoi(token);
                                getline(ss, token, '|');
                                name = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                gender = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                string idp1 = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                string makh1 = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                sdt = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                mail = token;
                                getline(ss, token, '|');
                                string birthday1 = token;
                                getline(ss, token, '|');
                                string maql1 = token;
                            }
                        }
                    }
                    int dk;
                    int giaphong;
                    do{
                        cout << "+-----Cac goi cho thue phong-------+" << endl;
                        cout << "|     1. 1 thang                   |" << endl;
                        cout << "|     2. 3 thang + Voucher (15%)   |" << endl;
                        cout << "|     3. 6 thang + Free 1 thang    |" << endl;
                        cout << "+----------------------------------+" << endl;
                        cout << "Ban muon thue goi : ";
                        cin >> dk;
                        if (dk == 1){
                            int voucher;
                            A.Date_of_end(datenew,monthnew,yearnew,1);
                            if (day1 == month1){
                                voucher = A.gia01(1) * 0.05;
                            }
                            else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                                voucher = A.gia01(1) * 0.1;
                            }
                            else {
                                voucher = 0;
                            }
                            giaphong=A.gia01(1);
                            int date01 = A.getDate01();
                            int month01 = A.getMonth01();
                            int year01 = A.getYear01();
                            o << makh << "|" << maql << "|" << idp << "|" << setw(5) << day1 << "/" << setw(2) << month1 <<  "/" << year1 << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                            cout << "+---------------------------------------------+" << endl;
                            cout << "|             HOA DON THANH TOAN              |" << endl;
                            cout << "|      Name  : " << setw(31) << left << name << "|" << endl;
                            cout << "|      Age   : " << setw(31) << left << age << "|" << endl;
                            cout << "|      Gender: " << setw(31) << left << gender << "|" << endl;
                            cout << "|      MAKH  : " << setw(31) << left << makh << "|" << endl;
                            cout << "|      IDP   : " << setw(31) << left << idp << "|" << endl;
                            cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(1) <<" VND  |" << endl;
                            cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                            cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                            cout << "|                                             |" << endl;
                            cout << "+---------------------------------------------+" << endl;

                        }
                        else if (dk == 2){
                            int voucher;
                            A.Date_of_end(datenew,monthnew,yearnew,3);
                            if (day1 == month1){
                                voucher = A.gia01(3) * 0.2;
                            }
                            else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                                voucher = A.gia01(3) * 0.25;
                            }
                            else {
                                voucher = A.gia01(3) * 0.15;
                            }
                            giaphong=A.gia01(3) - voucher;
                            int date01 = A.getDate01();
                            int month01 = A.getMonth01();
                            int year01 = A.getYear01();
                            o << makh << "|" << maql << "|" << idp << "|" << setw(5) << day1 << "/" << setw(2) << month1 <<  "/" << year1 << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                            cout << "+---------------------------------------------+" << endl;
                            cout << "|             HOA DON THANH TOAN              |" << endl;
                            cout << "|      Name  : " << setw(31) << left << name << "|" << endl;
                            cout << "|      Age   : " << setw(31) << left << age << "|" << endl;
                            cout << "|      Gender: " << setw(31) << left << gender << "|" << endl;
                            cout << "|      MAKH  : " << setw(31) << left << makh << "|" << endl;
                            cout << "|      IDP   : " << setw(31) << left << idp << "|" << endl;
                            cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(3) <<" VND  |" << endl;
                            cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                            cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                            cout << "|                                             |" << endl;
                            cout << "+---------------------------------------------+" << endl;
                        }
                        else{
                            A.Date_of_end(datenew,monthnew,yearnew,7);
                            int voucher;
                            if (day1 == month1){
                                voucher = A.gia01(6) * 0.05 + A.gia01(1);
                            }
                            else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                                voucher = A.gia01(6) * 0.1 + A.gia01(1);
                            }
                            else {
                                voucher = A.gia01(1);
                            }
                            giaphong = A.gia01(7) - voucher;
                            int date01 = A.getDate01();
                            int month01 = A.getMonth01();
                            int year01 = A.getYear01();
                            o << makh << "|" << maql << "|" << idp << "|" << setw(5) << day1 << "/" << setw(2) << month1 <<  "/" << year1 << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                            cout << "+---------------------------------------------+" << endl;
                            cout << "|             HOA DON THANH TOAN              |" << endl;
                            cout << "|      Name  : " << setw(31) << left << name << "|" << endl;
                            cout << "|      Age   : " << setw(31) << left << age << "|" << endl;
                            cout << "|      Gender: " << setw(31) << left << gender << "|" << endl;
                            cout << "|      MAKH  : " << setw(31) << left << makh << "|" << endl;
                            cout << "|      IDP   : " << setw(31) << left << idp << "|" << endl;
                            cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(7) <<" VND  |" << endl;
                            cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                            cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                            cout << "|                                             |" << endl;
                            cout << "+---------------------------------------------+" << endl;
                        }
                    }while(dk != 1 && dk != 2 && dk != 3);
                    o.close();
                    int money;
                    int check = 0;
                    ifstream pin ("HoaDon.txt");
                    ofstream pout ("HoaDon.txt",ios::app);
                    if(pin.is_open()){
                        string line;
                        while(getline(pin,line)){
                            istringstream ss(line);
                            string token;
                            getline (ss,token,'/');
                            int daay = stoi(token);
                            getline (ss,token,'/');
                            int monthh = stoi(token);
                            getline (ss,token,'|');
                            int yearr = stoi(token);
                            if(day1 == daay && month1 == monthh && year1 == yearr && line.find(MaKH) != string::npos && line.find("Gia Han Phong") != string::npos){
                                istringstream ss(line);
                                string token;
                                getline (ss,token,'/');
                                int daay = stoi(token);
                                getline (ss,token,'/');
                                int monthh = stoi(token);
                                getline (ss,token,'|');
                                int yearr = stoi(token);
                                getline (ss,token,'|');
                                string makht = token;
                                getline (ss,token,'|');
                                money = stoi(token);
                                getline (ss,token,'|');
                                string tt = token;
                                if (day1 == daay && month1 == monthh && year1 == yearr){
                                    money += giaphong;
                                }
                                DeleteLinesFromFiles("HoaDon.txt",line);
                                check++;
                                pout << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << MaKH << setw(2) << "|" << setw(10) << money << setw(4) << "|" << setw(15) << "Gia Han Phong" << setw(3) << "|" << endl;
                            }
                        }
                    }
                    if (check == 0){
                        pout << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << MaKH << setw(2) << "|" << setw(10) << giaphong << setw(4) << "|" << setw(15) << "Gia Han Phong" << setw(3) << "|" << endl;
                    }
                    pout.close();
                    pin.close();
                    int money1;
                    int tmp = 0;
                    ifstream in_put ("ThanhToan.txt");
                    ofstream out_put ("ThanhToan.txt",ios::app);
                    if (in_put.is_open()){
                        string line;
                        while(getline(in_put,line)){
                            if (line.find(MaKH) != string::npos){
                                istringstream ss (line);
                                string token;
                                getline (ss,token,'|');
                                string makhtt = token;
                                getline (ss,token,'|');
                                money1 = stoi(token);
                                money1 += giaphong;
                                DeleteLinesFromFiles("ThanhToan.txt",line);
                                out_put << setw(9) << MaKH << setw(4) << "|" << setw(12) << money1 << setw(4) << "|" << endl;
                                tmp++;
                            }
                        }
                    }
                    if (tmp == 0){
                        out_put << setw(9) << MaKH << setw(4) << "|" << setw(12) << giaphong << setw(4) << "|" << endl;
                    }
                    out_put.close();
                    in_put.close();
                }else {
                    cout << "Khong Ton Tai Phong" << endl;
                }
            }

            else if (lc == 9){
                Room A;
                int datenew,monthnew,yearnew,giaphong;
                time_t now = time(nullptr);
                struct tm* tm_now = localtime(&now);
                    // Lấy ngày
                int day1 = tm_now->tm_mday;
                        // Lấy tháng
                int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
                    // Lấy năm
                int year1 = tm_now->tm_year + 1900; // Năm bắt đầu từ 1900
                string idpnew;
                int age;
                int user;
                string name,gender,sdt,makh;
                string gmail,maql;
                string check;
                int datebirthday,monthbirthday,yearbirthday;
                cout <<"Mail Or SDT Da Duoc Dang Ki Truoc Do: " << endl;
                do{
                    cout << "+-----------------------------------------+" << endl;
                    cout << "|    1.SDT                       2.MAIL   |" << endl;
                    cout << "+-----------------------------------------+" << endl;
                    cin >> user;
                    if (user == 1){
                        do{
                            cout << "SDT: ";
                            cin >> check;
                            try{
                                if (check.size()!=10){
                                    throw invalid_argument ("=> So dien thoai can du 10 so ");
                                }else{
                                    break;
                                }
                            } 
                            catch (invalid_argument e){
                                cout << e.what() << endl;
                            }
                        }while (check.size()!=10);
                    }
                    else if(user == 2){
                        do{
                            cout << "MAIL: ";
                            cin.ignore();
                            getline(cin,check);
                            try{
                                if (check.find("@gmail.com") != string::npos && check.find("@gmail.com") == check.length() - 10){
                                    break; 
                                }else{
                                    throw invalid_argument ("=> MaiL hop le co duoi :  @gmail.com ");
                                }
                            } 
                            catch (invalid_argument e){
                                cout << e.what() << endl;
                            }
                        }while ((check.find("@gmail.com") == string::npos && check.find("@gmail.com") != check.length() - 10));
                    }
                }while(user != 1 && user != 2);
                if( KtraTonTai("KhachHangout.txt",check)){
                    cout << "Ma Nhan Vien Dang Ki: ";
                    maql = username;
                    cout << maql << endl;
                    Vector<string> out = readLinesFromFilesWithIf("KhachHangout.txt",check);
                    for(int i = 0; i < out.Size(); ++i){
                        istringstream ss(out[i]);
                        string token;
                        if (getline(ss, token, '|')) {
                            age = std::stoi(token);
                            if (getline(ss, token, '|')) {
                                name = token;
                                if (getline(ss, token, '|')) {
                                    token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                    gender = token;
                                    if (getline(ss, token, '|')) {
                                        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                        sdt = token;
                                        if (getline(ss, token, '|')) {
                                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                            gmail = token;
                                            if (getline(ss, token, '/')) {
                                                datebirthday = std::stoi(token);
                                                if (getline(ss, token, '/')) {
                                                    monthbirthday = std::stoi(token);
                                                    if (getline(ss, token, '|')) {
                                                        yearbirthday = std::stoi(token);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        cout << datebirthday << "/" << monthbirthday << "/" << yearbirthday << endl;
                    }
                    Vector<string> mkh = readLinesFromFile1("MaKH.txt");
                    if(!mkh.empty()){
                        makh = mkh.back();
                        cout << "MAKH: " << makh << endl;
                        Vector<string> idp = readLinesFromFile1("IDP.txt");
                        idpnew = idp.back();
                        cout << "IDP: " << idpnew << endl;
                        int count = 0;
                        do{
                            cout << "Date of Begin (dd/mm/yyyy): ";
                            cin >> datenew; cin.ignore(); cin >> monthnew; cin.ignore(); cin >> yearnew;
                            try{
                                if ((datenew <= 0 || monthnew <= 0 || datenew > 31 || monthnew > 12 || yearnew > 2100) || (yearnew < year1 || (yearnew == year1 && monthnew < month1) || (yearnew == year1 && monthnew == month1 && datenew < day1))){
                                    count++;
                                    throw invalid_argument ("! Error !");
                                }else{
                                    break;
                                }
                            }
                            catch(invalid_argument e){
                                cout << e.what() << endl;
                            }
                        }while(datenew <= 0 || monthnew <= 0 || datenew > 31 || monthnew > 12 || count != 0 || yearnew > 2100);
                        ofstream oP ("PHG.txt", ios::app);
                        ofstream outK ("KhachHang.txt", ios::app);
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
                                int voucher;
                                A.Date_of_end(datenew,monthnew,yearnew,1);
                                if (day1 == month1){
                                    voucher = A.gia01(1) * 0.05;
                                }
                                else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                                    voucher = A.gia01(1) * 0.1;
                                }
                                else {
                                    voucher = 0;
                                }
                                int giaphong=A.gia01(1);
                                int date01 = A.getDate01();
                                int month01 = A.getMonth01();
                                int year01 = A.getYear01();
                                outK << setw(5) << age << setw(4) << "|" << setw(20) << name << "|" << setw(10) << gender <<  setw(8) << "|" << setw(8) << idpnew <<   setw(6) << "|" << setw(10) << makh << setw(5) << "|" << setw(13)<< sdt <<  setw(4) << "|" << setw(25) << gmail << setw(4) << "|" << setw(5) << datebirthday << "/" << setw(2) << monthbirthday << "/" << yearbirthday << setw (4) << "|" << setw(8) << maql << setw(2) << "|" << endl;
                                oP << setw(8)<< makh << setw(2) << "|" << setw(8) << maql << setw(2) << "|" << setw(6) << idpnew << setw(4) << "|" << setw(5) << datenew << "/" << setw(2) << monthnew <<  "/" << yearnew << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                                cout << "+---------------------------------------------+" << endl;
                                cout << "|             HOA DON THANH TOAN              |" << endl;
                                cout << "|                                             |" << endl;
                                cout << "|      Name  : " << setw(31) << left << name << "|" << endl;
                                cout << "|      Age   : " << setw(31) << left << age << "|" << endl;
                                cout << "|      Gender: " << setw(31) << left << gender << "|" << endl;
                                cout << "|      MAKH  : " << setw(31) << left << makh << "|" << endl;
                                cout << "|      IDP   : " << setw(31) << left << idp << "|" << endl;
                                cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(1) <<" VND  |" << endl;
                                cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                                cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                                cout << "|                                             |" << endl;
                                cout << "+---------------------------------------------+" << endl;

                            }
                            else if (dk == 2){
                                int voucher;
                                A.Date_of_end(datenew,monthnew,yearnew,3);
                                if (day1 == month1){
                                    voucher = A.gia01(3) * 0.2;
                                }
                                else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                                    voucher = A.gia01(3) * 0.25;
                                }
                                else {
                                    voucher = A.gia01(3) * 0.15;
                                }
                                int giaphong=A.gia01(3) - voucher;
                                int date01 = A.getDate01();
                                int month01 = A.getMonth01();
                                int year01 = A.getYear01();
                                outK << setw(5) << age << setw(4) << "|" << setw(20) << name << "|" << setw(10) << gender <<  setw(8) << "|" << setw(8) << idpnew <<   setw(6) << "|" << setw(10) << makh << setw(5) << "|" << setw(13)<< sdt <<  setw(4) << "|" << setw(25) << gmail << setw(4) << "|" << setw(5) << datebirthday << "/" << setw(2) << monthbirthday << "/" << yearbirthday << setw (4) << "|" << setw(8) << maql << setw(2) << "|" << endl;
                                oP << setw(8)<< makh << setw(2) << "|" << setw(8) << maql << setw(2) << "|" << setw(6) << idpnew << setw(4) << "|" << setw(5) << datenew << "/" << setw(2) << monthnew <<  "/" << yearnew << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                                cout << "+---------------------------------------------+" << endl;
                                cout << "|             HOA DON THANH TOAN              |" << endl;
                                cout << "|                                             |" << endl;
                                cout << "|      Name  : " << setw(31) << left << name << "|" << endl;
                                cout << "|      Age   : " << setw(31) << left << age << "|" << endl;
                                cout << "|      Gender: " << setw(31) << left << gender << "|" << endl;
                                cout << "|      MAKH  : " << setw(31) << left << makh << "|" << endl;
                                cout << "|      IDP   : " << setw(31) << left << idp << "|" << endl;
                                cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(3) <<" VND  |" << endl;
                                cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                                cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                                cout << "|                                             |" << endl;
                                cout << "+---------------------------------------------+" << endl;
                            }
                            else if (dk == 3){
                                A.Date_of_end(datenew,monthnew,yearnew,7);
                                int voucher;
                                if (day1 == month1){
                                    voucher = A.gia01(6) * 0.05 + A.gia01(1);
                                }
                                else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                                    voucher = A.gia01(6) * 0.1 + A.gia01(1);
                                }
                                else {
                                    voucher = A.gia01(1);
                                }
                                int giaphong = A.gia01(7) - voucher;
                                int date01 = A.getDate01();
                                int month01 = A.getMonth01();
                                int year01 = A.getYear01();
                                outK << setw(5) << age << setw(4) << "|" << setw(20) << name << "|" << setw(10) << gender <<  setw(8) << "|" << setw(8) << idpnew <<   setw(6) << "|" << setw(10) << makh << setw(5) << "|" << setw(13)<< sdt <<  setw(4) << "|" << setw(25) << gmail << setw(4) << "|" << setw(5) << datebirthday << "/" << setw(2) << monthbirthday << "/" << yearbirthday << setw (4) << "|" << setw(8) << maql << setw(2) << "|" << endl;
                                oP << setw(8)<< makh << setw(2) << "|" << setw(8) << maql << setw(2) << "|" << setw(6) << idpnew << setw(4) << "|" << setw(5) << datenew << "/" << setw(2) << monthnew <<  "/" << yearnew << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                                cout << "+---------------------------------------------+" << endl;
                                cout << "|             HOA DON THANH TOAN              |" << endl;
                                cout << "|                                             |" << endl;
                                cout << "|      Name  : " << setw(31) << left << name << "|" << endl;
                                cout << "|      Age   : " << setw(31) << left << age << "|" << endl;
                                cout << "|      Gender: " << setw(31) << left << gender << "|" << endl;
                                cout << "|      MAKH  : " << setw(31) << left << makh << "|" << endl;
                                cout << "|      IDP   : " << setw(31) << left << idp << "|" << endl;
                                cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(7) <<" VND  |" << endl;
                                cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                                cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                                cout << "|                                             |" << endl;
                                cout << "+---------------------------------------------+" << endl;
                            }
                        }while(dk != 1 && dk != 2 && dk != 3);
                        int money;
                        int check = 0;
                        ifstream pin ("HoaDon.txt");
                        ofstream pout ("HoaDon.txt",ios::app);
                        if(pin.is_open()){
                            string line;
                            while(getline(pin,line)){
                                istringstream ss(line);
                                string token;
                                getline (ss,token,'/');
                                int daay = stoi(token);
                                getline (ss,token,'/');
                                int monthh = stoi(token);
                                getline (ss,token,'|');
                                int yearr = stoi(token);
                                if(day1 == daay && month1 == monthh && year1 == yearr && line.find(makh) != string::npos && line.find("Dang Ki Phong") != string::npos){
                                    istringstream ss(line);
                                    string token;
                                    getline (ss,token,'/');
                                    int daay = stoi(token);
                                    getline (ss,token,'/');
                                    int monthh = stoi(token);
                                    getline (ss,token,'|');
                                    int yearr = stoi(token);
                                    getline (ss,token,'|');
                                    string makht = token;
                                    getline (ss,token,'|');
                                    money = stoi(token);
                                    getline (ss,token,'|');
                                    string tt = token;
                                    if (day1 == daay && month1 == monthh && year1 == yearr){
                                        money += giaphong;
                                    }
                                    DeleteLinesFromFiles("HoaDon.txt",line);
                                    check++;
                                    pout << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << makh << setw(2) << "|" << setw(10) << money << setw(4) << "|" << setw(15) << "Dang Ki Phong" << setw(3) << "|" << endl;
                                }
                            }
                        }
                        if (check == 0){
                            pout << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << makh << setw(2) << "|" << setw(10) << giaphong << setw(4) << "|" << setw(15) << "Dang Ki Phong" << setw(3) << "|" << endl;
                        }
                        pout.close();
                        pin.close();
                        int money1;
                        int tmp = 0;
                        ifstream in_put ("ThanhToan.txt");
                        ofstream out_put ("ThanhToan.txt",ios::app);
                        if (in_put.is_open()){
                            string line;
                            while(getline(in_put,line)){
                                if (line.find(makh) != string::npos){
                                    istringstream ss (line);
                                    string token;
                                    getline (ss,token,'|');
                                    string makhtt = token;
                                    getline (ss,token,'|');
                                    money1 = stoi(token);
                                    money1 += giaphong;
                                    DeleteLinesFromFiles("ThanhToan.txt",line);
                                    out_put << setw(9) << makh << setw(4) << "|" << setw(12) << money1 << setw(4) << "|" << endl;
                                    tmp++;
                                }
                            }
                        }
                        if (tmp == 0){
                            out_put << setw(9) << makh << setw(4) << "|" << setw(12) << giaphong << setw(4) << "|" << endl;
                        }
                        out_put.close();
                        in_put.close();
                        ofstream os ("MaKH.txt",ios::out);
                        mkh.pop_back();
                        for (size_t i = 0; i < mkh.Size(); ++i) {
                            string makhEntry = mkh[i];
                            os << makhEntry << endl;
                        }
                        os.close();
                        ofstream onr ("IDP.txt",ios::out);
                        idp.pop_back();
                        for (size_t i = 0; i< idp.Size();++i){
                            string IdpEntry = idp[i];
                            onr << IdpEntry << endl;
                        }
                        onr.close();
                        DeleteLinesFromFiles("KhachHangout.txt",gmail);
                    }else{
                        cout << "Da Het Phong . Cam On Quy Khach . Hen Gap Lai" << endl;
                    }  
                }
                else {
                    cout<< " Du Lieu Khong Ton Tai "<< endl;
                } 
            }

            else if (lc == 10){
                cout << "Danh Sach Phong: " << endl;
                KtraRoom();
            }

            else if (lc == 11){
                string MAKH;
                do{
                    cout << "MaKH: ";
                    cin >> MAKH;
                }while (MAKH.length() != 6 && MAKH.substr(0, 3) != "KH-");
                DeleteLinesFromFiles("ThanhToan.txt",MAKH);
            }

            else if (lc == 12){
                DoiMatKhau(username,password);
            }

            else {
                cout << "Khong Ton Tai Yeu Cau" << endl;
            }

            char input = _getch();
        }
    }
/*--------------------------------MENU OF ROOM---------------------------------------------*/
    else if (tk.authenticate(username,password) == 3 ){
        while(1){
            cout << "********************   MENU   ****************" << endl;
            cout << "**                                          **" << endl;
            cout << "**       1.Trang Thai Cua Phong Cua Ban     **" << endl;
            cout << "**       2.Gia Han PHong                    **" << endl;
            cout << "**       3.Tra Phong                        **" << endl;
            cout << "**       4.Uu Dai Cua Ban                   **" << endl;
            cout << "**       5.Danh Gia Dich Vu                 **" << endl;
            cout << "**       6.Order Do An                      **" << endl;
            cout << "**       7.Doi Mat Khau                     **" << endl;
            cout << "**       0.Thoat                            **" << endl;
            cout << "**                                          **" << endl;
            cout << "**********************************************" << endl;
            cout << "Nhap Lua Chon Cua Ban: ";
            cin >> lc;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

            if (lc == 0){
                cout << "Hen Gap Lai" << endl;
                break;
            }

            else if (lc == 1){
                
                if (FindLinesFromFiles("PHG.txt",username)){
                    FindLinesFromFiles("KhachHang.txt",username);
                }else{
                    cout<<"Phong ban da het han, neu muon dang ki thi truy cap vao muc 4" << endl;
                }
            }

            else if (lc == 2){
                time_t now = time(nullptr);
                struct tm* tm_now = localtime(&now);
                // Lấy ngày
                int day1 = tm_now->tm_mday;
                // Lấy tháng
                int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
                // Lấy năm
                int year1 = tm_now->tm_year + 1900;
                string MaKH;
                int count=0;
                // Biến lưu trữ các giá trị
                string makh, maql, idp, name, gender, sdt, mail;
                int date, month, year;
                int date01, month01, year01;
                int giaphong,age;
                MaKH = username;
                ifstream output("PHG.txt");
                if(output.is_open()){
                    string line;
                    while(getline(output,line)){
                        if(line.find(MaKH)!=string::npos){
                            istringstream ss(line);
                            string token;

                            // Trích xuất các giá trị từ chuỗi
                            if (getline(ss, makh, '|') && getline(ss, maql, '|') && getline(ss, idp, '|')) {
                                // Trích xuất ngày, tháng, năm từ chuỗi
                                if (getline(ss, token, '/')) {
                                    date = stoi(token);
                                    if (getline(ss, token, '/')) {
                                        month = stoi(token);
                                        if (getline(ss, token, '|')) {
                                            year = stoi(token);

                                            // Trích xuất ngày, tháng, năm từ chuỗi
                                            if (getline(ss, token, '/')) {
                                                date01 = stoi(token);
                                                if (getline(ss, token, '/')) {
                                                    month01 = stoi(token);
                                                    if (getline(ss, token, '|')) {
                                                        year01 = stoi(token);

                                                        // Trích xuất giá trị giaphong
                                                        if (getline(ss, token)) {
                                                            giaphong = stoi(token);
                                                            
                                                        } else {
                                                            cerr << "Error: Missing giaphong." << endl;
                                                        }
                                                    } else {
                                                        cerr << "Error: Invalid input format (year01)." << endl;
                                                    }
                                                } else {
                                                    cerr << "Error: Invalid input format (month01)." << endl;
                                                }
                                            } else {
                                                cerr << "Error: Invalid input format (date01)." << endl;
                                            }
                                        } else {
                                            cerr << "Error: Missing year separator (|) after year." << endl;
                                        }
                                    } else {
                                        cerr << "Error: Invalid input format (month)." << endl;
                                    }
                                } else {
                                    cerr << "Error: Invalid input format (date)." << endl;
                                }
                            } else {
                                cerr << "Error: Missing separator (|) after idp." << endl;
                            }
                        }        
                    }
                }
                DeleteLinesFromFiles("PHG.txt",MaKH);
                Room A;
                int datenew,monthnew,yearnew;
                datenew = date01;
                monthnew = month01;
                yearnew = year01;
                cout << "Date of Begin (dd/mm/yyyy): " << datenew << "/" << monthnew << "/" << yearnew << endl;
                ofstream o ("PHG.txt",ios::app);
                ifstream in ("KhachHang.txt");
                if (in.is_open()){
                    string line;
                    while (getline (in, line)){
                        if(line.find(MaKH) != string::npos){
                            istringstream ss(line);
                            string token;
                            getline(ss, token, '|');
                            age = stoi(token);
                            getline(ss, token, '|');
                            name = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            gender = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            string idp1 = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            string makh1 = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            sdt = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            mail = token;
                            getline(ss, token, '|');
                            string birthday1 = token;
                            getline(ss, token, '|');
                            string maql1 = token;
                        }
                    }
                }
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
                        int voucher;
                        A.Date_of_end(datenew,monthnew,yearnew,1);
                        if (day1 == month1){
                            voucher = A.gia01(1) * 0.05;
                        }
                        else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                            voucher = A.gia01(1) * 0.1;
                        }
                        else {
                            voucher = 0;
                        }
                        int giaphong=A.gia01(1);
                        int date01 = A.getDate01();
                        int month01 = A.getMonth01();
                        int year01 = A.getYear01();
                        o << makh << "|" << maql << "|" << idp << "|" << setw(5) << datenew << "/" << setw(2) << monthnew <<  "/" << yearnew << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                        cout << "+---------------------------------------------+" << endl;
                        cout << "|             HOA DON THANH TOAN              |" << endl;
                        cout << "|      Name  : " << setw(31) << left << "Le Dinh Toan" << "|" << endl;
                        cout << "|      Age   : " << setw(31) << left << "18" << "|" << endl;
                        cout << "|      Gender: " << setw(31) << left << "Nam" << "|" << endl;
                        cout << "|      MAKH  : " << setw(31) << left << "KH-106" << "|" << endl;
                        cout << "|      IDP   : " << setw(31) << left << "B05" << "|" << endl;
                        cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(1) <<" VND  |" << endl;
                        cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                        cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                        cout << "|                                             |" << endl;
                        cout << "+---------------------------------------------+" << endl;

                    }
                    else if (dk == 2){
                        int voucher;
                        A.Date_of_end(datenew,monthnew,yearnew,3);
                        if (day1 == month1){
                            voucher = A.gia01(3) * 0.2;
                        }
                        else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                            voucher = A.gia01(3) * 0.25;
                        }
                        else {
                            voucher = A.gia01(3) * 0.15;
                        }
                        int giaphong=A.gia01(3) - voucher;
                        int date01 = A.getDate01();
                        int month01 = A.getMonth01();
                        int year01 = A.getYear01();
                        o << makh << "|" << maql << "|" << idp << "|" << setw(5) << datenew << "/" << setw(2) << monthnew <<  "/" << yearnew << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                        cout << "+---------------------------------------------+" << endl;
                        cout << "|             HOA DON THANH TOAN              |" << endl;
                        cout << "|      Name  : " << setw(31) << left << "Le Dinh Toan" << "|" << endl;
                        cout << "|      Age   : " << setw(31) << left << "18" << "|" << endl;
                        cout << "|      Gender: " << setw(31) << left << "Nam" << "|" << endl;
                        cout << "|      MAKH  : " << setw(31) << left << "KH-106" << "|" << endl;
                        cout << "|      IDP   : " << setw(31) << left << "B05" << "|" << endl;
                        cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(3) <<" VND  |" << endl;
                        cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                        cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                        cout << "|                                             |" << endl;
                        cout << "+---------------------------------------------+" << endl;
                    }
                    else{
                        A.Date_of_end(datenew,monthnew,yearnew,7);
                        int voucher;
                        if (day1 == month1){
                            voucher = A.gia01(6) * 0.05 + A.gia01(1);
                        }
                        else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3) || (day1 == 25 && month1 == 12) || (day1 == 1 && month1 == 1)){
                            voucher = A.gia01(6) * 0.1 + A.gia01(1);
                        }
                        else {
                            voucher = A.gia01(1);
                        }
                        int giaphong = A.gia01(7) - voucher;
                        int date01 = A.getDate01();
                        int month01 = A.getMonth01();
                        int year01 = A.getYear01();
                        o << makh << "|" << maql << "|" << idp << "|" << setw(5) << date << "/" << setw(2) << month <<  "/" << year << setw(4) << "|" << setw(5) << date01 << "/" << setw(2) << month01 << "/" << year01 << setw(4) << "|" << setw(11) << giaphong << setw(3) << "|" << endl;
                        cout << "+---------------------------------------------+" << endl;
                        cout << "|             HOA DON THANH TOAN              |" << endl;
                        cout << "|      Name  : " << setw(31) << left << "Le Dinh Toan" << "|" << endl;
                        cout << "|      Age   : " << setw(31) << left << "18" << "|" << endl;
                        cout << "|      Gender: " << setw(31) << left << "Nam" << "|" << endl;
                        cout << "|      MAKH  : " << setw(31) << left << "KH-106" << "|" << endl;
                        cout << "|      IDP   : " << setw(31) << left << "B05" << "|" << endl;
                        cout << "|      Tong Tien Phong : " << setw(15) << right << A.gia01(7) <<" VND  |" << endl;
                        cout << "|      Voucher         : " << setw(8) << right << "-" << setw(7) << voucher << " VND  |" << endl;
                        cout << "|      Tong Phai Tra   : " << setw(15) << right << giaphong <<" VND  |" << endl;
                        cout << "|                                             |" << endl;
                        cout << "+---------------------------------------------+" << endl;
                    }
                }while(dk != 1 && dk != 2 && dk != 3);
                o.close();
                int money;
                int check = 0;
                ifstream pin ("HoaDon.txt");
                ofstream pout ("HoaDon.txt",ios::app);
                if(pin.is_open()){
                    string line;
                    while(getline(pin,line)){
                        istringstream ss(line);
                        string token;
                        getline (ss,token,'/');
                        int daay = stoi(token);
                        getline (ss,token,'/');
                        int monthh = stoi(token);
                        getline (ss,token,'|');
                        int yearr = stoi(token);
                        if(day1 == daay && month1 == monthh && year1 == yearr && line.find(MaKH) != string::npos && line.find("Gia Han Phong") != string::npos){
                            istringstream ss(line);
                            string token;
                            getline (ss,token,'/');
                            int daay = stoi(token);
                            getline (ss,token,'/');
                            int monthh = stoi(token);
                            getline (ss,token,'|');
                            int yearr = stoi(token);
                            getline (ss,token,'|');
                            string makht = token;
                            getline (ss,token,'|');
                            money = stoi(token);
                            getline (ss,token,'|');
                            string tt = token;
                            if (day1 == daay && month1 == monthh && year1 == yearr){
                                money += giaphong;
                            }
                            DeleteLinesFromFiles("HoaDon.txt",line);
                            check++;
                            pout << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << MaKH << setw(2) << "|" << setw(10) << money << setw(4) << "|" << setw(15) << "Gia Han Phong" << setw(3) << "|" << endl;
                        }
                    }
                }
                if (check == 0){
                    pout << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << MaKH << setw(2) << "|" << setw(10) << giaphong << setw(4) << "|" << setw(15) << "Gia Han Phong" << setw(3) << "|" << endl;
                }
                pout.close();
                pin.close();
                int money1;
                int tmp = 0;
                ifstream in_put ("ThanhToan.txt");
                ofstream out_put ("ThanhToan.txt",ios::app);
                if (in_put.is_open()){
                    string line;
                    while(getline(in_put,line)){
                        if (line.find(MaKH) != string::npos){
                            istringstream ss (line);
                            string token;
                            getline (ss,token,'|');
                            string makhtt = token;
                            getline (ss,token,'|');
                            money1 = stoi(token);
                            money1 += giaphong;
                            DeleteLinesFromFiles("ThanhToan.txt",line);
                            out_put << setw(9) << MaKH << setw(4) << "|" << setw(12) << money1 << setw(4) << "|" << endl;
                            tmp++;
                        }
                    }
                }
                if (tmp == 0){
                    out_put << setw(9) << MaKH << setw(4) << "|" << setw(12) << giaphong << setw(4) << "|" << endl;
                }
                out_put.close();
                in_put.close();
            }

            else if (lc == 3){
                string MaKH;
                int count=0;
                // Biến lưu trữ các giá tri
                string makh, maql, idp;
                cout<<"Nhap ma khach hang cua ban: ";
                cin.ignore();
                getline(cin,MaKH);
                ifstream output("PHG.txt");
                string line;
                if(output.is_open()){
                    while(getline(output,line))
                    {
                        if(line.find(MaKH)!=string::npos){
                            istringstream ss (line);
                            string token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            makh = token;
                            getline(ss, token, '|');
                            maql = token;
                            getline(ss, token, '|');
                            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                            idp = token;
                            getline(ss, token, '|');
                            string begin = token;
                            getline(ss, token, '|');
                            string end = token;
                            getline(ss, token, '|');
                            int giaphong = stoi(token);
                        }    
                    }
                    ofstream o("IDP.txt",ios::app);
                    o << idp << endl;
                    o.close();
                    ofstream o1("MaKH.txt",ios::app);
                    o1 << makh << endl;
                    o1.close();
                    string name, birthday, gender, sdt,mail;
                    int age;
                    DeleteLinesFromFiles("PHG.txt",MaKH);
                    ifstream file("KhachHang.txt");
                    if (file.is_open()) {
                        string line;
                        while (getline(file, line)) {
                            if(line.find(MaKH) != string::npos){
                                istringstream ss(line);
                                string token;
                                getline(ss, token, '|');
                                age = stoi(token);
                                getline(ss, token, '|');
                                name = token;
                                getline(ss, token, '|');
                                gender = token;
                                getline(ss, token, '|');
                                idp = token;
                                getline(ss, token, '|');
                                makh = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                sdt = token;
                                getline(ss, token, '|');
                                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                                mail = token;
                                getline(ss,token,'|');
                                birthday = token;
                                getline(ss, token, '|');
                                maql = token;
                            }
                        }
                        file.close();
                    } 
                    else {
                        cout << "FILE Khong Ton Tai" << endl;
                    }
                    DeleteLinesFromFiles("KhachHang.txt",MaKH);
                    ofstream out_file ("KhachHangout.txt",ios::app);
                    out_file << setw(5) << age << setw(4) << "|" << name <<  "|" << gender << "|" << setw(13)<< sdt <<  setw(4) << "|" << setw(25) << mail << setw(4) << "|" << setw(13) << birthday << "|" << endl;
                    out_file.close();
                }
            }

            else if (lc == 4){
                time_t now = time(nullptr);
                struct tm* tm_now = localtime(&now);
                // Lấy ngày
                int day1 = tm_now->tm_mday;
                // Lấy tháng
                int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
                // Lấy năm
                int year1 = tm_now->tm_year + 1900;

                if (day1 == month1){
                    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
                    cout << "|                                           SAN SALE CUNG VUTOAN-HOURSE                                    |" << endl;
                    cout << "|                                                                                                          |" << endl;
                    cout << "|   Hay Dang Ki Lien Tay <3 Voucher giam gia 5% cho khach hang dang ki ngay hom nay ^^ Nhanh tay keo het   |" << endl;
                    cout << "+----------------------------------------------------------------------------------------------------------+" << endl;

                }
                else if ((day1 == 14 && month1 == 2) || (day1 == 14 && month1 == 3)){
                    cout << "+---------------------------------------------------------------------------------------------------------------------------------------+" << endl;
                    cout << "|                                                DANG KI NHAN NGAY VOUCHER KHUNG                                                        |" << endl;
                    cout << "|                                                                                                                                       |" << endl;
                    cout << "|          Ngay le tinh nhan ban da ai de om ap chua :> Neu co hay đen sleep box cua chung toi de tan huong khong gian rieng tu         |" << endl;
                    cout << "|                                       ben canh nguoi minh thuong voi nhung phut an ai man nong :)))                                   |" << endl;
                    cout << "|                             Voucher giam 10% gia phong cho cac cap doi nhanh tay dang ki vao ngay hom nay                             |" << endl;
                    cout << "+---------------------------------------------------------------------------------------------------------------------------------------+" << endl;
                }
                else if (day1 == 25 && month1 == 12){
                    cout << "+------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
                    cout << "|                                                  GIANG SINH AN LANH CUNG VUTOAN-HOUSE                                                   |" << endl;
                    cout << "|                                                                                                                                          |" << endl;
                    cout << "|          Giang Sinh da den cung voi mua dong lanh gia . Lieu co phai ban dang can mot cho de suoi am cho trai tym cua minh :))           |" << endl;                                         
                    cout << "|             Hay den VUTOAN-HOUSE de tan huong nhung dich vu tuyet voi va nhung uu dai hap dan trong dip giang sinh nay                  |" << endl;
                    cout << "|                                                      Voucher giam 10% gia phong                                                          |" << endl;
                    cout << "+------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
                }
                else if (day1 == 1 && month1 == 1){
                    cout << "+-----------------------------------------------------------------------------------------------------------------+" << endl;
                    cout << "|                                           NAM MOI PHAT TAI PHAT LOC                                             |" << endl;
                    cout << "|                                                                                                                 |" << endl;
                    cout << "|          Nam cu da qua nam moi lai toi :> Chuc Ban Mot Nam Moi Vui Ve Tran Day Hanh Phuc Ben Gia Dinh           |" << endl;
                    cout << "|    Nam Het Tet Den VUTOAN-HOUSE tri an khach hang voucher 10% gia phong cho khach hang dang ki ngay hom nay    |" << endl;
                    cout << "|                                             Nhanh Tay Nhan Tai Loc                                              |" << endl;
                    cout << "+-----------------------------------------------------------------------------------------------------------------+" << endl;
                }
            }

            else if (lc == 5){
                time_t now = time(nullptr);
                struct tm* tm_now = localtime(&now);
                // Lấy ngày
                int day1 = tm_now->tm_mday;
                // Lấy tháng
                int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
                // Lấy năm
                int year1 = tm_now->tm_year + 1900;
                string Makh;
                string dg;
                string dg1;
                Makh = username;
                if(KtraTonTai("KhachHang.txt",Makh) == true){
                    Vector<string> DG;
                    DG.push_back(Makh);
                    string danhgia;
                    int lc1;
                    int tick = 1;
                    if (tick == 1){
                        do{
                            cout << "+---------------------------DICH VU PHONG--------------------------+" << endl;
                            cout << "|                                                                  |" << endl;
                            cout << "|     1.Rat Te    2.Te    3.Binh Thuong    4.Tot     5.Rat Tot     |" << endl;
                            cout << "|                                                                  |" << endl;
                            cout << "+------------------------------------------------------------------+" << endl;
                            cout << " Lua Chon Cua Ban: ";
                            cin >> lc1;
                            if (lc1 == 1){
                                dg = "Rat Te";
                            }else if (lc1 == 2){
                                dg = "Te";
                            }else if (lc1 == 3){
                                dg = "Binh Thuong";
                            }else if (lc1 == 4){
                                dg = "Tot";
                            }else if (lc1 == 5){
                                dg = "Rat Tot";
                            }
                        }while (lc1 != 1 && lc != 2 && lc != 3 && lc != 4 && lc != 5);
                        tick ++;
                        if (tick == 2){
                            do{
                                cout << "+-------------------------THAI DO NHAN VIEN------------------------+" << endl;
                                cout << "|                                                                  |" << endl;
                                cout << "|     1.Rat Te    2.Te    3.Binh Thuong    4.Tot     5.Rat Tot     |" << endl;
                                cout << "|                                                                  |" << endl;
                                cout << "+------------------------------------------------------------------+" << endl;
                                cout << " Lua Chon Cua Ban: ";
                                cin >> lc1;
                                if (lc1 == 1){
                                    dg1 = "Rat Te";
                                }else if (lc1 == 2){
                                    dg1 = "Te";
                                }else if (lc1 == 3){
                                    dg1 = "Binh Thuong";
                                }else if (lc1 == 4){
                                    dg1 = "Tot";
                                }else if (lc1 == 5){
                                    dg1 = "Rat Tot";
                                }
                            }while(lc1 != 1 && lc != 2 && lc != 3 && lc != 4 && lc != 5);
                            tick++;
                            if (tick == 3){
                                do{
                                    cout << "+-------------------------DANH GIA CHI TIET------------------------+" << endl;
                                    cout << "|                                                                  |" << endl;
                                    cout << "|                1.YES                         2.NO                |" << endl;
                                    cout << "|                                                                  |" << endl;
                                    cout << "+------------------------------------------------------------------+" << endl;
                                    cout << " Lua Chon Cua Ban: ";
                                    cin >> lc1;
                                    if (lc1 == 1){
                                        cout << "Danh Gia Cua Ban: ";
                                        cin.ignore();
                                        getline(cin,danhgia);
                                    }
                                    else if (lc1 == 2){
                                        danhgia = "TRONG";
                                    }
                                }while (lc1 != 1 && lc1 == 2);
                            }
                        }
                    }
                    ofstream out_fin ("DanhGia.txt",ios::app);
                    out_fin << setw(2) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(8) << Makh << setw(3) << "|" << setw(15) << dg << setw(4) << "|" << setw(15) << dg1 << setw(4) << "|   " << danhgia << endl;
                    out_fin.close();
                }
            }
            
            else if (lc == 6){
                time_t now = time(nullptr);
                struct tm* tm_now = localtime(&now);
                // Lấy ngày
                int day1 = tm_now->tm_mday;
                // Lấy tháng
                int month1 = tm_now->tm_mon + 1; // Tháng bắt đầu từ 0
                // Lấy năm
                int year1 = tm_now->tm_year + 1900;
                Vector<int> tick;
                Vector<int> so_luong;
                Vector<int> hoa_don;
                int lc2 , sl2;
                int gia = 0;
                int vnd1 = 10000,vnd2=20000,vnd3=15000,vnd4=50000,vnd5=40000,vnd6=25000,vnd7=30000,vnd8=8000;
                cout << " _________________________________________________________________________________________________________________________________________________"  << endl;
                cout << "|                 |     DO AN     |                       |      DO UONG      |                          |        DO AN VAT        |              |" << endl;
                cout << "|                 +---------------+                       +-------------------+                          +-------------------------+              |" << endl;
                cout << "|          1.Mi tom               10.000           10. Ca phe                 25.000             19.Banh trang tron               15.000          |" << endl;
                cout << "|          2.Com chien            20.000           11. Coca                   15.000             20.Snack tron                    25.000          |" << endl;
                cout << "|          3.Banh mi              15.000           12. Nuoc suoi              10.000             21.Xoai lac                      15.000          |" << endl;
                cout << "|          4.Kimbap               50.000           13. Tra sua                25.000             22.Banh dong xu                  25.000          |" << endl;
                cout << "|          5.Tokbokki             40.000           14. Tra dao                25.000             23.Hoa qua say kho               30.000          |" << endl; 
                cout << "|          6.Com suon nuong       25.000           15. Tra chanh              15.000             24.Trung ga nuong                8000/tr         |" << endl; 
                cout << "|          7.Bun thit nuong       30.000           16. Sua chua nha dam       20.000             25.Bim Bim                       10.000          |" << endl; 
                cout << "|          8.Bo ne                15.000           17. Capuchino              30.000             26.Pho mai que                   25.000          |" << endl; 
                cout << "|          9.Com ga quay          25.000           18. Latte                  30.000             27.Banh pho mai                  20.000          |" << endl; 
                cout << "|                                                                                                                                                 |" << endl;
                cout << "|                                                        0. Thoat khoi Menu                                                                       |" << endl;                                             
                cout << "|_________________________________________________________________________________________________________________________________________________|" << endl;
                for (int i = 0; i< 1000;i++){
                    cout << "Lua Chon: ";
                    cin >> lc2;
                    if(lc2 != 0){
                        tick.push_back(lc2);
                    }
                    if( lc2 != 0){
                        cout << "So Luong: ";
                        cin >> sl2;
                        so_luong.push_back(sl2);
                    }else{
                        break;
                    }
                }

                string name;
                int gia1;
                cout << "+--------------------------------------------------------+" << endl;
                cout << "|                    Hoa Don Thanh Toan                  |" << endl;
                cout << "|                                                        |" << endl;
                for(int i = 0 ; i<so_luong.Size(); ++i){
                    if (tick[i] == 1){
                        gia1=10000*so_luong[i];
                        name = "My Tom";
                    }
                    if (tick[i] == 2){
                        gia1=20000*so_luong[i];
                        name = "Com Chien";
                    }
                    if (tick[i] == 3){
                        gia1=15000*so_luong[i];
                        name = "Banh My";
                    }
                    if (tick[i] == 4){
                        gia1=50000*so_luong[i];
                        name = "Kimbap";
                    }
                    if (tick[i] == 5){
                        gia1=40000*so_luong[i];
                        name = "Tokbokki";
                    }
                    if (tick[i] == 6){
                        gia1=25000*so_luong[i];
                        name = "Com Suon Nuong";
                    }
                    if (tick[i] == 7){
                        gia1=30000*so_luong[i];
                        name = "Bun Thit Nuong";
                    }
                    if (tick[i] == 8){
                        gia1=15000*so_luong[i];
                        name = "Bo Ne";
                    }
                    if (tick[i] == 9){
                        gia1=25000*so_luong[i];
                        name = "Com ga quay";
                    }
                    if (tick[i] == 10){
                        gia1=25000*so_luong[i];
                        name = "Ca phe";
                    }
                    if (tick[i] == 11){
                        gia1=15000*so_luong[i];
                        name = "Coca";
                    }
                    if (tick[i] == 12){
                        gia1=10000*so_luong[i];
                        name = "Nuoc Suoi";
                    }
                    if (tick[i] == 13){
                        gia1=25000*so_luong[i];
                        name = "Tra Sua";
                    }
                    if (tick[i] == 14){
                        gia1=25000*so_luong[i];
                        name = "Tra dao";
                    }
                    if (tick[i] == 15){
                        gia1=15000*so_luong[i];
                        name = "Tra chanh";
                    }
                    if (tick[i] == 16){
                        gia1=20000*so_luong[i];
                        name = "Sua chua nha dam";
                    }
                    if (tick[i] == 17){
                        gia1=30000*so_luong[i];
                        name = "Capuchino";
                    }
                    if (tick[i] == 18){
                        gia1=30000*so_luong[i];
                        name = "Latte";
                    }
                    if (tick[i] == 19){
                        gia1=15000*so_luong[i];
                        name = "Banh Trang Tron";
                    }
                    if (tick[i] == 20){
                        gia1=25000*so_luong[i];
                        name = "Snack tron";
                    }
                    if (tick[i] == 21){
                        gia1=15000*so_luong[i];
                        name = "Xoa lac";
                    }
                    if (tick[i] == 22){
                        gia1=25000*so_luong[i];
                        name = "Banh Dong xu";
                    }
                    if (tick[i] == 23){
                        gia1=30000*so_luong[i];
                        name = "Hoa qua say kho";
                    }
                    if (tick[i] == 24){
                        gia1=8000*so_luong[i];
                        name = "Trung ga nuong";
                    }
                    if (tick[i] == 25){
                        gia1=10000*so_luong[i];
                        name = "BimBim";
                    }
                    if (tick[i] == 26){
                        gia1=25000*so_luong[i];
                        name = "Pho Mai Que";
                    }
                    if (tick[i] == 27){
                        gia1=20000*so_luong[i];
                        name = "Banh pho mai";
                    }
                    cout << "|   " << setw(30) << left << name << setw(5) << so_luong[i] << setw(10) << left << gia1 << "VND     |" << endl;
                    gia = gia + gia1;
                }
                cout << "|                                                        |" << endl;
                cout << "|   " << setw(30) << left << "Tong Tien: " << setw(15) << left << gia << "VND     |" << endl;
                cout << "+--------------------------------------------------------+" << endl;
                string maKhtt;
                int money;
                int check = 0;
                ifstream pin ("HoaDon.txt");
                    ofstream pout ("HoaDon.txt",ios::app);
                    if(pin.is_open()){
                        string line;
                        while(getline(pin,line)){
                            istringstream ss(line);
                            string token;
                            getline (ss,token,'/');
                            int daay = stoi(token);
                            getline (ss,token,'/');
                            int monthh = stoi(token);
                            getline (ss,token,'|');
                            int yearr = stoi(token);
                            if(day1 == daay && month1 == monthh && year1 == yearr && line.find(username) != string::npos && line.find("Oder Do An") != string::npos){
                                istringstream ss(line);
                                string token;
                                getline (ss,token,'/');
                                int daay = stoi(token);
                                getline (ss,token,'/');
                                int monthh = stoi(token);
                                getline (ss,token,'|');
                                int yearr = stoi(token);
                                getline (ss,token,'|');
                                string makht = token;
                                getline (ss,token,'|');
                                money = stoi(token);
                                getline (ss,token,'|');
                                string tt = token;
                                if (day1 == daay && month1 == monthh && year1 == yearr){
                                    money += gia;
                                }
                                DeleteLinesFromFiles("HoaDon.txt",line);
                                check++;
                                pout << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << username << setw(2) << "|" << setw(10) << money << setw(4) << "|" << setw(15) << "Oder Do An" << setw(3) << "|" << endl;
                            }
                        }
                    }
                    if (check == 0){
                        pout << setw(4) << day1 << "/" << setw(2) << month1 << "/" << year1 << setw(3) << "|" << setw(7) << username << setw(2) << "|" << setw(10) << gia << setw(4) << "|" << setw(15) << "Oder Do An" << setw(3) << "|" << endl;
                    }
                    pout.close();
                    pin.close();
            }

            else if (lc == 7){
                DoiMatKhau(username,password);
            }

            else {
                cout << "Khong Ton Tai Yeu Cau" << endl;
            }
        }
    }
    return 0;
}
