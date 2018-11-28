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
	cout << "\t   5 : Add Song in each List" << endl;
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
	string data;
	cout << "Enter music to add to the user list : " << endl;
	MasterType item;
	item.SetTitleFromKB();
	item.SetIdFromKB();
	GenreList g_item;
	AlbumList al_item;
	ArtistList ar_item;
	SongList indata;
	bool found;
	Tree.RetrieveItem(item, found);
	g_item.SetGenreName(item.GetGenre());
	ar_item.SetArtistName(item.GetArtist());
	al_item.SetAlbumName(item.GetAlbum());

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