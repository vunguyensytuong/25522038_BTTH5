#ifndef KHACHHANGLOAIA_H
#define KHACHHANGLOAIA_H
#include "KhachHang.h"
class KhachHangLoaiA : public KhachHang {
public:
    double tinhTien() override {
        // tinh tien loai A voi 10% VAT tren gia goc
        double giaGoc = soLuong * donGia;
        return giaGoc + 0.1 * giaGoc;
    }
};
#endif
