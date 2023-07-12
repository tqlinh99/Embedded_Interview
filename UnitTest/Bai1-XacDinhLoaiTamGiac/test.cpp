#include "pch.h"

enum LoaiTamGiac {
    TamGiacKhongTonTai,
    TamGiacDeu,
    TamGiacCan,
    TamGiacVuong,
    TamGiacThuong
};

LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return TamGiacKhongTonTai;
    }

    if (a == b && b == c) {
        return TamGiacDeu;
    }

    if (a == b || b == c || c == a) {
        return TamGiacCan;
    }

    double maxSide = std::max(a, std::max(b, c));
    double sumSquares = a * a + b * b + c * c;

    if (2 * maxSide * maxSide == sumSquares) {
        return TamGiacVuong;
    }

    return TamGiacThuong;
}

TEST(XacDinhLoaiTamGiac, tamGiacKhongTonTai) {
    EXPECT_EQ(XacDinhLoaiTamGiac(0, 6, 8), TamGiacKhongTonTai);
    EXPECT_EQ(XacDinhLoaiTamGiac(6, 0, 8), TamGiacKhongTonTai);
    EXPECT_EQ(XacDinhLoaiTamGiac(6, 8, 0), TamGiacKhongTonTai);
}


TEST(XacDinhLoaiTamGiac, tamGiacDeu) {
    EXPECT_EQ(XacDinhLoaiTamGiac(6, 6, 6), TamGiacDeu);
}


TEST(XacDinhLoaiTamGiac, tamGiacCan) {
    EXPECT_EQ(XacDinhLoaiTamGiac(6, 6, 8), TamGiacCan);
    EXPECT_EQ(XacDinhLoaiTamGiac(8, 6, 6), TamGiacCan);
    EXPECT_EQ(XacDinhLoaiTamGiac(6, 8, 6), TamGiacCan);
}


TEST(XacDinhLoaiTamGiac, tamGiacVuong) {
    EXPECT_EQ(XacDinhLoaiTamGiac(6, 8, 10), TamGiacVuong);
}


TEST(XacDinhLoaiTamGiac, tamGiacThuong) {
    EXPECT_EQ(XacDinhLoaiTamGiac(4, 5, 6), TamGiacThuong);
}