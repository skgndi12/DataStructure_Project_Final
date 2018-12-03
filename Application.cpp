#include "Application.h"

// Application 실행 함수
void Application::Run()
{
	while (1)
	{
		command = GetCommand();

		switch (command)
		{
		case 1: 
			SelectAddMenu();
			break;
		case 2:
			SelectDeleteMenu();
			break;
		case 3:
			RepalceItem();
			break;
		case 4:
			SelectDisplayMenu();
			break;
		case 5:
			SelectSearchMenu();
			break;
		case 6:
			SelectPlayerMenu();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}
void Application::SelectAddMenu()
{
	while(1)
	{
		menu_add = GetAddCommand();
		switch(menu_add)
		{
			case 1:
				InsertItem();
				return;
			case 2:
				Add();
				return;
			case 0:
				return;
			default:
			cout << "\tIllegal sellection...\n";
				return;
		}
	}
}

void Application::SelectDeleteMenu()
{
	while(1)
	{
		menu_delete = GetDeleteCommand();
		switch(menu_delete)
		{
			case 1:
				RemoveItem();
				return;
			case 2:
				DeleteGenreItem();
				return;
			case 3:
				DeleteAlbumItem();
				return;
			case 4:
				DeleteArtistItem();
			case 0:
				return;
			default:
			cout << "\tIllegal sellection...\n";
				return;
		}
	}
}

void Application::SelectDisplayMenu()
{
	while(1)
	{
		menu_dis = GetDisplayCommand();
		switch(menu_dis)
		{
			case 1:
				DisplayItem();
				return;
			case 2:
				DisplayMasterList();
				return;
			case 3:
				DisplayGenreList();
				return;
			case 4:
				DisplayAlbumList();
				return;
			case 5:
				DisplayArtistList();
				return;
			case 0:
				return;
			default:
			cout << "\tIllegal sellection...\n";
				return;
		}
	}
}

void Application::SelectSearchMenu()
{
	while(1)
	{
		menu_search = GetSearchCommand();
		switch(menu_search)
		{
			case 1:
				SearchItem();
				return;
			case 2:
				SearchByTitleNLyric();
				return;
			case 3:
				SearchByGenre();
				return;
			case 4:
				SearchByGenreNLyric();
				return;
			case 5:
				SearchByArtist();
				return;
			case 6:
				SearchByArtistNGenre();
				return;
			case 7:
				SearchByAlbum();
				return;
			case 8:
				SearchByAlbumNLyric();
				return;
			case 0:
				return;
			default:
			cout << "\tIllegal sellection...\n";
				return;
		}
	}
}

void Application::SelectPlayerMenu()
{
	while(1)
	{
		menu_player = GetPlayerCommand();
		switch(menu_player)
		{
			case 1:
				AddPlayList();
				return;
			case 2:
				DeletePlayList();
				return;
			case 3:
				DisplayPlayList();
				return;
			case 4:
				DisplayPlayLog();
				return;
			case 5:
				ExecutePlayList();
				return;
			case 0:
				return;
			default:
			cout << "\tIllegal sellection...\n";
				return;
		}
	}
}

void Application::RunPlayer()
{
	while(1)
	{
		playmode = GetPlayModeCommand();
		switch(playmode)
		{
			case 1:
				PlayMusic();
				break;
			case 2:
				StopMusic();
				return;
			case 3:
				MoveForward();
				break;
			case 4:
				MoveBackward();
				break;
			case 0:
				return;
			default:
			cout << "\tIllegal sellection...\n";
				break;
		}
	}
}

void Application::RunPlayerInStop()
{
	while(1)
	{
		playmodeinstop = GetPlayModeCommandInStop();
		switch(playmodeinstop)
		{
			case 1:
				PlayMusic();
				return;
			case 2:
				MoveForward();
				return;
			case 3:
				MoveBackward();
				return;
			case 0:
				return;
			default:
			cout << "\tIllegal sellection...\n";
				break;
		}
	}
}


// command 값 입력받는 함수
int Application::GetCommand()
{
	string command;
	cout << endl << endl;
	cout << "\t    >------ID -- Command ------< " << endl;
	cout << "\t   1 : <ADD>" << endl;
	cout << "\t   2 : <DELETE>" << endl;
	cout << "\t   3 : <UPDATE>" << endl;
	cout << "\t   4 : <DISPLAY>" << endl;
	cout << "\t   5 : <SEARCH>" << endl;
	cout << "\t   6 : <PLAYER MENU>" << endl;
	cout << "\t   0 : <QUIT> " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, command);
	cout << endl;
	return stoi(command);
}

int Application::GetAddCommand()
{
	string menu_add;
	cout << "\t   >------ ADD -- COMMAND ------< " << endl;
	cout << "\t   1 : <ADD TO MASTER LIST> " << endl;
	cout << "\t   2 : <ADD TO ALL LIST> " << endl;
	cout << "\t   0 : <BACK> " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, menu_add);
	cout << endl;
	return stoi(menu_add);
}

