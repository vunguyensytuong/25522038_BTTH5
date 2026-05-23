#include "QuanLyNhanVien.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    QuanLyNhanVien ql;
    int luaChon;

    while (true) {
        cout << "\n================== QUAN LY NHAN VIEN ==================\n";
        cout << "1. Nhap danh sach nhan vien SX va VP\n";
        cout << "2. Tinh luong cho tung nhan vien\n";
        cout << "3. Xuat thong tin danh sach cac nhan vien\n";
        cout << "4. Tinh tong luong cong ty phai tra cho cac nhan vien\n";
        cout << "5. Cho boi nhan vien san xuat nao co luong thap nhat\n";
        cout << "6. Cho biet nhan vien van phong nao co tuoi cao nhat\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "=======================================================\n";
        cout << "Nhap lua chon cua ban: ";

        // thuat toan kiem tra tinh hop le cua lua chon menu
        while (true) {
            cin >> luaChon;
            if (cin.fail() || (cin.peek() != '\n' && cin.peek() != EOF)) {
                cout << "Loi! Vui long chi nhap so nguyen hop le!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nhap lai lua chon: ";
                continue;
            }
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (luaChon == 0) {
            cout << "Tam biet!\n";
            break;
        }

        switch (luaChon) {
            case 1:
                ql.NhapDanhSach();
                break;
            case 2:
                // thuat toan thuc thi tinh luong dong loat
                ql.TinhLuongToanBo();
                cout << "Da cap nhat tinh xong luong cho tat ca nhan vien!\n";
                break;
            case 3:
                cout << "\n------ DANH SACH THONG TIN NHAN VIEN ------\n";
                ql.XuatDanhSach();
                break;
            case 4:
                cout << "\nTong luong ma cong ty phai tra: " << ql.TinhTongLuong() << " VND\n";
                break;
            case 5:
                cout << "\n------ NHAN VIEN SAN XUAT CO LUONG THAP NHAT ------\n";
                ql.TimNVSXLuongThapNhat();
                break;
            case 6:
                cout << "\n------ NHAN VIEN VAN PHONG CO TUOI CAO NHAT ------\n";
                ql.TimNVVPTuoiCaoNhat();
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon tu 0 den 6.\n";
                break;
        }
    }

    return 0;
}
