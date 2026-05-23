#include "DanhSachNhanVien.h"

int main() {
    DanhSachNhanVien ds;

    cout << "=== a. Nhap danh sach nhan vien ===\n";
    ds.nhapDanhSach();

    cout << "\n=== b. Xuat danh sach nhan vien ===\n";
    ds.xuatDanhSach();

    cout << "\n=== c. Danh sach nhan vien co luong thap hon trung binh ===\n";
    ds.xuatLuongDuoiTrungBinh();

    cout << "\n=== d. Thong tin nhan vien co luong cao nhat ===\n";
    ds.xuatLuongCaoNhat();

    cout << "\n=== e. Thong tin nhan vien co luong thap nhat ===\n";
    ds.xuatLuongThapNhat();

    cout << "\n=== f. Thong tin lap trinh vien co luong cao nhat ===\n";
    ds.xuatLTVLuongCaoNhat();

    cout << "\n=== g. Thong tin kiem chung vien co luong thap nhat ===\n";
    ds.xuatKCVLuongThapNhat();

    return 0;
}
