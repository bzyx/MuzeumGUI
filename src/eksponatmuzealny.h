#ifndef EKSPONATMUZEALNY_H
#define EKSPONATMUZEALNY_H
#include <string>
#include <QPair>
#include <QList>

class QStringList;
class QString;


/**
 * @brief
 * G³ówna klasa nadaj¹ca interfejs wszyskim klas¹ pochodnym
 * jakie zostan¹ z niej wyprowadzone.
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
     * Okreœla typ elementu jaki jest przechowywany w wektorze (zamiast RTTI)
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
     * Okreœla rodzaj materia³u z jakego jest wykonay przedmiot
     * wymagana ponowna komplilacja aby dodaæ nowy typ :(
     */
    typedef enum {NieOkreslonoMaterialu=-1, Braz=5, Drewno, Gips,
                  Glina, Granit, Marmur, Metal, Mosiadz,
                  Piaskowiec, Srebro, Zloto } Material;
    /**
     * @brief
     * Okreœla format zapisu daty. Nie mo¿na przechowywaæ datetime poniewa¿
     * niektóre z eksponatów mog¹ byæ znane tylko z
     * wieku (w), roku (r), miesi¹ca i roku (mr),
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
     *  Ustawia identyfikator obiektu (nie u¿ywaæ)
     * @param id
     */
    void id(int id);
    /**
     * @brief
     * Zwraca nazwê/tytu³ obiektu
     */
    std::string getNazwa();
    /**
     * @brief
     * Ustawia nazwê/tytu³ obiektu
     * @param nazwa
     */
    void nazwa(std::string nazwa);
    /**
     * @brief
     * Zwraca wartoœæ true jeœli obiekt ma ustawiony status "wystawiony"
     */
    bool getWystawiony();
    /**
     * @brief
     * Ustwia czy obiekt ma byæ wystawiony czy nie
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
     * Zwraca po³o¿enie obiektu "w którym jest magazynie"
     */
    std::string getPolozenie();
    /**
     * @brief
     * Ustawia po³o¿enie obiektu "do którego magazynu przynajle¿y"
     * @param polozenie
     */
    void polozenie(std::string polozenie);
    /**
     * @brief
     * Zwraca wartoœæ obiektu (eksponatu)
     */
    int getWartosc();
    /**
     * @brief
     * Ustawia wartoœæ obiektu (eksponatu)
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
     * Ustawia w jakim formacie ma byæ zapisana data
     * @param formatDaty
     */
    void formatDaty(FormatDaty formatDaty);
    /**
     * @brief
     * Zwraca datê przpisan¹ do obiektu
     */
    std::string getData();
    /**
     * @brief
     * Ustawia datê dla zadanego obietu
     * nale¿y pamiêtaæ o formacie daty zadanym w formatDaty
     * @param data
     */
    void data(std::string data);

/**
 * @brief
 * Konsturktor domyœlny. Przydziela obiektowi unikalny
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
     * Ustawia wewnêtrzy licznik identyfikatora.
     * Po uruchomieniu programu i wczytaniu pliku
     * nie mo¿e wczytywaæ od 0 bo by nadpisa³.
     */
    void lastId(int id);
    /**
     * @brief
     * Metoda czysto wirtulana.
     * Nale¿y przeci¹¿yæ w klasach pochodnych.
     * Ma zwracaæ jako listê QString poszczegó³ne atrybuty obiektu.
     */
    virtual QStringList getAtrybuty() =0;
    /**
     * @brief
     * Zwraca listê QString'ów z atrybutami klasy
     * EksponatMuzelany tak aby mo¿na j¹ wywo³aæ w klasie pochodnej
     */
    QStringList getPodstawoweAtrybuty();
    /**
     * @brief
     * Metoda czysto wirtualna.
     * Bêdzie zwracaæ nag³ówek z nazwami pól
     */
    virtual QStringList getHeaders() = 0;
    /**
     * @brief
     * Zwraca nag³ówek z nazwami pól klasy EksponatMuzealny
     */
    QStringList getPodstawoweHeaders();
    /**
     * @brief
     * Zwraca listê par typu QString, QString w postaci
     * Atrybut, WartoœcAtrybutu
     */
    virtual r2f saveElement() =0;
    /**
     * @brief
     * Zwraca nazwê typu jako string
     */
    std::string nazwaTypu(Typ typ);
    /**
     * @brief
     * Zwraca nazwê formatu daty jako string
     */
    std::string nazwaFormatDaty(FormatDaty formatDaty);
    /**
     * @brief
     * Konwersja wartoœci bool na "Tak/Nie"
     */
    std::string b2s(bool b);

    /**
     * @brief
     * Wirtualny deskturuktor
     */
    virtual ~EksponatMuzealny();
};

#endif // EKSPONATMUZEALNY_H
