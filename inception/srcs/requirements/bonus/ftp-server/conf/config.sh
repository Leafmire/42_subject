#!/bin/bash

if ! id "${FTP_USER}" > /dev/null;
then
    mkdir -p /var/run/vsftpd/empty
    chmod -R 757 /var/www/html/wp-content
    adduser ${FTP_USER} --disabled-password --gecos ""
    echo ${FTP_USER}:${FTP_PASS} | chpasswd > /dev/null
    chown -R ${FTP_USER}:${FTP_USER} /var/www/html
fi

echo ${FTP_USER} | tee -a /etc/vsftpd.userlist > /dev/null

vsftpd /etc/vsftpd.conf