#ifndef KHACHHANGLOAIC_H
#define KHACHHANGLOAIC_H
#include "KhachHang.h"
class KhachHangLoaiC : public KhachHang {
public:
    double tinhTien() override {
        // tinh tien loai C tinh 50% gia goc roi cong 10% VAT
        double giaGoc = soLuong * donGia;
        return giaGoc * 0.5 + 0.1 * giaGoc;
    }
};
#endif
