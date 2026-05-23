#include "GiaoDichNhaPho.h"
#include <iostream>
#include <limits>
using namespace std;


void GiaoDichNhaPho::Nhap(istream&is){
    GiaoDich::Nhap(is);
    cout<<"Chon loai nha:\n[1] de chon loai nha ""Cao Cap"".\n[2] de chon loai nha ""Thuong"".\n";
    while (true){
        is>>LoaiNha;
        if (is.fail()||(is.peek()!='\n'&&is.peek()!=EOF)){
            cout<<"Loi! Vui long chi nhap so nguyen.\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if (LoaiNha!=1&&LoaiNha!=2){
            cout<<"Loi! Vui long chi nhap [1] hoac [2].\n";
            continue;
        }
        break;
    }

    cout<<"Nhap dia chi: ";
    getline(is,DiaChi);
}

void GiaoDichNhaPho::Xuat(ostream&os){
    GiaoDich::Xuat(os);
    cout<<"Loai nha: ";
    if (LoaiNha==1) cout<<"Cao Cap\n";
    else cout<<"Thuong\n";
    cout<<"Dia chi: "<<DiaChi;
}

float GiaoDichNhaPho::TinhThanhTien(){
    if (LoaiNha==1) return DienTich*DonGia;
    return DienTich*DonGia*0.9;
}
