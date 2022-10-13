#!/usr/bin/python
import smtplib
import DNS
import socket
import argparse


def get_mx(hostname):
    try:
        servidor_mx = DNS.mxlookup(hostname)
    except ServerError as e:
        if e.rcode == 3 or e.rcode == 2:  # NXDOMAIN (Non-Existent Domain) or SERVFAIL
            servidor_mx = None
        else:
            raise
    return servidor_mx


def validar_email(email, debug=False):
    try:
        hostname = email[email.find('@') + 1:]
        mx_hosts = get_mx(hostname)
        if mx_hosts is None:
            print('No se encuentra MX para el dominio {}'.format(hostname))
            return None
        for mx in mx_hosts:
            try:
                print('Servidor {}'.format(mx[1]))
                print('Cuenta {}'.format(email))
                servidor = smtplib.SMTP(timeout=10)
                servidor.connect(mx[1])
                servidor.set_debuglevel(debug)
                status, _ = servidor.helo()
                if status != 250:
                    servidor.quit()
                    continue
                servidor.mail('')
                status, _ = servidor.rcpt(email)
                if status == 250:
                    servidor.quit()
                    return True
                servidor.quit()
            except smtplib.SMTPServerDisconnected:  # Server not permits verify user
                if debug:
                    print('{} disconected.'.format(mx[1]))
            except smtplib.SMTPConnectError:
                if debug:
                    print('Unable to connect to {}.'.format(mx[1]))
        return False
    except (ServerError, socket.error) as e:
        print('ServerError or socket.error exception raised ({}).'.format(e))
        return None


ServerError = DNS.ServerError

if __name__ == "__main__":
    PARSER = argparse.ArgumentParser(
        description="""DESCRIPCIÓN: Este script comprueba si una dirección de correo existe en un MX (intercambiador de correo).""", usage="\n./main.py email@address \n./main.py -h for help", epilog="""Autor : Oscar Navarrete, onavarrete@protonmail.com""")
    PARSER.add_argument('email', help='Dirección de email a comprobar')
    PARSER.add_argument('--debug', required=False, default=False, type=bool, help='Mostrar mensajes por pantalla (True/False)')
    USERSARGS = PARSER.parse_args()

    resultado = validar_email(USERSARGS.email, USERSARGS.debug)
    if resultado:
        print('La cuenta existe')
    elif resultado is None:
        print('No se puede determinar')
    else:
        print('La cuenta no existe')
