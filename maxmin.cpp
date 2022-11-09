//phuthanh code
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