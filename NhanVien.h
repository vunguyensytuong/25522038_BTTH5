#ifndef NHANVIEN_H
#define NHANVIEN_H
#include "NgayThangNam.h"
#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
protected:
    std::string HoTen;
    NgayThangNam NgaySinh;
    float Luong;
public:
    virtual float TinhLuong();
    virtual void Nhap(istream&is);
    virtual void Xuat(ostream&os);
    friend istream&operator>>(istream&is, NhanVien&NV);
    friend ostream&operator<<(ostream&os, NhanVien&NV);
};

#endif // NHANVIEN_H