int Application::GetDeleteCommand()
{
	string menu_delete;
	cout << "\t   >------ DELETE -- COMMAND ------< " << endl;
	cout << "\t   1 : <DELETE IN MASTER LIST> " << endl;
	cout << "\t   2 : <DELETE IN GENRE LIST> " << endl;
	cout << "\t   3 : <DELETE IN ALBUM LIST> " << endl;
	cout << "\t   4 : <DELETE IN ARTIST LIST>" << endl;
	cout << "\t   0 : <BACK>  " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, menu_delete);
	cout << endl;
	return stoi(menu_delete);
}

int Application::GetDisplayCommand()
{
	string menu_dis;
	cout << "\t   >------ DISPLAY -- COMMAND ------< " << endl;
	cout << "\t   1 : <DISPLAY ALL ITEM IN ALL LIST> " << endl;
	cout << "\t   2 : <DISPLAY ALL ITEM IN MASTER LIST> " << endl;
	cout << "\t   3 : <DISPLAY ALL ITEM IN GENRE LIST> " << endl;
	cout << "\t   4 : <DISPLAY ALL ITEM IN ALBUM LIST>" << endl;
	cout << "\t   5 : <DISPLAY ALL ITEM IN ARTIST LIST>" << endl;
	cout << "\t   0 : <BACK>  " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, menu_dis);
	cout << endl;
	return stoi(menu_dis);
}

int Application::GetSearchCommand()
{
	string menu_search;
	cout << "\t   >------ DISPLAY -- COMMAND ------< " << endl;
	cout << "\t   1 : <SEARCH BY ID N TITLE> " << endl;
	cout << "\t   2 : <SEARCH BY TITLE N LYRIC> " << endl;
	cout << "\t   3 : <SEARCH BY GENRE> " << endl;
	cout << "\t   4 : <SEARCH BY GENRE N LYRIC>" << endl;
	cout << "\t   5 : <SEARCH BY ARTIST>" << endl;
	cout << "\t   6 : <SEARCH BY ARTIST N GENRE>" << endl;
	cout << "\t   7 : <SEARCH BY ALBUM>" << endl;
	cout << "\t   8 : <SEARCH BY ALBUM N LYRIC>" << endl;
	cout << "\t   0 : <BACK>  " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, menu_search);
	cout << endl;
	return stoi(menu_search);
}

int Application::GetPlayerCommand()
{
	string menu_player;
	cout << "\t   >------ DISPLAY -- COMMAND ------< " << endl;
	cout << "\t   1 : <ADD TO PLAY LIST> " << endl;
	cout << "\t   2 : <DELETE IN PLAY LIST> " << endl;
	cout << "\t   3 : <DISPLAY PLAY LIST> " << endl;
	cout << "\t   4 : <DISPLAY PLAYER LOG>" << endl;
	cout << "\t   5 : <EXECUTE PLAYER>" << endl;
	cout << "\t   0 : <BACK>  " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, menu_player);
	cout << endl;
	return stoi(menu_player);	
}


int Application::GetPlayModeCommand()
{
	string playmode;
	cout << "\t   >------ MODE -- COMMAND ------< " << endl;
	cout << "\t   1 : <PLAY MUSIC> " << endl;
	cout << "\t   2 : <STOP MUSIC> " << endl;
	cout << "\t   3 : <MOVE FORWARD> " << endl;
	cout << "\t   4 : <MOVE BACKWARD>" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, playmode);
	cout << endl;
	return stoi(playmode);
}

int Application::GetPlayModeCommandInStop()
{
	string playmodeinstop;
	cout << "\t   >------ MODE -- COMMAND ------< " << endl;
	cout << "\t   1 : <PLAY MUSIC> " << endl;
	cout << "\t   2 : <MOVE FORWARD> " << endl;
	cout << "\t   3 : <MOVE BACKWARD>" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, playmodeinstop);
	cout << endl;
	return stoi(playmodeinstop);
}

// Tree에 item을 추가하는 함수 
void Application::InsertItem()
{
	MasterType item;
	cout << "\t   INSERT ITEM : " << endl << endl;
	item.SetRecordFromKB();				// Tree에 추가할 item 값을 키보드로부터 입력받음
	Tree.Add(item);						// Add함수를 통해서 item을 Tree에 추가함
	DisplayItem();						// 현재 Tree의 node를 모두 출력함
}

