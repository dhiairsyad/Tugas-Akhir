#include <iostream>
#include <fstream>
using namespace std;
class dahlan 
{
private :
int jd,harga[100],stok[100],kurir,stok_baru,menu,password,input_pw,e_money,sorting,tmp;
int no_barang,jumlah_beli,total,pil_kurir,method;
string nama_barang[100],tmp1,cari,username,input_user,data;
char pil_sorting,pil_cari;
public :
void input();
void proses();
};
void dahlan::input()
{
	e_money = 1000000;
  username = "budi";
  password = 123;
  l:
  cout<<"=================================="<<endl;
  cout<<"\t\tSelamat Datang\t\t"<<endl;
  cout<<"=================================="<<endl;
  cout<<"Username : ";getline(cin, input_user);
  cout<<"Password : ";cin>>input_pw;
}
void dahlan::proses()
{
	if ((input_user == username) && (input_pw == password))
  {
    m:
    cout<<"=================================="<<endl;
    cout<<"\t\tMenu Pilihan"<<endl;
    cout<<"=================================="<<endl;
    cout<<"1. Menambah Data"<<endl;
    cout<<"2. Berbelanja"<<endl;
    cout<<"3. Update Stok"<<endl;
    cout<<"Masukan Pilihan Menu : ";cin>>menu;
    cout<<"=================================="<<endl;
    cout<<endl;
  }
  if (menu == 1)
  {
    ofstream barang("data_barang.txt");
    cout<<"Masukan Jumlah Data : ";cin>>jd;
    for (int i=0; i<jd; i++)
      {
        cout<<"Nama Barang : ";cin>>nama_barang[i];
        cout<<"Harga       : ";cin>>harga[i];
        cout<<"Stok        : ";cin>>stok[i];
        cout<<endl;

        barang<<"Nama Barang : "<<nama_barang[i]<<endl;
        barang<<"Harga       : "<<harga[i]<<endl;
        barang<<"Stok        : "<<stok[i]<<endl;
        barang<<endl;
      }
     barang.close();
     goto m;
    
  }
  if (menu == 2)
  {
  	cout<<"=================================="<<endl;
    cout<<"\t\tList Barang"<<endl;
    cout<<"=================================="<<endl;
  	for (int i=0; i<jd; i++)
      {
        cout<<"Nama Barang : "<<nama_barang[i]<<endl;
        cout<<"Harga       : "<<harga[i]<<endl;
        cout<<"Stok        : "<<stok[i]<<endl;
        cout<<"=================================="<<endl;
        cout<<endl;
      }
    cout<<"Ingin Melakukan Sorting y/n : ";cin>>pil_sorting;
    switch(pil_sorting)
    {
    case 'y':
    cout<<"Melakukan Sorting : "<<endl;
    cout<<"1.Harga Termahal"<<endl;
    cout<<"2.Harga Termurah"<<endl;
    cout<<"Ingin Sorting Dari : ";cin>>sorting;
    if (sorting == 1) 
    {
      for (int i = 0; i < jd; i++) 
    {
      for (int d = 0; d < jd - i; d++) 
      {
        if (harga[d] < harga[d + 1]) 
        {
          tmp = harga[d];
          harga[d] = harga[d + 1];
          harga[d + 1] = tmp;
          
        tmp1 = nama_barang[d];
        nama_barang[d] = nama_barang[d+ 1];
        nama_barang[d+1] = tmp1;

        tmp = stok[d];
        stok[d] = stok[d + 1];
        stok[d + 1] = tmp;  
        }
      }
    }
      for (int i=0; i<jd; i++)
      {
      cout<<"Nomor : "<<i<<endl;
      cout<<"Nama Barang : "<<nama_barang[i]<<endl;
      cout<<"Harga       : "<<harga[i]<<endl;
      cout<<"Stok        : "<<stok[i]<<endl;
      cout<<endl;
        }
      }
    if (sorting == 2)
    {
      for (int a = 0; a < jd; a++) 
    {
      for (int c = jd - 1; c >= a; c--) 
      {
        if (harga[c] < harga[c - 1]) 
        {
          tmp = harga[c];
          harga[c] = harga[c - 1];
          harga[c - 1] = tmp;
          
          tmp = stok[c];
          stok[c] = stok[c - 1];
          stok[c - 1] = tmp;

          tmp1 = nama_barang[c];
          nama_barang[c] = nama_barang[c - 1];
          nama_barang[c - 1] = tmp1;
        }
      }
      }
      for (int a=0; a<jd; a++)
      {
      cout<<"Nomor : "<<a<<endl;
      cout<<"Nama Barang : "<<nama_barang[a]<<endl;
      cout<<"Harga       : "<<harga[a]<<endl;
      cout<<"Stok        : "<<stok[a]<<endl;
      cout<<endl;
      }
  }
    case 'n':
    	goto c;
    }	
    c:
    cout<<"Ingin Mencari Barang ? y/n : ";cin>>pil_cari;
    switch(pil_cari)
    {
	case 'y':
    cout << "Masukan Nama Barang : ";
	cin.ignore();
	getline(cin,cari);
	cout<<"Ditemukan : "<<endl;
	for(int i = 0; i < jd ; i++)
	{
		if(nama_barang[i] == cari)
		{
	    cout<<"Nomor : "<<i<<endl;
		cout<<"Nama Barang : "<<nama_barang[i]<<endl;
        cout<<"Harga       : "<<harga[i]<<endl;
        cout<<"Stok        : "<<stok[i]<<endl;
        cout<<endl;
		}
	}
	case 'n':
		goto b;
	}
	b:
    cout<<"Berbelanja Barang No : ";cin>>no_barang;
    cout<<"Jumlah beli          : ";cin>>jumlah_beli;
    for (int i=0; i<jd; i++)
    {
    	if (no_barang == i)
    	{
    		total = harga[i] * jumlah_beli;
    		stok_baru = stok[i] - jumlah_beli;
    		stok[i] = stok_baru;
    		 cout<<"=================================="<<endl;
    		 cout<<"Pilihan Kurir : "<<endl;
    		 cout<<"1.SiCepat (Rp.15.000)"<<endl;
    		 cout<<"2.JNT     (Rp.10.000)"<<endl;
    		 cout<<"Masukan Nomor Pilihan Kurir : ";cin>>pil_kurir;
    		 cout<<"=================================="<<endl;
    		 if (pil_kurir == 1)
    		 {
    		 	total = total + 15000;
			 }
			 if (pil_kurir == 2)
			 {
			 	total = total + 10000;
			 }
			 cout<<"Ingin Membayar Menggunakan : "<<endl;
			 cout<<"1.E-Money"<<endl;
			 cout<<"2.Minimarket"<<endl;
			 cout<<"Masukan Pilihan : ";cin>>method;
			 cout<<endl;
			 if (method == 1)
			 {
			  e_money = e_money - total;
			  ofstream MyFile("invoice.txt");
			  cout<<"=================================="<<endl;
			  cout<<"\t\tINVOICE"<<endl;
			  cout<<"=================================="<<endl;
			  cout<<"Nama Barang  : "<<nama_barang[i]<<endl;
			  cout<<"Total Harga  : "<<total<<endl;
			  cout<<"Sisa E-Money : "<<e_money<<endl;
			  cout<<"Status       : LUNAS"<<endl;
			  cout<<"=================================="<<endl;
			  cout<<"\t\tTERIMAKASIH"<<endl;
			  cout<<"\t\tTELAH BERBELANJA"<<endl;
			  cout<<endl;
			  
			  MyFile<<"=================================="<<endl;
			  MyFile<<"\t\tINVOICE"<<endl;
			  MyFile<<"=================================="<<endl;
			  MyFile<<"Nama Barang  : "<<nama_barang[i]<<endl;
			  MyFile<<"Total Harga  : "<<total<<endl;
			  MyFile<<"Sisa E-Money : "<<e_money<<endl;
			  MyFile<<"Status       : LUNAS"<<endl;
			  MyFile<<"=================================="<<endl;
			  MyFile<<"\t\tTERIMAKASIH"<<endl;
			  MyFile<<"\t\tTELAH BERBELANJA"<<endl;
			  MyFile<<endl;
			  MyFile.close();
			  goto m;	
			 }
			 if (method == 2)
			 {
			 	ofstream MyFile("invoice.txt");
			  cout<<"=================================="<<endl;
			  cout<<"\t\tINVOICE"<<endl;
			  cout<<"=================================="<<endl;
			  cout<<"Nama Barang  : "<<nama_barang[i]<<endl;
			  cout<<"Total Harga  : "<<total<<endl;
			  cout<<"Status       : BELUM LUNAS"<<endl;
			  cout<<"=================================="<<endl;
			  cout<<"\t\tTERIMAKASIH"<<endl;
			  cout<<"\t\tTELAH BERBELANJA"<<endl;
			  cout<<endl;
			  
			  MyFile<<"=================================="<<endl;
			  MyFile<<"\t\t\tINVOICE"<<endl;
			  MyFile<<"=================================="<<endl;
			  MyFile<<"Nama Barang  : "<<nama_barang[i]<<endl;
			  MyFile<<"Total Harga  : "<<total<<endl;
			  MyFile<<"Status       : BELUM LUNAS"<<endl;
			  MyFile<<"=================================="<<endl;
			  MyFile<<"\t\t\tTERIMAKASIH"<<endl;
			  MyFile<<"\t\tTELAH BERBELANJA"<<endl;
			  MyFile<<endl;
			  MyFile.close();
			  goto m;	
			 }
		}
	}
  }
    if (menu == 3)
  {
    fstream barang; 
    barang.open("data_barang.txt");
  	 cout << "Masukan Nama Barang Yang Akan Di Update Stok : ";
	cin.ignore();
	getline(cin,cari);
    
	for(int i = 0; i < jd ; i++)
	{
		if(nama_barang[i] == cari)
		{
			cout<<"Masukan Berapa Stok Yang Ingin Ditambahkan : ";cin>>stok_baru;
			stok[i] = stok[i] + stok_baru;
      barang<<"Nama Barang : "<<nama_barang[i]<<endl;
        barang<<"Harga       : "<<harga[i]<<endl;
        barang<<"Stok        : "<<stok[i]<<endl;
        barang<<endl;
		}
	}
     barang.close();
    goto m;
  }
}

int main() 
{
  dahlan x;
  x.input();
  x.proses();
}