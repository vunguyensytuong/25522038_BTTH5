#ifndef SINHVIENCAODANG_H
#define SINHVIENCAODANG_H

#include "SinhVien.h"

class SinhVienCaoDang : public SinhVien {
private:
    float diemThiTN;

public:
    void Nhap() override;
    void Xuat() override;
    bool XetTotNghiep() override;
    int LayLoaiSV() override;
};

#endif
