#include <cstring>

#include "MasterType.h"

int MasterType::GetId()
{
    return id;
}
string MasterType::GetTitle()
{
    return title;
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
    cout << "\t   <ID> : " << id << endl;
}

void MasterType::DisplayTitleOnScreen()
{
    cout << "\t   <TITLE> : " << title << endl;
}

void MasterType::DisplayArtistOnScreen()
{
    cout << "\t   <ARTIST> : "<< artist << endl;
}
void MasterType::DisplayComposerOnScreen()
{
    cout << "\t   <COMPOSER> : " << composer << endl;
}
void MasterType::DisplayLyricistOnScreen()
{
    cout << "\t   <LYRICSIT> : " << lyricist << endl;
}
void MasterType::DisplayAlbumOnScreen()
{
    cout << "\t   <ALBUM> : " << album << endl;
}
void MasterType::DisplayGenreOnScreen()
{
    cout << "\t   <GENRE> : " << genre << endl;
}
void MasterType::DisplayLyricOnScreen()
{
    cout << "\t   <LYRIC> : " << lyric << endl;
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
    cout << "\t   <ID> : ";
    getline(cin, ID);
    id = stoi(ID);
}

void MasterType::SetTitleFromKB()
{
    cout << "\t   <TITLE> : ";
    getline(cin, title);
}

// Set artist from keyboard.
void MasterType::SetArtistFromKB()
{
    cout << "\t   <ARTIST> : ";
    getline(cin, artist);
}

void MasterType::SetComposerFromKB()
{
    cout << "\t   <COMPOSER> : ";
    getline(cin, composer);
}
void MasterType::SetLyricistFromKB()
{
    cout << "\t   <LYRICIST> : ";
    getline(cin, lyricist);
}
// Set album from keyboard.
void MasterType::SetAlbumFromKB()
{
    cout << "\t   <ALBUM> : ";
    getline(cin, album);
}

void MasterType::SetGenreFromKB()
{
    cout << "\t   <GENRE> : ";
    getline(cin, genre);
}

void MasterType::SetLyricFromKB()
{
    cout << "\t   <LYRIC> : ";
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

void MasterType::ResetSongInfoFromKB()
{
    cout << "\t   INPUT THE INFORMATION OF THE SONG TO BE UPDATED " << endl << endl;
    SetArtistFromKB();
    SetComposerFromKB();
    SetLyricistFromKB();
    SetAlbumFromKB();
    SetGenreFromKB();
    SetLyricistFromKB();
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

    ::snprintf(buf, sizeof(buf), "\t%s%s\n\t%s%s\n\t%s%s\n\t%s%s\n\t%s%s\n\t%s%s\n\t%s%s\n\t%s%s\n\n",
        "   <ID> : ",ID.c_str(),"   <TITLE> : ", title.c_str(), "   <ARTIST> : ", artist.c_str(),"   <COMPOSER> : ",composer.c_str(),"   <LYRICIST> : ", lyricist.c_str(),"   <ALBUM> : ",
        album.c_str(), "   <GENRE> : ", genre.c_str(),"   <LYRIC> : ", lyric.c_str());
	
	return buf;
}


bool MasterType::operator>(const MasterType &obj)
{
	return (this->title > obj.title);
}
bool MasterType::operator==(const MasterType &obj)
{
    if(this->title == obj.title)
    {
        return true;
    }
    return false;
}
    
bool MasterType::operator<(const MasterType &obj)
{
	return (this->title < obj.title);
}


// Compare two itemtypes.