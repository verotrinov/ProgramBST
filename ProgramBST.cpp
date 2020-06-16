#include<iostream>
#include<cstdlib>
using namespace std;

struct simpul
{
	int info;
	struct simpul *kiri;
	struct simpul *kanan;
}
*akar;

void insert(simpul *tree, simpul *simpulbaru)
{
	if(akar==NULL)
	{
		akar = new simpul;
		akar->info = simpulbaru->info;
		akar->kanan = NULL;
		akar->kiri = NULL;
		cout<<"--Bilangan Terinput"<<endl;
		cout<<endl;
		return;
	}
	if(tree->info == simpulbaru->info)
	{
		cout<<"--Bilangan sudah Terdapat dalam BST"<<endl;
		cout<<endl;
		return;
	}
	
	if(tree->info > simpulbaru->info)
	{
		if(tree->kiri != NULL)
		{
			insert(tree->kiri, simpulbaru);
		}
		else
		{
			tree->kiri = simpulbaru;
			(tree->kiri)->kiri = NULL;
			(tree->kiri)->kanan = NULL;
			cout<<"--Bilangan Terinput"<<endl;
			cout<<endl;
			return;
		}
	}
	else
	{
		if(tree->kanan != NULL)
		{
			insert(tree->kanan, simpulbaru);
		}
		
		else
		{
			(tree->kanan) = simpulbaru;
			(tree->kanan)->kiri = NULL;
			(tree->kanan)->kanan = NULL;
			cout<<"--Bilangan Terinput"<<endl;
			cout<<endl;
			return;
		}
	}
}

void preorder(simpul *ptr)
{
	if(akar == NULL)
	{
		cout<<"--BST KOSONG"<<endl;
		return;
	}
	if(ptr != NULL)
	{
		cout<<ptr->info<<" ";
		preorder(ptr->kiri);
		preorder(ptr->kanan);
	}
}

void inorder(simpul *ptr)
{
	if(akar == NULL)
	{
		cout<<"--BST KOSONG"<<endl;
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->kiri);
		cout<<ptr->info<<" ";
		inorder(ptr->kanan);
	}
}

void postorder(simpul *ptr)
{
	if(akar == NULL)
	{
		cout<<"--BST KOSONG"<<endl;
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->kiri);
		postorder(ptr->kanan);
		cout<<ptr->info<<" ";
	}
}


void max(simpul *tree)
{
	while(tree != NULL && tree->kanan!=NULL)
	{
		tree = tree->kanan;
	}
	cout<<"--Bilangan Terbesar adalah : "<<tree->info;
	cout<<endl;
}

void min(simpul *tree)
{
	while(tree != NULL && tree->kiri!=NULL)
	{
		tree = tree->kiri;
	}
	cout<<"--Bilangan Terkecil adalah : "<<tree->info;
	cout<<endl;
}

void cari(int item, simpul **par, simpul **loc)
{
    simpul *pointer, *simpan;
    if (akar == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == akar->info)
    {
        *loc = akar;
        *par = NULL;
        return;
    }
    if (item < akar->info)
        pointer = akar->kiri;
    else
        pointer = akar->kanan;
    	simpan = akar;
    while (pointer != NULL)
    {
        if (item == pointer->info)
        {
            *loc = pointer;
            *par = simpan;
            return;
        }
        simpan = pointer;
        if (item < pointer->info)
            pointer = pointer->kiri;
	else
	    pointer = pointer->kanan;
    }
    *loc = NULL;
    *par = simpan;
}
	
void kondisi1(simpul *par, simpul *loc)	
{
	if (par == NULL)
    {
        akar = NULL;
    }
    else
    {
        if (loc == par->kiri)
            par->kiri = NULL;
        else
            par->kanan = NULL;
    }
}

void kondisi2(simpul *par, simpul *loc)
{
	simpul *anak;
    if (loc->kiri != NULL)
        anak = loc->kiri;
    else
        anak = loc->kanan;
    if (par == NULL)
    {
        akar = anak;
    }
    else
    {
        if (loc == par->kiri)
            par->kiri = anak;
        else
            par->kanan = anak;
    }
}

void kondisi3(simpul *par, simpul *loc)
{
	simpul *pointer, *simpan, *x, *y;
    simpan = loc;
    pointer = loc->kanan;
    while (pointer->kiri != NULL)
    {
        simpan = pointer;
        pointer = pointer->kiri;
    }
    x = pointer;
    y = simpan;
    if (x->kiri == NULL && x->kanan == NULL)
        kondisi1(y, x);
    else
        kondisi2(y, x);
    if (par == NULL)
    {
        akar = x;
    }
    else
    {
        if (loc == par->kiri)
            par->kiri = x;
        else
            par->kanan = x;
    }
    x->kiri = loc->kiri;
    x->kanan = loc->kanan;
}

