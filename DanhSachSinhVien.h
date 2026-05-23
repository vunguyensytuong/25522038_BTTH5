#ifndef DANHSACHSINHVIEN_H
#define DANHSACHSINHVIEN_H

#include "SinhVien.h"
#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"
#include <vector>

class DanhSachSinhVien {
private:
    vector<SinhVien*> ds;

public:
    ~DanhSachSinhVien();
    void Nhap();
    void Xuat();
    void XuatSVTotNghiep();
    void XuatSVKhongTotNghiep();
    void SVDHDiemTBCaoNhat();
    void SVCDDiemTBCaoNhat();
    void ThongKeKhongTotNghiep();
};

#endif
