#include<iostream>
#include<fstream>
#include<iomanip>
#define MAX 10000;
using namespace std;
fstream fp1;
ofstream fp2;
void taofile()
{
	fp1.open("DATACTDL.in");
	fp2.open("cay.out");
}
struct canh1{
	int t;
	int s;
	int tso;
};
    int n;
    int a[20][20];//do thi
    int truoc[10];//luu cac dinh truoc tai thoi diem dang xet cua dinh
    int mark[10];//de danh dau dinh dang xet
    int dodai[10];//luu do dai  duong di tu dinh bat dau den cac dinh con lai
    int count=0;//de dich cac dinh
    int s[20];
    void initdijksytra()//khoi tao cac mang
    {
        for(int i=1;i<=n;i++)
        {
            dodai[i]=1000;//khoi tao do dai tu dinh dang xet den cac dinh con la 999
            mark[i]=0;//khoi tao cac dinh chua xet la 0;
            truoc[i]=0;//khoi tao dinh truoc cua cac dinh hien tai la 0;
           s[i]=0;//luu dinh truoc cua cac dinh ma co duong di nho nhat,khoi tao la 0;
        }
       
    }
    int minimum()//tim dinh co khoang cach den dinh dang xet ngan nhat
    {  
         int min=1000;
         int i,t;
         for(i=1;i<=n;i++)
         {
              if(mark[i]!=1)//neu chua xet dinh i;
              {
                  if(min>=dodai[i])//neu dodai[i] nho hon min
                  {
                       min=dodai[i];//min bang do dai cua dodai[i]
                       t=i;//t bang dinh i
                  }
            }
         }
         return t;
     
    }
    void induongdi(int s,int j,int truoc[])
    {
      cout<<"\n";
        if(j==s)
        {
            printf("%d",s);
        }
        else
            if(truoc[j]==0)
                printf("khong co duong di tu dinh %d den dinh %d\n",s,j);
            else
            {
                induongdi(s,truoc[j],truoc);//de quy de in duong di tu dinh bat dau den j
                printf("..%d",j);
            }
    }
    void dijkstra(int source)//diem bat dau
    {
      int i,j,u;
      while(count<n)//lan luot xet cac dinh
      {
         u=minimum(); //tim dinh co duong di ngan nhat tu dinh dang xet
         s[++count]=u;//danh dau  dinh ke u có dinh truoc la u
         //bat dau lay u ra xet
         mark[u]=1;//danh dau da xet;
         for(i=0;i<n;i++)
             if(a[u][i]!=0)//neu co duong di tu u->i
                 if(dodai[i]>dodai[u]+a[u][i])
                     /*neu tong cua khoang cach tu  dinh dang xet va trong
                     so cua canh [u,i]
                     be hon khoang cach hien tai*/
                 {
                            dodai[i]=dodai[u]+a[u][i];//gan cho no
                            truoc[i]=u;//truoc i la u;
                 }
     
       }
      for(j=1;j<=n;j++)
      {
            induongdi(source,j,truoc);
            if(dodai[j]!=1000)
                cout<<" :khoang cach tu : "<<source<<"--->"<<j<<" la :"<<dodai[j];
     
      }
     
     
    }
     
     
    int main(void)
    {
    taofile();
	fp1>>n;
	canh1 b[100];
	int t=0;
	int x,y,z;
	while(true)
	{
		fp1>>x>>y>>z;
		if(fp1==NULL)
		{
			break;
		}
		else
		{
			b[t].t=x;
			b[t].s=y;
			b[t].tso=z;
			t++;
		}
	}
	fp1.close();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
	 a[i][j]=MAX;
	}
	
	for(int i=0;i<t;i++)
	{
		a[b[i].t][b[i].s]=b[i].tso;
		a[b[i].s][b[i].t]=b[i].tso;
	}
	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<a[i][j]<<"         ";
		cout<<'\n';	}
		cout<<'\n';
      	int source =1; 
        initdijksytra();//khoi tao
        dodai[source]=0;//do dai cua dinh dang xet den dinh dang xet di nhien phai bang 0
        dijkstra(source);
        return 0;
    }