void Application::Add()
{
	cout << "\t   INPUT MUSIC TO ADD TO THE USER LIST : " << endl;
	MasterType item;
	item.SetIdFromKB();
	item.SetTitleFromKB();
	GenreList g_item;
	AlbumList al_item;
	ArtistList ar_item;
	SongList indata;
	bool found;
	Tree.RetrieveItem(item, found);
	g_item.SetGenreName(item.GetGenre());
	al_item.SetAlbumName(item.GetAlbum());
	ar_item.SetArtistName(item.GetArtist());

	if(found == true)
	{
		indata.SetInfo(item.GetId(), item.GetTitle());//SongList 자료형을 만들고 거기다가 MasterType의 ID를 받아서 넣고 각 List에 추가
		bool found_g;
		g_Tree.RetrieveItem(g_item,found_g);
		if(found_g == true)
		{
			bool found_s;
			g_Tree.RetrieveItem(g_item, found_s);
			g_Tree.DeleteItem(g_item);
			g_item.AddSongList(indata);
			g_Tree.Add(g_item);
		}
		else if(found_g == false)
		{
			g_item.AddSongList(indata);
			g_Tree.Add(g_item);
		}
		bool found_ar;
		ar_Tree.RetrieveItem(ar_item,found_ar);
		if(found_ar == true)
		{
			bool found_s;
			ar_Tree.RetrieveItem(ar_item, found_s);
			ar_Tree.DeleteItem(ar_item);
			ar_item.AddSongList(indata);
			ar_Tree.Add(ar_item);
		}
		else{
			ar_item.AddSongList(indata);
			ar_Tree.Add(ar_item);
		}
		bool found_al;
		al_Tree.RetrieveItem(al_item, found_al);
		if(found_al == true)
		{
			bool found_s;
			al_Tree.RetrieveItem(al_item, found_s);
			al_Tree.DeleteItem(al_item);
			al_item.AddSongList(indata);
			al_Tree.Add(al_item);
		}
		else{
			al_item.AddSongList(indata);
			al_Tree.Add(al_item);
		}
	}
	else
	{
		cout << "\t   THERE IS NO MATCHED DATA" << endl;
	}
	DisplayItem();
}
// Tree에서 item을 지우는 함수
void Application::RemoveItem()
{
	MasterType item;
	GenreList g_item;
	AlbumList al_item;
	ArtistList ar_item;
	SongList indata;
	cout << "\t   INPUT ID AND TITLE TO DELETE ITEM : " << endl;
	item.SetIdFromKB();					// Tree에서 지우려고 하는 id 값을 키보드로부터 입력받음
	item.SetTitleFromKB();            //Tree에서 지우려고 하는 title 값을 키보드로부터 입력받음
	indata.SetInfo(item.GetId(), item.GetTitle());// 입력받은 정보를 song list에 저장
	bool found;							// 검색여부에 따른 결과를 저장할 found
	bool found_g;
	bool found_al;
	bool found_ar;
	Tree.RetrieveItem(item, found);		// RetrieveItem 함수를 통해서 Tree에서 검색
	g_item.SetGenreName(item.GetGenre());//g_Tree에서 지우려고 하는 Genre name을 item으로부터 받아서 g_item에 저장
	g_Tree.RetrieveItem(g_item, found_g);//g_Tree에서 해당하는 genre가 있는지 검색
	al_item.SetAlbumName(item.GetAlbum());//al_Tree에서 지우려고 하는 Album name을 item으로부터 받아서 al_item에 저장
	al_Tree.RetrieveItem(al_item, found_al);//al_Tree에서 해당하는 album가 있는지 검색
	ar_item.SetArtistName(item.GetArtist());//ar_Tree에서 지우려고 하는 Artist name을 item으로부터 받아서 ar_item에 저장
	ar_Tree.RetrieveItem(ar_item, found_ar);//ar_Tree에서 해당하는 artist가 있는지 검색

	if (found == true)					// Tree에 item이 있으면
	{
		if(found_g == true)//해당하는 genre가 있는 경우
		{
			bool found_s;
			BinarySearchTree<class SongList> *temp;
			temp = g_item.GetGenreList();//해당하는 genre에서 g_list를 받아온다.
			temp->RetrieveItem(indata, found_s);//g_list에서 입력받은 song list의 정보가 있는지 검색
			if(found_s == true)//g_list에서 song list의 정보가 있을 경우
			{
				g_Tree.DeleteItem(g_item);//g_Tree에서 해당하는 장르의 노드를 지운다.
				g_item.DeleteSongList(indata);//해당하는 장르에서 입력받은 song list의 데이터를 자운다.
				g_Tree.Add(g_item);//지웠던 장르를 다시 추가한다.
			}
			else//g_list에서 song list의 정보가 없을 경우
			{
				cout << "\t   THERE IS NO MATCHED SONG IN GENRE LIST" << endl;
			}
		}
		else//해당하는 genre가 없을 경우
		{
			cout << "\t   THERE IS NO MATCHED GENRE" << endl;
		}
		if(found_al == true)//해당하는 album이 있는 경우
		{
			bool found_s;
			BinarySearchTree<class SongList> *temp;
			temp = al_item.GetAlbumList();//해당하는 album에서 al_list를 받아온다.
			temp->RetrieveItem(indata, found_s);//al_list에서 입력받은 song list의 정보가 있는지 검색
			if(found_s == true)//al_list에서 song list의 정보가 있을 경우
			{
				al_Tree.DeleteItem(al_item);//al_Tree에서 해당하는 앨범의 노드를 지운다.
				al_item.DeleteSongList(indata);//해당하는 앨범에서 입력받은 song list의 데이터를 자운다.
				al_Tree.Add(al_item);//지웠던 앨범을 다시 추가한다
			}
			else//al_list에서 song list의 정보가 없을 경우
			{
				cout << "\t   THERE IS NO MATCHED SONG IN ALBUM LIST" << endl;
			}
		}
		
		else//해당하는 album이 없을 경우
		{
			cout << "\t   THERE IS NO MATCHED ALBUM" << endl;
		}
		if(found_ar == true)//해당하는 artist가 있는 경우
		{
			bool found_s;
			BinarySearchTree<class SongList> *temp;
			temp = ar_item.GetArtistList();//해당하는 artist에서 ar_list를 받아온다.
			temp->RetrieveItem(indata, found_s);//ar_list에서 입력받은 song list의 정보가 있는지 검색
			if(found_s == true)//ar_list에서 song list의 정보가 있을 경우
			{
				ar_Tree.DeleteItem(ar_item);//ar_Tree에서 해당하는 앨범의 노드를 지운다.
				ar_item.DeleteSongList(indata);//해당하는 앨범에서 입력받은 song list의 데이터를 자운다.
				ar_Tree.Add(ar_item);//지웠던 앨범을 다시 추가한다
			}
			else//ar_list에서 song list의 정보가 없을 경우
			{
				cout << "\t   THERE IS NO MATCHED SONG IN ARTIST LIST" << endl;
			}
		}
		else//해당하는 artist이 없을 경우
		{
			cout << "\t   THERE IS NO MATCHED ARTIST" << endl;
		}	
		Tree.DeleteItem(item);			// DeleteItem함수를 통해서 Tree에서 item값에 해당하는 노드를 삭제함
		DisplayItem();					// 지우고 나서의 Tree를 출력
	}
	else
		cout << "\t   NO ITEM TO DELETE" << endl;	// 지우려고 하는 값의 node가 없을 경우 
}

