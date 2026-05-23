#include "DanhSachGiaoDich.h"
#include <iostream>

using namespace std;

int main()
{
    DanhSachGiaoDich ql;

    cout << "===== CHUONG TRINH QUAN LY GIAO DICH BDT VAKALAND =====\n";
    ql.Nhap();

    ql.ThongKeSoLuongTungLoai();
    ql.TrungBinhThanhTienChungCu();
    ql.GiaoDichNhaPhoCaoNhat();
    ql.XuatGiaoDichThang12Nam2024();

    return 0;
}
