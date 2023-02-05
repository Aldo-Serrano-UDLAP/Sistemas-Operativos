echo Se va a programar un timer de apagado :D
@echo off
set /p "tiempo=Establezca el tiempo de apagado (en segundos): "
echo El equipo se apagara en %tiempo% segundos
shutdown -s -t %tiempo%
timeout /t 10
shutdown -a
echo Se ha detenido el proceso de apagado :D