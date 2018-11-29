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
			SearchItem();
			break;
		case 5:
			Add();
			break;
		case 6:
			RepalceItem();
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
	cout << "\t   1 : Add Item" << endl;
	cout << "\t   2 : Delete Item" << endl;
	cout << "\t   3 : Display Item" << endl;
	cout << "\t   4 : Search Item" << endl;
	cout << "\t   5 : Add Song in each list" << endl;
	cout << "\t   6 : Update song in each list" << endl;
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
	cout << "Input Id to delete item : " << endl;
	item.SetIdFromKB();					// Tree에서 지우려고 하는 item 값을 키보드로부터 입력받음

	bool found;							// 검색여부에 따른 결과를 저장할 found
	Tree.RetrieveItem(item, found);		// RetrieveItem 함수를 통해서 Tree에서 검색

	if (found == true)					// Tree에 item이 있으면
	{
		Tree.DeleteItem(item);			// DeleteItem함수를 통해서 Tree에서 item값에 해당하는 노드를 삭제함
		DisplayItem();					// 지우고 나서의 Tree를 출력
	}
	else
		cout << "No item to delete" << endl;	// 지우려고 하는 값의 node가 없을 경우 
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
				cout << "There is change in Genre List" << endl;
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

	bool found;										// 겁색여부를 저장할 found
	Tree.RetrieveItem(item, found);					// RetrieveItem 함수를 통해 Tree에서 검색
	if (found == true)								// 찾으면 찾았다는 문구와 함께, 관련 정보까지 출력
	{
		cout << "Target item exists in the list." << endl;
		item.DisplayRecordOnScreen();
	}
	else
		cout << "Target item is not in the list." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
}