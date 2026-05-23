#ifndef LAPTRINHVIEN_H
#define LAPTRINHVIEN_H

#include "NhanVien.h"

class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    LapTrinhVien();
    void nhap() override;
    void xuat() const override;
    long long tinhLuong() const override;
    int getLoai() const override;
};

#endif
