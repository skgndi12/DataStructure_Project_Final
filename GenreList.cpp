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
    cout << "\tGenre ID : "<<  mGenreId << endl;
}

void GenreList::DisplayGenreNameOnScreen()
{
    cout << "\tGenre Name : " << mGenre << endl;
}

void GenreList::DisplaySongListOnScreen()
{
    g_list.PrintTree(cout);
}

void GenreList::DisplayGenreRecordsOnScreen()
{
    DisplayGenreNameOnScreen();
    DisplaySongListOnScreen();
}

void GenreList::SetGenreIdFromKB()
{
    string ID;
    cout << "\tGenre ID : ";
    getline(cin, ID);
    mGenreId = stoi(ID);
}

void GenreList::SetGenreNameFromKB()
{
    cout << "\tGenre Name : ";
    getline(cin, mGenre);
}

string GenreList::to_string() const
{
    char buf[256];

    ::snprintf(buf, sizeof(buf), "\t%s%s\n\n",
       "Genre : ", mGenre.c_str());
	
	return buf;
}
bool GenreList::operator== (const GenreList &obj)
{
	return (this->mGenre == obj.mGenre);
}

bool GenreList::operator> (const GenreList &obj)
{
	return (this->mGenre > obj.mGenre);
}

bool GenreList::operator< (const GenreList &obj)
{
	return (this->mGenre < obj.mGenre);
}

bool GenreList::operator!= (const GenreList &obj) 
{
    return (this->mGenre != obj.mGenre);
}