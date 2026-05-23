#include "GiaoDichCanHoChungCu.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void GiaoDichCanHoChungCu::Nhap(istream& is){
    GiaoDich::Nhap(is);
    cout<<"Nhap ma can ho chung cu: ";
    getline(is,MaCan);

    cout<<"Nhap vi tri tang: ";
    while (true){
        is>>ViTriTang;
        if (is.fail()||(is.peek()!='\n'&&is.peek()!=EOF)){
            cout<<"Loi! Vui long nhap dung kieu so nguyen.\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        break;
    }
}

float GiaoDichCanHoChungCu::TinhThanhTien(){
    if (ViTriTang==1) return DienTich*DonGia*2;
    if (ViTriTang>=15) return DienTich*DonGia*1.2;
    return DienTich*DonGia;
}

void GiaoDichCanHoChungCu::Xuat(ostream&os){
    GiaoDich::Xuat(os);
    cout<<"Ma can ho: "<<MaCan<<'\n';
    cout<<"Vi tri tang: "<<ViTriTang<<'\n';
}
