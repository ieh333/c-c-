#include <iostream>
#include <string>
#include <ctype.h>
#include "CAuto.h"
#include "CAvtopark.h"

using namespace std;

//konstruktor po podrazbirane
CAvtopark::CAvtopark():CAuto() {
   name="";
   chain="";
   count_dealership=0;
   count_sales=0;
}

//explitsiden konstruktor
CAvtopark::CAvtopark(string r_n, string b, int y1, string c, int mil, string n, string ch, int c_d, int c_s):CAuto(r_n, b, y1, c, mil) {
   name=n;
   chain=ch;
   count_dealership=c_d;
   count_sales=c_s;
}

//konstruktor za kopirane
CAvtopark::CAvtopark(const CAvtopark &avtopark):CAuto(avtopark) {
}

//zadavane na ime na avtoparka
void CAvtopark::set_name(string n1) {
   name=n1;
}

//zadavane na verigata
void CAvtopark::set_chain(string ch1) {
   chain=ch1;                 
}

//zadavane na broia na avtokashtite v avtoparka
void CAvtopark::set_count_dealership(int cd) {
   count_dealership=cd;
}

//zadavane na broia na prodajbite na den
void CAvtopark::set_count_sales(int cs) {
   count_sales=cs;
}

//izvejdane na ime na avtoparka
string CAvtopark::get_name() const {
   return name;
}

//izvejdane na verigata
string CAvtopark::get_chain() const {
   return chain;
}

//izvejdane na broia na avtokashtite v avtoparka
int CAvtopark::get_count_dealership() const {
   return count_dealership;
}

//izvejdane na broia na prodajbite na den
int CAvtopark::get_count_sales() const {
   return count_sales;
}

//pechat
void CAvtopark::print() {
   CAuto::print();
   cout<<get_name()<<endl;
   cout<<get_chain()<<endl;
   cout<<get_count_dealership()<<endl;
   cout<<get_count_sales()<<endl;
}

//sravniavane na dva obekta ot tip CAvtopark
bool CAvtopark::compare(const CAvtopark &avtopark) {
   if((reg_number==avtopark.reg_number)&&(brand==avtopark.brand)&&(year==avtopark.year)&&(color==avtopark.color)&&(mileage==avtopark.mileage)&&(name==avtopark.name)&&(chain==avtopark.chain)&&(count_dealership==avtopark.count_dealership)&&(count_sales==avtopark.count_sales)) {
      cout<<"Both sites are identical!"<<endl;
      return true;
   }
   cout<<"Both sites aren't identical!"<<endl;
   return false;
}

//destruktor
CAvtopark::~CAvtopark() {
   
}
