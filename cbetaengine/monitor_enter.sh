sudo iwconfig ra0 mode monitor
sudo iwconfig ra0 channel 11
sudo tshark -o 'wlan.enable_decryption:FALSE' -i ra0 -f 'subtype qos-data' -Y 'wlan.fc.retry==0'  -T fields -e wlan.bssid -e prism.did.channel -e wlan.sa -e wlan.da -e data.len 2>/dev/null
