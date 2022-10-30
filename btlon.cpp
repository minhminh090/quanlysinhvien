#include<iostream>
#include<cstring>
#include<iomanip>
//HUNG MINH CODE	
using namespace std;
int dem=0;
struct sinhvien{
		int mssv;
    	char ten[30];
    	char gioitinh[10];
    	char lop[10];
 		float toan,ly,hoa;
 		float DiemTB;
	void nhap(){
 			cout <<"Nhap ma so sinh vien: ";
	        cin >>mssv;
	        cout <<"Nhap ho ten sinh vien: ";
	        fflush(stdin);
	        gets(ten);
	        cout <<"Nhap gioi tinh: ";
	        fflush(stdin);
	        gets(gioitinh);
	        cout<<"nhap lop: ";
	        fflush(stdin);
	        gets(lop);
	        do{
	        	cout <<"Nhap diem toan: ";
	            cin >>toan;
	            cout <<"Nhap diem ly: ";
	            cin >>ly;
	            cout <<"Nhap diem hoa: ";
	            cin >>hoa;
	            if(toan<0||ly<0||hoa<0||toan>10||ly>10||hoa>10)
	                cout <<"Moi ban nhap lai!"<<endl;
       } while(toan<0||ly<0||hoa<0||toan>10||ly>10||hoa>10);
   }
   		float DTB(){
   			return(toan+ly+hoa)/3;
		   }
		string hocluc()
    {
        string hl;
        if(DTB()>=9)
            hl = "Xuat sac";
        else if(DTB()>=8)
            hl = "Gioi";
        else if(DTB()>=6.5)
            hl = "Kha";
        else if(DTB()>=5)
            hl = "Trung binh";
        else hl = "Yeu";
        return hl;
    }
 	void xuat(){
 		cout <<setw(2)<<++dem<<setw(8)<<mssv<<setw(12)<<ten<<setw(15)<<gioitinh<<setw(12)<<lop<<setw(12)<<toan;
        cout<<setw(12)<<ly<<setw(12)<<hoa<<setw(12)<<DTB()<<setw(12)<<hocluc()<<endl;
		 }
};
typedef sinhvien SV;
		
//ham nhap so luong sinh vien
void nhapSL(int &n){
	do{
		cout<<"nhap so luong sinh vien: ";
		cin>>n;
		if(n<0)
			cout<<"nhap lai"<<endl;
	}while(n<0);
}
//ham nhap danh sach sinh vien
void nhapSV(SV *sv,int n)
{
	int res=0;
    for(int i=0;i<n;i++)
    {
    	do{
    	res=0;
    	cout <<"Nhap thong tin sinh vien thu "<<i+1<<": "<<endl;
        sv[i].nhap();
        for(int j=0;j<i;j++){
        	if(sv[j].mssv==sv[i].mssv){
        		cout<<"mssv bi trung nhap lai"<<endl;
        		res++;
				}
			}
    	}
	while(res!=0);	
}
}
//ham tieu de
void tieude(){
	cout<<setw(3)<<"STT"<<setw(8)<<"MSSV"<<setw(15)<<"Ho Ten"<<setw(15)<<"Gioi Tinh"<<setw(12)<<"Lop"<<setw(12)<<"Toan";
    cout <<setw(12)<<"Ly"<<setw(12)<<"Hoa"<<setw(12)<<"Diem TB"<<setw(12)<<"Hoc luc"<<endl;
}
//ham xuat danh sach sinh vien
void xuatSV(SV *sv, int n){
	dem=0;
 	tieude();
	for(int i=0;i<n;i++){
		sv[i].xuat();
	}
}
//ham them sinh vien
void themSV(SV *sv,int &n){
	n++;
	int res=0;
	//for(int i=0;i<n;i++)
	//{
	do{
	res=0;
	cout<<"nhap thong tin sinh vien can them: "<<endl;
	sv[n-1].nhap();
	for(int i=0;i<n-1;i++){
        	if(sv[i].mssv==sv[n-1].mssv){
        		cout<<"mssv bi trung nhap lai"<<endl;
        		res++;
			}
		}
	}while(res!=0);
}

//ham xoa sinh vien
void xoaSV(SV *sv,int &n){
	int xoa;
	int res=0;
	cout<<"nhap mssv can xoa: ";
	cin>>xoa;
	for(int i=0;i<n;i++){
		if(sv[i].mssv==xoa){
			res++;
			for(int j=i;j<n;j++){
				sv[j]=sv[j+1];
			}
		}
	}
	if(res==0)
		cout<<"mssv ban nhap khong ton tai\n";
	else n--;
}	

     
void menu(){
    cout<<" *************************MENU********************************************\n";
    cout<<" 1. Nhap danh sach sinh vien                                            **\n";
    cout<<" 2. Hien thi danh sach sinh vien                                        **\n";
    cout<<" 3. Them thong tin 1 sinh vien                                          **\n";
    cout<<" 4. Xoa thong tin 1 sinh vien                                           **\n";
    cout<<" 5. Hien thi thong tin nhung sinh vien co diem trung binh cao nhat      **\n";
    cout<<" 6. Hien thi thong tin nhung sinh vien co diem trung binh thap nhat     **\n"; 
    cout<<" 7. Tim sinh vien boi ma so sinh vien                                   **\n"; 
    cout<<" 8. Sap xep danh sach sinh vien theo ma diem tb tang dan                **\n"; 
    cout<<" 9. Sap xep danh sach sinh vien theo ten alphabet                       **\n";
    cout<<" 0. Thoat                                                               **\n";
    cout<<"**************************************************************************\n";
}
int main(){
	int n=0;
	SV *sv;
	sv=new SV[100];
	nhapSL(n);
	nhapSV(sv,n);
	xuatSV(sv,n);
	themSV(sv,n);
	xoaSV(sv,n);
	xuatSV(sv,n);

}







