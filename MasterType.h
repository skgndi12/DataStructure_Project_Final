#ifndef _MASTERLIST_H
#define _MASTERLIST_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 *  두 항목간의 비교
 */


/**
 * 항목 정보 클래스
 */

class MasterType
{
    public:
        /**
         *기본 생성자
         */
        MasterType()
        {
            id = -1;
            title = "";
            artist = "";
            album = "";
            genre = "";
            lyric = "";
        }

        /**
         *소멸자
         */

        ~MasterType(){}

       /* MasterType& operator=(const MasterType& other)
        {
            song_num = other.song_num; 
            music = other.music;
            artist = other.artist;
            album = other.album;
            genre = other.genre;
            return *this;
        }*/

        /**
         *  @brief  곡명
         *  @pre    곡명 설정
         *  @post   없음
         *  @return 곡명 반환
         */


        int GetId();

        string GetTitle();

        /**
         *  @brief 가수명을 가져옴
         *  @pre 가수명이 설정
         *  @post   없음
         *  @return  가수명
         */

        string GetArtist();

        /**
         *  @brief 앨범명을 가져옴
         *  @pre 앨범명이 설정
         *  @post   없음
         *  @return 앨범명을 반환
         */

        string GetAlbum();

        /**
         *  @brief 장르명을 가져옴
         *  @pre 장르명을 설정
         *  @post   없음
         *  @return 장르명을 반환
         */

        string GetGenre();
        /**
         *  @brief 곡명을 설정
         *  @pre 없음
         *  @post   곡명을 설정
         *  @param  
         */

        string GetLyric();

        void SetId(int in_id);
        


        void SetTitle(string in_title);


        /**
         *  @brief 가수명을 설정
         *  @pre 없음
         *  @post   가수명이 설정
         *  @param  in_artist 가수명
         */
        
        void SetArtist(string in_artist);


        /**
         *  @brief 앨범명를 설정
         *  @pre 없음
         *  @post   앨범명를 설정
         *  @param  in_album 앨범명
         */
        void SetAlbum(string in_album);

        /**
         * @brief   장르명를 설정
         * @pre     없음
         * @post    장르명가 설정
         * @param   in_album 
         */

        void SetGenre(string in_genre);

        void SetLyric(string in_lyric);

        void SetRecord(int in_id, string in_title, string in_artist, string in_album,string in_genre,string in_lyric);

        /**
         *  @brief 화면에 곡명을 보여줌
         *  @pre    곡명이 설정
         *  @post   곡명을 화면에 띄움
         */

        void DisplayIdOnScreen();

        void DisplayTitleOnScreen();

         /**
         *  @breif  화면에 가수을 보여줌
         *  @pre    가수명이 설정
         *  @post   가수명을 화면에 띄움
         */

        void DisplayArtistOnScreen();

        /**
         *  @breif  화면에 앨범명를 보여줌
         *  @pre    앨범명를 설정
         *  @post   앨범명를 화면에 띄움
         */

        void DisplayAlbumOnScreen();

    

        /**
         *  @breif  화면에 장르명을 보여줌
         *  @pre    장르명을 설정
         *  @post   장르명을 화면에 띄움
         */

        void DisplayGenreOnScreen();
        /**             * @brief   화면에 곡의 정보들을 보여줌
         * @pre     곡의 정보들들을 설정
         * @post    곡의 정보들을 화면에 띄움
         */

        
        void DisplayLyricOnScreen();


        void DisplayRecordOnScreen();

    /**
     *  @breif  곡명을 키보드로부터 설정
     *  @pre    없음
     *  @post   곡명이 설정
     */
    void SetIdFromKB();

    void SetTitleFromKB();

    /**
     * @brief   가수명을 키보드로부터 설정
     * @pre     없음
     * @post    가수명이 설정
     */

    void SetArtistFromKB();

    /**
     * @brief   앨범명를 키보드로부터 설정
     * @pre     없음
     * @post    앨범명이 설정
     */

    void SetAlbumFromKB();

    /**
     * @brief   장르명을 키보드로부터 설정
     * @pre     없음
     * @post    장르명이 설정
     */

    void SetGenreFromKB();

    /**
     * @brief   곡의 정보들을 키보드로부터 입력
     * @pre     없음
     * @post    곡의 정보들이 설정
     */

    void SetLyricFromKB();



    void SetRecordFromKB();

    /**
     * @brief   파일로부터 기록을 읽음
     * @pre     타겟 파일이 열려있어야 됨
     * @post    곡의 정보들이 설정
     * @param   fin file descriptor
     * @return  이 함수가 기능을 잘한다면 1을 반환 그렇지 않다면 0을 반환.
     */

    int ReadDataFromFile(ifstream& fin);

    /**
     * @brief   기록을 파일안에 쓴다.
     * @pre     타겟 파일이 열려있고 리스트는 초기화 되어야됨
     * @post    타겟 파일은 새로운 곡의 정보들이 포함되어야함
     * @param   fout file descriptor
     * @return  이 함수가 기능을 잘한다면 1을 반환 그렇지 않다면 0을 반환.
     */

    int WriteDataToFile(ofstream& fout);

    /**
     * itemtype을 비교한다
     * @brief   두 item types를 item id로 비교한다
     * @pre     두 item type들은 반드시 초기화 되어야한다
     * @post    타겟 파일은 새로운 기록을 포함하여야한다.
     * @param   data target item for comparing
     * return   return SMALL if this.id < data.id,
     *          return BIG if this.id > data.id,
     *          otherwise return EQUAL
     */
    

    /** 
     * @brief   목표 데이터를 삭제한다.
     * @pre     삭제되야할 데이터의 학번이 입력되어야한다.
     * @post    목표 데이터가 삭제
     */

    string to_string() const;//MasterType의 데이터를 모두 string으로 바꾼다.

    bool operator>(MasterType item);


    bool operator<(MasterType item);


    bool operator==(MasterType item);

private:
    int id;
    string title;
    string artist;    
    string album;  
    string genre;
    string lyric;
};

#endif // _MASTERLIST_H