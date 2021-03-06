#include <vector>
#include <iostream>
#include "tinyutf8.h"
#include <list>

//Stores the information about the given word
typedef struct wordData {
    utf8_string word;
    float weight;
    int occurrences; //Number of occurences
    int score;  //Accumulated score

    wordData() :
    word(""), weight(0.0), occurrences(0), score(0) { }

} wordData;

//Estrutura utilizada durante o processo de rehashing
typedef struct status{
    bool ocupado;
    bool livre;
    bool realocado;

    status():
        ocupado(false), livre(true), realocado (false)
        {}

}STATUS;

class Dictionary {
private:
    int maxSize;
    int currentSize;
    std::vector <wordData> table;   //Table that stores the registers

public:
    //HASH E NÃO HUSH HUSH HUSH(pussycat dools) [Generates the place to where the word belongs]
    unsigned int hash1(utf8_string key);
    unsigned int hash2 (utf8_string key);

    //Change the size of the dictionary (maxsize), will be used in rehash
    void setMaxSize(int newSize);

    //Returns a bool that indicates if the dictionary needs re-hash or not;
    bool needReHash();

    //Returns true if a given hash key is empty in the table
    bool isEmpty(unsigned int key);

    //Verify if the given number is prime
    bool isPrime(int number);

    //Finds the next prime number forwards actualNumber
    int nextPrime(int actualNumber);

    //Realoca posicao em nova tabela de um dado elemento
    void realocaPosicao(int posicao, std::vector <STATUS>& controle);

    //Re-hash funcion
    void resizeDictionary();

    //Realiza o processo de rehash quando necessario
    void reHash();

public:
    //Default constructor for dictionary
    Dictionary();

    //Insert wordData
    int insertWord(wordData newWord);

    //Retrieve wordData
    wordData retrieveWordData(utf8_string word);

    //Returns hash key for a given word
    int find(utf8_string word);

};



