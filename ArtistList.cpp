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
    cout << "\tArtist ID : "<<  mArtistId << endl;
}

void ArtistList::DisplayArtistNameOnScreen()
{
    cout << "\tArtist Name : " << mArtist << endl;
}

void ArtistList::DisplaySongListOnScreen()
{
    ar_list.PrintTree(cout);
}

void ArtistList::DisplayArtistRecordsOnScreen()
{
    DisplayArtistNameOnScreen();
    DisplaySongListOnScreen();
}

void ArtistList::SetArtistIdFromKB()
{
    string ID;
    cout << "\t   <ARTIST ID> : ";
    getline(cin, ID);
    mArtistId = stoi(ID);
}

void ArtistList::SetArtistNameFromKB()
{
    cout << "\t   <ARTIST> : ";
    getline(cin, mArtist);
}

string ArtistList::to_string() const
{
    char buf[256];

    ::snprintf(buf, sizeof(buf), "\t%s%s\n\n",
        "   <ARTIST> : ",mArtist.c_str());
	
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