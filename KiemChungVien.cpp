#include "KiemChungVien.h"

KiemChungVien::KiemChungVien() : NhanVien() {
    soLoiPhatHien = 0;
}

void KiemChungVien::nhap() {
    NhanVien::nhap();
    // kiem tra so loi phat hein khong duoc am
    do {
        cout << "Nhap so loi phat hien: ";
        cin >> soLoiPhatHien;
        if (soLoiPhatHien < 0) {
            cout << "So loi phat hien khong hop le (phai >= 0). Vui long nhap lai!\n";
        }
    } while (soLoiPhatHien < 0);
}

void KiemChungVien::xuat() const {
    NhanVien::xuat();
    cout << " | So loi: " << soLoiPhatHien
         << " | Tong Luong: " << tinhLuong() << "\n";
}

long long KiemChungVien::tinhLuong() const {
    // tinh luong theo cong thuc luong co ban + so loi * 50000
    return luongCoBan + (long long)soLoiPhatHien * 50000;
}

int KiemChungVien::getLoai() const {
    return 2; // 2 dai dien cho kiem chung vien
}
