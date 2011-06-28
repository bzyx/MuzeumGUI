

#ifndef MK_H
#define MK_H

#include <deque>
#include <string>
#include <QXmlStreamReader>
#include <src/eksponatmuzealny.h>
//DO usuniêcia jak bêdzie w eksponacie
#include <src/meta.h>

/**
 * @brief
 * Wewnêtrza struktiura przechowywania danych. Wybra³em
 * deque z powodu po³¹czenia zalet z kontenerów vector i list
 */
/*!
 \brief

 \typedef MKontener*/
typedef std::deque<EksponatMuzealny *> MKontener;


/**
 * @brief
 * Klasa MK - MuzdeumKontener zarz¹dza i przechowuje dane.
 * Umo¿liwia uzyskanie dostêpu do wewnêtrznej listy - nie zalecane.
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
     * Klasa jest singletonem. Umo¿liwa dostêp tylko
     * metodê getInstance()
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
     * EksponatMuzealny. Nie jest to równoznaczne identyfikatorowi
     * elementu w liœcie!
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
     * Zwraca wskaŸnik do elementu o zadanym identyfikatorze
     * eksponatu. Nie jest to równoznaczne z identyfikatorem
     * elementu na liœcie!
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
     * Zwraca wskaŸnik do wewnêtrznej listy.
     * U¿ywaæ ostro¿nie!
     */
    /*!
     \brief

     \fn getList
    */
    MKontener* getList();
    /**
     * @brief
     * Zapisuje wewnêtrzn¹ listu do pliku o zadanej nazwie.
     * Wywo³uje zewnêtrzn¹ funkcjê.
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
     * Odczytwuje plik zewnêtrzn¹ funkcj¹ do listy.
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
 * SINGLETON - Prywatny konstruktor kopiuj¹cy.
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
    static MKontener m_kontener; /** Lista przechowuj¹ca dane */ /*!< TODO */
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
