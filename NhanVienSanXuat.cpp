#include "NhanVienSanXuat.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void NhanVienSanXuat::Nhap(istream&is){
    NhanVien::Nhap(is);

    cout<<"Nhap luong co ban: ";
    while (true){
        is>>LuongCanBan;
        if (is.fail()||(is.peek()!='\n'&&is.peek()!=EOF)){
            cout<<"Loi! Vui long nhap dung kieu so thuc\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if (LuongCanBan<=0){
            cout<<"Loi! Luong can ban khong the nho hon hoac bang 0\n";
            continue;
        }
        break;
    }

    cout<<"Nhap so san pham: ";
    while (true){
        is>>SoSanPham;
        if (is.fail()||(is.peek()!='\n'&&is.peek()!=EOF)){
            cout<<"Loi! Vui long nhap dung kieu so nguyen\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if (SoSanPham<0){
            cout<<"Loi! So san pham khong the nho hon 0\n";
            continue;
        }
        break;
    }
    is.ignore(numeric_limits<streamsize>::max(), '\n');
}

void NhanVienSanXuat::Xuat(ostream&os){
    NhanVien::Xuat(os);
    os<<"Luong can ban: "<<LuongCanBan<<'\n';
    os<<"So san pham: "<<SoSanPham<<'\n';
    os<<"Luong: "<<Luong<<'\n';
}

float NhanVienSanXuat::TinhLuong(){
    Luong=LuongCanBan+SoSanPham*5000;
    return Luong;
}
