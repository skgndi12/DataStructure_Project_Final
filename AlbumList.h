#ifndef _ALBUMLIST_H
#define _ALBUMLIST_H
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "SongList.h"
using namespace std;
class AlbumList
{
    public:

    AlbumList()
    {
        mAlbumId = -1;
        mAlbum = "";
    }

    AlbumList(SongList data)
    {
        al_list.Add(data);
    }

    ~AlbumList(){}

    int GetAlbumId();
    
    string GetAlbumName();

    BinarySearchTree<SongList>* GetAlbumList();
    
    void SetAlbumId(int inAlbumId);

    void SetAlbumName(string inAlbum);
    
    void SetInfo(int inAlbumId, string inAlbum);
    

    void DisplayAlbumIdOnScreen();

    void DisplayAlbumNameOnScreen();

    void DisplayAlbumRecordsOnScreen();

    void SetAlbumIdFromKB();

    void SetAlbumNameFromKB();

    bool operator== (const AlbumList &);

	bool operator> (const AlbumList &);
	
	bool operator< (const AlbumList &); 
	
	bool operator!= (const AlbumList &);

protected:
	int mAlbumId;	///< Primary key
	string mAlbum;
	BinarySearchTree<SongList> al_list;
}; 
#endif //_ALBUMLIST_H