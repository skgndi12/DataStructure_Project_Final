#ifndef _SONGLIST_H
#define _SONGLIST_H
#include <iostream>
#include <string>

using namespace std;

class SongList
{
    public:
    //default constructor 

    SongList()
    {
        s_id = -1;
    }
    //copy constructor
    SongList(int s_id, string s_title );
    //destructor set
    ~SongList(){}

    SongList& operator= (SongList &obj)
	{
		this->s_id = obj.s_id;
		this->s_title = obj.s_title;

		return *this;
	}

    void SetId(int in_id)
    {
        s_id = in_id;
    }

    void SetTitle(string in_title)
    {
        s_title = in_title;
    }

    int GetId()
    {
        return s_id;
    }

    string GetTitle()
    {
        return s_title;
    }

    void SetInfo(int in_id, string in_title)
    {
        s_title = in_title;
        s_id = in_id;
    }

    void SetIdFromKB()
    {
        string ID;
        cout << "\t   <ID> : ";
        getline(cin, ID);
        s_id = stoi(ID);
        
    }

    void SetTitleFromKB()
    {
        cout << "\t   <TITLE> : ";
        getline(cin, s_title);
    }

    void SetInfoFromKB()
    {
        SetIdFromKB();
        SetTitleFromKB();
    }

    
    void DisplayId()
    {
        cout << "\t   <ID> : " << s_id <<endl;
    }

    void DisplayTitle()
    {
        cout << "\t   <TITLE> : " << s_title << endl;
    }

    string to_string() const
    {
    string ID(std::to_string(s_id));
    char buf[256];

    ::snprintf(buf, sizeof(buf), "\t%s%s\n\t%s%s\n\n",
        "   <ID> : ", ID.c_str(),"   <TITLE> : ", s_title.c_str());
	
	return buf;
    }

    void DisplayAll()
    {
        cout << "\t   <ID> : " << s_id << endl;
        cout << "\t   <TITLE> : " << s_title << endl;
    }
    bool operator==(SongList item)
	{
		return (this->GetId() == item.GetId());
	}
	bool operator>(SongList item)
	{
		return (this->GetId() > item.GetId());
	}
	bool operator>=(SongList item)
	{
		return (this->GetId() >= item.GetId());
	}
	bool operator<(SongList item)
	{
		return (this->GetId() < item.GetId());
	}
	bool operator<=(SongList item)
	{
		return (this->GetId() <= item.GetId());
	}

    protected:
    int s_id;
    string s_title;
};

#endif	// _SONGLIST_H