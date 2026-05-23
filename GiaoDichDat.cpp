#include "GiaoDichDat.h"
#include <iostream>
#include <limits>

using namespace std;


void GiaoDichDat::Nhap(istream&is){
    GiaoDich::Nhap(is);
    cout<<"Nhap loai dat: ";
    while (true){
        is>>LoaiDat;
        if (is.fail()||(is.peek()!='\n'&&is.peek()!=EOF)){
            cout<<"Loi! Vui long chi nhap 1 ki tu duy nhat.\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if (LoaiDat!='a'||LoaiDat!='A'||LoaiDat!='b'||LoaiDat!='B'||LoaiDat!='c'||LoaiDat!='C'){
            cout<<"Loi! Vui long chi nhap [A], [B] hoac [C]\n";
            continue;
        }
        break;
    }
}

void GiaoDichDat::Xuat(ostream&os){
    GiaoDich::Xuat(os);
    cout<<"Loai dat: "<<LoaiDat;
}

float GiaoDichDat::TinhThanhTien(){
    if (LoaiDat=='a'||LoaiDat=='A'){
        return DienTich*DonGia*1.5;
    }
    return DienTich*DonGia;
}
