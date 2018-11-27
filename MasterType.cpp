#include <cstring>

#include "MasterType.h"

int MasterType::GetId()
{
    return id;
}
string MasterType::GetArtist()
{
    return artist;
}
string MasterType::GetComposer()
{
    return composer;
}
string MasterType::GetLyricist()
{
    return lyricist;
}
string MasterType::GetAlbum()
{
    return album;
}
string MasterType::GetGenre()
{
    return genre;
}
string MasterType::GetLyric()
{
    return lyric;
}

void MasterType::SetId(int in_id)
{
    id = in_id;
}

void MasterType::SetTitle(string in_title)
{
    title = in_title;
}

void MasterType::SetArtist(string in_artist)
{
    artist = in_artist;
}

void MasterType::SetComposer(string in_composer)
{
    composer = in_composer;
}

void MasterType::SetLyricist(string in_lyricist)
{
    lyricist = in_lyricist;
}
void MasterType::SetAlbum(string in_album)
{
    album = in_album;
}
void MasterType::SetGenre(string in_genre)
{
    genre = in_genre;
}
void MasterType::SetLyric(string in_lyric)
{
    lyric = in_lyric;
}


void MasterType::SetRecord(int in_id, string in_title,string in_artist,string in_composer,string in_lyricist,string in_album, string in_genre, string in_lyric)
{
    SetId(in_id);
    SetTitle(in_title);
    SetArtist(in_artist);
    SetComposer(in_composer);
    SetLyricist(in_lyricist);
    SetAlbum(in_album);
    SetGenre(in_genre);
    SetLyric(in_lyric);
}
void MasterType::DisplayIdOnScreen()
{
    cout << "\tId : " << id << endl;
}

void MasterType::DisplayTitleOnScreen()
{
    cout << "\tTitle : " << title << endl;
}

void MasterType::DisplayArtistOnScreen()
{
    cout << "\tArtist : "<< artist << endl;
}
void MasterType::DisplayComposerOnScreen()
{
    cout << "\tCompose : " << composer << endl;
}
void MasterType::DisplayLyricistOnScreen()
{
    cout << "\tLyricist : " << lyricist << endl;
}
void MasterType::DisplayAlbumOnScreen()
{
    cout << "\tAlbum : " << album << endl;
}
void MasterType::DisplayGenreOnScreen()
{
    cout << "\tGenre : " << genre << endl;
}
void MasterType::DisplayLyricOnScreen()
{
    cout << "\tLyric : " << lyric << endl;
}

void MasterType::DisplayRecordOnScreen()
{
    DisplayIdOnScreen();
    DisplayTitleOnScreen();
    DisplayArtistOnScreen();
    DisplayComposerOnScreen();
    DisplayLyricistOnScreen();
    DisplayAlbumOnScreen();
    DisplayGenreOnScreen();
    DisplayLyricOnScreen();
}
void MasterType::SetIdFromKB()
{
    string ID;
    cout << "\tId : ";
    getline(cin, ID);
    id = stoi(ID);
}

void MasterType::SetTitleFromKB()
{
    cout << "\tTitle : ";
    getline(cin, title);
}

// Set artist from keyboard.
void MasterType::SetArtistFromKB()
{
    cout << "\tArtist : ";
    getline(cin,artist);
}

void MasterType::SetComposerFromKB()
{
    cout << "\tComposer : ";
    getline(cin, composer);
}
void MasterType::SetLyricistFromKB()
{
    cout << "\tLyricist : ";
    getline(cin, lyricist);
}
// Set album from keyboard.
void MasterType::SetAlbumFromKB()
{
    cout << "\tAlbum : ";
    getline(cin, album);
}

void MasterType::SetGenreFromKB()
{
    cout << "\tGenre : ";
    getline(cin, genre);
}

void MasterType::SetLyricFromKB()
{
    cout << "\tLyric : ";
    getline(cin, lyric);
}


// Set song_num information from keyboard.
void MasterType::SetRecordFromKB()
{
    SetIdFromKB();
    SetTitleFromKB();
    SetArtistFromKB();
    SetComposerFromKB();
    SetLyricistFromKB();
    SetAlbumFromKB();
    SetGenreFromKB();
    SetLyricFromKB();
}



// Read a record from file.
int MasterType::ReadDataFromFile(ifstream& fin)
{
    fin >> id;
    fin >> title;
    fin >> artist;
    fin >> composer;
    fin >> lyricist;
    fin >> album;
    fin >> genre;
    fin >> lyric;

    return 1;
}


// Write a record into file.
int MasterType::WriteDataToFile(ofstream& fout)
{
   
    fout << id << " ";
    fout << title << " ";
    fout << artist << " ";
    fout << composer << " ";
    fout << lyricist << " ";
    fout << album << " ";
    fout << genre << " ";
    fout << lyric << " ";

    return 1;
}

string MasterType::to_string() const
{
    string ID(std::to_string(id));
    char buf[256];

    ::snprintf(buf, sizeof(buf), "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
        ID.c_str(), title.c_str(), artist.c_str(),composer.c_str(), lyricist.c_str(),
        album.c_str(), genre.c_str(), lyric.c_str());
	
	return buf;
}


bool MasterType::operator>(MasterType item)
{
    if(this->GetId() > item.GetId())
    {
        return true;
    }
return false;
}
bool MasterType::operator==(MasterType item)
{
    if(this->GetId() == item.GetId())
    {
        return true;
    }
return false;
}
bool MasterType::operator<(MasterType item)
{
    if(this->GetId() < item.GetId())
    {
        return true;
    }
return false;
}

// Compare two itemtypes.