# Docker Cheat Sheet

## Images

```bash
# Alle Images anzeigen
docker images

# Alternativ
docker image ls

# Image löschen
docker rmi <image>:<tag>
```

---

## Container

```bash
# Laufende Container anzeigen
docker ps

# Alle Container anzeigen (auch gestoppte)
docker ps -a

# Container starten
docker start <container>

# Container stoppen
docker stop <container>

# Container neu starten
docker restart <container>

# Container löschen
docker rm <container>
```

---

## Container erstellen und starten

```bash
docker run --name <container> -d -p <host-port>:<container-port> <image>:<tag>
```

Beispiel:

```bash
docker run --name weatherapi -d -p 8080:8080 weatherapi:arm64
```

---

## Logs

```bash
# Logs anzeigen
docker logs <container>

# Logs live verfolgen
docker logs -f <container>
```

---

## Shell im Container

```bash
# Mit Bash
docker exec -it <container> /bin/bash

# Falls Bash nicht vorhanden ist
docker exec -it <container> /bin/sh
```

---

## Images importieren & exportieren

```bash
# Image als TAR speichern
docker save -o weatherapi-arm64.tar weatherapi:arm64

# Image laden
docker load -i weatherapi-arm64.tar
```

---

## System

```bash
# Docker-Version
docker version

# Docker-Informationen
docker info

# Speicherverbrauch anzeigen
docker system df

# Nicht verwendete Ressourcen entfernen
docker system prune

# Alles Unbenutzte entfernen (inkl. Images)
docker system prune -a
```

> **⚠️ Achtung:** `docker system prune -a` löscht alle Images, die von keinem Container verwendet werden.

---

## Kurzreferenz

| Aufgabe | Befehl |
|---------|---------|
| Images anzeigen | `docker images` |
| Laufende Container | `docker ps` |
| Alle Container | `docker ps -a` |
| Container starten | `docker start <container>` |
| Container stoppen | `docker stop <container>` |
| Container neu starten | `docker restart <container>` |
| Container löschen | `docker rm <container>` |
| Image löschen | `docker rmi <image>` |
| Logs anzeigen | `docker logs -f <container>` |
| Shell öffnen | `docker exec -it <container> /bin/sh` |
| Image exportieren | `docker save -o image.tar <image>` |
| Image importieren | `docker load -i image.tar` |
