#include <iostream>

using namespace std;

const int max=100;


class Hero
{
private:
    string Fname;
    string Lname;
    bool isGood;
    int Hatred;
    int Attraction;

public:
    Hero()
    {
        Fname="";
        Lname="";
        isGood=false;
        Hatred=0;
        Attraction=0;
    }
    Hero(string fname, string lname, bool is_good, int hatred, int attraction)
    {
        Fname=fname;
        Lname=lname;
        isGood=is_good;
        Hatred=hatred;
        Attraction=attraction;
    }
    Hero (const Hero &h)
    {
        Fname=h.Fname;
        Lname=h.Lname;
        isGood=h.isGood;
        Hatred=h.Hatred;
        Attraction=h.Attraction;
    }
    void set_Fname(string first_name)
    {
        Fname=first_name;
    }
    void set_Lname(string last_name)
    {
        Lname=last_name;
    }
    void set_isGood(bool is_good)
    {
        isGood=is_good;
    }
    void set_hatred(int hatred)
    {
        Hatred=hatred;
    }
    void set_attraction(int attraction)
    {
        Attraction=attraction;
    }
    string get_Fname() const
    {
        return Fname;
    }
    string get_Lname() const
    {
        return Lname;
    }
    bool get_isGood() const
    {
        return isGood;
    }
    int get_hatred() const
    {
        return Hatred;
    }
    int get_attraction() const
    {
        return Attraction;
    }
    Hero& operator=(const Hero& h)
    {
        if(this!=&h)
        {
            Fname=h.Fname;
            Lname=h.Lname;
            isGood=h.isGood;
            Hatred=h.Hatred;
            Attraction=h.Attraction;
        }
        return *this;
    }
    void print_Hero()
    {
        cout<<get_Fname()<<" "<<get_Lname()<<" "<<get_isGood()<<" "<<get_hatred()<<" "<<get_attraction()<<endl;
    }
    ~Hero() {}
};

class Event
{
private:
    string Name;
    int Episodes;

public:
    Event()
    {
        Name="";
        Episodes=0;
    }
    Event(string name, int episodes)
    {
        Name=name;
        Episodes=episodes;
    }
    Event(const Event &e)
    {
        this->Name=e.Name;
        this->Episodes=e.Episodes;
    }
    void set_Name(string name)
    {
        Name=name;
    }
    void set_Episodes(int episodes)
    {
        Episodes=episodes;
    }
    string get_Name() const
    {
        return Name;
    }
    int get_Episodes() const
    {
        return Episodes;
    }
    Event& operator=(const Event& event)
    {
        if(this!=&event)
        {
            Name=event.Name;
            Episodes=event.Episodes;
        }
        return *this;
    }
    void print_Event()
    {
        cout<<get_Name()<<" "<<get_Episodes()<<endl;
    }
    ~Event() {}
};

