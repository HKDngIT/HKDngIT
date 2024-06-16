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
    struct Person *next;
} Person;

// Hinzufuegen von Person an die Liste - An das Listen-Ende!!!
void anhaengen(Person **listenKopf, char *name, int alter, int lebend) {
    Person *aktuellesElement = *listenKopf;
    
    // Listenelement allozieren
    Person *neuePerson = (Person *) malloc (sizeof(Person));
    neuePerson->name = name;
    neuePerson->alter = alter;
    neuePerson->lebend = lebend;
    neuePerson->next = NULL; // Markiert das Ende

    // Falls die Liste leer ist, wird es als Listenkopf erzeugt
    if(aktuellesElement == NULL) {
        *listenKopf = neuePerson;
    } else {
        while(aktuellesElement->next != NULL) {
            aktuellesElement = aktuellesElement->next;
        }
        aktuellesElement->next = neuePerson;
    }
}

// Ausgabe aller Personen
void gebeListeAus(Person *listenKopf) {
    Person *aktuellesElement = listenKopf;
    while(aktuellesElement != NULL) {
        printf("Name: %s", aktuellesElement->name);
        printf("\nAlter: %d", aktuellesElement->alter);
        printf("\nLebend: %d\n\n", aktuellesElement->lebend);
        aktuellesElement = aktuellesElement->next;
    }
    printf("Liste zu ende\n");
}

// Loeschen des letzten Listen-Elementes
int entferneLetzteselement(Person **listenKopf) {
    int erfolgreich = 1;
    Person *aktuellesElement = *listenKopf;
    Person *vorigesElement = aktuellesElement;
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
    } else {
        erfolgreich = 0;
    }
    return erfolgreich;
}

// Main Methode
int main()
{
    Person *kopfDerListe_Kinder = NULL;
    anhaengen(&kopfDerListe_Kinder, "Hai Bui", 31, 1);
    anhaengen(&kopfDerListe_Kinder, "Dennis Bui", 25, 1);
    anhaengen(&kopfDerListe_Kinder, "Vanessa Bui", 21, 1);
    anhaengen(&kopfDerListe_Kinder, "David Bui", 16, 1);

    gebeListeAus(kopfDerListe_Kinder);

    printf("\nLoesche Liste fuer das Beenden des Programms...\n");
    while(kopfDerListe_Kinder != NULL){
        entferneLetzteselement(&kopfDerListe_Kinder);
        printf("\nloesche");
    }
    printf("\n");
}
```
