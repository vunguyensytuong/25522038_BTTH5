#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class KhachHang {
protected:
    string ten;
    int soLuong;
    double donGia;
public:
    virtual ~KhachHang() {}
    virtual void doc(istream& is) {
        // loai bo khoang trang thua truoc khi doc chuoi
        getline(is >> ws, ten);
        is >> soLuong >> donGia;
    }
    virtual void ghi(ostream& os) {
        os << ten << "\n" << fixed << setprecision(2) << tinhTien() << "\n";
    }
    virtual double tinhTien() = 0;
};
#endif
