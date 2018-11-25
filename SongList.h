#ifndef _SONGLIST_H
#define _SONGLIST_H
#include <iostream>
#include <string>
#include "MasterType.h"

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
        cin >> s_id;
    }

    void SetTitleFromKB()
    {
        cin >> s_title;
    }

    
    void DisplayId()
    {
        cout << "\tSong ID : " << s_id <<endl;
    }

    void DisplayTitle()
    {
        cout << "\tSong Title : " << s_title << endl;
    }

    void DisplayAll()
    {
        cout << "ID" << s_id << endl;
        cout << "TITLE" << s_title << endl;
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