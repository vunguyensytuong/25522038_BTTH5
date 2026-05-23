#ifndef NHANVIENSANXUAT_H
#define NHANVIENSANXUAT_H
#include "NhanVien.h"
#include <iostream>

class NhanVienSanXuat : public NhanVien
{
private:
    float LuongCanBan;
    int SoSanPham;
public:
    float TinhLuong()override;
    void Nhap(istream&is)override;
    void Xuat(ostream&os)override;
};

#endif // NHANVIENSANXUAT_H
