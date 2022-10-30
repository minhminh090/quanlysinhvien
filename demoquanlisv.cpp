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
	
