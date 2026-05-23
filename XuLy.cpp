#include "XuLy.h"
void taoFileDauVao() {
    ofstream out("XYZ.INP");
    int x, y, z;
    // kiem tra dieu kien nhap x y z va xu ly xoa bo dem neu nhap chu
    while (true) {
        cout << "Nhap so luong khach loai A, B, C (0 < x,y,z < 1000): ";
        cin >> x >> y >> z;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Kieu du lieu phai la so! Vui long nhap lai.\n";
            continue;
        }
        if (x <= 0 || x >= 1000 || y <= 0 || y >= 1000 || z <= 0 || z >= 1000) {
            cout << "Du lieu khong hop le, vui long nhap lai!\n";
            continue;
        }
        break;
    }
    out << x << " " << y << " " << z << "\n";
    auto nhapDanhSach = [&](int soLuongKhach, char loai) {
        for (int i = 0; i < soLuongKhach; i++) {
            string ten;
            int sl;
            double dg;
            cout << "Nhap ten khach hang loai " << loai << " thu " << i + 1 << ": ";
            getline(cin >> ws, ten);
            out << ten << "\n";
            // kiem tra so luong va don gia hop le chong treo luong nhap
            while (true) {
                cout << "Nhap so luong va don gia (>0): ";
                cin >> sl >> dg;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Kieu du lieu phai la so! Vui long nhap lai.\n";
                    continue;
                }
                if (sl <= 0 || dg <= 0) {
                    cout << "Gia tri phai > 0, nhap lai!\n";
                    continue;
                }
                break;
            }
            out << sl << "\n" << dg << "\n";
            if (loai == 'B') {
                int soNam;
                // kiem tra so nam than thiet chu y xoa bo dem neu nhap sai kieu
                while (true) {
                    cout << "Nhap so nam than thiet (>=0): ";
                    cin >> soNam;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Kieu du lieu phai la so! Vui long nhap lai.\n";
                        continue;
                    }
                    if (soNam < 0) {
                        cout << "So nam khong duoc am, nhap lai!\n";
                        continue;
                    }
                    break;
                }
                out << soNam << "\n";
            }
        }
    };
    nhapDanhSach(x, 'A');
    nhapDanhSach(y, 'B');
    nhapDanhSach(z, 'C');
    out.close();
    cout << "Da tao thanh cong file XYZ.INP\n";
}
void xuLyVaXuatFile() {
    ifstream in("XYZ.INP");
    if (!in) {
        cout << "Khong the mo file XYZ.INP\n";
        return;
    }
    ofstream out("XYZ.OUT");
    int x, y, z;
    in >> x >> y >> z;
    out << x << " " << y << " " << z << "\n";
    vector<KhachHang*> danhSach;
    double tongTienCongTy = 0;
    // phan bo doi tuong theo so luong doc duoc
    for (int i = 0; i < x; i++) {
        KhachHang* kh = new KhachHangLoaiA();
        kh->doc(in);
        danhSach.push_back(kh);
    }
    for (int i = 0; i < y; i++) {
        KhachHang* kh = new KhachHangLoaiB();
        kh->doc(in);
        danhSach.push_back(kh);
    }
    for (int i = 0; i < z; i++) {
        KhachHang* kh = new KhachHangLoaiC();
        kh->doc(in);
        danhSach.push_back(kh);
    }
    // tinh tien va xuat ket qua ra file
    for (KhachHang* kh : danhSach) {
        kh->ghi(out);
        tongTienCongTy += kh->tinhTien();
    }
    out << fixed << setprecision(2) << tongTienCongTy << "\n";
    // don dep bo nho
    for (KhachHang* kh : danhSach) delete kh;
    in.close();
    out.close();
    cout << "Da xu ly va xuat ket qua ra file XYZ.OUT\n";
}
