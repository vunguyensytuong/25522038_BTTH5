#include "NgayThangNam.h"
#include <iostream>
#include <limits>
using namespace std;

bool NgayThangNam::NgayHopLe(int d, int m, int y) {
    if (y < 1 || m < 1 || m > 12) return false; //nam phai >0, thang phai >0 va <=12
    if (d < 1 || d > NgayTrongThang(m, y)) return false; //kiem tra ngay hop le
    return true;
}

bool NgayThangNam::NamNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int NgayThangNam::NgayTrongThang(int m, int y){
    switch (m){
        case 2:
        if (NamNhuan(y)) return 29;
        return 28;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 0;
    }
}


istream& operator >> (istream& in, NgayThangNam& d) {
    int TempNgay, TempThang, TempNam;

    while (true) {
        cout << "Nhap ngay thang nam (cach nhau khoang trang): ";

        //kiem tra co phai la so nguyen khong
        if (in >> TempNgay >> TempThang >> TempNam) {

            //kiem tra ngay co hop le khong
            if (NgayThangNam::NgayHopLe(TempNgay, TempThang, TempNam)) {
                d.Ngay = TempNgay;
                d.Thang = TempThang;
                d.Nam = TempNam;
                break; //thoat khoi vong lap
            } else {
                cout << "Loi! Ngay thang nam khong ton tai trong thuc te!\n";
            }
        } else {
            //khi nhap ki tu khong phai so nguyen
            cout << "Loi! Vui long chi nhap so nguyen!\n";
            in.clear(); //xoa loi
            in.ignore(numeric_limits<streamsize>::max(), '\n'); //xoa loi nhap lai
        }
    }
    return in;
}

//toan tu xuat
ostream& operator << (ostream& out, const NgayThangNam& d) {
    //in theo dinh dang dd/mm/yyyy
    if (d.Ngay < 10) out << "0";
    out << d.Ngay << "/";
    if (d.Thang < 10) out << "0";
    out << d.Thang << "/";
    out << d.Nam;
    return out;
}
