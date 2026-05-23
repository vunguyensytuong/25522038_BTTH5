#ifndef KHACHHANGLOAIB_H
#define KHACHHANGLOAIB_H
#include "KhachHang.h"
#include <algorithm>
class KhachHangLoaiB : public KhachHang {
private:
    int soNamThanThiet;
public:
    void doc(istream& is) override {
        KhachHang::doc(is);
        is >> soNamThanThiet;
    }
    double tinhTien() override {
        // tinh tien loai B khuyen mai toi da 50% roi cong 10% VAT
        double giaGoc = soLuong * donGia;
        double khuyenMai = min(soNamThanThiet * 0.05, 0.50);
        return giaGoc * (1.0 - khuyenMai) + 0.1 * giaGoc;
    }
};
#endif
