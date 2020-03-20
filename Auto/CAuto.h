#ifndef CAUTO_H
#define CAUTO_H

using namespace std;

class CAuto {
	protected:
		string reg_number; //registratsionen nomer
		string brand;     // marka na kolata
		int year;        // godina na proizvodstvo
		string color;   //  tsviat na kolata
		int mileage;   // izminal probeg na kolata
	public:
		CAuto(); //konstruktor po podrazbirane
		CAuto(string r_n, string b, int y1, string c, int mil); //explitsiden konstruktor
		CAuto(const CAuto &a);  //konstruktor za kopirane
		void set_reg_number(string rn); //zadavane na registratsionnia nomer
		void set_brand(string br); //zadavane na markata
		void set_year(int y2); //zadavane na godinata na proizvodstvo
		void set_color(string col); //zadavane na tsveta
		void set_mileage(int m); //zadavane na brobega
		string get_reg_number() const; //izvejdane na registratsionnia nomer
		string get_brand() const;  //izvejdane na markata
		int get_year() const;   //izvejdane na godinata na proizvodstvo
		string get_color() const;   //izvejdane na tsveta
		int get_mileage() const;   //izvejdane na probega
		virtual void print();  //pechat
		virtual bool compare(const CAuto &a); //sravniavane na dva obekta ot tip CAuto
		bool validate(string reg);  //validirane na registratsionnia nomer
		int age();   //izchisliavane i vrashtane na vazrastta na kolata
		void printer(); //otpechatvane (na reshenieto na zadachata) na printera
	    void operator=(const CAuto& a); //prisvoiavane na obecta ot drug obect
		bool isMetalik(); //proverka dali kolata e s tsviat metalik
		bool compare_mileage(const CAuto &car2);   //sravniava dva obecta po probeg (sas znak '<')
		bool isCoinColor(const CAuto &car3);   //proverka dali dva obekta savpadat po tsviat
		~CAuto();   //destruktor
};

#endif // CAUTO_H
