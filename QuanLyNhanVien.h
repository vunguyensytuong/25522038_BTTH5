#ifndef QUANLYNHANVIEN_H
#define QUANLYNHANVIEN_H

#include "NhanVien.h"
#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"
#include <vector>

class QuanLyNhanVien
{
private:
    std::vector<NhanVien*> danhSach;
public:
    ~QuanLyNhanVien();
    void NhapDanhSach();
    void TinhLuongToanBo();
    void XuatDanhSach();
    float TinhTongLuong();
    void TimNVSXLuongThapNhat();
    void TimNVVPTuoiCaoNhat();
};

#endif // QUANLYNHANVIEN_H
