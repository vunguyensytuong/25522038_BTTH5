#ifndef GIAODICH_H
#define GIAODICH_H
#include "NgayThangNam.h"
#include <iostream>
#include <string>
using namespace std;


class GiaoDich
{
protected:
    std::string MaGiaoDich;
    NgayThangNam NgayGiaoDich;
    float DonGia;
    float DienTich;
public:
    NgayThangNam getNgayGiaoDich() const { return NgayGiaoDich; }
    virtual float TinhThanhTien();
    virtual ~GiaoDich();
    virtual void Nhap(istream&is);
    friend istream& operator>>(istream& is, GiaoDich&GD);
    virtual void Xuat(ostream& os);
    friend ostream& operator <<(ostream& os, GiaoDich&GD);
};

#endif // GIAODICH_H
