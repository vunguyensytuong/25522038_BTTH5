#include "QuanLyNhanVien.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

// thuat toan giai phong bo nho cho danh sach nhan vien da cap phat dong
QuanLyNhanVien::~QuanLyNhanVien() {
    for (NhanVien* nv : danhSach) {
        delete nv;
    }
    danhSach.clear();
}

// thuat toan nhap danh sach nhan vien san xuat va nhan vien van phong
void QuanLyNhanVien::NhapDanhSach() {
    int nSX, nVP;

    cout << "Nhap so luong nhan vien san xuat: ";
    while (true) {
        cin >> nSX;
        if (cin.fail() || (cin.peek() != '\n' && cin.peek() != EOF)) {
            cout << "Loi! Vui long nhap dung kieu so nguyen\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (nSX < 0) {
            cout << "Loi! So luong khong the nho hon 0\n";
            continue;
        }
        break;
    }

    for (int i = 0; i < nSX; ++i) {
        cout << "\n--- Nhap thong tin nhan vien san xuat thu " << i + 1 << " ---\n";
        NhanVien* nv = new NhanVienSanXuat();
        cin >> *nv;
        danhSach.push_back(nv);
    }

    cout << "\nNhap so luong nhan vien van phong: ";
    while (true) {
        cin >> nVP;
        if (cin.fail() || (cin.peek() != '\n' && cin.peek() != EOF)) {
            cout << "Loi! Vui long nhap dung kieu so nguyen\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (nVP < 0) {
            cout << "Loi! So luong khong the nho hon 0\n";
            continue;
        }
        break;
    }

    for (int i = 0; i < nVP; ++i) {
        cout << "\n--- Nhap thong tin nhan vien van phong thu " << i + 1 << " ---\n";
        NhanVien* nv = new NhanVienVanPhong();
        cin >> *nv;
        danhSach.push_back(nv);
    }
}

// thuat toan duyet qua toan bo danh sach de cap nhat luong tung nhan vien
void QuanLyNhanVien::TinhLuongToanBo() {
    for (NhanVien* nv : danhSach) {
        nv->TinhLuong();
    }
}

// thuat toan xuat thong tin cua tat ca nhan vien co trong danh sach
void QuanLyNhanVien::XuatDanhSach() {
    if (danhSach.empty()) {
        cout << "Danh sach trong!\n";
        return;
    }
    for (size_t i = 0; i < danhSach.size(); ++i) {
        cout << "\n[Nhan vien thu " << i + 1 << "]\n";
        cout << *danhSach[i];
    }
}

// thuat toan tinh tong luong ma cong ty can phai chi tra
float QuanLyNhanVien::TinhTongLuong() {
    float tongLuong = 0;
    for (NhanVien* nv : danhSach) {
        tongLuong += nv->TinhLuong();
    }
    return tongLuong;
}

// thuat toan tim nhan vien san xuat co muc luong thap nhat
void QuanLyNhanVien::TimNVSXLuongThapNhat() {
    NhanVienSanXuat* nvMin = nullptr;
    float luongMin = -1;

    for (NhanVien* nv : danhSach) {
        // dung dynamic_cast de loc ra nhan vien san xuat
        NhanVienSanXuat* nvsx = dynamic_cast<NhanVienSanXuat*>(nv);
        if (nvsx != nullptr) {
            float luongHienTai = nvsx->TinhLuong();
            if (nvMin == nullptr || luongHienTai < luongMin) {
                nvMin = nvsx;
                luongMin = luongHienTai;
            }
        }
    }

    if (nvMin != nullptr) {
        cout << *nvMin;
    } else {
        cout << "Khong co nhan vien san xuat nao trong danh sach!\n";
    }
}

// thuat toan tro giup trich xuat ngay sinh tu ham Xuat de so sanh tuoi ma khong can sua file cu
void LayNgayThangNamSinh(NhanVien* nv, int &d, int &m, int &y) {
    stringstream ss;
    nv->Xuat(ss);
    string dongHoTen, dongNgaySinh;
    getline(ss, dongHoTen);  // bo qua dong chua ho ten
    getline(ss, dongNgaySinh); // lay dong chua ngay sinh ("Ngay sinh: dd/mm/yyyy")

    size_t viTri = dongNgaySinh.find("Ngay sinh: ");
    if (viTri != string::npos) {
        string chuoiNgay = dongNgaySinh.substr(viTri + 11);
        stringstream ssDate(chuoiNgay);
        char kyTuPhanCach;
        ssDate >> d >> kyTuPhanCach >> m >> kyTuPhanCach >> y;
    }
}

// thuat toan tim nhan vien van phong co tuoi cao nhat (nam sinh nho nhat)
void QuanLyNhanVien::TimNVVPTuoiCaoNhat() {
    NhanVienVanPhong* nvGiaNhat = nullptr;
    int ngayMin = 0, thangMin = 0, namMin = 0;

    for (NhanVien* nv : danhSach) {
        // dung dynamic_cast de loc ra nhan vien van phong
        NhanVienVanPhong* nvvp = dynamic_cast<NhanVienVanPhong*>(nv);
        if (nvvp != nullptr) {
            int d, m, y;
            LayNgayThangNamSinh(nvvp, d, m, y);

            if (nvGiaNhat == nullptr) {
                nvGiaNhat = nvvp;
                ngayMin = d; thangMin = m; namMin = y;
            } else {
                // nguoi co tuoi lon nhat se co nam sinh nho nhat
                if (y < namMin) {
                    nvGiaNhat = nvvp; ngayMin = d; thangMin = m; namMin = y;
                } else if (y == namMin) {
                    if (m < thangMin) {
                        nvGiaNhat = nvvp; ngayMin = d; thangMin = m; namMin = y;
                    } else if (m == thangMin) {
                        if (d < ngayMin) {
                            nvGiaNhat = nvvp; ngayMin = d; thangMin = m; namMin = y;
                        }
                    }
                }
            }
        }
    }

    if (nvGiaNhat != nullptr) {
        cout << *nvGiaNhat;
    } else {
        cout << "Khong co nhan vien van phong nao trong danh sach!\n";
    }
}
