

#ifndef MK_H
#define MK_H

#include <deque>
#include <string>
#include <QXmlStreamReader>
#include <src/eksponatmuzealny.h>
//DO usuni�cia jak b�dzie w eksponacie
#include <src/meta.h>

/**
 * @brief
 * Wewn�trza struktiura przechowywania danych. Wybra�em
 * deque z powodu po��czenia zalet z kontener�w vector i list
 */
/*!
 \brief

 \typedef MKontener*/
typedef std::deque<EksponatMuzealny *> MKontener;


/**
 * @brief
 * Klasa MK - MuzdeumKontener zarz�dza i przechowuje dane.
 * Umo�liwia uzyskanie dost�pu do wewn�trznej listy - nie zalecane.
 */
/*!
 \brief

 \class MK muzeumkontener.h "src/muzeumkontener.h"
*/
class MK
{
public:
    /**
     * @brief
     * Klasa jest singletonem. Umo�liwa dost�p tylko
     * metod� getInstance()
     */
    /*!
     \brief

     \fn getInstance
    */
    static MK& getInstance();
    /**
     * @brief
     * Dodaje element do listy. Nie wykonuje sprawdzenia.
     * @param e
     */
    /*!
     \brief

     \fn addItem
     \param e
    */
    void addItem(EksponatMuzealny *e);
    /**
     * @brief
     * Usuwa element o zadanym identyfikatorze, elementu klasy
     * EksponatMuzealny. Nie jest to r�wnoznaczne identyfikatorowi
     * elementu w li�cie!
     * @param id
     */
    /*!
     \brief

     \fn deleteItem
     \param id
    */
    bool deleteItem(int id);
    /**
     * @brief
     * Usuwa wszyskie elementy z listy.
     */
    /*!
     \brief

     \fn deleteAll
    */
    void deleteAll();
    /**
     * @brief
     * Zwraca wska�nik do elementu o zadanym identyfikatorze
     * eksponatu. Nie jest to r�wnoznaczne z identyfikatorem
     * elementu na li�cie!
     * @param id
     */
    /*!
     \brief

     \fn operator []
     \param id
    */
    EksponatMuzealny* operator[] (int id);
    /**
     * @brief
     * Zwraca wska�nik do wewn�trznej listy.
     * U�ywa� ostro�nie!
     */
    /*!
     \brief

     \fn getList
    */
    MKontener* getList();
    /**
     * @brief
     * Zapisuje wewn�trzn� listu do pliku o zadanej nazwie.
     * Wywo�uje zewn�trzn� funkcj�.
     * @param filename
     */
    /*!
     \brief

     \fn countByTyp
     \param typ
    */
    int countByTyp(Meta::Typ typ);
    /*!
     \brief

     \fn count
    */
    int count();
    /*!
     \brief

     \fn getObjectOfTyp
     \param typ
    */
    EksponatMuzealny* getObjectOfTyp(Meta::Typ typ);
    /*!
     \brief

     \fn next
     \param typ
    */
    EksponatMuzealny* next(Meta::Typ typ);
    /*!
     \brief

     \fn saveToFile
     \param filename
    */
    void saveToFile(std::string filename);
    /**
     * @brief
     * Odczytwuje plik zewn�trzn� funkcj� do listy.
     * @param filename
     */
    /*!
     \brief

     \fn readFromFile
     \param filename
    */
    void readFromFile(std::string filename);
private:
    /**
 * @brief
 * SINGLETON - Prywatny konstruktor.
 */
/*!
 \brief

 \fn MK
*/
    MK();
    /**
 * @brief
 * SINGLETON - Prywatny konstruktor kopiuj�cy.
 * @param
 */
/*!
 \brief

 \fn MK
 \param
*/
    MK(const MK&);
    /**
    * @brief
    * SINGLETON - prywatny opertator przypisania/
    * @param
    */
    /*!
     \brief

     \fn operator =
     \param
    */
    MK& operator=(const MK&);
    static MKontener m_kontener; /** Lista przechowuj�ca dane */ /*!< TODO */
private:
    MKontener::iterator itForTyp; /*!< TODO */
    /*!
     \brief

     \fn paraseAttributesAndAdd
     \param Meta::Typ
     \param attr
    */
    void paraseAttributesAndAdd(Meta::Typ,QXmlStreamAttributes* attr);
};

#endif // MK_H
