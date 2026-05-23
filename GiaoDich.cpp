#include "GiaoDich.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

GiaoDich::~GiaoDich(){
}

void GiaoDich::Nhap(istream&is){
    cout<<"Nhap ma giao dich: ";
    getline(is, MaGiaoDich);

    cout<<"Nhap ngay giao dich:\n";
    is>>NgayGiaoDich;

    while (true){
        cout<<"Nhap don gia: ";
        is>>DonGia;
        if (is.fail()||(is.peek()!='\n'&&is.peek()!=EOF)){
            cout<<"Loi! Vui long nhap dung kieu so nguyen.\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        break;
    }

    while (true){
        cout<<"Nhap dien tich: ";
        is>>DienTich;
        if (is.fail()||(is.peek()!='\n'&&is.peek()!=EOF)){
            cout<<"Loi! Vui long nhap dung kieu so nguyen.\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        break;
    }
}

istream& operator>>(istream&is,GiaoDich& GD){
    GD.Nhap(is);
    return is;
}

void GiaoDich::Xuat(ostream& os){
    os<<"\nMa giao dich: "<<MaGiaoDich;
    os<<"\nNgay giao dich: "<<NgayGiaoDich;
    os<<"\nDon gia: "<<DonGia;
    os<<"\nDien tich: "<<DienTich;
}

ostream& operator<<(ostream& os, GiaoDich& GD){
    GD.Xuat(os);
    return os;
}


float GiaoDich::TinhThanhTien(){}
