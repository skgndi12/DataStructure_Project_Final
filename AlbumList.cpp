#include "AlbumList.h"
using namespace std;

int AlbumList::GetAlbumId()
{
    return mAlbumId;
}

string AlbumList::GetAlbumName()
{
    return mAlbum;
}

BinarySearchTree<SongList>* AlbumList::GetAlbumList()
{
    return &al_list;
}

void AlbumList::SetAlbumId(int inAlbumId)
{
    mAlbumId = inAlbumId;
}

void AlbumList::SetAlbumName(string inAlbum)
{
    mAlbum = inAlbum;
}

void AlbumList::SetInfo(int inAlbumId, string inAlbum)
{
    SetAlbumId(inAlbumId);
    SetAlbumName(inAlbum);
}

void AlbumList::DisplayAlbumIdOnScreen()
{
    cout << "\t   <ALBUM ID> : "<<  mAlbumId << endl;
}

void AlbumList::DisplayAlbumNameOnScreen()
{
    cout << "\t   <ALBUM NAME> : " << mAlbum << endl;
}

void AlbumList::DisplaySongListOnScreen()
{
    al_list.PrintTree(cout);
}

void AlbumList::DisplayAlbumRecordsOnScreen()
{
    DisplayAlbumNameOnScreen();
    DisplaySongListOnScreen();
}

void AlbumList::SetAlbumIdFromKB()
{
    string ID;
    cout << "\t   <ALBUM ID> : ";
    getline(cin, ID);
    mAlbumId = stoi(ID);
}

void AlbumList::SetAlbumNameFromKB()
{
    cout << "\t   <ALBUM> : ";
    getline(cin, mAlbum);
}
string AlbumList::to_string() const
{
    char buf[256];

    ::snprintf(buf, sizeof(buf), "\t%s%s\n\n",
        "   <ALBUM> : ", mAlbum.c_str());
	
	return buf;
}
bool AlbumList::operator== (const AlbumList &obj)
{
	return (this->mAlbum == obj.mAlbum);
}

bool AlbumList::operator> (const AlbumList &obj)
{
	return (this->mAlbum > obj.mAlbum);
}

bool AlbumList::operator< (const AlbumList &obj)
{
	return (this->mAlbum < obj.mAlbum);
}

bool AlbumList::operator!= (const AlbumList &obj) 
{
    return (this->mAlbum != obj.mAlbum);
}