void Application::DeleteGenreItem()
{
	SongList s_item;
	GenreList g_item;
	bool found_s;
	bool found_g;
	cout << "\t   INPUT ID AND TITLE TO DELETE ITEM IN GENRE LIST " << endl << endl;
	s_item.SetInfoFromKB();
	g_item.SetGenreNameFromKB();
	g_Tree.RetrieveItem(g_item, found_g);
	if(found_g == true)//입력한 genre랑 일치하는 genre가 존재하는 경우
	{
		BinarySearchTree<class SongList> *temp;
		temp = g_item.GetGenreList();
		temp->RetrieveItem(s_item, found_s);//기존의 genre의 song list에서 입력받은 정보가 있는지 검색
		if(found_s == true)//입력받은 정보가 있는 경우
		{
			g_item.DeleteSongList(s_item);//해당하는 genre에서 입력받은 song list 데이터를 지운다.
			g_Tree.DeleteItem(g_item);//기존의 genre list에서 해당하는 장르를 지운다.
			g_Tree.Add(g_item);//다시 genre list에 genre를 추가 한다.
		}
		else
		{
			cout << "\t   THERER IS NO MATCHED SONG IN GENRE LIST" << endl;
		}
	}
	else
	{
		cout << "\t   THERE IS NO MATCHED GENRE " << endl;
	}
}

void Application::DeleteAlbumItem()
{
	SongList s_item;
	AlbumList al_item;
	bool found_s;
	bool found_al;
	cout << "\t   INPUT ID AND TITLE TO DELETE ITEM IN ALBUM LIST " << endl << endl;
	s_item.SetInfoFromKB();
	al_item.SetAlbumNameFromKB();
	al_Tree.RetrieveItem(al_item, found_al);
	if(found_al == true)//입력한 genre랑 일치하는 genre가 존재하는 경우
	{
		BinarySearchTree<class SongList> *temp;
		temp = al_item.GetAlbumList();
		temp->RetrieveItem(s_item, found_s);//기존의 genre의 song list에서 입력받은 정보가 있는지 검색
		if(found_s == true)//입력받은 정보가 있는 경우
		{
			al_item.DeleteSongList(s_item);//해당하는 genre에서 입력받은 song list 데이터를 지운다.
			al_Tree.DeleteItem(al_item);//기존의 genre list에서 해당하는 장르를 지운다.
			al_Tree.Add(al_item);//다시 genre list에 genre를 추가 한다.
		}
		else
		{
			cout << "\t   THERER IS NO MATCHED SONG IN ALBUM LIST" << endl;
		}
	}
	else
	{
		cout << "\t   THERE IS NO MATCHED ALBUM " << endl;
	}
}

