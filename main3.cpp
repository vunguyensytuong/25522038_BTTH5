#include "DanhSachSinhVien.h"

int main() {
    DanhSachSinhVien qlsv;

    // a. Nhap vao danh sach cac sinh vien
    qlsv.Nhap();

    // b. Xuat danh sach cac sinh vien
    qlsv.Xuat();

    // c. Xuat danh sach sinh vien du dieu kien tot nghiep
    qlsv.XuatSVTotNghiep();

    // d. Xuat danh sach sinh vien khong du dieu kien tot nghiep
    qlsv.XuatSVKhongTotNghiep();

    // e. Cho biet sinh vien dai hoc nao co diem trung binh cao nhat
    qlsv.SVDHDiemTBCaoNhat();

    // f. Cho biet sinh vien cao dang nao co diem trung binh cao nhat
    qlsv.SVCDDiemTBCaoNhat();

    // g. Voi moi loai, cho biet co bao nhieu sinh vien khong du dieu kien tot nghiep
    qlsv.ThongKeKhongTotNghiep();

    cout << "\nChuong trinh ket thuc.\n";
    return 0;
}
