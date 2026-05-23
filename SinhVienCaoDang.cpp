#include "SinhVienCaoDang.h"

void SinhVienCaoDang::Nhap() {
    SinhVien::Nhap();

    // kiem tra dieu kien diem thi tot nghiep he cao dang
    do {
        cout << "Nhap diem thi tot nghiep (0 - 10): ";
        cin >> diemThiTN;
        if (diemThiTN < 0 || diemThiTN > 10) {
            cout << "Diem thi khong hop le. Vui long nhap lai!\n";
        }
    } while (diemThiTN < 0 || diemThiTN > 10);
}

void SinhVienCaoDang::Xuat() {
    cout << "[Cao dang] ";
    SinhVien::Xuat();
    cout << " | Diem thi TN: " << diemThiTN << "\n";
}

bool SinhVienCaoDang::XetTotNghiep() {
    // thuat toan xet dieu kien tot nghiep cao dang
    return (tongTinChi >= 120 && diemTB >= 5.0 && diemThiTN >= 5.0);
}

int SinhVienCaoDang::LayLoaiSV() {
    return 1;
}