void Application::DeleteArtistItem()
{
	SongList s_item;
	ArtistList ar_item;
	bool found_s;
	bool found_ar;
	cout << "\t   INPUT ID AND TITLE TO DELETE ITEM IN ARTIST LIST " << endl << endl;
	s_item.SetInfoFromKB();
	ar_item.SetArtistNameFromKB();
	ar_Tree.RetrieveItem(ar_item, found_ar);
	if(found_ar == true)//입력한 genre랑 일치하는 genre가 존재하는 경우
	{
		BinarySearchTree<class SongList> *temp;
		temp = ar_item.GetArtistList();
		temp->RetrieveItem(s_item, found_s);//기존의 genre의 song list에서 입력받은 정보가 있는지 검색
		if(found_s == true)//입력받은 정보가 있는 경우
		{
			ar_item.DeleteSongList(s_item);//해당하는 genre에서 입력받은 song list 데이터를 지운다.
			ar_Tree.DeleteItem(ar_item);//기존의 genre list에서 해당하는 장르를 지운다.
			ar_Tree.Add(ar_item);//다시 genre list에 genre를 추가 한다.
		}
		else
		{
			cout << "\t   THERER IS NO MATCHED SONG IN ARTIST LIST" << endl;
		}
	}
	else
	{
		cout << "\t   THERE IS NO MATCHED ARTIST " << endl;
	}
}

void Application::DisplayItem()
{
	DisplayMasterList();
	DisplayGenreList();
	DisplayAlbumList();
	DisplayArtistList();
}

// 현재 Tree의 모든 노드를 출력하는 함수
void Application::DisplayMasterList()
{
	cout << "\t   [PRINT MASTERLIST]" << endl;
	Tree.PrintTree(cout);				// PrintTree함수를 통해서 출력
	cout << endl;
}

void Application::DisplayGenreList()
{
	cout << "\t   [PRINT GENRELIST]" << endl;
	g_Tree.PrintTree(cout);
	cout << endl;
}

void Application::DisplayAlbumList()
{
	cout << "\t   [PRINT ALBUMLIST]" << endl;
	al_Tree.PrintTree(cout);
	cout << endl;
}
void Application::DisplayArtistList()
{
	cout << "\t   [PRINT ARTISTLIST]" << endl;
	ar_Tree.PrintTree(cout);
	cout << endl;
}


