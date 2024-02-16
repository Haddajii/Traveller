prog:main.o menu.o MenuMouseControl.o MenuKeyboardControl.o freeMenu.o fonts.o lvl1.o perso.o Collision.o death.o IceMob.o hunter.o BossRoomlvl1.o EnigmeRussia.o Save.o lvl2.o Anubis.o Fly.o TicTacToe.o BossRoomLVL2.o EnigmeEgypt.o lvl3.o Youkai.o Fox.o BossRoomLVL3.o EnigmeJapan.o FinalBossRoom.o EndScreen.o trailer.o
	gcc main.o menu.o MenuMouseControl.o MenuKeyboardControl.o freeMenu.o fonts.o lvl1.o perso.o Collision.o death.o IceMob.o hunter.o BossRoomlvl1.o EnigmeRussia.o Save.o lvl2.o Anubis.o Fly.o TicTacToe.o BossRoomLVL2.o EnigmeEgypt.o lvl3.o Youkai.o Fox.o BossRoomLVL3.o EnigmeJapan.o FinalBossRoom.o EndScreen.o trailer.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g   
menu.o:menu.c          
	gcc -c menu.c -g              
MenuMouseControl.o:MenuMouseControl.c         
	gcc -c MenuMouseControl.c -g
freeMenu.o:freeMenu.c
	gcc -c freeMenu.c -g
MenuKeyboardControl.o: MenuKeyboardControl.c
	gcc -c MenuKeyboardControl.c -g 
lvl1.o:lvl1.c
	gcc -c lvl1.c -g 
perso.o:perso.c
	gcc -c perso.c -g
Collision.o:Collision.c
	gcc -c Collision.c -g   
death.o:death.c 
	gcc -c death.c -g 
IceMob.o:IceMob.c
	gcc -c IceMob.c -g
hunter.o:hunter.c   
	gcc -c hunter.c -g 
BossRoomlvl1.o:BossRoomlvl1.c
	gcc -c BossRoomlvl1.c -g 
EnigmeRussia.o:EnigmeRussia.c
	gcc -c EnigmeRussia.c -g
Save.o:Save.c
	gcc -c Save.c -g   
lvl2.o:lvl2.c
	gcc -c lvl2.c -g
Anubis.o:Anubis.c
	gcc -c Anubis.c -g
Fly.o:Fly.c
	gcc -c Fly.c -g
TicTacToe.o:TicTacToe.c
	gcc -c TicTacToe.c -g
BossRoomLVL2.o:BossRoomLVL2.c
	gcc -c BossRoomLVL2.c -g
EnigmeEgypt.o:EnigmeEgypt.c
	gcc -c EnigmeEgypt.c -g
lvl3.o:lvl3.c
	gcc -c lvl3.c -g
Youkai.o:Youkai.c
	gcc -c Youkai.c -g
Fox.o:Fox.c
	gcc -c Fox.c -g
BossRoomLVL3.o:BossRoomLVL3.c
	gcc -c BossRoomLVL3.c -g
EnigmeJapan.o:EnigmeJapan.c
	gcc -c EnigmeJapan.c -g
FinalBossRoom.o:FinalBossRoom.c	
	gcc -c FinalBossRoom.c -g
EndScreen.o:EndScreen.c
	gcc -c EndScreen.c -g
trailer.o:trailer.c	
	gcc -c trailer.c -g
     
