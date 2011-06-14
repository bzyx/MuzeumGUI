

#ifndef MK_H
#define MK_H

#include <deque>
#include <string>
#include <src/eksponatmuzealny.h>

/**
 * @brief
 * Wewnêtrza struktiura przechowywania danych. Wybra³em
 * deque z powodu po³¹czenia zalet z kontenerów vector i list
 */
typedef std::deque<EksponatMuzealny *> MKontener;


/**
 * @brief
 * Klasa MK - MuzdeumKontener zarz¹dza i przechowuje dane.
 * Umo¿liwia uzyskanie dostêpu do wewnêtrznej listy - nie zalecane.
 */
class MK
{
public:
    /**
     * @brief
     * Klasa jest singletonem. Umo¿liwa dostêp tylko
     * metodê getInstance()
     */
    static MK& getInstance();
    /**
     * @brief
     * Dodaje element do listy. Nie wykonuje sprawdzenia.
     * @param e
     */
    void addItem(EksponatMuzealny *e);
    /**
     * @brief
     * Usuwa element o zadanym identyfikatorze, elementu klasy
     * EksponatMuzealny. Nie jest to równoznaczne identyfikatorowi
     * elementu w liœcie!
     * @param id
     */
    bool deleteItem(int id);
    /**
     * @brief
     * Usuwa wszyskie elementy z listy.
     */
    void deleteAll();
    /**
     * @brief
     * Zwraca wskaŸnik do elementu o zadanym identyfikatorze
     * eksponatu. Nie jest to równoznaczne z identyfikatorem
     * elementu na liœcie!
     * @param id
     */
    EksponatMuzealny* operator[] (int id);
    /**
     * @brief
     * Zwraca wskaŸnik do wewnêtrznej listy.
     * U¿ywaæ ostro¿nie!
     */
    MKontener* getList();
    /**
     * @brief
     * Zapisuje wewnêtrzn¹ listu do pliku o zadanej nazwie.
     * Wywo³uje zewnêtrzn¹ funkcjê.
     * @param filename
     */
    void saveToFile(std::string filename);
    /**
     * @brief
     * Odczytwuje plik zewnêtrzn¹ funkcj¹ do listy.
     * @param filename
     */
    void readFromFile(std::string filename);
private:
/**
 * @brief
 * SINGLETON - Prywatny konstruktor.
 */
   MK();
/**
 * @brief
 * SINGLETON - Prywatny konstruktor kopiuj¹cy.
 * @param
 */
   MK(const MK&);
   /**
    * @brief
    * SINGLETON - prywatny opertator przypisania/
    * @param
    */
   MK& operator=(const MK&);
   static MKontener m_kontener; /** Lista przechowuj¹ca dane */

};

#endif // MK_H
