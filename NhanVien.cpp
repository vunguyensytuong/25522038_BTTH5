#include "NhanVien.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void NhanVien::Nhap(istream&is){
    cout<<"Nhap ho ten: ";
    getline(is,HoTen);

    cout<<"Nhap ngay sinh:\n";
    is>>NgaySinh;
}

istream&operator>>(istream&is,NhanVien&NV){
    NV.Nhap(is);
    return is;
}

void NhanVien::Xuat(ostream&os){
    os<<"Ho ten: "<<HoTen<<'\n';
    os<<"Ngay sinh: "<<NgaySinh<<'\n';
}

ostream&operator<<(ostream&os, NhanVien&NV){
    NV.Xuat(os);
    return os;
}

float NhanVien::TinhLuong(){
    return 0;
}
