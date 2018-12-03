#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "BinarySearchTree.h"
#include "MasterType.h"
#include "GenreList.h"
#include "ArtistList.h"
#include "AlbumList.h"
#include "SongList.h"
#include "PlayList.h"
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"
#include "CircularQueueType.h"
#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;

class Application
{
public:
	// 생성자
	Application() 
	{
		command = 0;
		playmode = 0;
		playmodeinstop = 0;
		menu_add = 0;
		menu_delete = 0;
		menu_dis = 0;
		menu_search = 0;
		menu_player = 0;
		itor = NULL;
	}
	// 소멸자
	~Application()
	{	
		delete itor;
	}

	// Application 실행 함수
	void Run();

	void SelectAddMenu();

	void SelectDeleteMenu();

	void SelectDisplayMenu();

	void SelectSearchMenu();

	void SelectPlayerMenu();

	void RunPlayer();//MusicPlayer 실행 함수

	void RunPlayerInStop();//Stop 상황에서 MusicPlayer 실행 함수
	
	/**
	*	@brief	command 번호를 입력받음
	*	@pre	none
	*	@post	command 값이 저장됨
	*	@return command 값을 리턴함
	*/
	int GetCommand();

	int GetAddCommand();

	int GetDeleteCommand();

	int GetDisplayCommand();

	int GetSearchCommand();

	int GetPlayerCommand();

	int GetPlayModeCommand();//Play 명령을 받아온다.

	int GetPlayModeCommandInStop();//Stop 상황에서 명령을 받는다.



	/**
	*	@brief	Tree에 item을 추가
	*	@pre	none
	*	@post	Tree에 item이 추가됨
	*/
	void InsertItem();

	/**
	*	@brief	Tree에서 item을 지움
	*	@pre	none
	*	@post	Tree에서 item이 지워짐
	*/

	void Add();
	//MasterType에서 제목을 검색해서 해당 데이터들을 Album & Genre & Artist 리스트에 추가한다.

	void RemoveItem();//MasterType에서 곡들을 삭제해서 각 리스트에서도 해당 곡을 삭제한다.

	void DeleteGenreItem();//GenreList의 SongList 속에있는 item을 지운다.

	void DeleteAlbumItem();//AlbumList의 SongList 속에있는 item을 지운다.

	void DeleteArtistItem();//ArtistList의 SongList 속에있는 item을 지운다.


	/**
	*	@brief	Tree의 모든 item을 출력함
	*	@pre	none
	*	@post	Tree의 모든 노드들이 출력됨
	*/
	void DisplayItem();

	/**
	*	@brief	Tree에서 item이 있는지 검색함
	*	@pre	none
	*	@post	Tree에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void DisplayMasterList();//MasterList 출력

	void DisplayGenreList();//GenreList 출력

	void DisplayAlbumList();//AlbumList 출력

	void DisplayArtistList();//ArtistList 출력

	void DisplayAllList();//모든 리스트를 출력

	void DisplaySongDetailInfo();//선택된 곡의 모든 정보를 출력

	void RepalceItem();// List에 있는 기존의 item들을 곡명과 id를 입력받아 찾은 후 해당 노드의 변수들을 다시 재설정한다.

	void SearchItem();

	void SearchByTitleNLyric();//MasterType에서 곡명과 가사를 사용하여 곡의 정보를 검색

	void SearchByGenre();//GenreList에서 장르명을 사용하여 장르명이 일치하는 곡의 정보를 모두 출력

	void SearchByGenreNLyric();//GenreList에서 장르와 가사를 사용하여 곡의 정보를 검색

	void SearchByArtist();//ArtitsList에서 아티스트명을 사용하여 아티스트명이 일치하는 곡의 정보를 모두 출력

	void SearchByArtistNGenre();//ArtistList와 GenreList에서 겹치는 곡의 정보를 출력

	void SearchByAlbum();//AlbumList에서 앨범명을 사용하여 얄범명이 일치하는 곡의 정보를 모두 출력

	void SearchByAlbumNLyric();//AlbumList에서 장르와 가사를 사용하여 곡의 정보를 검색


	void AddPlayList();//PlayList에 곡 추가

	void DeletePlayList();//PlayList에서 곡 삭제

	void DisplayPlayList();//현재 PlayList를 출력

	void ExecutePlayList();//PlayList의 음악을 실행시킨다

	void PlayMusic();//음악을 재생한다.

	void StopMusic();//음악 재생을 멈춘다.

	void MoveForward();//다음 곡으로 넘어가는 기능

	void MoveBackward();//이전 곡으로 되돌아가는 기능

	void DisplayPlayLog();// 현재부터 30개 이전까지의 재생했던 곡을 출력

	
	
private:
	BinarySearchTree<class MasterType> Tree;
	// MasterType 객체
	BinarySearchTree<class GenreList> g_Tree;
	// GenreList 객체
	BinarySearchTree<class AlbumList> al_Tree;
	// AlbumList 객체
	BinarySearchTree<class ArtistList> ar_Tree;
	// ArtistList 객체 
	DoublySortedLinkedList<class PlayList> p_Tree;
	// 재생했던 곡을 저장 해놓아서  비교하는 용도로 쓸 객체
	DoublyIterator<class PlayList>* itor;
	// PlayList의 현재 재생 곡을 보관하는 인덱스 객체
	CircularQueueType<class PlayList> playlog;
	
	// PlayList의 현재 재생 곡을 저장하는 객체
	int command;							// command
	int playmode;
	int playmodeinstop;
	int menu_add;
	int menu_delete;
	int menu_dis;
	int menu_search;
	int menu_player;

};
#endif