void del(int item)
{
	simpul *induk, *lokasi;
	if(akar==NULL)
	{
		cout<<"--BST KOSONG"<<endl;
		return;
	}
	cari(item, &induk, &lokasi);
    if (lokasi == NULL)
    {
        cout<<"--Bilangan Tidak Terdapat dalam BST"<<endl;
        return;
    }
    if (lokasi->kiri == NULL && lokasi->kanan == NULL)
        kondisi1(induk, lokasi);
    if (lokasi->kiri != NULL && lokasi->kanan == NULL)
        kondisi2(induk, lokasi);
    if (lokasi->kiri == NULL && lokasi->kanan != NULL)
        kondisi2(induk, lokasi);
    if (lokasi->kiri != NULL && lokasi->kanan != NULL)
        kondisi3(induk, lokasi);
    cout<<"--Bilangan Terhapus"<<endl;
    free(lokasi);
}

void search(simpul **akar, int num)
{
    if((*akar) == NULL)
    {
        cout<<"--TIDAK DITEMUKAN"<<endl;
    }
    else if(num < (*akar)->info)
        search(&(*akar)->kiri, num);
    else if(num > (*akar)->info)
        search(&(*akar)->kanan, num);
    else if(num == (*akar)->info)
        cout<<"--DITEMUKAN"<<endl;
}

void reset(simpul * tree)
{
	if (tree)
	{
	reset(tree->kiri);
	reset(tree->kanan);
	free(tree);
	}
}

int main()
{
int ans, order;
simpul *pos;
while(1)
{

menu :
	cout<<" ----------------------------"<<endl;
	cout<<"| PROGRAM BINARY SEARCH TREE |"<<endl;
	cout<<" ----------------------------"<<endl;
	cout<<"MENU : "<<endl;
	cout<<"1. Insert Bilangan"<<endl;
	cout<<"2. Cetak"<<endl;
	cout<<"3. Cari"<<endl;
	cout<<"4. Hapus"<<endl;
	cout<<"5. Reset"<<endl;
	cout<<"Masukkan pilihan : ";
	cin>>ans;
	
	if(ans==1)
	{
		cout<<endl;
		pos = new simpul;
		cout<<"//Menu Insert Bilangan"<<endl;
		cout<<"Masukkan bilangan : ";
		cin>>pos->info;
		insert(akar, pos);	
	}
	if(ans==2)
	{
		cout<<"//Menu Cetak"<<endl;
		cout<<"1. Cetak Preorder"<<endl;
		cout<<"2. Cetak Inorder"<<endl;
		cout<<"3. Cetak Postorder"<<endl;
		cout<<"4. Cetak Bilangan Terbesar"<<endl;
		cout<<"5. Cetak Bilangan Terkecil"<<endl;
		cout<<"Masukkan Pilihan : ";
		cin>>order;
		
		if(order==1){
			cout<<"Preorder : ";
			preorder(akar);
			cout<<endl;
			goto menu;
		}
		if(order==2)
		{
			cout<<"Inorder : ";
			inorder(akar);
			cout<<endl;
			goto menu;
		}
		if(order==3)
		{
			cout<<"Postorder : ";
			postorder(akar);
			cout<<endl;
			goto menu;
		}	
		if(order==4)
		{
			max(akar);
			goto menu;
		}
		if(order==5)
		{
			min(akar);
			goto menu;
		}
	}
	if(ans==3)
	{
		int num;
		cout<<endl;
		cout<<"//Menu Cari"<<endl;
		cout<<"Masukkan Bilangan yang Ingin Dicari : ";
		cin>>num;
		search(&akar, num);
		cout<<endl;
	}
	if(ans==4)
	{
		int angka;
		cout<<"//Menu Hapus"<<endl;
		cout<<"Masukkan Bilangan yang Ingin Dihapus : ";
		cin>>angka;
		del(angka);
		cout<<endl;
		goto menu;
	}
	if(ans==5)
	{
		reset(akar);
		cout<<"--Data Berhasil Tereset"<<endl;
		cout<<"--BST KOSONG"<<endl;
		cout<<"Silahkan Masuk Ke Menu Insert Bilangan untuk Memulai Ulang Program"<<endl;
		cout<<endl;
		goto menu;
	}
}
}
