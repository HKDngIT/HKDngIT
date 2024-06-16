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
    Person *next;
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

// Main Methode
int main()
{
    Person *kopfDerListe = NULL;
    anhaengen(&kopfDerListe, "Hai Bui", 31, 1);
    anhaengen(&kopfDerListe, "Dennis Bui", 25, 1);
    anhaengen(&kopfDerListe, "Vanessa Bui", 21, 1);
    anhaengen(&kopfDerListe, "David Bui", 16, 1);

    gebeListeAus(kopfDerListe);
}
```
