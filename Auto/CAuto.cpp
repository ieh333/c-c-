#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <time.h>
#include "CAuto.h"

using namespace std;

//konstruktor po podrazbirane
CAuto::CAuto() {
    reg_number="";
    brand="";
    year=1900;
    color="";
    mileage=0;
}

//explitsiden konstruktor
CAuto::CAuto(string r_n, string b, int y1, string c, int mil) {
    reg_number=r_n;
    brand=b;
    year=y1;
    color=c;
    mileage=mil;
}

//konstruktor za kopirane
CAuto::CAuto(const CAuto &a) {
    reg_number=a.reg_number;
    brand=a.brand;
    year=a.year;
    color=a.color;
    mileage=a.mileage;
}

//zadavane na registratsionnia nomer
void CAuto::set_reg_number(string rn) {
    reg_number=rn;
}

//zadavane na markata
void CAuto::set_brand(string br) {
    brand=br;
}

//zadavane na godinata na proizvodstvo
void CAuto::set_year(int y2) {
    year=y2;
}

//zadavane na tsveta
void CAuto::set_color(string col) {
    color=col;
}

//zadavane na brobega
void CAuto::set_mileage(int m) {
    mileage=m;
}

//izvejdane na registratsionnia nomer
string CAuto::get_reg_number() const {
    return reg_number;
}

//izvejdane na markata
string CAuto::get_brand() const {
    return brand;
}

//izvejdane na godinata na proizvodstvo
int CAuto::get_year() const {
    return year;
}

//izvejdane na tsveta
string CAuto::get_color() const {
    return color;
}

//izvejdane na probega
int CAuto::get_mileage() const {
    return mileage;
}

//pechat
void CAuto::print() {
     cout<<get_reg_number()<<endl;
     cout<<get_brand()<<endl;
     cout<<get_year()<<endl;
     cout<<get_color()<<endl;
     cout<<get_mileage()<<endl;
}

//sravniavane na dva obekta ot tip CAuto
bool CAuto::compare(const CAuto &a) {
     if((reg_number==a.reg_number)&&(brand==a.brand)&&(year==a.year)&&(color==a.color)&&(mileage==a.mileage)) 
     {
        cout<<"Both sites are identical!"<<endl;
        return true;                                                                                                         
     }
     cout<<"Both sites aren't identical!"<<endl;
     return false;                                                                                                
}

//validirane na registratsionnia nomer
bool CAuto::validate(string reg) {
     unsigned i;
     int len, ch, result;
     len=reg.length();
     for(i=0;i<len;i++) {
      ch=reg[i];
      if(len==9) {
       switch(i) {
        case 0: result=isalpha(ch);
                if(result==0)
                {
                 cout<<"The number is invalid!"<<endl;
                 return false;    
                }
                break;
        case 1: result=isspace(ch);
                if(isspace(ch)==0) {
                 cout<<"The number is invalid!"<<endl;
                 return false;
                }
                break;
        case 2:
        case 3:
        case 4:
        case 5: result=isdigit(ch);
                if(result==0) {
                 cout<<"The number is invalid!"<<endl;
                 return false;
                }
                break;
        case 6: result=isspace(ch);
                if(isspace(ch)==0) {
                 cout<<"The number is invalid!"<<endl;
                 return false;
                }
                break;
        case 7:
        case 8: result=isalpha(ch);
                if(result==0)
                {
                 cout<<"The number is invalid!"<<endl;
                 return false;    
                }
                break;
       }        
      }
      else if(len==10) {
       switch(i) {
        case 0:
        case 1: result=isalpha(ch);
                if(result==0)
                {
                 cout<<"The number is invalid!"<<endl;
                 return false;    
                }
                break;
        case 2: result=isspace(ch);
                if(isspace(ch)==0) {
                 cout<<"The number is invalid!"<<endl;
                 return false;
                }
                break;
        case 3:
        case 4:
        case 5:
        case 6: result=isdigit(ch);
                if(result==0) {
                 cout<<"The number is invalid!"<<endl;
                 return false;
                }
                break;
        case 7: result=isspace(ch);
                if(isspace(ch)==0) {
                 cout<<"The number is invalid!"<<endl;
                 return false;
                }
                break;
        case 8:
        case 9: result=isalpha(ch);
                if(result==0)
                {
                 cout<<"The number is invalid!"<<endl;
                 return false;    
                }
                break;
       }         
      }
      else {
       cout<<"The number is invalid!"<<endl;
       return false;
      }
     }
     return true;   
}

//izchisliavane i vrashtane na vazrastta na kolata
int CAuto::age() {
    int year2, year_diff;
    time_t Time = time(NULL);
    struct tm *aTime = localtime(&Time);
    year2=aTime->tm_year+1900;
    year_diff=year2-year;
    return year_diff;
}

//otpechatvane (na reshenieto na zadachata) na printera
void CAuto::printer() {
     ofstream print;
     print.open("PRN");
     if(!print) {
        cout<<"The printer isn't installed!"<<endl;
        return;
     }
     print<<endl;
     print<<"The registration number is: "<<get_reg_number()<<endl;
     print<<"The brand is: "<<get_brand()<<endl;
     print<<"The year is: "<<get_year()<<endl;
     print<<"The color is: "<<get_color()<<endl;
     print<<"The mileage is: "<<get_mileage()<<endl;
     print<<endl;
     print.close();
}

//prisvoiavane na obecta ot drug obect
void CAuto::operator=(const CAuto& car) {
     reg_number=car.reg_number;
     brand=car.brand;
     year=car.year;
     color=car.color;
     mileage=car.mileage;
}

//proverka dali kolata e s tsviat metalik
bool CAuto::isMetalik() {
     const string col_m="Metalik";
     if(color==col_m) {
       cout<<"The car is with Metalik color."<<endl;
       return true;
     }
     cout<<"The car isn't with Metalik color."<<endl;
     return false;
}

//sravniava dva obecta po probeg (sas znak '<')
bool CAuto::compare_mileage(const CAuto &car2) {
     if(mileage<car2.mileage) {
      cout<<"The first car have less mileage than the second."<<endl;
      return true;
     }
     else if(mileage>car2.mileage) {
      cout<<"The first car have greater mileage than the second."<<endl;
      return false;
     }
     else {
       cout<<"The first car have same mileage than the second."<<endl;
       return false;
     }
}

//proverka dali dva obekta savpadat po tsviat
bool CAuto::isCoinColor(const CAuto &car3) {
     if(color==car3.color) {
        cout<<"The colors of both cars match."<<endl;
        return true;
     }
     cout<<"The colors of both cars don't match."<<endl;
     return false;
}

//destruktor
CAuto::~CAuto(){
 
}


