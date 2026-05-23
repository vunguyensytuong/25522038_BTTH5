#ifndef SINHVIENDAIHOC_H
#define SINHVIENDAIHOC_H

#include "SinhVien.h"

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    float diemLuanVan;

public:
    void Nhap() override;
    void Xuat() override;
    bool XetTotNghiep() override;
    int LayLoaiSV() override;
};

#endif
