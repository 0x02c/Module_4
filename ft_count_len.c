/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c <0x2c@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 01:53:40 by 0x2c              #+#    #+#             */
/*   Updated: 2026/09/28 01:56:42 by 0x2c             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c <0x2c@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:25:12 by 0x2c              #+#    #+#             */
/*   Updated: 2026/09/28 01:50:14 by 0x2c             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
          DAS UTILITY IRC-NETZWERK HANDBUCH (NEUTRAL)
====================================================================

Dieses Handbuch enthält alle Befehle, den kompletten Server-Code
und die universellen Anleitungen für den Host und alle Teilnehmer.

--------------------------------------------------------------------
TEIL 1: NETZWERK-DATEN ERMITTELN (Am Server-MacBook)
--------------------------------------------------------------------
Öffne ein normales macOS-Terminal und nutze diese Befehle:

1. Lokale IP-Adresse herausfinden (Wird für die interne Einwahl benötigt):
   ipconfig getifaddr en0
   
2. Öffentliche Internet-IP herausfinden (Wird für externe Freunde benötigt):
   curl ifconfig.me

--------------------------------------------------------------------
TEIL 2: DEN SERVER STARTEN (Python-Code)
--------------------------------------------------------------------
Navigiere in das gewünschte Verzeichnis. Falls ein alter Server läuft, 
beende ihn zuerst mit Ctrl + C. Kopiere diesen gesamten Block, füge 
ihn in das Terminal ein und drücke Enter:

cat << 'EOF' > simple_irc.py
import socket, threading

clients = {}
channels = {}

def broadcast_to_channel(channel_name, sender_socket, packet):
    if channel_name in channels:
        for client_socket in channels[channel_name]:
            if client_socket != sender_socket:
                try:
                    client_socket.send(packet)
                except:
                    pass

def handle_client(c, a):
    print(f"Verbindung von {a} erfolgreich geoeffnet!")
    c.send(b":c0x2BitchX 001 * :Willkommen auf dem c0x2BitchX Netzwerk!\r\n")
    
    current_nick = f"User_{a}"
    my_channels = set()
    
    while True:
        try:
            data = c.recv(1024)
            if not data: break
            raw = data.decode('utf-8', errors='ignore').strip()
            print(f"Raw: {raw}")
            
            for line in raw.split('\r\n'):
                line = line.strip()
                if not line: continue
                
                parts = line.split()
                cmd = parts[0].upper()
                
                if cmd == "NICK" and len(parts) > 1:
                    current_nick = parts[1]
                elif cmd == "PING":
                    c.send(f":c0x2BitchX PONG c0x2BitchX :{parts[1] if len(parts)>1 else ''}\r\n".encode())
                elif cmd == "JOIN" and len(parts) > 1:
                    ch = parts[1].lower()
                    if not ch.startswith('#'): ch = '#' + ch
                    if ch not in channels: channels[ch] = set()
                    channels[ch].add(c)
                    my_channels.add(ch)
                    join_packet = f":{current_nick}!~user@127.0.0.1 JOIN {ch}\r\n"
                    c.send(join_packet.encode())
                    broadcast_to_channel(ch, c, join_packet.encode())
                elif cmd == "PRIVMSG" and len(parts) > 2:
                    target = parts[1].lower()
                    msg_content = line.split(':', 1)[1] if ':' in line else ' '.join(parts[2:])
                    out_packet = f":{current_nick}!~user@127.0.0.1 PRIVMSG {target} :{msg_content}\r\n"
                    if target.startswith('#'):
                        broadcast_to_channel(target, c, out_packet.encode())
                    else:
                        for cl, nick in clients.items():
                            if nick.lower() == target:
                                cl.send(out_packet.encode())
        except:
            break
            
    for ch in list(my_channels):
        if ch in channels and c in channels[ch]:
            channels[ch].remove(c)
            broadcast_to_channel(ch, c, f":{current_nick}!~user@127.0.0.1 PART {ch}\r\n".encode())
    c.close()

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(('0.0.0.0', 6667))
s.listen(10)
print("IRC-Server c0x2BitchX laeuft im CHANNEL-MODUS auf Port 6667...")
while True:
    c, a = s.accept()
    threading.Thread(target=handle_client, args=(c, a)).start()
EOF
python3 simple_irc.py

--------------------------------------------------------------------
TEIL 3: EINWAHL FÜR DEN SERVER-INHABER (Lokal)
--------------------------------------------------------------------
1. Öffne ein NEUES Terminal-Fenster (Cmd + N).
2. Installiere Irssi (falls noch nicht vorhanden):
   brew install irssi
3. Starte Irssi:
   irssi
4. Verbinde dich mit deiner lokalen IP (aus Teil 1, Punkt 1):
   /connect [DEINE_LOKALE_IP] 6667
5. Betritt den Gruppenraum:
   /join #lobby

--------------------------------------------------------------------
TEIL 4: ANLEITUNG FÜR TEILNEHMER / FREUNDE (Zum Teilen)
--------------------------------------------------------------------
Kopiere den folgenden Text zwischen den Sternchen für deine Freunde:

***
ANLEITUNG: Tritt dem privaten IRC-Netzwerk bei!

So installierst du den Chat-Client und verbindest dich mit dem Server:

Schritt 1: Öffne das normale Mac-Terminal.

Schritt 2: Paketmanager (Homebrew) installieren. Kopiere diesen Befehl und drücke Enter:
/bin/bash -c "$(curl -fsSL https://githubusercontent.com)"
(Hinweis: Das Mac-Passwort muss blind eingetippt und mit Enter bestätigt werden).

Schritt 3: Chat-Client Irssi installieren:
brew install irssi

Schritt 4: Programm starten:
irssi

Schritt 5: Mit dem Server verbinden (Ersetze [ÖFFENTLICHE_IP] durch die Internet-IP des Hosts):
/connect [ÖFFENTLICHE_IP] 6667

Schritt 6: Dem Gruppenraum beitreten:
/join #lobby

Danach kann direkt ohne Schrägstrich im Fenster losgeschrieben werden!
***

--------------------------------------------------------------------
TEIL 5: WICHTIGER ROUTER-HINWEIS (Portweiterleitung)
--------------------------------------------------------------------
Damit externe Teilnehmer eine Verbindung aufbauen können, muss im 
WLAN-Router des Server-Inhabers eine Portfreigabe eingerichtet sein:
- Ziel-Gerät: Das Server-MacBook (Lokale IP aus Teil 1, Punkt 1)
- Protokoll: TCP
- Port extern & intern: 6667
====================================================================
*/