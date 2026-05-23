#include "NhanVienVanPhong.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void NhanVienVanPhong::Nhap(istream&is){
    NhanVien::Nhap(is);
    cout<<"Nhap so ngay lam viec: ";
    while (true){
        is>>SoNgayLamViec;
        if (is.fail()||(is.peek()!='\n'&&is.peek()!=EOF)){
            cout<<"Loi! Vui long chi nhap so nguyen\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if (SoNgayLamViec<0){
            cout<<"Loi! So ngay lam viec khong the nho hon 0\n";
            continue;
        }
        break;
    }
    is.ignore(numeric_limits<streamsize>::max(), '\n');
}

void NhanVienVanPhong::Xuat(ostream&os){
    NhanVien::Xuat(os);
    os<<"So ngay lam viec: "<<SoNgayLamViec<<'\n';
}

float NhanVienVanPhong::TinhLuong(){
    Luong=SoNgayLamViec*100000;
    return Luong;
}
