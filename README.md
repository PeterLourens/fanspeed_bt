# fanspeed_bt

Test for receiving fanspeed from ventilation controller to ithowifi device. For testing purposes three strings "low", "medium" and " "high" will light up outputs 32, 33, 25. All other strings sent wil light up output 26. Recieved data is a char array but can easily be converted to an int