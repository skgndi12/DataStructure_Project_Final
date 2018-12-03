#ifndef _PLAYLIST_H
#define _PLAYLIST_H
#include <iostream>
#include <string>
using namespace std;

class PlayList
{
    public:

    PlayList()
    {
        p_id = -1;
        p_title = "";
    }
    //copy constructor
    PlayList(int p_id, string p_title);
    //destructor set
    ~PlayList(){}

    PlayList& operator= (PlayList &obj)
    {
        this->p_id = obj.p_id;
        this->p_title = obj.p_title;

        return *this;
    }

    void SetId(int in_id)
    {
        p_id = in_id;
    }

    void SetTitle(string in_title)
    {
        p_title = in_title;
    }

    int GetId()
    {
        return p_id;
    }

    string GetTitle()
    {
        return p_title;
    }

    void SetInfo(int in_id, string in_title)
    {
        p_id = in_id;
        p_title = in_title;
    }

    void DisplayId()
    {
        cout <<"\t   <ID> : " << p_id << endl;
    }

    void DisplayTitle()
    {
        cout << "\t   <TITLE> : " << p_title << endl;
    }

    string to_string() const
    {
    string ID(std::to_string(p_id));
    char buf[256];

    ::snprintf(buf, sizeof(buf), "\t%s%s\n\t%s%s\n\n",
        "   <ID> : ", ID.c_str(),"   <TITLE> : ", p_title.c_str());
	
	return buf;
    }

    void DisplayAll()
    {
        cout << "\t   <ID> : " << p_id << endl;
        cout << "\t   <TITLE> : " << p_title << endl;
    }

    bool operator==(PlayList item)
	{
		return (this->GetId() == item.GetId());
	}
	bool operator>(PlayList item)
	{
		return (this->GetId() > item.GetId());
	}
	bool operator>=(PlayList item)
	{
		return (this->GetId() >= item.GetId());
	}
	bool operator<(PlayList item)
	{
		return (this->GetId() < item.GetId());
	}
	bool operator<=(PlayList item)
	{
		return (this->GetId() <= item.GetId());
	}

    protected:
    int p_id;
    string p_title;
};

#endif // _PLAYLIST_H