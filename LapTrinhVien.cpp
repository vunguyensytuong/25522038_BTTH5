#include "LapTrinhVien.h"

LapTrinhVien::LapTrinhVien() : NhanVien() {
    soGioOvertime = 0;
}

void LapTrinhVien::nhap() {
    NhanVien::nhap();
    // kiem tra so gio overtime khong duoc am
    do {
        cout << "Nhap so gio overtime: ";
        cin >> soGioOvertime;
        if (soGioOvertime < 0) {
            cout << "So gio overtime khong hop le (phai >= 0). Vui long nhap lai!\n";
        }
    } while (soGioOvertime < 0);
}

void LapTrinhVien::xuat() const {
    NhanVien::xuat();
    cout << " | So gio OT: " << soGioOvertime
         << " | Tong Luong: " << tinhLuong() << "\n";
}

long long LapTrinhVien::tinhLuong() const {
    // tinh luong theo cong thuc luong co ban + so gio ot * 200000
    return luongCoBan + (long long)soGioOvertime * 200000;
}

int LapTrinhVien::getLoai() const {
    return 1; // 1 dai dien cho lap trinh vien
}
