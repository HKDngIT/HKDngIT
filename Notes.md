# Code-Roadmap

1. Struct Person erstellen
2. Dynamisch hinzufügen Methode schreiben
3. Ausgabe der hinzugefügten Personen

# Notizen
- Speicherplatz sauber frei machen nach dem Beenden des Programms

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur für eine Person im Stammbaum
typedef struct Person
{
    char *name;
    int alter;
    int lebend;
    char *rolle;
    struct Person *next;
} Person;

// Hinzufuegen von Person an die Liste - An das Listen-Ende!!!
void anhaengen(Person **listenKopf, char *name, int alter, int lebend, char *rolle) {
    Person *aktuellesElement = *listenKopf;

    // Listenelement allozieren
    Person *neuePerson = (Person *) malloc (sizeof(Person));
    neuePerson->name = name;
    neuePerson->alter = alter;
    neuePerson->lebend = lebend;
    neuePerson->rolle = rolle;
    neuePerson->next = NULL; // Markiert das Ende

    // Falls die Liste leer ist, wird es als Listenkopf erzeugt
    if(aktuellesElement == NULL) {
        *listenKopf = neuePerson;
    } else {
        // Gehe bis zum Ende der Liste und füge es dann hinzu
        while(aktuellesElement->next != NULL) {
            aktuellesElement = aktuellesElement->next;
        }
        aktuellesElement->next = neuePerson;
    }
}

// Ausgabe aller Personen
void gebeListeAus(Person *listenKopf) {
    Person *aktuellesElement = listenKopf;
    // Gehe bis zum Listenende und gebe dabei immer die aktuelle Person aus
    while(aktuellesElement != NULL) {
        printf("Name: %s", aktuellesElement->name);
        printf("\nAlter: %d", aktuellesElement->alter);
        printf("\nLebend: %d", aktuellesElement->lebend);
        printf("\nRolle: %s\n\n", aktuellesElement->rolle);
        aktuellesElement = aktuellesElement->next;
    }
    printf("Genration zu Ende\n\n");
}

// Loeschen des letzten Listen-Elementes
// @return 1 wenn erfolgreich gelöscht wurde
// @return 0 wenn nichts gelöscht wurde
int entferneLetzteselement(Person **listenKopf) {
    int erfolgreich = 1;
    Person *aktuellesElement = *listenKopf;
    Person *vorigesElement = aktuellesElement;
    // Wenn Listenkopf nicht leer ist
    if(*listenKopf != NULL) {
        while(aktuellesElement->next != NULL) {
            vorigesElement = aktuellesElement;
            aktuellesElement = aktuellesElement->next;
        }
        free(aktuellesElement);
        if(vorigesElement!=aktuellesElement) {
            vorigesElement->next = NULL;
        } else {
            *listenKopf = NULL; // Verweis auf Listenkopf loeschen
        }
    // Wenn Listenkopf leer ist
    } else {
        erfolgreich = 0;
    }
    return erfolgreich;
}

// Suchen einer Person mit Namen
Person *pSuche(Person *listenKopf, char* name) {
    // Wenn die Liste nicht leer ist...
    if(listenKopf != NULL){
        Person *aktuellesElement = listenKopf;
        int check = 1;
        if(name != NULL) {
            check = strcmp(aktuellesElement->name, name); // strcmp vergleicht 2 strings -> 0 für TRUE, 1 für FALSE
            // Wenn Name nicht gleicht und wenn der Zeiger auf nächste Person nicht NULL ist ...
            while(check != 0 && aktuellesElement->next != NULL) {
                aktuellesElement = aktuellesElement->next;
                check = strcmp(aktuellesElement->name, name);
            }
        }
        // Letzter check ob Person gefunden wurde... check ist '0' wenn gefunden wurde. '1' wenn nicht.
        if(check == 0) {
            return aktuellesElement;
        } else {
            return NULL;
        }
    } else {
        printf("\nListe ist leer!\n");
    }
}

// Main Methode
int main()
{
    Person *DritteGeneration = NULL;
    printf("Dritte Generation\n\n");
    anhaengen(&DritteGeneration, "Hai Bui", 31, 1, "Bruder");
    anhaengen(&DritteGeneration, "Dennis Bui", 25, 1, "Bruder");
    anhaengen(&DritteGeneration, "Vanessa Bui", 21, 1, "Ich");
    anhaengen(&DritteGeneration, "David Bui", 16, 1, "Bruder");

    gebeListeAus(DritteGeneration);
printf("|######################################################################|\n");

    Person *ZweiteGeneration = NULL;
    printf("Zweitgeneration:\n\n");
    anhaengen(&ZweiteGeneration, "Thanh Bui", 58, 1, "Vater");
    anhaengen(&ZweiteGeneration, "To Anh Nguyen", 55, 1, "Mutter");
    anhaengen(&ZweiteGeneration, "Tram Anh Nguyen", 58, 1, "Tante");
    anhaengen(&ZweiteGeneration, "Trung Nguyen", 50, 1, "Onkel");

    gebeListeAus(ZweiteGeneration);
    printf("|######################################################################|\n");


    Person *ErsteGeneration = NULL;
    printf("Erste Generation:\n\n");
    anhaengen(&ErsteGeneration, "Tram Nguyen", 80, 1, "Oma - Mütterlicher Seite");
    anhaengen(&ErsteGeneration, "Noi Bui", 93, 1, "Oma - Väterliche Seite");
    anhaengen(&ErsteGeneration, "Ong Lu", 95, 0, "Opa - Mütterlicher Seite");
    anhaengen(&ErsteGeneration, "Ong Bui", 85, 0, "Opa - Väterliche Seite");

    gebeListeAus(ErsteGeneration);
    printf("|######################################################################|\n");

    printf("\nSuche nach Khiem...\n");
    Person *sucheKhiem = pSuche(DritteGeneration, "Khiem");
    if(sucheKhiem == NULL){
        printf("Khiem wurde nicht gefunden.\n");
    } else {
        printf("Name: %s, Alter: %d, Lebend: %d, Rolle: %s\n", sucheKhiem->name, sucheKhiem->alter, sucheKhiem->lebend, sucheKhiem->rolle);
    }

    printf("\nSuche nach Thanh Bui...\n");
    Person *sucheThanhBui = pSuche(ZweiteGeneration, "Thanh Bui");
    if(sucheThanhBui == NULL){
        printf("\nKhiem wurde nicht gefunden.\n");
    } else {
        printf("Name: %s, Alter: %d, Lebend: %d, Rolle: %s\n", sucheThanhBui->name, sucheThanhBui->alter, sucheThanhBui->lebend, sucheThanhBui->rolle);
    }

    printf("\nLoesche Liste fuer das Beenden des Programms...\n");
    int geloeschtePersonen = 0;
    while(DritteGeneration != NULL){
        entferneLetzteselement(&DritteGeneration);
        geloeschtePersonen++;
    }
    while(ZweiteGeneration != NULL){
        entferneLetzteselement(&ZweiteGeneration);
        geloeschtePersonen++;
    }
    while(ErsteGeneration != NULL){
        entferneLetzteselement(&ErsteGeneration);
        geloeschtePersonen++;
    }
    printf("\nGeloeschte Personen: %d", geloeschtePersonen);
}
```
