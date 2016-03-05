./tcpdump -i wlan0 -tnNq -e -s 0 dir tods and type data subtype qos-data | sed 's/.*BSSID:\(.*\) SA:\(.*\) DA:\(.*\) Data IV:\(.*\) Pad.*/\1\t11\t\2\t\3\t0x\4/'
