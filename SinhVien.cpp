#include "SinhVien.h"

SinhVien::SinhVien() : tongTinChi(0), diemTB(0.0) {}

SinhVien::~SinhVien() {}

void SinhVien::Nhap() {
    cin.ignore();
    cout << "Nhap MSSV: ";
    getline(cin, mssv);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    // kiem tra dieu kien nhap tong so tin chi phai lon hon 0
    do {
        cout << "Nhap tong so tin chi (>0): ";
        cin >> tongTinChi;
        if (tongTinChi <= 0) {
            cout << "So tin chi khong hop le. Vui long nhap lai!\n";
        }
    } while (tongTinChi <= 0);

    // kiem tra dieu kien nhap diem trung binh tu 0 den 10
    do {
        cout << "Nhap diem trung binh (0 - 10): ";
        cin >> diemTB;
        if (diemTB < 0 || diemTB > 10) {
            cout << "Diem khong hop le. Vui long nhap lai!\n";
        }
    } while (diemTB < 0 || diemTB > 10);
}

void SinhVien::Xuat() {
    cout << "MSSV: " << mssv << " | Ho ten: " << hoTen
         << " | Dia chi: " << diaChi << " | Tin chi: " << tongTinChi
         << " | Diem TB: " << diemTB;
}

float SinhVien::GetDiemTB() const {
    return diemTB;
}