void Application::RepalceItem()
{
	MasterType item;
	GenreList g_item;
	AlbumList al_item;
	ArtistList ar_item;
	cout << "\t   INPUT THE TITLE OF THE SONG TO BE UPDATED AND ITS ID : " << endl;
	item.SetIdFromKB();//갱신할 정보를 검색하기 위한 정보를 저장
	item.SetTitleFromKB();
	SongList indata;
	indata.SetInfo(item.GetId(), item.GetTitle());//SongList에 미리 정보를 미리 넘갸서 갱신 후 위치가 바뀌는 list에 넘길 정보를 설정
	bool found;//검색해서 찾았는지를 알려주는 변수
	Tree.RetrieveItem(item, found);
	
	if(found == true)
	{
		string to_search_g = item.GetGenre();//기존의 MasterType의 곡 정보를 검색을 위해서 저장
		string to_search_al = item.GetAlbum();
		string to_search_ar = item.GetArtist();
		Tree.DeleteItem(item);
		item.ResetSongInfoFromKB();//id & title을 제외한 곡의 정보를 재설정하는 함수
		g_item.SetGenreName(item.GetGenre());
		al_item.SetAlbumName(item.GetAlbum());
		ar_item.SetArtistName(item.GetArtist());
		bool found_g;//검색해서 찾았는지를 알려주는 변수;
		bool found_al;
		bool found_ar;
		bool found_s;
		g_Tree.RetrieveItem(g_item, found_g);
		al_Tree.RetrieveItem(al_item, found_al);
		ar_Tree.RetrieveItem(ar_item, found_ar);
		if(found_g == true)
		{
			BinarySearchTree<class SongList> *temp;//노드에 직접 접근해서 해당 노드의 SongList 부분을 수정해주는 방법을 모르겠음.
			temp = g_item.GetGenreList();
			bool found_s;//검색을 위한 변수
			temp->RetrieveItem(indata, found_s);
			if(found_s == true)//Genre의 변경사항이 없음
			{
				cout << "\t   THERE IS NO CHANGE IN GENRE LIST" << endl;
			}
			else//기존의 장르에서 다른 기존 장르로 재설정한 경우
			{
				GenreList g_temp;
				g_item.AddSongList(indata);
				g_Tree.Add(g_item);
				bool found_temp;
				g_temp.SetGenreName(to_search_g);
				g_Tree.RetrieveItem(g_temp, found_temp);
				g_temp.DeleteSongList(indata);
				
			}
		}
		else//기존 리스트에 있는 장르에서 새로운 장르로 재설정한 경우
		{
			g_item.SetGenreName(item.GetGenre());
			g_item.AddSongList(indata);
			g_Tree.Add(g_item);
		}
	if(found_al == true)
		{
			BinarySearchTree<class SongList> *temp;//노드에 직접 접근해서 해당 노드의 SongList 부분을 수정해주는 방법을 모르겠음.
			temp = al_item.GetAlbumList();
			bool found_s;//검색을 위한 변수
			temp->RetrieveItem(indata, found_s);
			if(found_s == true)//Album의 변경사항이 없음
			{
				cout << "\t   THERE IS NO CHANGE IN ALBUM LIST" << endl;
			}
			else//기존의 장르에서 다른 기존 장르로 재설정한 경우
			{
				AlbumList al_temp;
				al_item.AddSongList(indata);
				al_Tree.Add(al_item);
				bool found_temp;
				al_temp.SetAlbumName(to_search_al);
				al_Tree.RetrieveItem(al_temp, found_temp);
				al_temp.DeleteSongList(indata);
				
			}
		}
		else//기존 리스트에 있는 장르에서 새로운 장르로 재설정한 경우
		{
			al_item.SetAlbumName(item.GetAlbum());
			al_item.AddSongList(indata);
			al_Tree.Add(al_item);
		}	
		if(found_ar == true)
		{
			BinarySearchTree<class SongList> *temp;//노드에 직접 접근해서 해당 노드의 SongList 부분을 수정해주는 방법을 모르겠음.
			temp = ar_item.GetArtistList();
			bool found_s;//검색을 위한 변수
			temp->RetrieveItem(indata, found_s);
			if(found_s == true)//Artist의 변경사항이 없음
			{
				cout << "\t   THERE IS NO CHANGE IN ARTIST LIST" << endl;
			}
			else//기존의 장르에서 다른 기존 장르로 재설정한 경우
			{
				ArtistList ar_temp;
				ar_item.AddSongList(indata);
				ar_Tree.Add(ar_item);
				bool found_temp;
				ar_temp.SetArtistName(to_search_ar);
				ar_Tree.RetrieveItem(ar_temp, found_temp);
				ar_temp.DeleteSongList(indata);
				
			}
		}
		else//기존 리스트에 있는 장르에서 새로운 장르로 재설정한 경우
		{
			ar_item.SetArtistName(item.GetArtist());
			ar_item.AddSongList(indata);
			ar_Tree.Add(ar_item);
		}
		Tree.Add(item);
	}
	else
	{
		cout << "\t   THERE IS NO MATCHED DATA" << endl;
	}
}
// Tree에서 찾고자 하는 값의 노드를 검색하는 함수
void Application::SearchItem()
{
	MasterType item;
	cout << "\t   INPUT ID TO SEARCH ITEM : " << endl;
	item.SetIdFromKB();								// 검색하고자 하는 값(Id)을 키보드로부터 입력받음
	item.SetTitleFromKB();// 검색하고자 하는 곡명을 키보드로부터 입력받음

	bool found;										// 겁색여부를 저장할 found
	Tree.RetrieveItem(item, found);					// RetrieveItem 함수를 통해 Tree에서 검색
	if (found == true)								// 찾으면 찾았다는 문구와 함께, 관련 정보까지 출력
	{
		cout << "\t   TARGET ITEM EXISTS IN THE MASTER LIST." << endl;
		item.DisplayRecordOnScreen();
	}
	else
		cout << "\t   TARGET ITEM IS NOT IN THE MASTER LIST." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
}

void Application::SearchByTitleNLyric()//MasterType에서 곡명과 가사로 검색
{
	MasterType item;
	bool found;
	cout << "\t   INPUT THE TITLE AND ID YOU WANT TO FIND " << endl;
	item.SetIdFromKB();
	item.SetTitleFromKB();
	string lyric;
	cout << "\t   PLEASE INPUT THE LYRICS : ";
	getline(cin, lyric);
	Tree.RetrieveItem(item, found);
	if(found == true || item.GetLyric() == lyric)
	{
			cout << "\t   TARGET ITEM EXISTS IN THE MASTER LIST." << endl << endl;
			item.DisplayRecordOnScreen();
	}
	else
	{
		cout << "\t   TARGET ITEM IS NOT IN THE MASTER LIST." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
	}
}

void Application::SearchByGenre()
{
	GenreList g_item;
	cout << "\t   INPUT THE GENRE NAME TO FIND THE SONG" << endl << endl;
	g_item.SetGenreNameFromKB();
	bool found_g;
	g_Tree.RetrieveItem(g_item, found_g);
	if(found_g == true)
	{
		cout << "\t   TARGET GENRE IS IN THE GENRE LIST" << endl << endl;
		g_item.DisplayGenreNameOnScreen();
		g_item.DisplaySongListOnScreen();
	}
	else
	{
		cout << "\t   TARGET GENRE IS NOT IN THE GENRE LIST." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
	}
	
	
}

