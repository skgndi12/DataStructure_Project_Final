#include "GenreList.h"
using namespace std;

int GenreList::GetGenreId()
{
    return mGenreId;
}

string GenreList::GetGenreName()
{
    return mGenre;
}

BinarySearchTree<SongList>* GenreList::GetGenreList()
{
    return &g_list;
}

void GenreList::SetGenreId(int inGenreId)
{
    mGenreId = inGenreId;
}

void GenreList::SetGenreName(string inGenre)
{
    mGenre = inGenre;
}

void GenreList::SetInfo(int inGenreId, string inGenre)
{
    SetGenreId(inGenreId);
    SetGenreName(inGenre);
}


void GenreList::DisplayGenreIdOnScreen()
{
    cout << "Genre ID : "<<  mGenreId << endl;
}

void GenreList::DisplayGenreNameOnScreen()
{
    cout << "Genre Name : " << mGenre << endl;
}

void GenreList::DisplaySongListOnScreen()
{
    g_list.PrintTree(cout);
}

void GenreList::DisplayGenreRecordsOnScreen()
{
    DisplayGenreIdOnScreen();
    DisplayGenreNameOnScreen();
    DisplaySongListOnScreen();
}

void GenreList::SetGenreIdFromKB()
{
    cin >> mGenreId;
}

void GenreList::SetGenreNameFromKB()
{
    cin >> mGenre;
}

bool GenreList::operator== (const GenreList &obj)
{
	return (this->mGenreId==obj.mGenreId);
}

bool GenreList::operator> (const GenreList &obj)
{
	return (this->mGenreId>obj.mGenreId);
}

bool GenreList::operator< (const GenreList &obj)
{
	return (this->mGenreId<obj.mGenreId);
}

bool GenreList::operator!= (const GenreList &obj) 
{
    return (this->mGenreId != obj.mGenreId);
}