/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c <0x2c@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 01:53:40 by 0x2c              #+#    #+#             */
/*   Updated: 2026/09/28 02:01:03 by 0x2c             ###   ########.fr       */
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
               IRC CHAT ANLEITUNG 0x2.c
====================================================================

BEVOR ES LOSGEHT: 
Du musst dich einmal kurz in deinen WLAN-Router (z. B. FRITZ!Box) 
einloggen. Richte dort eine "Portfreigabe" für dein MacBook ein:
- Protokoll: TCP
- Port-Nummer: 6667

--------------------------------------------------------------------
TEIL 1: FÜR DICH (Der Server-Besitzer)
--------------------------------------------------------------------

1. Schritt: Den Server einschalten
Öffne das ganz normale, schwarze Mac-Terminal-Fenster. Kopiere diesen 
Code komplett, füge ihn ein und drücke Enter:

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
    nick, chans = f"User_{a[1]}", set()
    while True:
        try:
            d = c.recv(1024)
            if not d: break
            for line in d.decode('utf-8', errors='ignore').strip().split('\r\n'):
                p = line.strip().split()
                if not p: continue
                cmd = p[0].upper()
                if cmd == "NICK" and len(p) > 1: nick = p[1]
                elif cmd == "PING": c.send(f":c0x2BitchX PONG c0x2BitchX :{p[1] if len(p)>1 else ''}\r\n".encode())
                elif cmd == "JOIN" and len(p) > 1:
                    ch = p[1].lower()
                    if ch not in channels: channels[ch] = set()
                    channels[ch].add(c); chans.add(ch)
                    pkt = f":{nick}!~u@127.0.0.1 JOIN {ch}\r\n".encode()
                    c.send(pkt); broadcast(ch, c, pkt)
                elif cmd == "PRIVMSG" and len(p) > 2:
                    t = p[1].lower()
                    txt = line.split(':', 1)[1] if ':' in line else ' '.join(p[2:])
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
print("Der Chat-Server läuft jetzt auf Port 6667!")
while True:
    c, a = s.accept()
    threading.Thread(target=handle, args=(c, a)).start()
EOF
python3 simple_irc.py

(Lass dieses Fenster danach einfach offen im Hintergrund laufen!)

2. Schritt: Selber mitchatten
Öffne ein NEUES Terminal-Fenster (Cmd + N). Tippe nacheinander ein:
- brew install irssi     (Drücke Enter. Nur beim ersten Mal nötig!)
- irssi                  (Drücke Enter. Startet das Chat-Programm.)
- /connect localhost     (Drücke Enter. Verbindet dich mit deinem Server.)
- /join #lobby           (Drücke Enter. Betritt den Raum.)

--------------------------------------------------------------------
TEIL 2: FÜR DEINE FREUNDE (Text zum Kopieren und Senden)
--------------------------------------------------------------------

Kopiere den Text ab hier für deine Freunde:

***
So kommst du in unseren privaten Chatroom:

1. Schritt: Öffne dein normales Mac-Terminal.
2. Schritt: Kopiere diesen Befehl für das Installations-System:
   /bin/bash -c "$(curl -fsSL https://githubusercontent.com)"
   (Tippe danach dein Mac-Passwort blind ein und drücke Enter).
3. Schritt: Installiere den Chat-Client:
   brew install irssi
4. Schritt: Starte das Programm:
   irssi
5. Schritt: Verbinde dich mit meiner Internet-IP:
   /connect 178.22.106.36
6. Schritt: Betritt unseren Raum:
   /join #lobby

Danach kannst du einfach losschreiben!
***

*/