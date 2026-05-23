#ifndef DANHSACHGIAODICH_H
#define DANHSACHGIAODICH_H

#include "GiaoDich.h"
#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
#include "GiaoDichCanHoChungCu.h"
#include <vector>

class DanhSachGiaoDich
{
private:
    std::vector<GiaoDich*> dsGiaoDich;
public:
    ~DanhSachGiaoDich();
    void Nhap();
    void ThongKeSoLuongTungLoai();
    void TrungBinhThanhTienChungCu();
    void GiaoDichNhaPhoCaoNhat();
    void XuatGiaoDichThang12Nam2024();
};

#endif // DANHSACHGIAODICH_H
