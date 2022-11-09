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
 		cout <<setw(3)<<++dem<<setw(8)<<mssv<<setw(15)<<ten<<setw(15)<<gioitinh<<setw(12)<<lop<<setw(12)<<toan;
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
//PHU THANH CODE
//ham tra ve diem cao nhat
float Max(SV *sv, int &n )
{
      float Max = sv[0].DTB();
      for(int i=1;i<n;i++)
      {
              if(sv[i].DTB()>Max)
                 Max = sv[i].DTB();
      }
      return Max;
}
//ham tra ve diem thap nhat
float Min(SV *sv, int &n ){
      float Min= sv[0].DTB();
      for(int i=1;i<n;i++)
      {
              if(sv[i].DTB()<Min)
                 Min = sv[i].DTB();
      }
      return Min;
}
// ham in ra sinh vien co diem cao nhat
void InMax(SV *sv,int n){
             dem=0;
             cout<<" danh sach sinh vien co diem cao nhat :"<<endl;
             tieude();
             for(int i=0;i<n;i++)
      {
              if(sv[i].DTB()== Max(sv,n))
                 sv[i].xuat();
      }
}
// ham in ra sinh vien co diem thap nhat
void InMin(SV *sv,int n){
             dem=0;
             cout<<" danh sach sinh vien co diem thap nhat :"<<endl;
             tieude();
             for(int i=0;i<n;i++)
             {
              if(sv[i].DTB()== Min(sv,n))
                 sv[i].xuat();
             }
}
//MINH NHUT CODE
//Ham tim sinh vien bang ma so sinh vien
void TimkiemSV(SV *sv,int &n){
	int soct;
	int dem=0;
	cout<<"Nhap mssv ban can tim: ";
	cin>>soct;
	for(int i=0;i<n;i++)
	{
		if(sv[i].mssv == soct)
		{
			tieude();
			sv[i].xuat();
			dem++;
		}
	}
	if(dem==0){
		cout<<"ma so sinh vien kh ton tai";
	}
}
//Ham sap xep sv theo diem tb tang dan
void SapXepDiemTB(SV *sv, int n)
{
	dem=0;
	cout<<"Danh sach sinh vien co diem TB tang dan theo thu tu: "<<endl;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (sv[i].DTB() > sv[j].DTB()>0)
			{
				swap(sv[i], sv[j]);
			}		
		}
	}
	xuatSV(sv, n);
}
//Ham sap xep sv theo alphabet
void SapXepABC(SV *sv, int n)
{
	//dem=0;
	cout<<"Danh sach sinh vien theo alphabet:"<<endl;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (strcmp(sv[i].ten, sv[j].ten)>0)
			{
				swap(sv[i], sv[j]);
			}
		}
	}
	xuatSV(sv, n);	
	
}
//Ham chinh sua sinh vien
void ChinhsuaSV(SV *sv, int n)
{   
	int soct;
	int dem=0;
	cout<<"Nhap mssv ban can chinh sua: ";
	cin>>soct;
	for(int i=0;i<n;i++)
	{
		if(sv[i].mssv == soct)
		{
			sv[i].nhap();
		}
		dem++;
	}
	if(dem==0){
		cout<<"ma so sinh vien kh ton tai";
	}
	
}
	
void menu(){
    cout<<" \n**************************MENU*********************************************\n";
    cout<<"  1. Nhap danh sach sinh vien                                            **\n";
    cout<<"  2. Hien thi danh sach sinh vien                                        **\n";
    cout<<"  3. Them thong tin 1 sinh vien                                          **\n";
    cout<<"  4. Xoa thong tin 1 sinh vien                                           **\n";
    cout<<"  5. Hien thi thong tin nhung sinh vien co diem trung binh cao nhat      **\n";
    cout<<"  6. Hien thi thong tin nhung sinh vien co diem trung binh thap nhat     **\n"; 
    cout<<"  7. Tim sinh vien boi ma so sinh vien                                   **\n"; 
    cout<<"  8. Sap xep danh sach sinh vien theo ma diem tb tang dan                **\n"; 
    cout<<"  9. Sap xep danh sach sinh vien theo ten alphabet                       **\n";
    cout<<"  10. Chinh sua sinh vien                                                **\n";
    cout<<"***************************************************************************\n";
}
int main(){
	int n=0;
	SV *sv;
	int luachon;
	sv=new SV[100];
	char chon;
	//Menu
	do
	{
		menu();
		cout<<" Moi ban lua chon: ";
		cin >>luachon;
		
		switch(luachon)
		{
			case 1:
				nhapSL(n);
				nhapSV(sv, n);
				break;
			case 2:
		 		 xuatSV(sv, n);	
				  break;
			case 3:
				 themSV(sv, n);
				 break;
			case 4:
				xoaSV(sv, n);
				break;
			case 5:
				 InMax(sv, n);
				 break;
			case 6:
				 InMin(sv, n);
				 break;	 	
			case 7:
				 TimkiemSV(sv, n);
				 break;
			case 8:
				 SapXepDiemTB(sv, n);
				 break;
			case 9:
				 SapXepABC(sv, n);
				 break;
			case 10:
				 ChinhsuaSV(sv, n);
				 break;	 	 	 	   	 	  
		default:
			cout<<"Ban da nhap lua chon sai!"<<endl;
				break;			  		   
		}
		
		
		cout<<"\nBan co muon lua chon tiep khong(y/n): ";
		cin>>chon;
	}while(chon == 'y');
	return 0;
}







