#include "DanhSachSinhVien.h"

DanhSachSinhVien::~DanhSachSinhVien() {
    // thuat toan giai phong vung nho cac con tro sinh vien
    for (int i = 0; i < ds.size(); i++) {
        delete ds[i];
    }
    ds.clear();
}

void DanhSachSinhVien::Nhap() {
    int n;
    // kiem tra dieu kien nhap so luong sinh vien
    do {
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        if (n <= 0) cout << "So luong phai > 0. Vui long nhap lai!\n";
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        int loai;
        // kiem tra dieu kien chon he dao tao
        do {
            cout << "Chon he (1 - Cao dang, 2 - Dai hoc): ";
            cin >> loai;
            if (loai != 1 && loai != 2) {
                cout << "Lua chon khong hop le. Vui long nhap lai!\n";
            }
        } while (loai != 1 && loai != 2);

        SinhVien* sv = nullptr;
        if (loai == 1) {
            sv = new SinhVienCaoDang();
        } else {
            sv = new SinhVienDaiHoc();
        }

        cout << "--- Nhap thong tin sinh vien thu " << i + 1 << " ---\n";
        sv->Nhap();
        ds.push_back(sv);
    }
}

void DanhSachSinhVien::Xuat() {
    cout << "\n=== DANH SACH SINH VIEN ===\n";
    for (int i = 0; i < ds.size(); i++) {
        ds[i]->Xuat();
    }
}

void DanhSachSinhVien::XuatSVTotNghiep() {
    cout << "\n=== DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP ===\n";
    // thuat toan duyet va loc sinh vien du dieu kien tot nghiep
    bool coSV = false;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i]->XetTotNghiep() == true) {
            ds[i]->Xuat();
            coSV = true;
        }
    }
    if (coSV == false) cout << "Khong co sinh vien nao!\n";
}

void DanhSachSinhVien::XuatSVKhongTotNghiep() {
    cout << "\n=== DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ===\n";
    // thuat toan duyet va loc sinh vien chua du dieu kien tot nghiep
    bool coSV = false;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i]->XetTotNghiep() == false) {
            ds[i]->Xuat();
            coSV = true;
        }
    }
    if (coSV == false) cout << "Khong co sinh vien nao!\n";
}

void DanhSachSinhVien::SVDHDiemTBCaoNhat() {
    cout << "\n=== SINH VIEN DAI HOC CO DIEM TB CAO NHAT ===\n";
    SinhVien* maxSV = nullptr;
    float maxDiem = -1;

    // thuat toan tim max diem trung binh cua sinh vien he dai hoc
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i]->LayLoaiSV() == 2) {
            if (ds[i]->GetDiemTB() > maxDiem) {
                maxDiem = ds[i]->GetDiemTB();
                maxSV = ds[i];
            }
        }
    }

    if (maxSV != nullptr) {
        maxSV->Xuat();
    } else {
        cout << "Danh sach khong co sinh vien dai hoc!\n";
    }
}

void DanhSachSinhVien::SVCDDiemTBCaoNhat() {
    cout << "\n=== SINH VIEN CAO DANG CO DIEM TB CAO NHAT ===\n";
    SinhVien* maxSV = nullptr;
    float maxDiem = -1;

    // thuat toan tim max diem trung binh cua sinh vien he cao dang
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i]->LayLoaiSV() == 1) {
            if (ds[i]->GetDiemTB() > maxDiem) {
                maxDiem = ds[i]->GetDiemTB();
                maxSV = ds[i];
            }
        }
    }

    if (maxSV != nullptr) {
        maxSV->Xuat();
    } else {
        cout << "Danh sach khong co sinh vien cao dang!\n";
    }
}

void DanhSachSinhVien::ThongKeKhongTotNghiep() {
    cout << "\n=== THONG KE SINH VIEN KHONG TOT NGHIEP ===\n";
    int demCD = 0;
    int demDH = 0;

    // thuat toan dem so luong sinh vien khong tot nghiep theo tung loai
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i]->XetTotNghiep() == false) {
            if (ds[i]->LayLoaiSV() == 1) demCD++;
            else if (ds[i]->LayLoaiSV() == 2) demDH++;
        }
    }

    cout << "So luong sinh vien Cao dang khong tot nghiep: " << demCD << "\n";
    cout << "So luong sinh vien Dai hoc khong tot nghiep: " << demDH << "\n";
}
