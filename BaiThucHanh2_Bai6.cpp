#include <iostream>
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

static int manvb = 10000;
static int madab = 10000;
static int mapcb = 1;

// Lop nhan vien
class NhanVien
{
private:
    int MaNV;
    string HoTen;
    string DiaChi;
    string ChuyenMon;
public:
    NhanVien()
    {
        MaNV = manvb++;
    }
    void NhapNV()
    {
        cout << "Ho va ten: "; getline(cin, HoTen);
        cout << "Dia chi: "; getline(cin, DiaChi);
        cout << "Chuyen mon: "; getline(cin, ChuyenMon);
    }
    void XuatNV()
    {
        cout << "Ma nhan vien: " << MaNV << endl;
        cout << "Ho ten nhan vien: " << HoTen << endl;
        cout << "Dia chi: " << DiaChi << endl;
        cout << "Chuyen mon: " << ChuyenMon << endl;
    }

    string getHoTenNV()
    {
        return HoTen;
    }

};

// Lop du an
class DuAn
{
private:
    int MaDA;
    string TenDA;
    int KieuDA;
    int KinhPhi;
public:
    DuAn()
    {
        MaDA = madab++;
    }
    void NhapDA()
    {
        cout << "Ten: "; getline(cin , TenDA);
        cout << "Vui long chon kieu du an:\n";
        cout << "1.Nho     2.Trung Binh     3.Lon\n";
        cout << "Lua chon: "; cin >> KieuDA;
        cout << "Tong kinh phi: "; cin >> KinhPhi;
        cin.ignore();

    }
    void XuatDA()
    {
        cout << "Ma du an: " << MaDA << endl;
        cout << "Ten du an: " << TenDA << endl;
        cout << "Kieu du an: " << KieuDA << endl;
        cout << "Tong kinh phi: ";
        if (KinhPhi == 1) cout << "Nho";
        else if (KinhPhi == 2) cout << "Trung binh";
        else cout << "Lon";
        cout << endl;
    }
};

// Lop phan cong cong viec cho nhan vien
class PhanCong
{
private:
    int MaPC;
    int SoNgay;
    string CongViec;
public:
    friend class NhanVien;
    friend class DuAn;
    NhanVien PCA;
    DuAn PCB;
    void NhapPC(NhanVien a, DuAn b)
    {
        MaPC = mapcb++;
        PCA = a;
        PCB = b;
        cin.ignore();
        cout << "Cong viec: "; getline(cin , CongViec);
        cout << "So ngay lam viec: "; cin >> SoNgay;

    }
    void XuatPC()
    {
        cout << "Ma PC" << MaPC << endl;
        PCA.XuatNV();
        PCB.XuatDA();
        cout << "So ngay lam viec: " << SoNgay << endl;
        cout << "Cong viec: " << CongViec << endl;
    }
    string getHoTen()
    {
        return PCA.getHoTenNV();
    }
    int getSoNgay()
    {
        return SoNgay;
    }
    void XuatCV()
    {
        cout << "Vi tri cong viec: " << CongViec << endl;
    }
};


int main()
{
    vector<NhanVien> nv;
    vector<DuAn> da;

    int slnv, slda; // slnv: so luong nhan vien
                    // slda: so luong du an

    // Nhap thong tin nhan vien
    cout << "So nhan vien muon nhap: "; cin >> slnv;
    cin.ignore();
    nv.resize(slnv);
    for(int i = 0; i < slnv; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i+1 << ":\n";
        nv[i].NhapNV();
    }

    // In lai thong tin nhan vien
    cout << "\n-----------------------------------------------\n";
    cout << "Thong tin nhan vien da co:\n";
    for (int i = 0; i < slnv; i++)
        nv[i].XuatNV();
    cout << "\n-----------------------------------------------\n";

    // Nhap thong tin du an
    cout << "So du an muon nhap: "; cin >> slda;
    cin.ignore();
    da.resize(slda);
    for(int i = 0; i < slda; i++)
    {
        cout << "Nhap thong tin du an thu " << i+1 << ":\n";
        da[i].NhapDA();
    }

    // In lai thong tin du an
    cout << "\n-----------------------------------------------\n";
    cout << "Thong tin du an da co:\n";
    for (int i = 0; i < slda; i++)
        da[i].XuatDA();
    cout << "\n-----------------------------------------------\n";

    // Nhap thong tin phan cong cong viec
    vector<PhanCong> pc(slnv*slda);
    cout << "\n--------------------------------------------------------------------------\n";
    cout << "Phan cong cong viec:\n";
    cout << "May chu se dua thong tin nhan vien va du an.\n";
    cout << "Neu ban muon phan cong nhan vien vao du an do. Vui long nhan phim 1.\n";
    cout << "Neu khong. Vui long nhan phim 0\n";
    cout << "--------------------------------------------------------------------------\n";
    int run = 0, slect;
    for(int i = 0; i < slnv; i++)
    {
        cout << "Thong tin nhan vien thu " << i << ":\n";
        nv[i].XuatNV();
        for (int j = 0; j < slda; j++)
        {
            cout << "Du an thu " << j  << ":\n";
            da[j].XuatDA();
            cout << "Lua chon cua ban: "; cin >> slect;
            if (slect == 1)
            {
                pc[run].NhapPC(nv[i], da[j]);
                run++;
            }

        }

    }

    return 0;

}
