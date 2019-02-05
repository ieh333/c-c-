#ifndef CAVTOPARK_H
#define CAVTOPARK_H



using namespace std;

class CAvtopark:public CAuto {
      private:
          string name;   //ime na avtoparka
          string chain;   //veriga avtopark
          int count_dealership;   //broi avtokashti
          int count_sales;   //broi prodajbi na den
      public:
         CAvtopark();   //konstruktor po podrazbirane
         CAvtopark(string r_n, string b, int y1, string c, int mil, string n, string ch, int c_d, int c_s);   //explitsiden konstruktor
         CAvtopark (const CAvtopark &avtopark);   //konstruktor za kopirane
         void set_name(string n1);   //zadavane na ime na avtoparka
         void set_chain(string ch1);   //zadavane na verigata
         void set_count_dealership(int cd);   //zadavane na broia na avtokashtite v avtoparka
         void set_count_sales(int cs);   //zadavane na broia na prodajbite na den
         string get_name() const;   //izvejdane na ime na avtoparka
         string get_chain() const;   //izvejdane na verigata
         int get_count_dealership() const;   //izvejdane na broia na avtokashtite v avtoparka
         int get_count_sales() const;   //izvejdane na broia na prodajbite na den
         virtual void print();   //pechat
         virtual bool compare(const CAvtopark &avtopark);   //sravniavane na dva obekta ot tip CAvtopark
         ~CAvtopark();   //destruktor
};

#endif // CAVTOPARK_H
