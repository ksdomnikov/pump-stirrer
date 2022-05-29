# pump-stirrer
Controller for two peristaltic pumps and one stirrer
1) Connect to HC-05 via Bluetooth
2) Use Bluetooth terminal for controling speed of stepmotors
3) Command format is: YXXX - where Y = {S, O, W, E} (S is stirrer; O is organic phase pump; W is water phase pump; E is end command); XXX = {integer}
(speed of stepmotors in steps/second  
