#ifndef _ARTISTLIST_H
#define _ARTISTLIST_H
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "SongList.h"
using namespace std;
class ArtistList
{
    public:

    ArtistList()
    {
        mArtistId = -1;
        mArtist = "";
    }

    ArtistList(SongList data)
    {
        ar_list.Add(data);
    }

    ~ArtistList(){}

    int GetArtistId();
    
    string GetArtistName();

    BinarySearchTree<SongList>* GetArtistList();
    
    void SetArtistId(int inArtistId);

    void SetArtistName(string inArtist);
    
    void SetInfo(int inArtistId, string inArtist);

    

    void DisplayArtistIdOnScreen();

    void DisplayArtistNameOnScreen();

    void DisplaySongListOnScreen();//ArtistList안에 있는 해당하는 Artist의 SongList를 출력

    void DisplayArtistRecordsOnScreen();

    void SetArtistIdFromKB();

    void SetArtistNameFromKB();

    bool operator== (const ArtistList &);

	bool operator> (const ArtistList &);
	
	bool operator< (const ArtistList &); 
	
	bool operator!= (const ArtistList &);

protected:
	int mArtistId;	///< Primary key
	string mArtist;
	BinarySearchTree<class SongList> ar_list;
}; 
#endif //_ARTISTLIST_H