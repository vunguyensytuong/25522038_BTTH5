#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <string>

using namespace std;

class SinhVien {
protected:
    string mssv;
    string hoTen;
    string diaChi;
    int tongTinChi;
    float diemTB;

public:
    SinhVien();
    virtual ~SinhVien();

    virtual void Nhap();
    virtual void Xuat();
    virtual bool XetTotNghiep() = 0;

    // ham ho tro phan loai de de xu ly thong ke
    virtual int LayLoaiSV() = 0; // 1: Cao dang, 2: Dai hoc

    float GetDiemTB() const;
};

#endif