class Series
{
private:
    string name_Series;
    int count_Episodes;
    Episode *list_Episodes[max];
    Event *list_Events[max];
    Hero *list_Heroes[max];

public:
    Series()
    {
        name_Series="";
        count_Episodes=0;
        list_Episodes=new Episode[];
        list_Events=new Event[];
        list_Heroes=new Hero[];
    }
    Series(string n_Series, int c_Episodes, Episode *episodes[], Event *events[], Hero *heroes[])
    {

        name_Series=n_Series;
        count_Episodes=c_Episodes;
        for(int i=0;i<max;i++)
        {
            list_Episodes[i]=episodes[i];
            list_Events[i]=events[i];
            list_Heroes[i]=heroes[i];
        }
    }
    Series(const Series &series)
    {
        this.name_Series=series.name_Series;
        this.count_Episodes=series.count_Episodes;
        for(int i=0;i<max;i++)
        {
            this.list_Episodes[i]=series.list_Episodes[i];
            this.list_Events[i]=series.list_Events[i];
            this.list_Heroes[i]=series.list_Heroes[i];
        }
    }
    void set_name_Series(string series_Name)
    {
        name_Series=series_Name;
    }
    void set_count_Episodes(int episodes_count)
    {
        count_Episodes=episodes_count;
    }
    void set_list_Episodes(size_t index, Episode episodes_List)
    {
        list_Episodes[index]=episodes_List;
    }
    void set_list_Events(size_t index, Event events_List)
    {
        list_Events[index]=events_List;
    }
    void set_list_Heroes(size_t index, Hero heroes_List)
    {
        list_Heroes[index]=heroes_List;
    }
    string get_name_Series() const
    {
        return name_Series;
    }
    int get_count_Episodes() const
    {
        return count_Episodes;
    }
    Episode get_list_Episodes(size_t index) const
    {
        return list_Episodes[index];
    }
    Event get_list_Events(size_t index) const
    {
        return list_Events[index];
    }
    Hero get_list_Heroes(size_t index) const
    {
        return list_Heroes[index];
    }
    Series& operator=(const Series& seriali)
    {
        if(this!=&seriali)
        {
            name_Series=seriali.name_Series;
            count_Episodes=seriali.count_Episodes;
            for(int k=0;k<max;k++)
            {
                list_Episodes[k]=seriali.list_Episodes[k];
                list_Events[k]=seriali.list_Events[k];
                list_Heroes[k]=seriali.list_Heroes[k];
            }
        }
        return *this;
    }
    void print_Series()
    {
        int len_array1,len_array2,len_array3;
        len_array1=sizeof(list_Episodes)/sizeof(list_Episodes[0]);
        len_array2=sizeof(list_Events)/sizeof(list_Events[0]);
        len_array3=sizeof(list_Heroes)/sizeof(list_Heroes[0]);
        cout<<get_name_Series()<<" "<<get_count_Episodes()<<endl;
        for(int i=0;i<len_array1;i++)
        {
            cout<<get_list_Episodes(i)<<",";
        }
        cout<<endl;
        for(int j=0;j<len_array2;j++)
        {
            cout<<get_list_Events(j)<<",";
        }
        cout<<endl;
        for(int k=0;k<len_array3;k++)
        {
            cout<<get_list_Heroes(k)<<",";
        }
        cout<<endl;
    }
    ~Series()
    {
        delete[] list_Episodes;
        delete[] list_Events;
        delete[] list_Heroes;
    }
};

class Episode: public Series
{
private:
    int number_Episode;
    string name_Episode;
    int count_Events;

public:
    Episode()
    {
        number_Episode=0;
        name_Episode="";
        count_Events=0;
    }
    Episode(int episode_number, string episode_name, int events_count)
    {
        number_Episode=episode_number;
        name_Episode=episode_name;
        count_Events=events_count;
    }
    Episode(const Episode &episodes)
    {
        this.number_Episode=episodes.number_Episode;
        this.name_Episode=episodes.name_Episode;
        this.count_Events=episodes.count_Events;
    }
    void set_number_Episode(int episode_Number)
    {
        number_Episode=episode_Number;
    }
    void set_name_Episode(string episode_Name)
    {
        name_Episode=episode_Name;
    }
    void set_count_Events(int events_Count)
    {
        count_Events=events_Count;
    }
    int get_number_Episode() const
    {
        return number_Episode;
    }
    string get_name_Episode() const
    {
        return name_Episode;
    }
    int get_count_Events() const
    {
        return count_Events;
    }
    Episode& operator=(const Episode& episode)
    {
        if(this!=&episode)
        {
            number_Episode=episode.number_Episode;
            name_Episode=episode.name_Episode;
            count_Events=episode.count_Events;
        }
        return *this;
    }
    void print_Episode()
    {
        cout<<get_number_Episode()<<" "<<get_name_Episode()<<" "<<get_count_Events()<<endl;
    }
    ~Episode() {}
};






int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
