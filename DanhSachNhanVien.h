#ifndef DANHSACHNHANVIEN_H
#define DANHSACHNHANVIEN_H

#include <vector>
#include "NhanVien.h"
#include "LapTrinhVien.h"
#include "KiemChungVien.h"

class DanhSachNhanVien {
private:
    vector<NhanVien*> ds;

public:
    ~DanhSachNhanVien();

    void nhapDanhSach();
    void xuatDanhSach() const;
    double tinhLuongTrungBinh() const;
    void xuatLuongDuoiTrungBinh() const;
    void xuatLuongCaoNhat() const;
    void xuatLuongThapNhat() const;
    void xuatLTVLuongCaoNhat() const;
    void xuatKCVLuongThapNhat() const;
};

#endif