void Application::SearchByGenreNLyric()
{
	GenreList g_item;
	SongList indata;
	bool found_g;
	bool found_s;
	string lyric;
	g_item.SetGenreNameFromKB();
	indata.SetIdFromKB();
	cout << "\t   PLEASE INPUT THE LYRICS : ";
	getline(cin, lyric);
	g_Tree.RetrieveItem(g_item, found_g);
	if(found_g == true)
	{
		BinarySearchTree<class SongList> *temp;
		temp = g_item.GetGenreList();//songlist의 데이터를 일일이 MasterType에 대입해봐서 가사와 장르가 똑같은 원소가 있는지 검사
		temp->RetrieveItem(indata, found_s);
		if(found_s == true)
		{
			MasterType item;
			bool found;
			item.SetId(indata.GetId());
			item.SetTitle(indata.GetTitle());
			Tree.RetrieveItem(item, found);
			if(item.GetLyric() == lyric)
			{
				cout << "\t   TARGET ITEM IS IN THE LIST" << endl << endl;
				item.DisplayRecordOnScreen();
			}
			else
			{
				cout << "\t   TARGET ITEM IS NOT IN THE LIST" << endl;
			}		
		}
		else
		{
			cout << "\t   TARGET ITEM IS NOT IN THE GENRE'S SONG LIST" << endl;
		}
	}
	else
	{
		cout << "\t   TARGET GENRE IS NOT IN THE GENRE LIST" << endl;
	}

	
}

void Application::SearchByArtist()
{
	ArtistList ar_item;
	cout << "\t   INPUT THE ARTIST NAME TO FIND THE SONG INFO" << endl << endl;
	ar_item.SetArtistNameFromKB();
	bool found_ar;
	ar_Tree.RetrieveItem(ar_item, found_ar);
	if(found_ar == true)
	{
		cout << "\t   TARGET ARTIST IS IN THE ARTIST LIST." << endl << endl;
		ar_item.DisplayArtistNameOnScreen();
		ar_item.DisplaySongListOnScreen();
	}
	else
	{
		cout << "\t   TARGET ARTIST IS NOT IN THE ARTIST LIST." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
	}	
}

void Application::SearchByArtistNGenre()
{
	GenreList g_item;
	ArtistList ar_item;
	SongList indata1;
	SongList indata2;
	bool found_g;
	bool found_ar;
	bool found_s1;
	bool found_s2;
	cout << "\t   INPUT THE ARTIST AND GENRE TO FIND THE SONG INFO" << endl << endl;
	g_item.SetGenreNameFromKB();
	ar_item.SetArtistNameFromKB();
	indata1.SetIdFromKB();
	indata2.SetId(indata1.GetId());
	g_Tree.RetrieveItem(g_item, found_g);
	ar_Tree.RetrieveItem(ar_item, found_ar);
	if(found_g == true && found_ar == true)
	{
		BinarySearchTree<class SongList> * temp_g;
		BinarySearchTree<class SongList> * temp_ar;
		temp_g = g_item.GetGenreList();
		temp_ar = ar_item.GetArtistList();
		temp_g->RetrieveItem(indata1, found_s1);
		temp_ar->RetrieveItem(indata2, found_s2);
		if(indata1.GetId() == indata2.GetId() && indata1.GetTitle() == indata2.GetTitle())
		{
			MasterType item;
			bool found;
			item.SetId(indata1.GetId());
			item.SetTitle(indata1.GetTitle());
			Tree.RetrieveItem(item, found);
			cout << "\t   TARGET ITEM IS IN THE ARTIST AND GNRE LIST" << endl << endl;
			item.DisplayRecordOnScreen();

		}
		else
		{
			cout <<"\t   TARGET ITEM IS NOT IN ARTIST LIST OR GENRE LIST " << endl;
		}
	}
	else
	{
		cout << "\t   THERE IS NO MATCHED ITEM IN ARTIST OR GENRE LIST" << endl;
	}
}

void Application::SearchByAlbum()
{
	AlbumList al_item;
	cout << "\t   INPUT THE ALBUM NAME TO FIND THE SONG INFO" << endl << endl;
	al_item.SetAlbumNameFromKB();
	bool found_al;
	al_Tree.RetrieveItem(al_item, found_al);
	if(found_al == true)
	{
		cout << "\t   TARGET ALBUM IS IN THE ALBUM LIST." << endl << endl;
		al_item.DisplayAlbumNameOnScreen();
		al_item.DisplaySongListOnScreen();
	}
	else
	{
		cout << "\t   TARGET ALBUM IS NOT IN THE ALBUM LIST." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
	}	
}
void Application::SearchByAlbumNLyric()
{
	AlbumList al_item;
	SongList indata;
	bool found_al;
	bool found_s;
	string lyric;
	al_item.SetAlbumNameFromKB();
	indata.SetIdFromKB();
	cout << "\t   PLEASE INPUT THE LYRICS : ";
	getline(cin, lyric);
	al_Tree.RetrieveItem(al_item, found_al);
	if(found_al == true)
	{
		BinarySearchTree<class SongList> *temp;
		temp = al_item.GetAlbumList();//songlist의 데이터를 일일이 MasterType에 대입해봐서 가사와 장르가 똑같은 원소가 있는지 검사
		temp->RetrieveItem(indata, found_s);
		if(found_s == true)
		{
			MasterType item;
			bool found;
			item.SetId(indata.GetId());
			item.SetTitle(indata.GetTitle());
			Tree.RetrieveItem(item, found);
			if(item.GetLyric() == lyric)
			{
				cout << "\t   TARGET ITEM IS IN THE LIST" << endl << endl;
				item.DisplayRecordOnScreen();
			}
			else
			{
				cout << "\t   TARGET ITEM IS NOT IN THE LIST" << endl;
			}		
		}
		else
		{
			cout << "\t   TARGET ITEM IS NOT IN THE ALBUM'S SONG LIST" << endl;
		}
	}
	else
	{
		cout << "\t   TARGET GENRE IS NOT IN THE ALBUM LIST" << endl;
	}
}

