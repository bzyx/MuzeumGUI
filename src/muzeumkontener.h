

#ifndef MK_H
#define MK_H

#include <deque>
#include <string>
#include <src/eksponatmuzealny.h>

/**
 * @brief
 * Wewn�trza struktiura przechowywania danych. Wybra�em
 * deque z powodu po��czenia zalet z kontener�w vector i list
 */
typedef std::deque<EksponatMuzealny *> MKontener;


/**
 * @brief
 * Klasa MK - MuzdeumKontener zarz�dza i przechowuje dane.
 * Umo�liwia uzyskanie dost�pu do wewn�trznej listy - nie zalecane.
 */
class MK
{
public:
    /**
     * @brief
     * Klasa jest singletonem. Umo�liwa dost�p tylko
     * metod� getInstance()
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
     * EksponatMuzealny. Nie jest to r�wnoznaczne identyfikatorowi
     * elementu w li�cie!
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
     * Zwraca wska�nik do elementu o zadanym identyfikatorze
     * eksponatu. Nie jest to r�wnoznaczne z identyfikatorem
     * elementu na li�cie!
     * @param id
     */
    EksponatMuzealny* operator[] (int id);
    /**
     * @brief
     * Zwraca wska�nik do wewn�trznej listy.
     * U�ywa� ostro�nie!
     */
    MKontener* getList();
    /**
     * @brief
     * Zapisuje wewn�trzn� listu do pliku o zadanej nazwie.
     * Wywo�uje zewn�trzn� funkcj�.
     * @param filename
     */
    void saveToFile(std::string filename);
    /**
     * @brief
     * Odczytwuje plik zewn�trzn� funkcj� do listy.
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
 * SINGLETON - Prywatny konstruktor kopiuj�cy.
 * @param
 */
   MK(const MK&);
   /**
    * @brief
    * SINGLETON - prywatny opertator przypisania/
    * @param
    */
   MK& operator=(const MK&);
   static MKontener m_kontener; /** Lista przechowuj�ca dane */

};

#endif // MK_H
