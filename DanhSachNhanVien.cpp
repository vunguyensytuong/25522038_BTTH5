#include "DanhSachNhanVien.h"

DanhSachNhanVien::~DanhSachNhanVien() {
    // giai phong vung nho cac con tro de tranh ro ri bo nho
    for (NhanVien* nv : ds) {
        delete nv;
    }
    ds.clear();
}

void DanhSachNhanVien::nhapDanhSach() {
    int n;
    // kiem tra so luong nhan vien nhap vao phai lon hon 0
    do {
        cout << "Nhap so luong nhan vien: ";
        cin >> n;
        if (n <= 0) {
            cout << "So luong phai lon hon 0. Vui long nhap lai!\n";
        }
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
        int loai;
        // kiem tra nhap dung loai nhan vien quy dinh
        do {
            cout << "Chon loai (1: Lap trinh vien, 2: Kiem chung vien): ";
            cin >> loai;
            if (loai != 1 && loai != 2) {
                cout << "Chon sai loai. Vui long nhap lai!\n";
            }
        } while (loai != 1 && loai != 2);

        NhanVien* nv = nullptr;
        if (loai == 1) {
            nv = new LapTrinhVien();
        } else {
            nv = new KiemChungVien();
        }
        nv->nhap();
        ds.push_back(nv);
    }
}

void DanhSachNhanVien::xuatDanhSach() const {
    // duyet va in ra toan bo nhan vien trong danh sach
    if (ds.empty()) {
        cout << "Danh sach trong!\n";
        return;
    }
    for (const NhanVien* nv : ds) {
        nv->xuat();
    }
}

double DanhSachNhanVien::tinhLuongTrungBinh() const {
    // tinh tong luong va chia cho tong so luong nhan vien
    if (ds.empty()) return 0;
    long long tong = 0;
    for (const NhanVien* nv : ds) {
        tong += nv->tinhLuong();
    }
    return (double)tong / ds.size();
}

void DanhSachNhanVien::xuatLuongDuoiTrungBinh() const {
    // loc ra cac nhan vien co luong nho hon muc trung binh
    double luongTB = tinhLuongTrungBinh();
    cout << "Muc luong trung binh cong ty: " << luongTB << "\n";
    bool coNhanVien = false;
    for (const NhanVien* nv : ds) {
        if (nv->tinhLuong() < luongTB) {
            nv->xuat();
            coNhanVien = true;
        }
    }
    if (!coNhanVien) {
        cout << "Khong co nhan vien nao co luong duoi muc trung binh.\n";
    }
}

void DanhSachNhanVien::xuatLuongCaoNhat() const {
    // tim gia tri luong lon nhat sau do in cac nhan vien dat muc do
    if (ds.empty()) return;
    long long maxLuong = ds[0]->tinhLuong();
    for (const NhanVien* nv : ds) {
        if (nv->tinhLuong() > maxLuong) {
            maxLuong = nv->tinhLuong();
        }
    }
    for (const NhanVien* nv : ds) {
        if (nv->tinhLuong() == maxLuong) {
            nv->xuat();
        }
    }
}

void DanhSachNhanVien::xuatLuongThapNhat() const {
    // tim gia tri luong nho nhat sau do in cac nhan vien dat muc do
    if (ds.empty()) return;
    long long minLuong = ds[0]->tinhLuong();
    for (const NhanVien* nv : ds) {
        if (nv->tinhLuong() < minLuong) {
            minLuong = nv->tinhLuong();
        }
    }
    for (const NhanVien* nv : ds) {
        if (nv->tinhLuong() == minLuong) {
            nv->xuat();
        }
    }
}

void DanhSachNhanVien::xuatLTVLuongCaoNhat() const {
    // tim luong cao nhat trong tat ca cac lap trinh vien
    long long maxLuong = -1;
    for (const NhanVien* nv : ds) {
        if (nv->getLoai() == 1) {
            if (nv->tinhLuong() > maxLuong) {
                maxLuong = nv->tinhLuong();
            }
        }
    }
    if (maxLuong == -1) {
        cout << "Khong co lap trinh vien nao trong danh sach!\n";
        return;
    }
    for (const NhanVien* nv : ds) {
        if (nv->getLoai() == 1 && nv->tinhLuong() == maxLuong) {
            nv->xuat();
        }
    }
}

void DanhSachNhanVien::xuatKCVLuongThapNhat() const {
    // tim luong thap nhat trong tat ca cac kiem chung vien
    long long minLuong = -1;
    for (const NhanVien* nv : ds) {
        if (nv->getLoai() == 2) {
            if (minLuong == -1 || nv->tinhLuong() < minLuong) {
                minLuong = nv->tinhLuong();
            }
        }
    }
    if (minLuong == -1) {
        cout << "Khong co kiem chung vien nao trong danh sach!\n";
        return;
    }
    for (const NhanVien* nv : ds) {
        if (nv->getLoai() == 2 && nv->tinhLuong() == minLuong) {
            nv->xuat();
        }
    }
}