void Application::AddPlayList()
{
	MasterType item;
	SongList s_item;
	bool found;
	bool found_s;
	s_item.SetInfoFromKB();
	item.SetId(s_item.GetId());
	item.SetTitle(s_item.GetTitle());
	Tree.RetrieveItem(item, found);
	if(found == true)
	{
		PlayList p_item;
		p_item.SetInfo(item.GetId(), item.GetTitle());
		p_Tree.Add(p_item);
		DisplayPlayList();
	}
	else
	{
		cout << "\t   CAN NOT ADD SONGS : THERE ARE NO SONGS IN THE MASTER LIST " << endl;
	}
}
void Application::DeletePlayList()
{
	SongList s_item;
	PlayList p_item;
	s_item.SetInfoFromKB();
	p_item.SetInfo(s_item.GetId(), s_item.GetTitle());
	p_Tree.Delete(p_item);
	DisplayPlayList();
}
void Application::DisplayPlayList()
{
	cout << "\t   <====== DISPLAY CURRENT PLAY LIST ======>" << endl;
	PlayList p_item;
	DoublyIterator<class PlayList> itor(p_Tree);
	itor.Next(p_item);
	while(itor.NextNotNull())
	{
		p_item.DisplayAll();
		itor.Next(p_item);
	}
}

void Application::ExecutePlayList()
{
	RunPlayer();
}

void Application::PlayMusic()
{
	cout << "\t   <====== PLAY MUSIC ======>" << endl << endl;
	MasterType item;
	bool found;
	while(1)
	{
		if(itor == NULL)
		{
			cout << "\t   <====== MUSIC SETTING ======>" << endl << endl;
			itor = new DoublyIterator<class PlayList>(p_Tree);
			itor->Next();
			break;
			
		}
		else
		{
			PlayList p_temp;
			PlayList *p_item = itor->Current();
			item.SetId(p_item->GetId());
			item.SetTitle(p_item->GetTitle());
			Tree.RetrieveItem(item, found);
			p_temp.SetInfo(p_item->GetId(), p_item->GetTitle());
			playlog.EnQueue(p_temp);
			cout << "\t   <====== PLAYING MUSIC ======>" << endl << endl;
			usleep(1000000);
			item.DisplayTitleOnScreen();	
			usleep(1000000);
			item.DisplayArtistOnScreen();
			usleep(1000000);
			item.DisplayLyricOnScreen();
			usleep(5000000);
			cout << "\t   <====== THE MUSIC IS OVER ======>" << endl << endl;
			return;
		}
	}
	/*else
	{
		if(p_item.GetId() == p_temp.GetId() && p_item.GetTitle() == p_temp.GetTitle())
		{
			item.SetId(p_item.GetId());

			item.SetTitle(p_item.GetTitle());
			Tree.RetrieveItem(item, found);
			item.DisplayTitleOnScreen();	
			item.DisplayArtistOnScreen();
			item.DisplayLyricOnScreen();
		}
		else
		{
			item.SetId(p_temp.GetId());
			item.SetTitle(p_temp.GetTitle());
			Tree.RetrieveItem(item, found);
			item.DisplayTitleOnScreen();	
			item.DisplayArtistOnScreen();
			item.DisplayLyricOnScreen();		
		}
	}*/
}

void Application::StopMusic()
{
	cout << "\t   <======== STOP ========>" << endl << endl;
	RunPlayerInStop();	
	RunPlayer();
}

void Application::MoveForward()//Move Forward가 되지 않음. 한 칸만 움직임
{
	cout << "\t   <====== MOVE FORWARD ======>" << endl << endl;
	if(itor->NextNotNull())
	{
		itor->Next();
	}
	else
	{
		cout << "\t   CAN NOT MOVE TO NEXT SONG" << endl << endl;
	}
}

void Application::MoveBackward()
{
	cout << "\t   <====== MOVE BACKWARD ======>" << endl << endl;
	if(itor->PrevNotNull())
	{
		itor->Prev();
	}
	else
	{
		cout << "\t   CAN NOT MOVE TO PREVIOUS SONG" << endl << endl;
	}
}

void Application::DisplayPlayLog()
{
	playlog.PrintQueue(cout);
}
