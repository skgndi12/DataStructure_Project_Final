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
    cout << "Album ID : "<<  mAlbumId << endl;
}

void AlbumList::DisplayAlbumNameOnScreen()
{
    cout << "Album Name : " << mAlbum << endl;
}

void AlbumList::DisplaySongListOnScreen()
{
    al_list.PrintTree(cout);
}

void AlbumList::DisplayAlbumRecordsOnScreen()
{
    DisplayAlbumIdOnScreen();
    DisplayAlbumNameOnScreen();
    DisplaySongListOnScreen();
}

void AlbumList::SetAlbumIdFromKB()
{
    cin >> mAlbumId;
}

void AlbumList::SetAlbumNameFromKB()
{
    cin >> mAlbum;
}

bool AlbumList::operator== (const AlbumList &obj)
{
	return (this->mAlbumId==obj.mAlbumId);
}

bool AlbumList::operator> (const AlbumList &obj)
{
	return (this->mAlbumId>obj.mAlbumId);
}

bool AlbumList::operator< (const AlbumList &obj)
{
	return (this->mAlbumId<obj.mAlbumId);
}

bool AlbumList::operator!= (const AlbumList &obj) 
{
    return (this->mAlbumId != obj.mAlbumId);
}