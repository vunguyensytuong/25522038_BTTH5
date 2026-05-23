#ifndef NHANVIENVANPHONG_H
#define NHANVIENVANPHONG_H
#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien
{
private:
    int SoNgayLamViec;
public:
    void Nhap(istream&is)override;
    void Xuat(ostream&os)override;
    float TinhLuong()override;
};

#endif // NHANVIENVANPHONG_H
