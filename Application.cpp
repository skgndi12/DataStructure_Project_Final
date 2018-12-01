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
			InsertItem();
			break;
		case 2:
			RemoveItem();
			break;
		case 3:
			DisplayItem();
			break;
		case 4:
			Add();
			break;
		case 5:
			RepalceItem();
			break;
		case 6:
			DeleteGenreItem();
			break;
		case 7:
			DeleteAlbumItem();
			break;
		case 8:
			DeleteArtistItem();
			break;
		case 9:
			SearchItem();
			break;
		case 10:
			SearchByTitleNLyric();
			break;
		case 11:
			SearchByGenre();
			break;
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
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Item to the Master List" << endl;
	cout << "\t   2 : Delete Item to the Master List" << endl;
	cout << "\t   3 : Display Item" << endl;
	cout << "\t   4 : Add Song in All List" << endl;
	cout << "\t   5 : Update Song in All List" << endl;
	cout << "\t   6 : Delete Song in Genre List" << endl;
	cout << "\t   7 : Delete Song in Album List" << endl;
	cout << "\t   8 : Delete Song in Artist List" << endl;
	cout << "\t   9 : Search By Title in Master List" << endl;
	cout << "\t   10 : Search By Title N Lyric in Master List" << endl;
	cout << "\t   11 : Search By Genre in Genre List" << endl;
	cout << "\t   12 : Search By Genre N Lyric in Genre List" << endl;
	cout << "\t   13 : Search By Artist in Artist List" << endl;
	cout << "\t   14 : Search By Artist N Genre in Master List" << endl;
	cout << "\t   15 : Search By Album in Album List" << endl;
	cout << "\t   16 : Search By Album N Lyric in Master List " << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	getline(cin, command);
	cout << endl;
	return stoi(command);
}

// Tree에 item을 추가하는 함수 
void Application::InsertItem()
{
	MasterType item;
	cout << "Insert Item : " << endl;
	item.SetRecordFromKB();				// Tree에 추가할 item 값을 키보드로부터 입력받음
	Tree.Add(item);						// Add함수를 통해서 item을 Tree에 추가함
	DisplayItem();						// 현재 Tree의 node를 모두 출력함
}

void Application::Add()
{
	cout << "Enter music to add to the user list : " << endl;
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
		else
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
		cout << "There is no matched data" << endl;
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
	cout << "Input Id and Title to delete item : " << endl;
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
				cout << "There is no matched Song in Genre List" << endl;
			}
		}
		else//해당하는 genre가 없을 경우
		{
			cout << "There is no matched Genre" << endl;
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
				cout << "There is no matched Song in Album List" << endl;
			}
		}
		
		else//해당하는 album이 없을 경우
		{
			cout << "There is no matched Album" << endl;
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
				cout << "There is no matched Song in Artist List" << endl;
			}
		}
		else//해당하는 artist이 없을 경우
		{
			cout << "There is no matched Artist" << endl;
		}	
		Tree.DeleteItem(item);			// DeleteItem함수를 통해서 Tree에서 item값에 해당하는 노드를 삭제함
		DisplayItem();					// 지우고 나서의 Tree를 출력
	}
	else
		cout << "No item to delete" << endl;	// 지우려고 하는 값의 node가 없을 경우 
}

void Application::DeleteGenreItem()
{
	SongList s_item;
	GenreList g_item;
	bool found_s;
	bool found_g;
	cout << "Input Id and Title to Delete Item in Genre List " << endl << endl;
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
			cout << "There is no matched Song in Genre List" << endl;
		}
	}
	else
	{
		cout << "There is no matched Genre " << endl;
	}
}

void Application::DeleteAlbumItem()
{
	SongList s_item;
	AlbumList al_item;
	bool found_s;
	bool found_al;
	cout << "Input Id and Title to Delete Item in Album List " << endl << endl;
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
			cout << "There is no matched Song in Album List" << endl;
		}
	}
	else
	{
		cout << "There is no matched Album " << endl;
	}
}

void Application::DeleteArtistItem()
{
	SongList s_item;
	ArtistList ar_item;
	bool found_s;
	bool found_ar;
	cout << "Input Id and Title to Delete Item in Artist List " << endl << endl;
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
			cout << "There is no matched Song in Artist List" << endl;
		}
	}
	else
	{
		cout << "There is no matched Artist " << endl;
	}
}

// 현재 Tree의 모든 노드를 출력하는 함수
void Application::DisplayItem()
{
	Tree.PrintTree(cout);				// PrintTree함수를 통해서 출력
	g_Tree.PrintTree(cout);
	ar_Tree.PrintTree(cout);
	al_Tree.PrintTree(cout);
}

void Application::RepalceItem()
{
	MasterType item;
	GenreList g_item;
	AlbumList al_item;
	ArtistList ar_item;
	cout << "Enter the title of the song to be updated and its ID : " << endl;
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
				cout << "There is no change in Genre List" << endl;
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
				cout << "There is change in Album List" << endl;
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
				cout << "There is change in Artist List" << endl;
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
		cout << "There is no matched data" << endl;
	}
}
// Tree에서 찾고자 하는 값의 노드를 검색하는 함수
void Application::SearchItem()
{
	MasterType item;
	cout << "Input Id to search item : " << endl;
	item.SetIdFromKB();								// 검색하고자 하는 값(Id)을 키보드로부터 입력받음
	item.SetTitleFromKB();// 검색하고자 하는 곡명을 키보드로부터 입력받음

	bool found;										// 겁색여부를 저장할 found
	Tree.RetrieveItem(item, found);					// RetrieveItem 함수를 통해 Tree에서 검색
	if (found == true)								// 찾으면 찾았다는 문구와 함께, 관련 정보까지 출력
	{
		cout << "Target item exists in the Master list." << endl;
		item.DisplayRecordOnScreen();
	}
	else
		cout << "Target item is not in the Master list." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
}

void Application::SearchByTitleNLyric()//MasterType에서 곡명과 가사로 검색
{
	MasterType item;
	bool found;
	cout << "Input the Title and ID you want to find ";
	item.SetIdFromKB();
	item.SetTitleFromKB();
	string lyric;
	cout << "Please Input the lyrics : ";
	getline(cin, lyric);
	Tree.RetrieveItem(item, found);
	if(found == true || item.GetLyric() == lyric)
	{
			cout << "Target item exists in the Master list." << endl;
			item.DisplayRecordOnScreen();
	}
	else
	{
		cout << "Target item is not in the Master list." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
	}
}

void Application::SearchByGenre()
{
	MasterType item;
	GenreList g_item;
	SongList indata;
	bool found;
	bool found_g;
	bool found_s;
	item.SetIdFromKB();
	item.SetTitleFromKB();
	g_item.SetGenreName(item.GetGenre());
	Tree.RetrieveItem(item, found);
	if(found == true)
	{
		g_Tree.RetrieveItem(g_item, found_g);
		if(found_g == true)
		{
			BinarySearchTree<class SongList> * temp;
			temp = g_item.GetGenreList();
			temp->RetrieveItem(indata, found_s);
			if(found_s == true)
			{
				cout << "Target item exists in the Genre list." << endl;
				item.DisplayRecordOnScreen();
			}
			else
			{
				cout << "Target item exists in the Genre list." << endl;
			}
		}
		else
		{
			cout << "There is no matched Genre" << endl;
		}
	}
	else
	{
		cout << "There is no matched Song in Master List" << endl;
	}
}