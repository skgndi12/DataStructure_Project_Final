#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "BinarySearchTree.h"
#include "MasterType.h"
#include "GenreList.h"
#include "ArtistList.h"
#include "AlbumList.h"
#include "SongList.h"
#include <string>
#include <iostream>
#include <string>
using namespace std;

class Application
{
public:
	// 생성자
	Application() 
	{
		command = 0;
	}
	// 소멸자
	~Application(){}

	// Application 실행 함수
	void Run();
	
	/**
	*	@brief	command 번호를 입력받음
	*	@pre	none
	*	@post	command 값이 저장됨
	*	@return command 값을 리턴함
	*/
	int GetCommand();

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
	void RemoveItem();

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
	void SearchItem();

private:
	BinarySearchTree<class MasterType> Tree;
	// MasterType 객체
	BinarySearchTree<class GenreList> g_Tree;
	// GenreList 객체
	BinarySearchTree<class AlbumList> al_Tree;
	BinarySearchTree<class ArtistList> ar_Tree;
	int command;							// command

};
#endif