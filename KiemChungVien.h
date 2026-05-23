#ifndef KIEMCHUNGVIEN_H
#define KIEMCHUNGVIEN_H

#include "NhanVien.h"

class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;

public:
    KiemChungVien();
    void nhap() override;
    void xuat() const override;
    long long tinhLuong() const override;
    int getLoai() const override;
};

#endif
