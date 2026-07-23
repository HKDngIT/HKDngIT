# Raspberry Pi als Bluetooth-Lautsprecher einrichten

> Eine kompakte Zusammenfassung des Tutorials von **Gerrit Stapper**.

## 📖 Credits

Dieses Dokument basiert auf dem folgenden Tutorial:

**Originalautor:** Gerrit Stapper  
**Originalartikel:** *Using your RaspberryPi as a bluetooth speaker*  
**Veröffentlicht:** 20. Dezember 2023 auf Medium

Dieses Dokument ist **keine Kopie**, sondern eine eigenständige Zusammenfassung der wichtigsten Schritte und Hintergründe.

---

# Voraussetzungen

- Raspberry Pi mit integriertem Bluetooth (z.B. Pi 3, Pi 4 oder Pi 5)
- Raspberry Pi OS installiert
- SSH-Zugriff auf den Pi
- Lautsprecher über 3,5-mm-Klinke oder USB angeschlossen
- Internetverbindung zum Installieren der Pakete

---

# 1. Eigenen Benutzer anlegen

Da PulseAudio als **Benutzerdienst** läuft, empfiehlt es sich, einen eigenen Benutzer dafür anzulegen.

Benutzer erstellen:

```bash
sudo useradd -m bluetooth
```

Passwort vergeben:

```bash
sudo passwd bluetooth
```

Danach künftig mit diesem Benutzer anmelden.

---

# 2. Automatisches Login aktivieren

Damit PulseAudio dauerhaft läuft, muss dieser Benutzer automatisch angemeldet werden.

```bash
sudo raspi-config
```

Dort:

```
System Options
    → Boot / Auto Login
        → Console Autologin
```

Den neu angelegten Benutzer auswählen.

Ohne Auto-Login kann zwar eine Bluetooth-Verbindung aufgebaut werden, sie trennt sich jedoch nach wenigen Sekunden wieder.

---

# 3. PulseAudio installieren

Benötigte Pakete installieren:

```bash
sudo apt update
sudo apt install pulseaudio pulseaudio-module-bluetooth
```

PulseAudio starten:

```bash
pulseaudio --start
```

Beim Login automatisch starten:

```bash
systemctl --user enable pulseaudio
```

> Wichtig: **Nicht** mit `sudo` ausführen, da PulseAudio ein Benutzerdienst ist.

---

# 4. Raspberry Pi dauerhaft sichtbar machen

Bluetooth-Konfiguration öffnen:

```bash
sudo nano /etc/bluetooth/main.conf
```

Folgende Zeile anpassen:

```ini
DiscoverableTimeout = 0
```

Dadurch bleibt der Raspberry Pi dauerhaft sichtbar und neue Geräte können jederzeit gekoppelt werden.

---

# 5. Bluetooth-Dienst prüfen

Status kontrollieren:

```bash
sudo systemctl status bluetooth
```

Falls nötig starten:

```bash
sudo systemctl start bluetooth
```

---

# 6. Gerät koppeln

Bluetooth-Konsole öffnen:

```bash
bluetoothctl
```

Bluetooth aktivieren:

```text
power on
```

Pi als koppelbar markieren:

```text
pairable on
```

Nach Geräten suchen:

```text
scan on
```

MAC-Adresse des gewünschten Geräts notieren.

Dann:

```text
pair AA:BB:CC:DD:EE:FF
```

Verbindung herstellen:

```text
connect AA:BB:CC:DD:EE:FF
```

Gerät dauerhaft vertrauen:

```text
trust AA:BB:CC:DD:EE:FF
```

Bluetooth-Konsole verlassen:

```text
exit
```

---

# 7. Musik wiedergeben

Nach erfolgreicher Verbindung kann das gekoppelte Gerät den Raspberry Pi als Bluetooth-Lautsprecher verwenden.

---

# Fehlerbehebung

## Verbindung trennt sich nach wenigen Sekunden

Meist läuft PulseAudio nicht.

Prüfen:

```bash
systemctl --user status pulseaudio
```

Kontrollieren, ob der Benutzer automatisch angemeldet wird.

---

## Raspberry Pi wird nicht gefunden

Bluetooth-Service prüfen:

```bash
sudo systemctl status bluetooth
```

Kontrollieren, ob

```ini
DiscoverableTimeout = 0
```

gesetzt wurde.

---

## Ton verzögert

Der Autor berichtet, dass unter Linux (Pop!_OS) das Schließen des Bluetooth-Einstellungsfensters die Verzögerung beseitigt hat.

---

## Bluetooth-Logs ansehen

Systemlog durchsuchen:

```bash
grep bluetooth /var/log/syslog
```

Bluetooth-Service prüfen:

```bash
sudo systemctl status bluetooth
```

---

# Hinweise des Autors

Der Originalartikel erwähnt zusätzliche Konfigurationsschritte, die in dessen eigener Installation **nicht erforderlich** waren:

- Benutzer zur Gruppe `bluetooth` hinzufügen
- Bluetooth Device Class (`Class = 0x41C`) setzen

In der getesteten Konfiguration funktionierte alles auch ohne diese Änderungen.

---

# Verwendete Komponenten

- Raspberry Pi OS
- Bluetooth (`bluez`)
- PulseAudio
- `bluetoothctl`

---

# Quellen

- Gerrit Stapper – *Using your RaspberryPi as a bluetooth speaker* (Medium, 20.12.2023)

Vielen Dank an Gerrit Stapper für die ursprüngliche Anleitung und die ausführlichen Erklärungen.

https://medium.com/elevate-tech/using-your-raspberrypi-as-a-bluetooth-speaker-9c59366c059e
