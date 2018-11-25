#include "ArtistList.h"
using namespace std;

int ArtistList::GetArtistId()
{
    return mArtistId;
}

string ArtistList::GetArtistName()
{
    return mArtist;
}

BinarySearchTree<SongList>* ArtistList::GetArtistList()
{
    return &ar_list;
}

void ArtistList::SetArtistId(int inArtistId)
{
    mArtistId = inArtistId;
}

void ArtistList::SetArtistName(string inArtist)
{
    mArtist = inArtist;
}

void ArtistList::SetInfo(int inArtistId, string inArtist)
{
    SetArtistId(inArtistId);
    SetArtistName(inArtist);
}


void ArtistList::DisplayArtistIdOnScreen()
{
    cout << "Artist ID : "<<  mArtistId << endl;
}

void ArtistList::DisplayArtistNameOnScreen()
{
    cout << "Artist Name : " << mArtist << endl;
}

void ArtistList::DisplaySongListOnScreen()
{
    ar_list.PrintTree(cout);
}

void ArtistList::DisplayArtistRecordsOnScreen()
{
    DisplayArtistIdOnScreen();
    DisplayArtistNameOnScreen();
    DisplaySongListOnScreen();
}

void ArtistList::SetArtistIdFromKB()
{
    cin >> mArtistId;
}

void ArtistList::SetArtistNameFromKB()
{
    cin >> mArtist;
}

bool ArtistList::operator== (const ArtistList &obj)
{
	return (this->mArtistId==obj.mArtistId);
}

bool ArtistList::operator> (const ArtistList &obj)
{
	return (this->mArtistId>obj.mArtistId);
}

bool ArtistList::operator< (const ArtistList &obj)
{
	return (this->mArtistId<obj.mArtistId);
}

bool ArtistList::operator!= (const ArtistList &obj) 
{
    return (this->mArtistId != obj.mArtistId);
}