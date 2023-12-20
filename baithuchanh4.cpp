#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class NGUOI {
public:
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
};

class BAC_SI : public NGUOI {
private:
    string MaBS;
    float SoNgayLamViec;
    float TienCongNgay;
public:
    BAC_SI() : MaBS(""), SoNgayLamViec(0), TienCongNgay(0) {}
    BAC_SI(string maBS, float soNgayLamViec, float tienCongNgay) : MaBS(maBS), SoNgayLamViec(soNgayLamViec), TienCongNgay(tienCongNgay) {}
    void Nhap() override {
        cout << "Nhap MaBS: ";
        cin >> MaBS;
        cout << "Nhap SoNgayLamViec: ";
        cin >> SoNgayLamViec;
        cout << "Nhap TienCongNgay: ";
        cin >> TienCongNgay;
    }
    void Xuat() override {
        cout << "MaBS: " << MaBS << ", SoNgayLamViec: " << SoNgayLamViec << ", TienCongNgay: " << TienCongNgay << endl;
    }
    float TienCongThang() {
        return SoNgayLamViec * TienCongNgay;
    }
    float getSoNgayLamViec() {
        return SoNgayLamViec;
    }
};

int main() {
    vector<NGUOI*> DanhSach;
    int n;
    cout << "Nhap so luong nguoi: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "Nhap loai (1 - BENH_NHAN, 2 - BAC_SI): ";
        cin >> loai;
        if (loai == 1) {
            // Tạo đối tượng BENH_NHAN và thêm vào danh sách
        } else if (loai == 2) {
            BAC_SI* bacSi = new BAC_SI();
            bacSi->Nhap();
            DanhSach.push_back(bacSi);
        }
    }
    // Hiển thị danh sách NGUOI
    for (auto nguoi : DanhSach) {
        nguoi->Xuat();
    }
    // Hiển thị thông tin các BAC_SI có số ngày làm việc nhiều nhất
    float maxNgay = 0;
    for (auto nguoi : DanhSach) {
        BAC_SI* bacSi = dynamic_cast<BAC_SI*>(nguoi);
        if (bacSi && bacSi->getSoNgayLamViec() > maxNgay) {
            maxNgay = bacSi->getSoNgayLamViec();
        }
    }
    for (auto nguoi : DanhSach) {
        BAC_SI* bacSi = dynamic_cast<BAC_SI*>(nguoi);
        if (bacSi && bacSi->getSoNgayLamViec() == maxNgay) {
            bacSi->Xuat();
        }
    }
    return 0;
}
