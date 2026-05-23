#ifndef GIAODICHNHAPHO_H
#define GIAODICHNHAPHO_H
#include <string>

#include <GiaoDich.h>


class GiaoDichNhaPho : public GiaoDich
{
private:
    int LoaiNha;
    std::string DiaChi;
public:
    float TinhThanhTien()override;
    void Nhap(istream&is) override;
    void Xuat(ostream&os) override;
};

#endif // GIAODICHNHAPHO_H
