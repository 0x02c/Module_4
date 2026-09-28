/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c <0x2c@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 01:53:40 by 0x2c              #+#    #+#             */
/*   Updated: 2026/09/28 02:07:13 by 0x2c             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




// ATT from EU

int ft_count_len(char *str)
{
    int i;
    i = 0;

    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

// They say a little knowledge is a dangerous thing, but it's not one half so bad as a lot of ignorance.]



/*
====================================================================
           IRC CHAT HANDBUCH FOR MAC, WINDOWS & LINUX
====================================================================

Dieses Handbuch funktioniert auf allen Betriebssystemen. 
Hinweis: Wenn du den Standort wechselst (anderes WLAN), ändern sich 
deine IP-Adressen! Führe Schritt 1 dann einfach erneut aus.

--------------------------------------------------------------------
SCHRITT 1: DIE AKTUELLEN IP-ADRESSEN HERAUSFINDEN
--------------------------------------------------------------------
Öffne die Kommandozeile (Mac/Linux: Terminal, Windows: CMD oder PowerShell).

1. Deine eigene Internet-IP herausfinden (Für deine Freunde):
   Mac/Linux/Windows: curl ifconfig.me
   (Diese Nummer gibst du deinen Freunden, z. B. 178.22.106.36)

2. Deine lokale Netzwerk-IP herausfinden (Für das Router-Setup):
   - Mac:      ipconfig getifaddr en0
   - Linux:    hostname -I
   - Windows:  ipconfig (Suche nach "IPv4-Adresse", z. B. 192.168.x.x)

--------------------------------------------------------------------
SCHRITT 2: DIE EINSTELLUNG IM WLAN-ROUTER
--------------------------------------------------------------------
Logge dich im Browser in den WLAN-Router des Hauses ein (z. B. fritz.box).
Richte unter "Portfreigaben" / "Port Forwarding" eine Regel ein:
- Ziel-Gerät: Wähle deinen PC aus (nutze die lokale IP aus Schritt 1, Punkt 2)
- Protokoll: TCP
- Port-Nummer: 6667

--------------------------------------------------------------------
SCHRITT 3: DEN SERVER STARTEN (FÜR DEN HOST)
--------------------------------------------------------------------
Stelle sicher, dass Python 3 installiert ist. Öffne dein Terminal/CMD,
erstelle eine Datei namens "simple_irc.py", kopiere diesen Code hinein 
und starte ihn (oder füge den Block direkt im Terminal ein):

cat << 'EOF' > simple_irc.py
import socket, threading
clients, channels = {}, {}
def broadcast(chan, sender, pkt):
    if chan in channels:
        for c in channels[chan]:
            if c != sender:
                try: c.send(pkt)
                except: pass
def handle(c, a):
    c.send(b":c0x2BitchX 001 * :Willkommen!\r\n")
    nick, chans = f"User_{a}", set()
    while True:
        try:
            d = c.recv(1024)
            if not d: break
            for line in d.decode('utf-8', errors='ignore').strip().split('\r\n'):
                p = line.strip().split()
                if not p: continue
                cmd = p.upper()
                if cmd == "NICK" and len(p) > 1: nick = p
                elif cmd == "PING": c.send(f":c0x2BitchX PONG c0x2BitchX :{p if len(p)>1 else ''}\r\n".encode())
                elif cmd == "JOIN" and len(p) > 1:
                    ch = p.lower()
                    if not ch.startswith('#'): ch = '#' + ch
                    if ch not in channels: channels[ch] = set()
                    channels[ch].add(c); chans.add(ch)
                    pkt = f":{nick}!~u@127.0.0.1 JOIN {ch}\r\n".encode()
                    c.send(pkt); broadcast(ch, c, pkt)
                elif cmd == "PRIVMSG" and len(p) > 2:
                    t = p.lower()
                    txt = line.split(':', 1) if ':' in line else ' '.join(p[2:])
                    pkt = f":{nick}!~u@127.0.0.1 PRIVMSG {t} :{txt}\r\n".encode()
                    broadcast(t, c, pkt)
        except: break
    for ch in list(chans):
        if ch in channels and c in channels[ch]: channels[ch].remove(c)
    c.close()
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(('0.0.0.0', 6667))
s.listen(10)
print("Der Chat-Server laeuft jetzt auf Port 6667!")
while True:
    c, a = s.accept()
    threading.Thread(target=handle, args=(c, a)).start()
EOF
python3 simple_irc.py

(Lass dieses Fenster danach einfach im Hintergrund geöffnet!)

--------------------------------------------------------------------
SCHRITT 4: SELBER MITCHATTEN (FÜR DEN HOST)
--------------------------------------------------------------------
Öffne ein NEUES Terminal-/CMD-Fenster, um dich selbst zu verbinden:

Unter Mac:
1. brew install irssi
2. irssi
3. /connect localhost
4. /join #lobby

Unter Linux (Ubuntu/Debian):
1. sudo apt install irssi
2. irssi
3. /connect localhost
4. /join #lobby

Unter Windows:
Lade dir ein IRC-Programm wie "mIRC" oder "HexChat" herunter, 
oder nutze Irssi via WSL/MSYS2. Verbinde dich dort mit der Adresse:
localhost (Port 6667) und gib ein: /join #lobby

--------------------------------------------------------------------
SCHRITT 5: ANLEITUNG FÜR DEINE FREUNDE (Zum Kopieren & Senden)
--------------------------------------------------------------------
Kopiere diesen Text für alle Teilnehmer, die mitchatten wollen:

***
So kommst du in unseren privaten Chatroom:

WENN DU EINEN MAC NUTZT:
1. Öffne das normale Terminal.
2. Installiere Homebrew (falls nötig): 
   /bin/bash -c "$(curl -fsSL https://githubusercontent.com)"
3. Installiere Irssi: brew install irssi
4. Starte das Programm: irssi

WENN DU LINUX NUTZT:
1. Öffne das Terminal.
2. Installiere Irssi: sudo apt install irssi (bzw. pacman -S / dnf install)
3. Starte das Programm: irssi

WENN DU WINDOWS NUTZT:
1. Installiere ein kostenloses IRC-Programm wie "HexChat" (hexchat.github.io).
2. Öffne das Programm.

FÜR ALLE ZUM VERBINDEN (Im Chat-Programm eingeben):
1. Verbinde dich mit dem Server: /connect [HIER_DIE_INTERNET_IP_DES_HOSTS_EINTRAGEN]
2. Betritt unseren Gruppenraum: /join #lobby

Danach kannst du einfach loslegen und schreiben!
***

*/