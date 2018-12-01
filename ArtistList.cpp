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
    string ID;
    cout << "\tArtist ID : ";
    getline(cin, ID);
    mArtistId = stoi(ID);
}

void ArtistList::SetArtistNameFromKB()
{
    cout << "\tArtist : ";
    getline(cin, mArtist);
}

string ArtistList::to_string() const
{
    char buf[256];

    ::snprintf(buf, sizeof(buf), "%s\n",
        mArtist.c_str());
	
	return buf;
}
bool ArtistList::operator== (const ArtistList &obj)
{
	return (this->mArtist == obj.mArtist);
}

bool ArtistList::operator> (const ArtistList &obj)
{
	return (this->mArtist > obj.mArtist);
}

bool ArtistList::operator< (const ArtistList &obj)
{
	return (this->mArtist < obj.mArtist);
}

bool ArtistList::operator!= (const ArtistList &obj) 
{
    return (this->mArtist != obj.mArtist);
}