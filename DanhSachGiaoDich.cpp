#include "DanhSachGiaoDich.h"
#include <iostream>
#include <limits>

using namespace std;

// huy vung nho cua cac con tro de tranh leak memory
DanhSachGiaoDich::~DanhSachGiaoDich() {
    for (size_t i = 0; i < dsGiaoDich.size(); i++) {
        delete dsGiaoDich[i];
    }
    dsGiaoDich.clear();
}

void DanhSachGiaoDich::Nhap() {
    int n;
    while (true) {
        cout << "Nhap so luong giao dich: ";
        cin >> n;
        if (cin.fail() || n < 0) {
            cout << "Loi! Vui long nhap so nguyen duong.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\n--- NHAP GIAO DICH THU " << i + 1 << " ---\n";
        cout << "Chon loai giao dich:\n[1] Dat\n[2] Nha pho\n[3] Can ho chung cu\nLua chon: ";
        cin >> loai;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // xoa bo nho dem de tranh troi lenh getline sau do

        GiaoDich* gd = nullptr;
        if (loai == 1) {
            gd = new GiaoDichDat();
        } else if (loai == 2) {
            gd = new GiaoDichNhaPho();
        } else if (loai == 3) {
            gd = new GiaoDichCanHoChungCu();
        } else {
            cout << "Loi! Lua chon khong hop le.\n";
            i--; // cho phep nhap lai neu chon sai
            continue;
        }

        // goi ham Nhap da hinh tuy thuoc vao loai object duoc khoi tao
        gd->Nhap(cin);
        dsGiaoDich.push_back(gd);
    }
}

void DanhSachGiaoDich::ThongKeSoLuongTungLoai() {
    int demDat = 0, demNhaPho = 0, demChungCu = 0;

    // ep kieu (dynamic_cast) de xac dinh lop con hien tai cua con tro
    for (size_t i = 0; i < dsGiaoDich.size(); i++) {
        if (dynamic_cast<GiaoDichDat*>(dsGiaoDich[i])) demDat++;
        else if (dynamic_cast<GiaoDichNhaPho*>(dsGiaoDich[i])) demNhaPho++;
        else if (dynamic_cast<GiaoDichCanHoChungCu*>(dsGiaoDich[i])) demChungCu++;
    }

    cout << "\n=== THONG KE SO LUONG ===\n";
    cout << "- Giao dich Dat: " << demDat << "\n";
    cout << "- Giao dich Nha pho: " << demNhaPho << "\n";
    cout << "- Giao dich Chung cu: " << demChungCu << "\n";
}

void DanhSachGiaoDich::TrungBinhThanhTienChungCu() {
    float tongTien = 0;
    int dem = 0;

    // tim cac giao dich chung cu va cong don thanh tien
    for (size_t i = 0; i < dsGiaoDich.size(); i++) {
        GiaoDichCanHoChungCu* cc = dynamic_cast<GiaoDichCanHoChungCu*>(dsGiaoDich[i]);
        if (cc != nullptr) {
            tongTien += cc->TinhThanhTien();
            dem++;
        }
    }

    cout << "\n=== TRUNG BINH THANH TIEN CHUNG CU ===\n";
    if (dem == 0) {
        cout << "Khong co giao dich chung cu nao!\n";
    } else {
        cout << "Gia tri trung binh: " << tongTien / dem << "\n";
    }
}

void DanhSachGiaoDich::GiaoDichNhaPhoCaoNhat() {
    float maxTien = -1;
    GiaoDichNhaPho* gdMax = nullptr;

    // tim giao dich nha pho co ket qua TinhThanhTien() lon nhat
    for (size_t i = 0; i < dsGiaoDich.size(); i++) {
        GiaoDichNhaPho* np = dynamic_cast<GiaoDichNhaPho*>(dsGiaoDich[i]);
        if (np != nullptr) {
            float tien = np->TinhThanhTien();
            if (tien > maxTien) {
                maxTien = tien;
                gdMax = np;
            }
        }
    }

    cout << "\n=== GIAO DICH NHA PHO CO GIA TRI CAO NHAT ===\n";
    if (gdMax != nullptr) {
        gdMax->Xuat(cout);
        cout << "\nThanh tien: " << maxTien << "\n";
    } else {
        cout << "Khong co giao dich nha pho nao!\n";
    }
}

void DanhSachGiaoDich::XuatGiaoDichThang12Nam2024() {
    cout << "\n=== DANH SACH GIAO DICH THANG 12 NAM 2024 ===\n";
    bool timThay = false;

    // lay thuoc tinh ngay giao dich, kiem tra thang va nam
    for (size_t i = 0; i < dsGiaoDich.size(); i++) {
        NgayThangNam ngay = dsGiaoDich[i]->getNgayGiaoDich();
        if (ngay.getThang() == 12 && ngay.getNam() == 2024) {
            dsGiaoDich[i]->Xuat(cout);
            cout << "\nThanh tien: " << dsGiaoDich[i]->TinhThanhTien() << "\n";
            cout << "-----------------------\n";
            timThay = true;
        }
    }
    if (!timThay) cout << "Khong ton tai giao dich nao trong thoi gian nay!\n";
}
