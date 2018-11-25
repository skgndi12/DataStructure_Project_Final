#ifndef _GENRELIST_H
#define _GENRELIST_H
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "SongList.h"
using namespace std;
class GenreList
{
    public:

    GenreList()
    {
        mGenreId = -1;
        mGenre = "";
    }

    GenreList(SongList data)
    {
        g_list.Add(data);
    }

    ~GenreList(){}

    int GetGenreId();
    
    string GetGenreName();

    BinarySearchTree<SongList>* GetGenreList();
    
    void SetGenreId(int inGenreId);

    void SetGenreName(string inGenre);
    
    void SetInfo(int inGenreId, string inGenre);
    
    void DisplayGenreIdOnScreen();

    void DisplayGenreNameOnScreen();

    void DisplaySongListOnScreen();//GenreList안에 있는 해당하는 Genre의 SongList를 출력

    void DisplayGenreRecordsOnScreen();

    void SetGenreIdFromKB();

    void SetGenreNameFromKB();

    bool operator== (const GenreList &);

	bool operator> (const GenreList &);
	
	bool operator< (const GenreList &); 
	
	bool operator!= (const GenreList &);

protected:
	int mGenreId;	///< Primary key
	string mGenre;
	BinarySearchTree<class SongList> g_list;
}; 
#endif //_GENRELIST_H
