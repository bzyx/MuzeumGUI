#ifndef EKSPONATMUZEALNY_H
#define EKSPONATMUZEALNY_H
#include <string>
#include <QPair>
#include <QList>

class QStringList;
class QString;


/**
 * @brief
 * G��wna klasa nadaj�ca interfejs wszyskim klas� pochodnym
 * jakie zostan� z niej wyprowadzone.
 */
/**
 * @brief
 *
 */
class EksponatMuzealny
{
public:
    /**
     * @brief
     * Okre�la typ elementu jaki jest przechowywany w wektorze (zamiast RTTI)
     */
    typedef enum {NieOkreslonoTypu=-1, Obraz=5, PrzedmiotUzytkowy,
                  Rzezba, Mebel, Rekopis, Starodruk } Typ;
    /**
     * @brief
     * Record to file - struktura do zapisu danych do pliku XML
     */
    typedef QPair<QString, QString> krotka;
    typedef QList<krotka> r2f;
    /**
     * @brief
     * Okre�la rodzaj materia�u z jakego jest wykonay przedmiot
     * wymagana ponowna komplilacja aby doda� nowy typ :(
     */
    typedef enum {NieOkreslonoMaterialu=-1, Braz=5, Drewno, Gips,
                  Glina, Granit, Marmur, Metal, Mosiadz,
                  Piaskowiec, Srebro, Zloto } Material;
    /**
     * @brief
     * Okre�la format zapisu daty. Nie mo�na przechowywa� datetime poniewa�
     * niekt�re z eksponat�w mog� by� znane tylko z
     * wieku (w), roku (r), miesi�ca i roku (mr),
     * dnia miesiaca i roku (dmr)
     * w, r, mm.rr, dd.mm.rrrr
     */
    typedef enum {w=5,r,mr,dmr} FormatDaty;

private:
    /**
      /var m_lastid przechowuje ostatnio nadany identyfikator
    */
    static int m_lastid;
    int m_id;
    std::string m_nazwa;
    bool m_wystawiony;
    std::string m_opis;
    std::string m_polozenie;
    int m_wartosc;
    Typ m_typ;
    FormatDaty m_FormatDaty;
    std::string m_data;
public:
    /**
     * @brief
     *  Zwraca identyfikator obiektu
     */
    int getId();
    /**
     * @brief
     *  Ustawia identyfikator obiektu (nie u�ywa�)
     * @param id
     */
    void id(int id);
    /**
     * @brief
     * Zwraca nazw�/tytu� obiektu
     */
    std::string getNazwa();
    /**
     * @brief
     * Ustawia nazw�/tytu� obiektu
     * @param nazwa
     */
    void nazwa(std::string nazwa);
    /**
     * @brief
     * Zwraca warto�� true je�li obiekt ma ustawiony status "wystawiony"
     */
    bool getWystawiony();
    /**
     * @brief
     * Ustwia czy obiekt ma by� wystawiony czy nie
     * @param wystawiony
     */
    void wystawiony(bool wystawiony);
    /**
     * @brief
     * Zwraca opis obiektu
     */
    std::string getOpis();
    /**
     * @brief
     * Ustawia opis obiektu
     * @param opis
     */
    void opis(std::string opis);
    /**
     * @brief
     * Zwraca po�o�enie obiektu "w kt�rym jest magazynie"
     */
    std::string getPolozenie();
    /**
     * @brief
     * Ustawia po�o�enie obiektu "do kt�rego magazynu przynajle�y"
     * @param polozenie
     */
    void polozenie(std::string polozenie);
    /**
     * @brief
     * Zwraca warto�� obiektu (eksponatu)
     */
    int getWartosc();
    /**
     * @brief
     * Ustawia warto�� obiektu (eksponatu)
     * @param wartosc
     */
    void wartosc(int wartosc);
    /**
     * @brief
     * Zwraca typ obiektu (jako element enumeratora Typ)
     */
    Typ getTyp();
    /**
     * @brief
     * Ustawia typ obiektu jako argument przyjmuje typ enumetatora
     * @param typ
     */
    void typ(Typ typ);
    /**
     * @brief
     * Zwraca w jakim formacie jest zapisana data
     */
    FormatDaty getFormatDaty();
    /**
     * @brief
     * Ustawia w jakim formacie ma by� zapisana data
     * @param formatDaty
     */
    void formatDaty(FormatDaty formatDaty);
    /**
     * @brief
     * Zwraca dat� przpisan� do obiektu
     */
    std::string getData();
    /**
     * @brief
     * Ustawia dat� dla zadanego obietu
     * nale�y pami�ta� o formacie daty zadanym w formatDaty
     * @param data
     */
    void data(std::string data);

/**
 * @brief
 * Konsturktor domy�lny. Przydziela obiektowi unikalny
 * identyfikator
 */

    EksponatMuzealny();
/**
 * @brief
 * Konstruktor z wszyskimi parametrami, id jest przydzielane
 * automatycznie.
 *
 * @param nazwa
 * @param wystawiony
 * @param opis
 * @param polozenie
 * @param wartosc
 * @param typ
 * @param formatDaty
 * @param data
 */
    EksponatMuzealny(std::string nazwa, bool wystawiony, std::string opis,
                     std::string polozenie, int wartosc,
                     Typ typ, FormatDaty formatDaty, std::string data);
    /**
     * @brief
     * Ustawia wewn�trzy licznik identyfikatora.
     * Po uruchomieniu programu i wczytaniu pliku
     * nie mo�e wczytywa� od 0 bo by nadpisa�.
     */
    void lastId(int id);
    /**
     * @brief
     * Metoda czysto wirtulana.
     * Nale�y przeci��y� w klasach pochodnych.
     * Ma zwraca� jako list� QString poszczeg�ne atrybuty obiektu.
     */
    virtual QStringList getAtrybuty() =0;
    /**
     * @brief
     * Zwraca list� QString'�w z atrybutami klasy
     * EksponatMuzelany tak aby mo�na j� wywo�a� w klasie pochodnej
     */
    QStringList getPodstawoweAtrybuty();
    /**
     * @brief
     * Metoda czysto wirtualna.
     * B�dzie zwraca� nag��wek z nazwami p�l
     */
    virtual QStringList getHeaders() = 0;
    /**
     * @brief
     * Zwraca nag��wek z nazwami p�l klasy EksponatMuzealny
     */
    QStringList getPodstawoweHeaders();
    /**
     * @brief
     * Zwraca list� par typu QString, QString w postaci
     * Atrybut, Warto�cAtrybutu
     */
    virtual r2f saveElement() =0;
    /**
     * @brief
     * Zwraca nazw� typu jako string
     */
    std::string nazwaTypu(Typ typ);
    /**
     * @brief
     * Zwraca nazw� formatu daty jako string
     */
    std::string nazwaFormatDaty(FormatDaty formatDaty);
    /**
     * @brief
     * Konwersja warto�ci bool na "Tak/Nie"
     */
    std::string b2s(bool b);

    /**
     * @brief
     * Wirtualny deskturuktor
     */
    virtual ~EksponatMuzealny();
};

#endif // EKSPONATMUZEALNY_H
