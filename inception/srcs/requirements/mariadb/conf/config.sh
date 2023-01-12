#!/bin/bash

service mysql start && mysql < /init.sql && rm /init.sql;
