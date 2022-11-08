//MINH NHUT CODE
//Ham tim sinh vien bang ma so sinh vien
void TimkiemSV(SV *sv,int &n){
	int soct;
	cout<<"Nhap mssv ban can tim: ";
	cin>>soct;
	for(int i=0;i<n;i++)
	{
		if(sv[i].mssv == soct)
		{
			sv[i].xuat();
		}
	  else{
		cout<<"khong tim thay sinh vien"<<endl;	
 	}
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
	dem=0;
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
void ChinhsuaSV(SV *sv, int n)
{   
	int soct;
	cout<<"Nhap mssv ban can chinh sua: ";
	cin>>soct;
	for(int i=0;i<n;i++)
	{
		if(sv[i].mssv == soct)
		{
			sv[i].xuat();
		}
	}
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
    cout<<" 10. Chinh sua sinh vien                                                **\n";
    cout<<" 0. Thoat                                                               **\n";
    cout<<"**************************************************************************\n";
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
		cout<<"Moi ban lua chon:";
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
		
		
		cout<<"Ban co muon lua chon tiep khong(y/n): ";
		cin>>chon;
	}while(chon == 'y');
	delete[]sv;
	return 0;
}



