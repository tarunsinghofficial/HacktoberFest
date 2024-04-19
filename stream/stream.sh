#!/bin/bash
echo "$(date +%Y-%m-%d_%H:%M:%S): Starting Broadcastify Script" >> /root/stream/run.log
while true; do

        acheck=$(ps -C arecord -lf | grep plughw &>/dev/null && echo 1 || echo 0)
        bcheck=$(ps -C lame -lf | grep lowpass &>/dev/null && echo 1 || echo 0)
        ccheck=$(ps -C ezstream -lf | grep bcfy &>/dev/null && echo 1 || echo 0)

        let result=$acheck+$bcheck+$ccheck
#       echo $result

        if [[ "$result" != "3" ]]; then
                echo "$(date +%Y-%m-%d_%H:%M:%S): Start-Restarting Broadcastify" >> /root/stream/run.log
                killall ezstream &>/dev/null
                killall lame &>/dev/null
                killall arecord &>/dev/null
                sleep 1
                /root/stream/bc-stream.sh &
                sleep 5
        else
                sleep 10
#               echo "good sleeping for 10"
        fi



done
