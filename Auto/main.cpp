#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CAuto.h"
#include "CAvtopark.h"

using namespace std;

//Izvejdane na dannite vav failove, kato za vsiaka veriga avtokashti da bade na otdelen fail
void write_file(CAvtopark &avto, string file) {  
     string filename,ext;
     ext=avto.get_chain();
     filename=file+"_"+ext+".txt";
     ofstream outfile(filename.c_str(),ios::out);
     outfile<<avto.get_reg_number()<<endl;
     outfile<<avto.get_brand()<<endl;
     outfile<<avto.get_year()<<endl;
     outfile<<avto.get_color()<<endl;
     outfile<<avto.get_mileage()<<endl;
     outfile<<avto.get_name()<<endl;
     outfile<<avto.get_chain()<<endl;
     outfile<<avto.get_count_dealership()<<endl;
     outfile<<avto.get_count_sales()<<endl;
     outfile.close();
}

//Izvejdane na vsichki avtoparkove, koito imat prodajbi za edin den - nad 1 kola
void print_sales (CAvtopark &avto) {
     int sales_day;
     sales_day=avto.get_count_sales();
     if(sales_day>1) {
        avto.print();
     } 
     else {
        cout<<"Niama avtoparkove, koito da imat prodajbi za edin den - nad 1 kola."<<endl;
     }
}

//Izvejdane na avtoparkovete, koito ne prodavat opredelena marka, koiato e podadena kato parametar
void print_not_brand(CAvtopark &avto, string brand) {
     string mark;
     mark=avto.get_brand();
     if(mark!=brand) {
        avto.print();
     }
     else {
        cout<<"Niama avtoparkove, koito da ne prodavat "<<mark<<"."<<endl;
     }
}

//Izvejdane na vsichki danni za avtoparkovete s nai-mnogo prodajbi

void print_sales_max(vector <CAvtopark> &avto) {
   int i;
   int sales, max_sales;
   max_sales=0;
   for(i=0;i<avto.size();i++) {
      sales=avto[i].get_count_sales();
      if(sales>max_sales) {
         max_sales=sales;
      }
   }
   for(i=0;i<avto.size();i++) {
      sales=avto[i].get_count_sales();
      if(sales==max_sales) {
         avto[i].print();
      }
   }
}


//Izvejdane na avtoparkovete pri podaden kato parametar tsviat, pritejavashti Reno ili Pegout, s nad 150000 km probeg
void print_selected(CAvtopark &avto, string col1) {
   string mark, col2;
   int mil1;
   mark=avto.get_brand();
   col2=avto.get_color();
   mil1=avto.get_mileage();
   if(col2==col1){
      if(((mark=="Reno")||(mark=="Pegout"))&&(mil1>150000)) {
         avto.print();
      }
   }
}


//Glavna funktsia
int main(int argc, char *argv[])
{
    int i,k;
    string rn, br, col,n1,ch1;
    int y, mil,cd1,cs1;
    vector <CAvtopark> a(10);
    cout<<endl;
    for(i=0;i<a.size();i++) {
       CAuto a1;
       cout<<"Vavedete registratsionnia nomer na kolata:";
       getline(cin,rn);
       a1.set_reg_number(rn);
       while(a1.validate(rn)==false) {
          cout<<"Vavedete registratsionnia nomer na kolata:";
          getline(cin,rn);
          a1.set_reg_number(rn);
       }
       a[i].set_reg_number(rn);
       cout<<"Vavedete proizvoditelia na kolata:";
       getline(cin,br);
       a[i].set_brand(br);
       cout<<"Vavedete godinata na proizvodstvo na kolata:";
       cin>>y;
       a[i].set_year(y);
       cout<<"Vavedete tsveta na kolata:";
       cin.ignore();
       getline(cin,col);
       a[i].set_color(col);
       cout<<"Vavedete kakav probeg e izminala kolata:";
       cin>>mil;
       a[i].set_mileage(mil);
       cout<<"Vavedete imeto na avtoparka:";
       cin.ignore();
       getline(cin,n1);
       a[i].set_name(n1);
       cout<<"Vavedete verigata na avtoparka:";
       getline(cin,ch1);
       a[i].set_chain(ch1);
       cout<<"Vavedete broia na avtokashtite:";
       cin>>cd1;
       a[i].set_count_dealership(cd1);
       cout<<"Vavedete broia na prodajbite:";
       cin>>cs1;
       a[i].set_count_sales(cs1);
       cin.ignore();
       system("CLS");
    }
    cout<<endl;
    cout<<"1. - Izvedete dannite vav failove, kato za vsiaka veriga avtokashti da bade na otdelen fail."<<endl;
    cout<<"2. - Izvedete vsichki avtoparkove, koito imat prodajbi za edin den - nad 1 kola. "<<endl;
    cout<<"3. - Izvedete avtoparkovete, koito ne prodavat opredelena marka, koiato e podadena kato parametar."<<endl;
    cout<<"4. - Izvedete vsichki danni za avtoparkovete s nai-mnogo prodajbi."<<endl;
    cout<<"5. - Pri podaden kato parametar tsviat, da se izvedat avtoparkovete, pritejavashti Reno ili Pegout, s nad 150000 km probeg."<<endl;
    cout<<"Izberete edin ot variantite, dadeni po-gore:";
    cin>>k;
    while(k) {
       switch(k) {
          case 1: for(i=0;i<a.size();i++) {
                     write_file(a[i],"test");
                  }
                  cout<<"Izberete edin ot variantite, dadeni po-gore:";
                  cin>>k;
                  break;
          case 2: for(i=0;i<a.size();i++) {
                     print_sales(a[i]);
                     cout<<endl;
                  }
                  cout<<"Izberete edin ot variantite, dadeni po-gore:";
                  cin>>k;
                  break;
          case 3: cout<<"Vavedete marka na kolata:";
                  cin>>br;
                  for(i=0;i<a.size();i++) {
                     print_not_brand(a[i],br);
                     cout<<endl;
                  }
                  cout<<"Izberete edin ot variantite, dadeni po-gore:";
                  cin>>k;
                  break;
          case 4: print_sales_max(a);
                  cout<<"Izberete edin ot variantite, dadeni po-gore:";
                  cin>>k;
                  break;
          case 5: cout<<"Vavedete tsveta na kolata:";
                  cin>>col;
                  for(i=0;i<a.size();i++) {
                     print_selected(a[i],col);
                     cout<<endl;
                  }
                  cout<<"Izberete edin ot variantite, dadeni po-gore:";
                  cin>>k;
                  break;
          default: cout<<"Vavedenia variant ne sashtestvuva v menuto."<<endl;
                   cout<<"Izberete edin ot variantite, dadeni po-gore:";
                   cin>>k;
       }
    }
    system("PAUSE");
    return 0;
}
