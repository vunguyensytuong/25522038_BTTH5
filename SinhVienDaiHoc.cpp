#include "SinhVienDaiHoc.h"

void SinhVienDaiHoc::Nhap() {
    SinhVien::Nhap();
    cin.ignore();

    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);

    // kiem tra dieu kien diem luan van he dai hoc
    do {
        cout << "Nhap diem luan van (0 - 10): ";
        cin >> diemLuanVan;
        if (diemLuanVan < 0 || diemLuanVan > 10) {
            cout << "Diem luan van khong hop le. Vui long nhap lai!\n";
        }
    } while (diemLuanVan < 0 || diemLuanVan > 10);
}

void SinhVienDaiHoc::Xuat() {
    cout << "[Dai hoc] ";
    SinhVien::Xuat();
    cout << " | Ten luan van: " << tenLuanVan
         << " | Diem luan van: " << diemLuanVan << "\n";
}

bool SinhVienDaiHoc::XetTotNghiep() {
    // thuat toan xet dieu kien tot nghiep dai hoc
    return (tongTinChi >= 170 && diemTB >= 5.0 && diemLuanVan >= 5.0);
}

int SinhVienDaiHoc::LayLoaiSV() {
    return 2;
}
