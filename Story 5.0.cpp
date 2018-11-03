#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//#include<dos.h>
#include<conio.h>
//functions
void setcursor(int x, int y);
void game();
void credits();
void introduction();
void progressset();
int progcipher();
void dad();
void die();
void curious();
void brave();
void ferrari();
void cardpin(int *y);
void move();
void longcut();
void ignoreold();
void barge();
void mum();
void bus();
void uber();
void talk();
void silence();
void treat();
void oldman();
void quiz();
void riddle();
void savemum();
void box(int x, int offset);
int selector(int opts,int offset);




//global declarations
char name[1000], ch='0';
int prog, lives, deathcount,trex, tag, daddy, time=50;//trex is dummy variable for step by step choice

/*HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.
struct small {
	
	SHORT Left;
	SHORT Right;
	SHORT Top;
	SHORT Bottom;
};*/


main(){
	SetConsoleTitle("THE JUDGEMENT DAY");


	SMALL_RECT windowSize = {0, 0, 170, 70};
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

	
//	windowsize();
/*int blex,bley;
blex = GetSystemMetrics(SM_CXSCREEN);
bley = GetSystemMetrics(SM_CYSCREEN);
getchar();*/
	
	system("cls");
	fflush(stdout);
	int menu, uprg,i;
	MENU:
	printf("*****  *  ****   *   \n");
	printf("   *  * * *   * * *  \n");
	printf("  *   *** **** ***** \n");
	printf(" *   *   **   **   * \n");
	printf("*****     *   *     *\n");
	
	int count;
	printf("Use arrow keys. Followed by enter.");
	setcursor(0,7);
	printf("[ ] : New Game \n[ ] : Load Game \n[ ] : Credits\n[ ] : Help\n[ ] : Settings\n");
	menu = selector(5,7);
	system("cls");
	switch(menu)
		{
			case 1:
				prog = 0;
				deathcount=0;
				printf("Enter name : ");
				scanf("%s", &name);
				game();
				break;
			case 2:
				printf("Enter name (Less than  10 characters): ");
				scanf("%s", &name);
				printf("Enter progress code : \n");
				scanf("%d",&prog);
				printf("Welcome back, %s\nPress enter when you are ready to continue.", name);
				fflush(stdout);
				getchar();
				system("cls");
				progressset();
				break;
			case 3:
				credits();			
				main();
				break;
			case 4:
				fflush(stdout);
				printf("1. Press enter to proceed\n");
				fflush(stdout);
				getchar();
				printf("2. Press selection followed by enter to progress on options");
				fflush(stdout);
				getchar();
				printf("3. After every death you will be given a progress code to continue the game");
				fflush(stdout);
				getchar();
				printf("4. Select load game and follow the on screen instructions to continue your game");
				fflush(stdout);
				getchar();
				printf("5. Contact the dev team for more information.");
				fflush(stdout);
				getchar();
				break;
			case 5:
				i=0;
				while(i!=1){
				printf("\nThe next screen should last for approximately 3 seconds for a smooth gameplay\n");
				printf("Set game speed (default = 50)>> ");
				scanf("%d",&time);
				for(i=0;i<time;i++){
				printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- %d%%",i*100/time);
				system("cls");
				printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ %d%%",i*100/time);
				system("cls");
				}
				i=0;
				printf("Is the speed okay?\n1. Yes\n2. No\n>> ");
				scanf("%d",&i);
				}
				main();
				break;
			default:
				printf("Invalid. Press enter to retry.\n");
				getchar();
				getchar();
				main();
		}

		
return 0;
}

int selector(int opts,int offset){
	int count = 1;
		while(1){
			box(count,offset);
			ch = getch();
			switch(ch){
				case 80:
					count++;
					if (count==opts+1) 
						count--;
					break;
				case 72:
	    			count--;
	    			if(count==0) 
						count++;
					break;
				}
				if(ch=='\r')
				break;
			}
	return count;
}

void box(int x, int offset){
		setcursor(1,x+offset-2);
		printf(" ");
		setcursor(1,x+offset-1);
		printf("%c",254);
		setcursor(1,x+offset);
		printf(" ");
}

//void windowsize(){
/*	
int argc, char* argv[]
struct small test;
	
	HANDLE hStdout;
	COORD coord;
	BOOL ok;
	
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 170;
	coord.Y = 100;
	ok = SetConsoleScreenBufferSize(hStdout,coord);
	
	test.Left = 0;
	test.Top = 0;
	test.Right = coord.X-1;
	test.Bottom = coord.Y-1;
	
*/	

//}

void setcursor (int x,int y){
	COORD coord={0,0};
	coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void progressset(){
	int x, y,z;
	x = ((((prog-2)/3)-43)/35);
	if(x==0)
	game();
	y = (x%10)+((((x-(x%10))/10)%10)*10);
	z = (x-y)/100;
	deathcount = (z%10)+((((z-(z%10))/10)%10)*10);
	daddy = (z-deathcount)/100;
	
	switch(y){
	case 11	:	introduction();
				break;
	case 12	:	curious();
				break;
	case 13	:	brave();
				break;
	case 14	:	ferrari();
				break;
	case 16	:	move();
				break;
	case 17	:	longcut();
				break;
	case 18	:	ignoreold();
				break;
	case 19	:	barge();
				break;
	case 20	:	mum();
				break;
	case 21	:	bus();
				break;
	case 22	:	uber();
				break;
	case 23	:	talk();
				break;
	case 24	:	quiz();
				break;
	case 25 :	riddle();
				break;
	case 26 :	savemum();
				break;
	default : 
				printf("Invalid progress code");
				getchar();
				main();
				break;
	}
}

void credits(){
	getchar();
	printf("Written and Programmed by : \nAmir Bin Iskandar\t\t2017645628\nMuhammad Wafiq Bin Ahmad Anuar\t2017671406\nMuhammad Fauzan Bin Mohd Isa\t2017658474\n");		
			printf("1. Press enter to proceed\n");
	fflush(stdout);
	getchar();
}

void game()
{	
	introduction();
}

	
	
void introduction(){
	system("cls");
	setcursor(0,2);//(x,y)
	printf("[ ] : Start tutorial\n[ ] : Skip tutorial\n");
	trex = selector(2,2);//(number of options,y-1)
	int i;
	if(trex==1||trex==2)
	for(i=0;i<time/2;i++){
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- %d%%",i*100/time/2);
	system("cls");
	printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ %d%%",i*100/time/2);
	system("cls");
	}
	if(trex==1){
				printf("1. Press enter to proceed");
				fflush(stdout);
				getchar();
				getchar();
				printf("2. Press selection followed by enter to progress on options");
				getchar();
				printf("3. After every death you will be given a progress code to continue the game");
				getchar();
				printf("4. Select load game and follow the on screen instructions to continue your game");
				getchar();
				printf("5. Contact the dev team for more information. (Email can be found on the help screen)");
				getchar();
				system("cls");
	}else if(trex!=2){
		printf("\nInvalid option");
		fflush(stdout);
		introduction();
	}
	dad();
}

void dad(){
	trex=0;
	int i;
	fflush(stdout);
	printf("...One fine evening...");
	getchar();
	printf("\n%s : I am so bored today ... I know ! It is time for DOTA!!",name);
	getchar();
	printf("%s : Come on Zanesx , you can do better !!",name);
	getchar();
	system("cls");
	for(i=0;i<time;i++){
	system("cls");
	printf("%s : W-what? why is my screen glitching??",name);
	system("cls");
	printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- %d%%",i*100/time);
	system("cls");
	printf("%s : W-what? why is my screen glitching??",name);
	}
	
	getchar();
		for(i=0;i<time/2;i++){
printf("``````  ` ````````...---/+osso/:-.-://:::::-::::-----::::::::///////+++++++++ooooooooooooooooooooo+o/+///:::////:/:::-::::-......```````    ````````  \n");
printf("```````` ````.```...--::+ooso/::.:////://///:::------::::::://///+++++++ooooooooooooooooooooooooooo++////:::::///////::://-:--:.-.-.``````  ``````````\n");
printf("```````````````````..-:/++so+/::/+++++++///:::::::::::::///////+++oooooooooooooooooooooooooooooooo++++//::----:::///////++++//:://-.``````````````````\n");
printf("`````````````````...--:+++o+/:/+++////:---.-----::::://///++++++oooossooooooooooooooooooooooooo+++++++//:::-----:::///////++++///-.`````````          \n");
printf("````````````````....-:///++//++++////:::---..--::////++++++++ooooooososooooooooooooooo++++o+o+++++++++//::---...--::::/::::::-----.``````             \n");
printf("`````````````.```..--://+///++++++++//::-----::://+++++++ooooooooossssoooooooooooooooo++++++++++++++++//::--.....---:::::::-------..```````           \n");
printf("  ```````````````...-:://++oo++o++//:----...-:://+++++ooooooooooooooooooooooooooooooo++++++++++++++++++/::--..`..---::::::::::----...`````            \n");
printf("````  ``````````...-::://+++++++//:------..--:///++++++ooooooooooooooooooooooooooo+++++++++++++++++++++/::--...``..---::::::::-.--.`.`````            \n");
printf("````     ```````..-::::/+++//++/:/:-----...-:://+++++++++oooooooooooooooooooooooo+++++++++++++++++++++///---.-..`...-:-::::::::-.-.``.```             \n");
printf("``````` ` ``````.-::::/o+o+//+///:-----:-.-:::///++++++++++++++ooooooooooooooo+++++++++++oooooo+++++++///:-----.....--::::/:::/:---```.```            \n");
printf("```````````````.-:::::+ooo+:/+//:-.--.::..-::////+++++++++++++++ooooooo++++++++++++++++ooooooooooo++++///:-.---:-...--::////////::-.```````         ``\n");
printf("``````````````.--::::/+++o//+++/:--.--::..-:///++++++++++++++++++++++++++++++///+/////////////+++++++////:-..----:----::////////+-:.```````````   ````\n");
printf("`````````..``..--:::/++++///+/+//-----:-..-:///++++++++++++///++++++++///////:::--.........-------:://////:.`.-:---:::::/+++///++/:-``.`..`````    ```\n");
printf("````````````...--:::+//+////+/+//:---::-..-::::::::::::::://///////+++////:::--..````````.........---::://:...--:/::-:///++++///++/:.`....```````   ` \n");
printf("```````````...-:::://:/+//:/+++/:::-:::-.`.-----.....````....-::///+++++//::--..````````...```....-.---::/:-`.---:///::://+o++//++//......``````````  \n");
printf("``````````.`..-::::+/://:/:/+++/:::-/::-.`.........``````````..-:://++++///:--.````````......````...---::/:-...---://///://++++//+//:.....````````````\n");
printf("`````````...---::-:++://:////+/:::::::--.```````````.`.``.````..-:/++++++//::...``.-.`````````````..--:::/:-......-:://////+++///+/:/.```.````````````\n");
printf(" ``````....--:-:--//+:/://:////-:::::--..```````````````.--.`...-:/+++++++//:-..`.-::...```.-......--::://:-...-....-:///////++//+/:::.`.`````````````\n");
printf("```````....--:::--://:/://:://:::/:::-....``````...``...::-.....-:/++oooo++//:-...--::----::-------:::////:-..`..-...-://+///++///:--::.```````  ```  \n");
printf("```````...--:::---/:/:////:://::/::----....````..----------...--://+oooooo++///::-...-------------:://////:-.` `..--..-://+///++/+:..-/-`.````````````\n");
printf("`````....-:::::---/:::///::://::/:::-:-.....`````..........---:///+ooooooo++++++//:------::::-::::////////:..` ```.----:/+////++/+:--./-``````````````\n");
printf("````..-.-:::::---:::://::::://::::::-:-................---::////++oosssssoo+++++++++/////:://////////++///:.``  ```..--://////+++/-.---.````    ``````\n");
printf("``...-.-::::::--:::--///::-:///::::::--..-....------:::::///+++++oossssssooo++++++++++++++++++++++++++++//.```  ```..--:///////++::::..````      `````\n");
printf("``..----:-::::::::::-://::-:++/:::::::-.-------:::::::///++++++++ossyyyyssoo+++++++oooooo+++++++++++++++/:``   ````...-:/++////++/:-..```````     ``  \n");
printf("``..---:-:::::/::::::///:--:+++//:/:::---------::://///++++++++++osyyyyyyssoo++++++ooooooooooo++++++++++/.`   ````....-:/+/////+//--..`````  ``       \n");
printf("``..-----::///:-:::::///:--:+++/::::::---:----::://++++++++++++/+sssyyyyssssooo+/++ooooooooooooo+++++++/-`  `````....-::///////+//:....``````````     \n");
printf("`...-----:://---::::://::--:/+++//:::::--:-----:///+++++o+++++/oooooooooooo+oooo+/++ooooooooooo++++++++/.`   ```...--:////////://::....````````  `` ``\n");
printf("``..-----://----:::::/:::--:///+//::::::-:-----:://++++++++++//o+//////////:::/++/++++ooooooo+++++++++/-````````..--://://///:///::....`````````  ````\n");
printf("`...----::/:---:/::://:-:--:::://+///:::--:-----:://++++++++////:-----------.-://+++++++++++++++++++///.````````--::::://///::/+/::....```````````````\n");
printf("`....--::::----:/::///:-:--:::-://+//::::--------::///+++++++++////////:://///+++++++++++++++++++/////:`.`````.--:::::::///:://+/:-.....``````````````\n");
printf("...----:-::----:::////::---:::--://++/::-------.--::////+++++++++++++++++++++++ooooo++++++++++////////-......-----:-:::////::/+/::-......`````````````\n");
printf("...------::.---::::/:/:---::-:-.::////:--.-----.--:::///+++++++o+++++o+++ooooooooooo+++++++++////////:.....--------::::///:::++/:-.......`````````````\n");
printf("...-------:----::::::/:---::--:.:::////---...--.---::://///+++++++++++++++++++++++++++++++//////////:.`.--:--------::://::::/+/:--...........````` ```\n");
printf("....-----------:/::::/:--:::--:.::::://:..-...-..---::://///////////:::/:::---::///////////////////:-.----.-------::://:::::+/-----.........``````````\n");
printf("...----.--.----::-:-:/:--::--.-.::::::/:.........----::::////:::-.```......`````...--::://////////:........------:://:---::/+:-----....```..``````````\n");
printf("...---.....---:::::-:::--::----:::::::/:.``......-.---:::::::...-..----...------:---::::////////:-```.....-.--::-:/::----::+/-------.....```.```````  \n");
printf("...--......--:::::-:-::-:::----:/:::::/:.``...``....---::::::..-::::::::::/::::/::://////////:::-``````.....-::::/:-...--:/+:-------.......``.``````  \n");
printf("...--....----:-::-----:::::---://::-::/-`.`..````....---:::::-----------:-:------::///////::::-.``````.....-:::///-..`.--/+:------:---.........````   \n");
printf("...-.....---:---::----:-::::-::/:----/:..`.`````````...---:::--..----..---..----::///////:::-.````````.....-:://::..``.-://--------::--........``   ``\n");
printf("....-....----.--:-------::::-::-----:/-.``.```````````..-----.-:::::::::::::::::////////::-.```````````...--:/:::.````.-:/----------::--.``.....``````\n");
printf("..--.-..-----..-:---.-.-:::::::----:/:.`.`.```.`````````..------://///////++++++//////::-...`````````.`...--:--:-.````.-/:.-::--------:--..`....``````\n");
printf(".--..-----------:---...-::::::-----/:...``.``....`````````..---.-:///////////////////:--....```````..``...-----:-````.-:/...-:-:-------:-....``..`````\n");
printf("-----------.----::--...-::::/:---:/:-...``..`.``````````````..---::///////////////::--.......```````.``...-------..``.-::....-:::-:-----:-......``````\n");
printf("----:----------:::-.....-////::::/:-..-.....`.``.````````````....--:::::::::::::::---.--.....```````.`....--..--.`.``.-::.`...::::-:-----:-.`....`````\n");
printf("-:::::---------:::-.....-///::://:-...-..........`..````````.......---------------------.....```````......--.--..````.-::.....-::::::-----:-.``...````\n");
printf("::::::-------::--:-.....-://:://:--..-.......`..``````````.........----------------------....```````......--......```.-:-......-:::::::--.-:-.``....``\n");
printf("::::::-------::-::--.....-/////::-----....`..``.`````````.......------------------------....```````.......--.-....`.`.-:-.......-/:/::::----:-```...``\n");
printf(":::--::------::-:::-.....-:///::::-.--..........````````.....----------------::::::::----...```````........--.......`.-::.......-::::::::----:.```..``\n");
printf("-:---::---.---:-::-......-:///:::::.......-..........``.....------::::::::::::::::::::---...``````.`.....-.--.........-::.......--:/::/::------````..`\n");
printf(":----:---..---::::-......::::/:::::-...-.---.............------::::::::::::::::::::::::---....```.``.-...--.--....-...-::-..-....-:::-:::---:--.````.`\n");
}
system("cls");
printf("``````  ` ````````...---/+osso/:-.-://:::::-::::-----::::::::///////+++++++++ooooooooooooooooooooo+o/+///:::////:/:::-::::-......```````    ````````  \n");
printf("```````` ````.```...--::+ooso/::.:////://///:::------::::::://///+++++++ooooooooooooooooooooooooooo++////:::::///////::://-:--:.-.-.``````  ``````````\n");
printf("```````````````````..-:/++so+/::/+++++++///:::::::::::::///////+++oooooooooooooooooooooooooooooooo++++//::----:::///////++++//:://-.``````````````````\n");
printf("`````````````````...--:+++o+/:/+++////:---.-----::::://///++++++oooossooooooooooooooooooooooooo+++++++//:::-----:::///////++++///-.`````````          \n");
printf("````````````````....-:///++//++++////:::---..--::////++++++++ooooooososooooooooooooooo++++o+o+++++++++//::---...--::::/::::::-----.``````             \n");
printf("`````````````.```..--://+///++++++++//::-----::://+++++++ooooooooossssoooooooooooooooo++++++++++++++++//::--.....---:::::::-------..```````           \n");
printf("  ```````````````...-:://++oo++o++//:----...-:://+++++ooooooooooooooooooooooooooooooo++++++++++++++++++/::--..`..---::::::::::----...`````            \n");
printf("````  ``````````...-::://+++++++//:------..--:///++++++ooooooooooooooooooooooooooo+++++++++++++++++++++/::--...``..---::::::::-.--.`.`````            \n");
printf("````     ```````..-::::/+++//++/:/:-----...-:://+++++++++oooooooooooooooooooooooo+++++++++++++++++++++///---.-..`...-:-::::::::-.-.``.```             \n");
printf("``````` ` ``````.-::::/o+o+//+///:-----:-.-:::///++++++++++++++ooooooooooooooo+++++++++++oooooo+++++++///:-----.....--::::/:::/:---```.```            \n");
printf("```````````````.-:::::+ooo+:/+//:-.--.::..-::////+++++++++++++++ooooooo++++++++++++++++ooooooooooo++++///:-.---:-...--::////////::-.```````         ``\n");
printf("``````````````.--::::/+++o//+++/:--.--::..-:///++++++++++++++++++++++++++++++///+/////////////+++++++////:-..----:----::////////+-:.```````````   ````\n");
printf("`````````..``..--:::/++++///+/+//-----:-..-:///++++++++++++///++++++++///////:::--.........-------:://////:.`.-:---:::::/+++///++/:-``.`..`````    ```\n");
printf("````````````...--:::+//+////+/+//:---::-..-::::::::::::::://///////+++////:::--..````````.........---::://:...--:/::-:///++++///++/:.`....```````   ` \n");
printf("```````````...-:::://:/+//:/+++/:::-:::-.`.-----.....````....-::///+++++//::--..````````...```....-.---::/:-`.---:///::://+o++//++//......``````````  \n");
printf("``````````.`..-::::+/://:/:/+++/:::-/::-.`.........``````````..-:://++++///:--.````````......````...---::/:-...---://///://++++//+//:.....````````````\n");
printf("`````````...---::-:++://:////+/:::::::--.```````````.`.``.````..-:/++++++//::...``.-.`````````````..--:::/:-......-:://////+++///+/:/.```.````````````\n");
printf(" ``````....--:-:--//+:/://:////-:::::--..```````````````.--.`...-:/+++++++//:-..`.-::...```.-......--::://:-...-....-:///////++//+/:::.`.`````````````\n");
printf("```````....--:::--://:/://:://:::/:::-....``````...``...::-.....-:/++oooo++//:-...--::----::-------:::////:-..`..-...-://+///++///:--::.```````  ```  \n");
printf("```````...--:::---/:/:////:://::/::----....````..----------...--://+oooooo++///::-...-------------:://////:-.` `..--..-://+///++/+:..-/-`.````````````\n");
printf("`````....-:::::---/:::///::://::/:::-:-.....`````..........---:///+ooooooo++++++//:------::::-::::////////:..` ```.----:/+////++/+:--./-``````````````\n");
printf("````..-.-:::::---:::://::::://::::::-:-................---::////++oosssssoo+++++++++/////:://////////++///:.``  ```..--://////+++/-.---.````    ``````\n");
printf("``...-.-::::::--:::--///::-:///::::::--..-....------:::::///+++++oossssssooo++++++++++++++++++++++++++++//.```  ```..--:///////++::::..````      `````\n");
printf("``..----:-::::::::::-://::-:++/:::::::-.-------:::::::///++++++++ossyyyyssoo+++++++oooooo+++++++++++++++/:``   ````...-:/++////++/:-..```````     ``  \n");
printf("``..---:-:::::/::::::///:--:+++//:/:::---------::://///++++++++++osyyyyyyssoo++++++ooooooooooo++++++++++/.`   ````....-:/+/////+//--..`````  ``       \n");
printf("``..-----::///:-:::::///:--:+++/::::::---:----::://++++++++++++/+sssyyyyssssooo+/++ooooooooooooo+++++++/-`  `````....-::///////+//:....``````````     \n");
printf("`...-----:://---::::://::--:/+++//:::::--:-----:///+++++o+++++/oooooooooooo+oooo+/++ooooooooooo++++++++/.`   ```...--:////////://::....````````  `` ``\n");
printf("``..-----://----:::::/:::--:///+//::::::-:-----:://++++++++++//o+//////////:::/++/++++ooooooo+++++++++/-````````..--://://///:///::....`````````  ````\n");
printf("`...----::/:---:/::://:-:--:::://+///:::--:-----:://++++++++////:-----------.-://+++++++++++++++++++///.````````--::::://///::/+/::....```````````````\n");
printf("`....--::::----:/::///:-:--:::-://+//::::--------::///+++++++++////////:://///+++++++++++++++++++/////:`.`````.--:::::::///:://+/:-.....``````````````\n");
printf("...----:-::----:::////::---:::--://++/::-------.--::////+++++++++++++++++++++++ooooo++++++++++////////-......-----:-:::////::/+/::-......`````````````\n");
printf("...------::.---::::/:/:---::-:-.::////:--.-----.--:::///+++++++o+++++o+++ooooooooooo+++++++++////////:.....--------::::///:::++/:-.......`````````````\n");
printf("...-------:----::::::/:---::--:.:::////---...--.---::://///+++++++++++++++++++++++++++++++//////////:.`.--:--------::://::::/+/:--...........````` ```\n");
printf("....-----------:/::::/:--:::--:.::::://:..-...-..---::://///////////:::/:::---::///////////////////:-.----.-------::://:::::+/-----.........``````````\n");
printf("...----.--.----::-:-:/:--::--.-.::::::/:.........----::::////:::-.```......`````...--::://////////:........------:://:---::/+:-----....```..``````````\n");
printf("...---.....---:::::-:::--::----:::::::/:.``......-.---:::::::...-..----...------:---::::////////:-```.....-.--::-:/::----::+/-------.....```.```````  \n");
printf("...--......--:::::-:-::-:::----:/:::::/:.``...``....---::::::..-::::::::::/::::/::://////////:::-``````.....-::::/:-...--:/+:-------.......``.``````  \n");
printf("...--....----:-::-----:::::---://::-::/-`.`..````....---:::::-----------:-:------::///////::::-.``````.....-:::///-..`.--/+:------:---.........````   \n");
printf("...-.....---:---::----:-::::-::/:----/:..`.`````````...---:::--..----..---..----::///////:::-.````````.....-:://::..``.-://--------::--........``   ``\n");
printf("....-....----.--:-------::::-::-----:/-.``.```````````..-----.-:::::::::::::::::////////::-.```````````...--:/:::.````.-:/----------::--.``.....``````\n");
printf("..--.-..-----..-:---.-.-:::::::----:/:.`.`.```.`````````..------://///////++++++//////::-...`````````.`...--:--:-.````.-/:.-::--------:--..`....``````\n");
printf(".--..-----------:---...-::::::-----/:...``.``....`````````..---.-:///////////////////:--....```````..``...-----:-````.-:/...-:-:-------:-....``..`````\n");
printf("-----------.----::--...-::::/:---:/:-...``..`.``````````````..---::///////////////::--.......```````.``...-------..``.-::....-:::-:-----:-......``````\n");
printf("----:----------:::-.....-////::::/:-..-.....`.``.````````````....--:::::::::::::::---.--.....```````.`....--..--.`.``.-::.`...::::-:-----:-.`....`````\n");
printf("-:::::---------:::-.....-///::://:-...-..........`..````````.......---------------------.....```````......--.--..````.-::.....-::::::-----:-.``...````\n");
printf("::::::-------::--:-.....-://:://:--..-.......`..``````````.........----------------------....```````......--......```.-:-......-:::::::--.-:-.``....``\n");
printf("::::::-------::-::--.....-/////::-----....`..``.`````````.......------------------------....```````.......--.-....`.`.-:-.......-/:/::::----:-```...``\n");
printf(":::--::------::-:::-.....-:///::::-.--..........````````.....----------------::::::::----...```````........--.......`.-::.......-::::::::----:.```..``\n");
printf("-:---::---.---:-::-......-:///:::::.......-..........``.....------::::::::::::::::::::---...``````.`.....-.--.........-::.......--:/::/::------````..`\n");
printf(":----:---..---::::-......::::/:::::-...-.---.............------::::::::::::::::::::::::---....```.``.-...--.--....-...-::-..-....-:::-:::---:--.````.`\n");

	printf("\nZara : Hi ! I am Zara and today I will be your personal assistant !");	
	setcursor(0,53);//(x,y)
	printf("[ ]: Ignore");
	printf("\n[ ]: Ask for more information");
	trex = selector(2,53);//(number of options,y)
	system("cls");
	fflush(stdout);
	
	if(trex==1){
	printf("%s : Yeah right . you disrupted my game and now you want me to listen to you ? IN. YOUR. DREAMS!\n",name);
	getchar();
	printf("Zara : Wait! It is my priority to keep you safe from the apo\n");
	getchar();
	for(i=0;i<time;i++){
	printf("Zara : Wait! It is my priority to keep you safe from the apo\n");
	printf("System shutting down");
	system("cls");
	}
	for(i=0;i<time/2;i++){
	printf("\nSystem shutting down");
	system("cls");
	printf("   t   shu ti g dow ");
	system("cls");
	printf("System");
	system("cls");
	}
	printf("%s : What? Oh I did not see that. Cause I just turned you off. HA! I am gonna go get some drinks now.\n",name);
	getchar();
	printf("%s : Hmm. I wonder what set my computer to go all crazy like that. Meh, time to get myself a new computer I guess\n",name);
	getchar();
	printf("...Suddenly the earth shakes heavily , and %s's house started to tumble apart...\n",name);
	getchar();
	printf("%s : No! Wait! What is going on? Stop shaking dear ground! Oh...\n",name);
	getchar();
	printf("...%s was one of 10,000 innocent people perished from the massive earthquake that has just occured...\n",name);
	tag=11;
	getchar();
	fflush(stdout);
	getchar();
	die();
	
	}else if(trex==2){
		tag=12;
		printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());	
		fflush(stdout);
		getchar();
		curious();
	}else{
		printf("Invalid choice. Try again.");
		dad();
	}
}
	
	void curious(){	
		system("cls");
		printf("\n%s : But - but I bought this computer 10 years ago... And only now you appear? Why should I believe you?\n",name);
		getchar();
		printf("\nZara : Before you ask anymore questions, please grab your phone, I will appear there soon.");
		getchar();
		printf("\nZara : Now quickly, hide yourself under a solid table\n");
		getchar();
		printf("\n%s : O-Okay\n",name);
		printf("*You grabbed your phone*");
		getchar();
		printf("\n%s : Now I am under the table . Now wh-\a\a OH MY GOD!",name);
		getchar();
		printf("\n...Suddenly the earth shakes heavily , and the house %s was living in has started to tumble apart",name);
		getchar();
		printf("\nZara : What hit your house just now was an earthquake of 9.8 magnitude on the Richter Scale .\n");
		getchar();
		printf("\nZara : Suspected death toll is approximately 10,000 people\n");
		getchar();
		printf("\n%s : What?I am confused now ... How did you know all this ? I've got to phone my parents and check on them.\n",name);
		getchar();
		system("cls");
		printf("\n%s : What?I am confused now ... How did you know all this ? I've got to phone my parents and check on them.\n",name);
			Beep(440,800);
			Beep(19,5);
			Beep(440,800);
			Beep(19,5);
		printf("\n...call denied...");
			Beep(440,800);
			Beep(19,5);
			Beep(440,800);
			Beep(19,5);
		printf("\n...call denied...");
			Beep(440,800);
			Beep(19,5);
			Beep(440,800);
			Beep(19,5);
		printf("\n...call denied...\n");
		getchar();
		printf("\nZara :  The earthquake seems to have totally destroyed the line around this area. Luckily I work on satelite.\n");
		getchar();
		printf("\n%s : But I've got to make sure they're safe. I've got to somehow make sure they know that I survived. Wait. Are they fine Zara?\n",name);
		getchar();
		printf("\nZara :  I detect no new health info regarding your parents within the last 4 hours...and I can see them both on CCTV. They're fine",name);
		getchar();
		printf("\n%s : Thank God they are okay.\n",name);
		getchar();
		printf("\nZara :  %s, I suggest we go out there and save your parents. I will be guiding you all the way!\n",name);
		getchar();
		system("cls");
		printf("\nZara :  %s, I suggest we go out there and save your parents. I will be guiding you all the way!\n",name);
		setcursor(0,4);
		printf("[ ] : Go and save the parents");
		printf("\n[ ] : Stay home and wait for them to come back");
		trex = selector(2,4);
		system("cls");
		if(trex==1){
			tag=13;
			printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
getchar();
	fflush(stdout);
			brave();
		}else if(trex==2){
			printf("\n%s : Thank you for that suggestion but I am going to stay put here and wait for them to arrive\n",name);
			getchar();
			printf("Zara : An expected tsunami followed by a hurricane is about to arrive here in the next few hours. I would recommend you leave this house and set foot towards your parents office.\n");
			getchar();
			printf("%s : Now that's just absurd. The beach is 10 km from here. The water can’t possibly reach us out here.\n",name);
			getchar();
			printf("Zara : If my calculations are correct, which they are, it will reach.\n\a");
			getchar();
			printf("%s : I qm fine thanks. Besides, my parents told me not to leave this house for the whole day today so...\n",name);
			getchar();
			printf("... 4 hours later ...\n");
			getchar();
			printf("A series of Tsunami has hit Z - City, where %s was living. Unfortunately he was drowned to death along with 98% of the city's population.",name);
			die();
		}else{
			printf("Invalid choice. Try again.");
			curious();
		}
	}
		
		void brave(){	
			printf("\n%s : I'll have to trust you right... How do you know I'll be safe out there?\n",name);
			getchar();
			printf("\nZara : I will guide you all the way . Get the car keys and will upload the GPS inside the car.\n");
			getchar();
			printf("\n%s : Hmm.. Should I take my dad's Ferrari or my mum's Fiat?\n",name);
			getchar();
			system("cls");
			
			
			printf("\n%s : Hmm.. Should I take my dad's Ferrari or my mum's Fiat?\n",name);
		   	setcursor(0,4);
			printf("[ ] : Ferrari");
		    printf("\n[ ] : Fiat ");
			trex = selector(2,4);
			fflush(stdout);
			system("cls");
			
			if(trex==1){
				tag=14;
				printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());	
				getchar();
				fflush(stdout);
				printf("\n%s : I am going with the Ferrari!",name);
				ferrari();
			}else if(trex==2){
				printf("\n%s : I am going with the Fiat!",name);
				getchar();
				printf("\n%s : We're all set and ready to go!",name);
				move();
			}else{
				printf("Invalid choice. Try again.");
				brave();
			}
		}
			void ferrari(){	
				int passby;
				printf("\n%s : I have always wanted to drive one of these supercars but dad always stopped me.. Today's my chance!!\n",name);
				getchar();
				printf("\n...inside the car.....\n");
				getchar();
				printf("\nZara : Great choice of car. Mind you there is not much fuel left...\n");
				getchar();
				printf("\n%s : Don't worry I know a petrol station nearby. Let's get going! Are we saving mum or dad first??\n",name);
				getchar();
				printf("\nZara : It is important that you know the fact that where your father is working, there is going to be\n");
				printf("\n       a sudden drop in temperature which will ultimately freeze the employees to death .\n");
				getchar();
				printf("\n%s : So let's go and save my dad first then!",name);
				printf("\nZara : I have to inform you that today will be the Judgement Day.");
				printf("\n%s : Judgement Day ? I am still too young to die!",name);
				printf("\nZara : Everybody dies eventually. However you are the chosen one for the future, so I will guide you and save you.");
				printf("\n%s : Wait... Wha- How- I- It doesn't make any se- UGH. I've so many questions to ask, but let's go get my dad first !\n",name);
				getchar();
				printf("\n...10 minutes later...\n");
				getchar();
				printf("\n%s : We've arrived at the petrol station. I'll go get the pump and we should be off soon!",name);
				getchar();
				printf("\n%s : Don't tell dad, but I've took his credit card hehe. It's kind of a dire need now right?\n",name);
				getchar();
				cardpin(&passby);
				if(passby==1){
					//pin success
					tag=16;
					printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
	getchar();
	fflush(stdout);
	getchar();
					printf("\n%s : Bingo ! Now its all fueled up and ready to go ! Which route should we take zara ?",name);
					move();
				}else if(passby==2){
					die();
				}else{
					printf("Invalid choice. Try again.");
					ferrari();
				}
			}
			
			void cardpin(int *y){	
				int pword;
				fflush(stdout);
				int x;
				printf("\n----------------------------------");
				printf("\n*PLEASE ENTER PASSWORD :         *");//If wrong more than 3 , he get stabbed and die
				printf("\n----------------------------------");
				
				printf("\n%s : Now how am I going to guess this ?I'll never get it right \n",name);
				getchar();
				printf("\nZara : It seems that your father is a big fan of Dua Lipa , Beyonce , Taylor Swift and also Adele");
				printf("\nZara : Try putting in one of their birth year ");//Bday Beyonce is right answer ,1977				
				printf("\nEnter password :");
				scanf("%d",&pword);
				
				int i=0;
	
				while (pword!=1977 && i<2)
				{
					printf("\nInvalid ! Please re-enter password :");
					scanf("%d",&pword);
					i++;
				}
				if (i==2)
				{
				printf("\n%s : I can't do this Zara ... It's not going to work , it's impossible ...",name);
				printf("\nZara : Watch out ! There's somebody behind you !");
				printf("\n...A group of thugs has been waiting for a chance to attack %s and after 3 times of incorrect password , they stabbed %s to death and ran off...",name,name);
			    *y=2;
			    return;
				}//continue here
				//success story
				*y=1;
				return;
			}
				
				void move(){	
					printf("\nZara : Very well . We have to get moving now! ");
					getchar();
					printf("\nZara :  I suggest we use the long route as it is a much clearer road and nobody is using it ...");
					getchar();
					
					system("cls");
					printf("\nZara :  I suggest we use the long route as it is a much clearer road and nobody is using it ...");
				   	setcursor(0,4);
					printf("[ ]: short route");
					printf("\n[ ]: long route");
					trex = selector(2,4);
					fflush(stdout);
					system("cls");
					

					if(trex==1){
						printf("\n%s :  I will take the short route Zara . It has to be quicker . The long route is too far i’m afraid we wouldn’t make it in time.",name);
						printf("\nZara : then I shall reroute to the shortest distance. ");
						printf("\n5 minutes into the highway...");
						getchar();
						printf("\n%s :  How come … It’s packed here ! Why ? I have to be quick !",name);
						printf("\nZara : indeed u do . At this rate u wont make it in time .. Plus-");
						printf("\n%s :  Plus what ?",name);
						getchar();
						printf("\nZara :  If we're moving at this pace , we're gonna get swallowed by the earth itself .");
						printf("\n%s : Oh no .. We can’t get out from here either since there’s no way to make a u turn . I have to run now !",name);
						printf("\nZara : it seems we may have made a wrong decision taking this route .. I’m sorry %s",name);
						printf("\n%s :  sorry ? wh- What was that sound ? LOOK AT THAT ! The road upfront has just been swallowed ! Wait.. No... It is continuing its way here.. Nooo!!!",name);
						getchar();						
						printf("\n...The earthquake earlier has caused the ground to fall into pieces ,");
						printf("and the highway was vanished into the core of the earth along with %s and other drivers who were using the road.",name);
						die();
					}else if(trex==2){
						tag=17;
						printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
	getchar();
	fflush(stdout);
	getchar();
						longcut();
					}else{
						printf("Invalid choice. Try again.");
						move();
					}
				}
				
					void longcut(){	
						system("cls");
						fflush(stdout);
						printf("\n%s : I will be using the long route. I think in this situation it is best not to use what people usually prefer which is the short route.",name);
						printf("\nZara : Very well . We have to get moving now! ");
						getchar();
						printf("\n...5 minutes into the road... ");
						getchar();
						printf("\n%s : look there’s an old lady walking cluelessly ! Should I stop by and help her out ?",name);
						printf("\nZara : It is best not to . You cannot trust too many people in the current situation...");
						getchar();
						
						system("cls");
						printf("\n%s : look there’s an old lady walking cluelessly ! Should I stop by and help her out ?",name);
						printf("\nZara : It is best not to . You cannot trust too many people in the current situation...");
					   	setcursor(0,5);
						printf("[ ] : Help");
						printf("\n[ ] : Ignore");
						trex = selector(2,5);
						fflush(stdout);
						system("cls");


						if(trex==1){
							printf("\n%s : I’m gonna slow down and check her out.",name);
							printf("\nZara : ...");
							getchar();
							printf("\n%s : Hello, can I help you ? It seems that you have walked a long distance...",name);
							printf("\nGrandma : Yes... I need... To get past the borders over there... My son is waiting for me");
							printf("\n%s : Hop in please, there’s still a long way to go",name);
							printf("\nGrandma : Thank you... ");
							
							printf("\n*Opens the door*");
							printf("\n*Closes*\a");
							getchar();
							
							printf("\n%s : Where are you fro- why are you pointing the gun at me ??",name);
							printf("\nGrandma : MY LIFE IS MORE IMPORTANT THAN YOURS. Get off this car now and I’ll spare ur life. NOW");
							getchar();
							
							printf("\n%s : please don’t do this .. Drop the gun pls , I’ll help you I promise.",name);
							printf("\n%s slowly holds the gun",name);
							getchar();
							printf("\nBANG! %s was shot!\a",name);
							printf("\nGrandma : I TOLD YOU NOT TO TOUCH IT !");
							die();
						}else if(trex==2){
							tag=18;
							printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
							getchar();
	fflush(stdout);
	getchar();
							ignoreold();
						}else{
							printf("Invalid choice. Try again.");
							longcut();
						}
					}
					
						void ignoreold(){	
							system("cls");
							printf("\n%s :  I have to ignore her .. I am afraid we wont make it in time if I help her.",name);
							
							printf("\nZara :  the lady you just saw was guilty of 56 murders in this state . You made the right choice ignoring her .");
							
							printf("\n%s :  What ? Couldn''t you tell me earlier , god !",name);
							getchar();
							printf("\nZara : I am relying on satellites to gether information. It's slower than 4G.");
							printf("\nZara : Didn't you learn this in your Computer Science class?");
							printf("\n%s : Hey I do focus in cla- Okay never mind.",name);
							printf("\n...5 minutes later...");
							getchar();
							
							printf("\n%s : Looks like we have arrived to dad's office,Zara",name);
							printf("\nZara : It is wise for you to go and ask the receptionist where your father is now .");
							printf("\n%s : Excuse me, Miss Pamela. do you know where Mr. Jacob is now ?",name);
							getchar();
							
							printf("\nMs. Pamela : Yes, he's currently in a meeting with the Head of the company up at the 7th floor.");
							printf("\n%s : Oh- Okay. When will the meeting end?",name);
							getchar();
							
							printf("\nMs.Pamela : It'll be about 3 hours from now.");
							printf("\n%s : Okay. Thank you Miss",name);
							printf("\nZara : For your information, the storm is about to come in around 15 minutes, so 3 hours is not enough.");
							printf("\n%s : I know but, but he's in a meeting right now and I can't just barge in, right ?",name);
							printf("\n%s : Let's get to the 7th floor first eh.",name);
							printf("\n...At the 7th floor...",name);
							printf("\n%s : We've arrived at the room Zara.",name);
							printf("\nZara : What do you want to do now, %s?\n",name);
							getchar();

							system("cls");
							printf("Ms.Pamela : It'll be about 3 hours from now.");
							printf("\n%s : Okay. Thank you Miss",name);
							printf("\nZara : For your information, the storm is about to come in around 15 minutes, so 3 hours is not enough.");
							printf("\n%s : I know but, but he's in a meeting right now and I can't just barge in, right ?",name);
							printf("\n%s : Let's get to the 7th floor first eh.",name);
							printf("\n...At the 7th floor...",name);
							printf("\n%s : We've arrived at the room Zara.",name);
							printf("\nZara : What do you want to do now, %s?\n",name);
						   	setcursor(0,11);
							printf("[ ] : Barge in ");
							printf("\n[ ] : Wait for the meeting to end ");
							trex = selector(2,11);
							fflush(stdout);
							system("cls");



							if(trex==1){
								tag=19;
								
								printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
								getchar();
	fflush(stdout);
	getchar();
								barge();
							}else if(trex==2){
																
								printf("\n%s :  I think I'll wait for dad outside ,Zara",name);
								printf("\nZara : THE ICE RAIN IS GOING TO ARRIVE IN 15 MINUTES , YOU HAVE NO IDE-");
								printf("\n%s : Zara, It's fine . This building is strong !",name);
								printf("\nZara : Humans have all the right to make their own choices.");
								getchar();
								
								printf("\n...A sudden drop in temperature has caused the entire building of %s's father's office to be freeze in an instant...",name);
								getchar();
								printf("\n...There are no known survivors.");
								die();
							}else{
								printf("Invalid choice. Try again.");
								ignoreold();
							}
						}
					
							void barge(){	
								system("cls");
								
								printf("\nBANG!");
								getchar();
								printf("\n%s : Sorry , but I have to talk to my dad , Mr. Jacob , right now !",name);
								printf("\nDad : What are you doing here %s? Let's talk this outside will you ?I am sorry everyone to cause such a chaos in this meeting",name);
								getchar();
								printf("\n...Outside the meeting room...");
								getchar();
								printf("\nDad : WHAT IN THE WORLD DO YOU THINK YOU ARE DOING?!");
								printf("\n%s : Dad, it's an urgent matter ,please believe me !",name);
								printf("\nDad : Whatever it is , you don't have to barge in like that ! You're a dissapointment!");
								printf("\n%s : Dad, our house was struck by an earthquake...Look at this picture",name);
								printf("\nDad : Oh my god ... How did you end up alive ? That looked devastating...");
								printf("\n%s : This is Zara ,dad and he helped me so much ! She told me to save you first and then mum !",name);
								getchar();
								
								printf("\nDad : Well, save me from what ? ");
								printf("\nZara : We have to get moving . Explain it to him other time, %s",name);
								printf("\n%s : Right . Dad . Come on . Follow me , we have to save mum now ",name);
								printf("\nZara : Your father are not allowed to follow or it will lower the probability of saving your mother.");
								printf("\nDad : But I am his husband ! You have no righ-");
								printf("\nZara :  It is a wiser choice to put him in a car , I will auto drive the car myself to a more secure place");
								getchar();
								
									
								system("cls");								
								printf("\nDad : Well, save me from what ? ");
								printf("\nZara : We have to get moving . Explain it to him other time, %s",name);
								printf("\n%s : Right . Dad . Come on . Follow me , we have to save mum now ",name);
								printf("\nZara : Your father are not allowed to follow or it will lower the probability of saving your mother.");
								printf("\nDad : But I am his husband ! You have no righ-");
								printf("\nZara :  The wiser choice is to put him in a car , I will auto drive the car myself to a more secure place");
							   	setcursor(0,8);
								printf("[ ]: Send dad to a car");
								printf("\n[ ]: Let dad follow ");
								trex = selector(2,8);
								fflush(stdout);
								system("cls");
				
								
								if(trex==1){
									printf("\n%s : Dad, it's fine . You can trust her .Trust me ",name);
									printf("\nDad : If anything is to happen to your mother, I won't forgive you!");
									printf("\n%s : Dad. I promise . Everything will be fine . Let's get you a car and Zara will help you ",name);
									getchar();
									printf("\n...After arriving at the ground floor , %s sent his dad to a car auto-driven by Zara to an unknown place...",name);
									daddy=1;
										fflush(stdout);
	printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
	getchar();
	fflush(stdout);

								}else if(trex==2){
									
									
									printf("\n%s : Zara, I think it's fine with dad following us . Besides, I am scared if anything were to happen to him.",name);
									printf("\nZara : So be it");
									printf("\nDad : Your mother is special to me , I can't let you save her alone ...");
									printf("\n      And your my child.if anything happens...I can't forgive myself");
									printf("\n%s : It's okay dad.Let's get her together",name);
									
									printf("\n...At the ground floor , there was no car to be driven ...");
									printf("\n%s : We just have to make a run for it ,won't we?",name);
									printf("\nZara : We have to be quick !");
									getchar();
									
									printf("\n...After 30 minutes of jogging...");
									getchar();
									
									printf("\n%s : Dad we can't slow down. We have to hurry",name);
									printf("\nDad : Don't worry son, I'll catch up to you ... (pants)",name);
									printf("\nZara : You have to tell your father . He has to be quick . A disaster is coming.");
									printf("\n%s : What kind of dis- DAD!!! NO! ",name);
									getchar();
									printf("\n...Mr.Jacob was swallowed by the earth as the ground suddenly collapsed...");
									getchar();
									printf("\n%s : Dad no ... I am sorry dad ...",name);
									printf("\nZara : We have to get going now %s ... Remember what you promised to your father ... ",name);
									getchar();
									printf("\n%s : For your sake , Dad ... I WILL SAVE MOM!",name);
									//handle dad dying
									daddy=0;
								}else{
									printf("Invalid choice. Try again.");
									barge();
								}
								mum();
							}
							
							
void mum(){	
	system("cls");
	int i, j;
	for(i=0;i<time;i++){
	printf("+-+-+-+-+-+-+-+-+-+-+-+-SOFTWARE UPDATE+-+-+-+-+-+-+-+-+-+-+-+- %d%%\n",i*100/time);
	system("cls");
	printf("-+-+-+-+-+-+-+-+-+-+-+-+SOFTWARE UPDATE-+-+-+-+-+-+-+-+-+-+-+-+ %d%%\n",i*100/time);
	system("cls");
	}
		getchar();
		for(i=0;i<time/2;i++){

printf("``````  ` ````````...---/+osso/:-.-://:::::-::::-----::::::::///////+++++++++ooooooooooooooooooooo+o/+///:::////:/:::-::::-......```````    ````````  \n");
printf("```````` ````.```...--::+ooso/::.:////://///:::------::::::://///+++++++ooooooooooooooooooooooooooo++////:::::///////::://-:--:.-.-.``````  ``````````\n");
printf("```````````````````..-:/++so+/::/+++++++///:::::::::::::///////+++oooooooooooooooooooooooooooooooo++++//::----:::///////++++//:://-.``````````````````\n");
printf("`````````````````...--:+++o+/:/+++////:---.-----::::://///++++++oooossooooooooooooooooooooooooo+++++++//:::-----:::///////++++///-.`````````          \n");
printf("````````````````....-:///++//++++////:::---..--::////++++++++ooooooososooooooooooooooo++++o+o+++++++++//::---...--::::/::::::-----.``````             \n");
printf("`````````````.```..--://+///++++++++//::-----::://+++++++ooooooooossssoooooooooooooooo++++++++++++++++//::--.....---:::::::-------..```````           \n");
printf("  ```````````````...-:://++oo++o++//:----...-:://+++++ooooooooooooooooooooooooooooooo++++++++++++++++++/::--..`..---::::::::::----...`````            \n");
printf("````  ``````````...-::://+++++++//:------..--:///++++++ooooooooooooooooooooooooooo+++++++++++++++++++++/::--...``..---::::::::-.--.`.`````            \n");
printf("````     ```````..-::::/+++//++/:/:-----...-:://+++++++++oooooooooooooooooooooooo+++++++++++++++++++++///---.-..`...-:-::::::::-.-.``.```             \n");
printf("``````` ` ``````.-::::/o+o+//+///:-----:-.-:::///++++++++++++++ooooooooooooooo+++++++++++oooooo+++++++///:-----.....--::::/:::/:---```.```            \n");
printf("```````````````.-:::::+ooo+:/+//:-.--.::..-::////+++++++++++++++ooooooo++++++++++++++++ooooooooooo++++///:-.---:-...--::////////::-.```````         ``\n");
printf("``````````````.--::::/+++o//+++/:--.--::..-:///++++++++++++++++++++++++++++++///+/////////////+++++++////:-..----:----::////////+-:.```````````   ````\n");
printf("`````````..``..--:::/++++///+/+//-----:-..-:///++++++++++++///++++++++///////:::--.........-------:://////:.`.-:---:::::/+++///++/:-``.`..`````    ```\n");
printf("````````````...--:::+//+////+/+//:---::-..-::::::::::::::://///////+++////:::--..````````.........---::://:...--:/::-:///++++///++/:.`....```````   ` \n");
printf("```````````...-:::://:/+//:/+++/:::-:::-.`.-----.....````....-::///+++++//::--..````````...```....-.---::/:-`.---:///::://+o++//++//......``````````  \n");
printf("``````````.`..-::::+/://:/:/+++/:::-/::-.`.........``````````..-:://++++///:--.````````......````...---::/:-...---://///://++++//+//:.....````````````\n");
printf("`````````...---::-:++://:////+/:::::::--.```````````.`.``.````..-:/++++++//::...``.-.`````````````..--:::/:-......-:://////+++///+/:/.```.````````````\n");
printf(" ``````....--:-:--//+:/://:////-:::::--..```````````````.--.`...-:/+++++++//:-..`.-::...```.-......--::://:-...-....-:///////++//+/:::.`.`````````````\n");
printf("```````....--:::--://:/://:://:::/:::-....``````...``...::-.....-:/++oooo++//:-...--::----::-------:::////:-..`..-...-://+///++///:--::.```````  ```  \n");
printf("```````...--:::---/:/:////:://::/::----....````..----------...--://+oooooo++///::-...-------------:://////:-.` `..--..-://+///++/+:..-/-`.````````````\n");
printf("`````....-:::::---/:::///::://::/:::-:-.....`````..........---:///+ooooooo++++++//:------::::-::::////////:..` ```.----:/+////++/+:--./-``````````````\n");
printf("````..-.-:::::---:::://::::://::::::-:-................---::////++oosssssoo+++++++++/////:://////////++///:.``  ```..--://////+++/-.---.````    ``````\n");
printf("``...-.-::::::--:::--///::-:///::::::--..-....------:::::///+++++oossssssooo++++++++++++++++++++++++++++//.```  ```..--:///////++::::..````      `````\n");
printf("``..----:-::::::::::-://::-:++/:::::::-.-------:::::::///++++++++ossyyyyssoo+++++++oooooo+++++++++++++++/:``   ````...-:/++////++/:-..```````     ``  \n");
printf("``..---:-:::::/::::::///:--:+++//:/:::---------::://///++++++++++osyyyyyyssoo++++++ooooooooooo++++++++++/.`   ````....-:/+/////+//--..`````  ``       \n");
printf("``..-----::///:-:::::///:--:+++/::::::---:----::://++++++++++++/+sssyyyyssssooo+/++ooooooooooooo+++++++/-`  `````....-::///////+//:....``````````     \n");
printf("`...-----:://---::::://::--:/+++//:::::--:-----:///+++++o+++++/oooooooooooo+oooo+/++ooooooooooo++++++++/.`   ```...--:////////://::....````````  `` ``\n");
printf("``..-----://----:::::/:::--:///+//::::::-:-----:://++++++++++//o+//////////:::/++/++++ooooooo+++++++++/-````````..--://://///:///::....`````````  ````\n");
printf("`...----::/:---:/::://:-:--:::://+///:::--:-----:://++++++++////:-----------.-://+++++++++++++++++++///.````````--::::://///::/+/::....```````````````\n");
printf("`....--::::----:/::///:-:--:::-://+//::::--------::///+++++++++////////:://///+++++++++++++++++++/////:`.`````.--:::::::///:://+/:-.....``````````````\n");
printf("...----:-::----:::////::---:::--://++/::-------.--::////+++++++++++++++++++++++ooooo++++++++++////////-......-----:-:::////::/+/::-......`````````````\n");
printf("...------::.---::::/:/:---::-:-.::////:--.-----.--:::///+++++++o+++++o+++ooooooooooo+++++++++////////:.....--------::::///:::++/:-.......`````````````\n");
printf("...-------:----::::::/:---::--:.:::////---...--.---::://///+++++++++++++++++++++++++++++++//////////:.`.--:--------::://::::/+/:--...........````` ```\n");
printf("....-----------:/::::/:--:::--:.::::://:..-...-..---::://///////////:::/:::---::///////////////////:-.----.-------::://:::::+/-----.........``````````\n");
printf("...----.--.----::-:-:/:--::--.-.::::::/:.........----::::////:::-.```......`````...--::://////////:........------:://:---::/+:-----....```..``````````\n");
printf("...---.....---:::::-:::--::----:::::::/:.``......-.---:::::::...-..----...------:---::::////////:-```.....-.--::-:/::----::+/-------.....```.```````  \n");
printf("...--......--:::::-:-::-:::----:/:::::/:.``...``....---::::::..-::::::::::/::::/::://////////:::-``````.....-::::/:-...--:/+:-------.......``.``````  \n");
printf("...--....----:-::-----:::::---://::-::/-`.`..````....---:::::-----------:-:------::///////::::-.``````.....-:::///-..`.--/+:------:---.........````   \n");
printf("...-.....---:---::----:-::::-::/:----/:..`.`````````...---:::--..----..---..----::///////:::-.````````.....-:://::..``.-://--------::--........``   ``\n");
printf("....-....----.--:-------::::-::-----:/-.``.```````````..-----.-:::::::::::::::::////////::-.```````````...--:/:::.````.-:/----------::--.``.....``````\n");
printf("..--.-..-----..-:---.-.-:::::::----:/:.`.`.```.`````````..------://///////++++++//////::-...`````````.`...--:--:-.````.-/:.-::--------:--..`....``````\n");
printf(".--..-----------:---...-::::::-----/:...``.``....`````````..---.-:///////////////////:--....```````..``...-----:-````.-:/...-:-:-------:-....``..`````\n");
printf("-----------.----::--...-::::/:---:/:-...``..`.``````````````..---::///////////////::--.......```````.``...-------..``.-::....-:::-:-----:-......``````\n");
printf("----:----------:::-.....-////::::/:-..-.....`.``.````````````....--:::::::::::::::---.--.....```````.`....--..--.`.``.-::.`...::::-:-----:-.`....`````\n");
printf("-:::::---------:::-.....-///::://:-...-..........`..````````.......---------------------.....```````......--.--..````.-::.....-::::::-----:-.``...````\n");
printf("::::::-------::--:-.....-://:://:--..-.......`..``````````.........----------------------....```````......--......```.-:-......-:::::::--.-:-.``....``\n");
printf("::::::-------::-::--.....-/////::-----....`..``.`````````.......------------------------....```````.......--.-....`.`.-:-.......-/:/::::----:-```...``\n");
printf(":::--::------::-:::-.....-:///::::-.--..........````````.....----------------::::::::----...```````........--.......`.-::.......-::::::::----:.```..``\n");
printf("-:---::---.---:-::-......-:///:::::.......-..........``.....------::::::::::::::::::::---...``````.`.....-.--.........-::.......--:/::/::------````..`\n");
printf(":----:---..---::::-......::::/:::::-...-.---.............------::::::::::::::::::::::::---....```.``.-...--.--....-...-::-..-....-:::-:::---:--.````.`\n");
}
system("cls");
printf("``````  ` ````````...---/+osso/:-.-://:::::-::::-----::::::::///////+++++++++ooooooooooooooooooooo+o/+///:::////:/:::-::::-......```````    ````````  \n");
printf("```````` ````.```...--::+ooso/::.:////://///:::------::::::://///+++++++ooooooooooooooooooooooooooo++////:::::///////::://-:--:.-.-.``````  ``````````\n");
printf("```````````````````..-:/++so+/::/+++++++///:::::::::::::///////+++oooooooooooooooooooooooooooooooo++++//::----:::///////++++//:://-.``````````````````\n");
printf("`````````````````...--:+++o+/:/+++////:---.-----::::://///++++++oooossooooooooooooooooooooooooo+++++++//:::-----:::///////++++///-.`````````          \n");
printf("````````````````....-:///++//++++////:::---..--::////++++++++ooooooososooooooooooooooo++++o+o+++++++++//::---...--::::/::::::-----.``````             \n");
printf("`````````````.```..--://+///++++++++//::-----::://+++++++ooooooooossssoooooooooooooooo++++++++++++++++//::--.....---:::::::-------..```````           \n");
printf("  ```````````````...-:://++oo++o++//:----...-:://+++++ooooooooooooooooooooooooooooooo++++++++++++++++++/::--..`..---::::::::::----...`````            \n");
printf("````  ``````````...-::://+++++++//:------..--:///++++++ooooooooooooooooooooooooooo+++++++++++++++++++++/::--...``..---::::::::-.--.`.`````            \n");
printf("````     ```````..-::::/+++//++/:/:-----...-:://+++++++++oooooooooooooooooooooooo+++++++++++++++++++++///---.-..`...-:-::::::::-.-.``.```             \n");
printf("``````` ` ``````.-::::/o+o+//+///:-----:-.-:::///++++++++++++++ooooooooooooooo+++++++++++oooooo+++++++///:-----.....--::::/:::/:---```.```            \n");
printf("```````````````.-:::::+ooo+:/+//:-.--.::..-::////+++++++++++++++ooooooo++++++++++++++++ooooooooooo++++///:-.---:-...--::////////::-.```````         ``\n");
printf("``````````````.--::::/+++o//+++/:--.--::..-:///++++++++++++++++++++++++++++++///+/////////////+++++++////:-..----:----::////////+-:.```````````   ````\n");
printf("`````````..``..--:::/++++///+/+//-----:-..-:///++++++++++++///++++++++///////:::--.........-------:://////:.`.-:---:::::/+++///++/:-``.`..`````    ```\n");
printf("````````````...--:::+//+////+/+//:---::-..-::::::::::::::://///////+++////:::--..````````.........---::://:...--:/::-:///++++///++/:.`....```````   ` \n");
printf("```````````...-:::://:/+//:/+++/:::-:::-.`.-----.....````....-::///+++++//::--..````````...```....-.---::/:-`.---:///::://+o++//++//......``````````  \n");
printf("``````````.`..-::::+/://:/:/+++/:::-/::-.`.........``````````..-:://++++///:--.````````......````...---::/:-...---://///://++++//+//:.....````````````\n");
printf("`````````...---::-:++://:////+/:::::::--.```````````.`.``.````..-:/++++++//::...``.-.`````````````..--:::/:-......-:://////+++///+/:/.```.````````````\n");
printf(" ``````....--:-:--//+:/://:////-:::::--..```````````````.--.`...-:/+++++++//:-..`.-::...```.-......--::://:-...-....-:///////++//+/:::.`.`````````````\n");
printf("```````....--:::--://:/://:://:::/:::-....``````...``...::-.....-:/++oooo++//:-...--::----::-------:::////:-..`..-...-://+///++///:--::.```````  ```  \n");
printf("```````...--:::---/:/:////:://::/::----....````..----------...--://+oooooo++///::-...-------------:://////:-.` `..--..-://+///++/+:..-/-`.````````````\n");
printf("`````....-:::::---/:::///::://::/:::-:-.....`````..........---:///+ooooooo++++++//:------::::-::::////////:..` ```.----:/+////++/+:--./-``````````````\n");
printf("````..-.-:::::---:::://::::://::::::-:-................---::////++oosssssoo+++++++++/////:://////////++///:.``  ```..--://////+++/-.---.````    ``````\n");
printf("``...-.-::::::--:::--///::-:///::::::--..-....------:::::///+++++oossssssooo++++++++++++++++++++++++++++//.```  ```..--:///////++::::..````      `````\n");
printf("``..----:-::::::::::-://::-:++/:::::::-.-------:::::::///++++++++ossyyyyssoo+++++++oooooo+++++++++++++++/:``   ````...-:/++////++/:-..```````     ``  \n");
printf("``..---:-:::::/::::::///:--:+++//:/:::---------::://///++++++++++osyyyyyyssoo++++++ooooooooooo++++++++++/.`   ````....-:/+/////+//--..`````  ``       \n");
printf("``..-----::///:-:::::///:--:+++/::::::---:----::://++++++++++++/+sssyyyyssssooo+/++ooooooooooooo+++++++/-`  `````....-::///////+//:....``````````     \n");
printf("`...-----:://---::::://::--:/+++//:::::--:-----:///+++++o+++++/oooooooooooo+oooo+/++ooooooooooo++++++++/.`   ```...--:////////://::....````````  `` ``\n");
printf("``..-----://----:::::/:::--:///+//::::::-:-----:://++++++++++//o+//////////:::/++/++++ooooooo+++++++++/-````````..--://://///:///::....`````````  ````\n");
printf("`...----::/:---:/::://:-:--:::://+///:::--:-----:://++++++++////:-----------.-://+++++++++++++++++++///.````````--::::://///::/+/::....```````````````\n");
printf("`....--::::----:/::///:-:--:::-://+//::::--------::///+++++++++////////:://///+++++++++++++++++++/////:`.`````.--:::::::///:://+/:-.....``````````````\n");
printf("...----:-::----:::////::---:::--://++/::-------.--::////+++++++++++++++++++++++ooooo++++++++++////////-......-----:-:::////::/+/::-......`````````````\n");
printf("...------::.---::::/:/:---::-:-.::////:--.-----.--:::///+++++++o+++++o+++ooooooooooo+++++++++////////:.....--------::::///:::++/:-.......`````````````\n");
printf("...-------:----::::::/:---::--:.:::////---...--.---::://///+++++++++++++++++++++++++++++++//////////:.`.--:--------::://::::/+/:--...........````` ```\n");
printf("....-----------:/::::/:--:::--:.::::://:..-...-..---::://///////////:::/:::---::///////////////////:-.----.-------::://:::::+/-----.........``````````\n");
printf("...----.--.----::-:-:/:--::--.-.::::::/:.........----::::////:::-.```......`````...--::://////////:........------:://:---::/+:-----....```..``````````\n");
printf("...---.....---:::::-:::--::----:::::::/:.``......-.---:::::::...-..----...------:---::::////////:-```.....-.--::-:/::----::+/-------.....```.```````  \n");
printf("...--......--:::::-:-::-:::----:/:::::/:.``...``....---::::::..-::::::::::/::::/::://////////:::-``````.....-::::/:-...--:/+:-------.......``.``````  \n");
printf("...--....----:-::-----:::::---://::-::/-`.`..````....---:::::-----------:-:------::///////::::-.``````.....-:::///-..`.--/+:------:---.........````   \n");
printf("...-.....---:---::----:-::::-::/:----/:..`.`````````...---:::--..----..---..----::///////:::-.````````.....-:://::..``.-://--------::--........``   ``\n");
printf("....-....----.--:-------::::-::-----:/-.``.```````````..-----.-:::::::::::::::::////////::-.```````````...--:/:::.````.-:/----------::--.``.....``````\n");
printf("..--.-..-----..-:---.-.-:::::::----:/:.`.`.```.`````````..------://///////++++++//////::-...`````````.`...--:--:-.````.-/:.-::--------:--..`....``````\n");
printf(".--..-----------:---...-::::::-----/:...``.``....`````````..---.-:///////////////////:--....```````..``...-----:-````.-:/...-:-:-------:-....``..`````\n");
printf("-----------.----::--...-::::/:---:/:-...``..`.``````````````..---::///////////////::--.......```````.``...-------..``.-::....-:::-:-----:-......``````\n");
printf("----:----------:::-.....-////::::/:-..-.....`.``.````````````....--:::::::::::::::---.--.....```````.`....--..--.`.``.-::.`...::::-:-----:-.`....`````\n");
printf("-:::::---------:::-.....-///::://:-...-..........`..````````.......---------------------.....```````......--.--..````.-::.....-::::::-----:-.``...````\n");
printf("::::::-------::--:-.....-://:://:--..-.......`..``````````.........----------------------....```````......--......```.-:-......-:::::::--.-:-.``....``\n");
printf("::::::-------::-::--.....-/////::-----....`..``.`````````.......------------------------....```````.......--.-....`.`.-:-.......-/:/::::----:-```...``\n");
printf(":::--::------::-:::-.....-:///::::-.--..........````````.....----------------::::::::----...```````........--.......`.-::.......-::::::::----:.```..``\n");
printf("-:---::---.---:-::-......-:///:::::.......-..........``.....------::::::::::::::::::::---...``````.`.....-.--.........-::.......--:/::/::------````..`\n");
printf(":----:---..---::::-......::::/:::::-...-.---.............------::::::::::::::::::::::::---....```.``.-...--.--....-...-::-..-....-:::-:::---:--.````.`\n");
	printf("\n%s : What was that?",name);
	getchar();
	printf("\nZara : Sorry, that was a software update. I should be more efficient now!");
	getchar();
	printf("%s : Okay great! I don't have a car. Now whatt?? How can I go to help my mom??",name);
	getchar();
	printf("\nZara : You have 2 options right now.\n       1.You can go by bus\n       2.You can call an uber for a ride");
	printf("\n%s : Okay let me think really fast",name);
	fflush(stdout);
	tag=20;
	printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
	fflush(stdout);

	system("cls");	
	printf("Zara : You have 2 options right now.\n       1.You can go by bus\n       2.You can call an uber for a ride");
	printf("\n%s : Okay let me think really fast",name);
   	setcursor(0,4);
	printf("[ ]: Bus");
	printf("\n[ ]: Uber ");
	trex = selector(2,4);
	fflush(stdout);
	system("cls");

	
	if(trex==1){
		bus();	
	}else if(trex==2){
		uber();
	}else{
		printf("Invalid choice. Try again.");
		mum();
	}
}

		void bus(){	
			system("cls");
			printf("\n%s : Zara where is the closest bus station from here?",name);
			getchar();
			printf("\nZara : You can walk 300m from here.");
			getchar();
			printf("\n%s : LEtzzgooo!! no time to waste",name);
			getchar();
			printf("\nZara : Okay.");
			getchar();
			printf("\n%s : We have entered the bus..Now we just have to wait until we arrived at mom's office");
			printf("\nAfter a few minutes sitting and waiting on the bus, you realise that the old man standing beside you is staring at you...");
			getchar();
			printf("\nYou feel guilty about it and you thought of giving him your seat");
			printf("\nWhat will you do?");
			getchar();
			printf("\n[ ] Pretend to sleep and continue to sit until you arrive at your mom's office\n[ ] Politely offer him your seat");
			getchar();
			fflush(stdout);
			tag=21;
			
			printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
			fflush(stdout);
			
			system("cls");				
			printf("\nYou feel guilty about it and you thought of giving him your seat");
			printf("\nWhat will you do?");


		   	setcursor(0,5);
			printf("[ ]Pretend to sleep and continue to sit until you arrive at your mom's office\n[ ]olitely offer him your seat");
			trex = selector(2,4);
			fflush(stdout);
			system("cls");
			
			
			
			if(trex==1){
				printf("\nYou pretend to sleep and close your eyes but suddenly you feel very sleepy and decide to take a short nap");
				printf("\nYou overslept. After a few hours of sleeping..");
				getchar();
				printf("\n%s : Zara where are we now? How long have I sleep?",name);
				getchar();
				printf("\nZara : We are now at two station past your mom's office and you have been sleeping for two hours.");
				getchar();
				printf("\n%s : Whyy don't you wake me up ?:(",name);
				getchar();
				printf("\nZara : I have tried...I keep vibrating your phone but you sleep like a log and do not want to wake up..");
				getchar();
				printf("\n%s : Heheheheh..Oh sorry now let's stop at this station and we figure out other ways to go to mom's office",name);
				getchar();
				printf("\nZara : Right.");
				getchar();
				printf("\nYou arrive at the bus station and you go out the bus");
				printf("\nWaiting you outside is a group of policemen doing an investigation");
				getchar();
				printf("\n%s : What are these police doing here Zara?",name);
				getchar();
				printf("\nZara : I do not know.");
				getchar();
				printf("\nPolice:We have found out that there are drugs inside this bus");
				printf("\nPolice: We are now searching for it and nobody can leave until we finish the investigation");
				printf("\nThen the police start investigating everyone on the bus");
				getchar();
				printf("\n%s : That old man beside me!! I am sure that he is the one carrying drugs",name);
				getchar();
				printf("\nZara : Why do you think he is the one who did it %s?",name);
				getchar();
				printf("\n%s : I don't know.. He looks so creepy and looks like hiding something",name);
				getchar();
				printf("\nPolice:You boy come here.. You are next..");
				printf("\n%s : Ohh okay sir but I need to hurry so please make it quick..",name);
				printf("\nThen one of the police search your body");
				getchar();
				printf("\nPolice:What is this boy?");
				printf("\nThe police show a packet of an unidentified white powder to you");
				getchar();
				printf("\n%s : What is that sir? Where did you find it?",name);
				getchar();
				printf("\nPolice:INSIDE YOUR BACK JEAN'S POCKET!!");
				printf("\nPolice:STOP THE INVESTIGATION AT ONCE. WE HAVE FOUND THE CULPRIT!!");
				getchar();
				printf("\n%s : Whatt??I swear that's not mine sir..I swear I don't know anything about it",name);
				getchar();
				printf("\nPolice:REMAIN SILENT!! Let's go to the police station for further investigation");
				printf("\nThe police handcuffed you and drag you to the police station");
				getchar();
				printf("\n%s : Help me Zara! Do something!",name);
				getchar();
				printf("\nZara : I am afraid I cannot help you this time %s",name);
				getchar();
				printf("\nThe police questions you inside the police station, your phone was confiscated and you deny all the police accusation");
				printf("\nAfter a few hours of investigation, everyone inside the police station were shocked by the sound of earthquake near the police station");
				getchar();
				printf("\nWithout any time to react, the ground under the police station star to break and split");
				printf("\nThe police station then starts collapsing");
				printf("\nThe police run away saving their ownselves and leave you behind");
				getchar();
				printf("\nYou, handcuffed to a chair cannot do much and cunable to move. You can only scream as you start falling into the earth when the ground split right under you");
				die();
			}else if(trex==2){
			oldman();
			}else{
				printf("Invalid choice. Try again.");
				bus();
			}
		}	
			void oldman(){	
				system("cls");
				printf("\n%s : would you like to seat sir?",name);
				getchar();
				printf("\nThe old man suddenly starts smiling and beginning to talk");
				printf("\nOld man:You are a good kid ..Thank you for offering me your seat but I don't need the seat as I will go out on the next station 3 minutes from here");
				getchar();
				printf("\n%s : ohh okay sir but can I ask you a question?",name);
				getchar();
				printf("\nOld Man: Yeah sure");
				getchar();
				printf("\n%s : excuse me but why are you staring at me like that?",name);
				getchar();
				printf("\nOld Man:Ohh thank you for asking.. I almost forgot to tell you there is a young man put something inside your back jean's pocket when you enter the bus");
				printf("\nOld Man:The young man is nowhere to be found now as he left the bus soon after doing that thing to you");
				getchar();
				printf("\nYou check your back pocket"); 
				getchar();
				printf("\n%s : What is this??",name);
				printf("\nYou hold a packet of unidentified white powder inside a small plastic");
				getchar();
				printf("\nOld Man:That is a drugs my boy.. Now give it to me before you get caught because of it");
				getchar();
				printf("\nYou give the thing to the old man and he throw it outside the bus window");
				getchar();
				printf("\nThe bus stop");
				getchar();
				printf("\nOld Man:Okay my station is this one.. Good luck on your journey kid");
				getchar();
				printf("\n%s : Thank you old man",name);
				getchar();
				printf("\nZara : That is one nice man"); 
				getchar();
				printf("\n%s : Yeah I think so too Zara",name);
				getchar();
				printf("\nThe Old Man smiles and go out the bus");
				printf("\nAfter 30 minutes, you arrived at your destination");
				fflush(stdout);
				riddle();
			}

				
				
		void uber(){	
			system("cls");
			printf("\n%s : How about we call an uber Zara?",name);
			getchar();
			printf("\nZara : Sure I will follow any of your choice");
			getchar(); 
			printf("\n%s : Hmm Zara what is an uber?? heheheh I had never ride one before",name);
			getchar();
			printf("\nZara Smacks her virtual forehead while shaking her virtual head");
			getchar();
			printf("\nZara : You are soooo rich %s",name);
			getchar();
			printf("\n%s : Come onn Zara help me please...",name);
			getchar();
			printf("\nZara help you download the uber app and order a ride straight to your mom's office");
			getchar(); 
			printf("\n%s : The uber is here Zara! Letzagooo",name);
			printf("\nYou enter the uber and your ride starts");
			getchar();
			printf("\nAfter a few minutes inside the uber you feel slightly uneasy as you and the uber driver do not make any conversation");
			getchar();

			fflush(stdout);
			tag=22;
			printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
			
				
							system("cls");
							printf("\nAfter a few minutes inside the uber you feel slightly uneasy as you and the uber driver do not make any conversation");
							printf("You decide to");
							setcursor(0,11);
							printf("[ ] Talk with the uber driver\n[ ] Keep silent and wait until you arrive at your destination");
							trex = selector(2,11);
							fflush(stdout);
							system("cls");
			
			
			
			if(trex==1){
				talk();
			}else if(trex==2){
				silence();
			}else{
				printf("Invalid choice. Try again.");
				uber();
			}
		}
			void talk(){	
				system("cls");
				printf("\n%s : Hello sir, how are you doing today?",name);
				getchar();
				printf("\nThe uber driver look at you and continue driving");
				getchar();
				printf("\n%s : Let's have a conversation sir... Sir?",name);
				getchar();
				printf("\nUber Driver : Please stop");
				getchar();
				printf("\n%s : I just want to talk with you sir what is wrong with that??",name);
				getchar();
				printf("\nUber Driver : I SAID STOPPP!");
				getchar();
				printf("\nZara : %s I think you should stop..",name);
				getchar();
				printf("\n%s : What is wrong with you sir?? I am not gonna give you any star on your uber driving if you keep this attitude sir..",name); 
				getchar();
				printf("\nThe uber driver then starts screaming");
				printf("\nUber Driver : ARGHHHH!  WHAT IS WRONG WITH EVERYONE!! ALL I NEED IS SILENCE!"); 
				getchar();
				printf("\nUber Driver : MY BOSS SCREAMS AT ME EVERYTIME! MY WIFE IS MAD AT ME ON EVERY SINGLE THING... MY KID CANT STOP CRYING AT HOME AND NOW YOUUUUU!!");
				getchar();
				printf("\nThe Yoober driver start driving like a crazy person");
				getchar();
				printf("\n%s : Stop sir! Pleasee..",name);
				getchar();
				printf("\nsuddenly the car hit a road divider and the driver fainted and the car broke down");
				printf("\nyou crawl outside the car");
				getchar();
				printf("\n%s : I think I broke my arm .. arghh what is wrong with him??",name);
				getchar();
				printf("\nZara : You should be careful next time you found someone like him");
				getchar();
				printf("\n%s : but whyy?",name);
				getchar();
				printf("\nZara : I saw a bottle of pills with specifications needed for stress disorder on the desk board");
				getchar();
				printf("\n%s : ohh he has stress problem that's why he act like that..Now I get it",name);
				getchar();
				printf("\nZara : Yes %s",name);
				getchar();
				printf("\nZara : Now you should decide whether to 1.treat to your arm wound or 2.continue your journey and ignore your wound");
				getchar();
				fflush(stdout);
				tag=23;
				printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
				
				
				system("cls");
				printf("Zara : Now you should decide whether to ");
				setcursor(0,5);
				printf("[ ]treat to your arm wound or\n[ ]continue your journey and ignore your wound");
				trex = selector(2,5);
				fflush(stdout);
				system("cls");
				
				
				
				if(trex==1){
					treat();
				}else if(trex==2){
					printf("\n%s : Zara, I think we need to continue our journey as fast as we can because there is no time to waste anymore",name);
					getchar();
					printf("\nZara : Okay then, let's go");
					getchar();
					printf("\nYou wait near a river to wait for your next Yoober to arrive");
					getchar();
					printf("\nSuddenly the Yoober driver approach your back silently and push you into the river");
					printf("\nYou try very hard to swim but your arm has dislocated and you can't move it like you want it");
					printf("\nYou also try to scream very hard but it is too late");
					getchar();
					printf(" as you start drowning and the only think you can do is watching the Yoober driver staring and laughing at you by the river banks");
					
					die();
				}else{
					printf("Invalid choice. Try again.");
					talk();
				}
			}
				void treat(){	
					system("cls");
					printf("\n%s : Zara, I think I should treat my wound first before we continue",name);
					getchar();
					printf("\nZara : Up to you %s",name);
					getchar();
					printf("\nYou walks to a nearby clinic to treat your arm");
					getchar();
					printf("\nDoctor : Don't be afraid my boy. Your arm is not broken, your arm just dislocate and I am glad that you tend to treat it fast");
					getchar();
					printf("\n%s : Thank you very much doctor",name);
					getchar();
					printf("\nDoctor : My shift has ended. How about I take you home? I am sure that you don't have any transport home right?");
					getchar();
					printf("\n%s : I am okay with it but how about you Zara?",name);
					getchar();
					printf("\nDoctor : Why are you talking at your phone boy?");
					getchar();
					printf("\n%s : Don't mind me doctor I am just talking to myself",name);
					getchar();
					printf("Doctor : Ohh Okay");
					getchar();
					printf("Zara : I have checked the background of this doctor and it is safe to go with him");
					getchar();
					printf("%s : Okay I accept your offer doctor but can you bring us to my mom's office close from here?",name);
					getchar();
					printf("Doctor : Of course ");
					getchar();
					printf("You arrive at your mom's office 15 minutes later");
					fflush(stdout);
					riddle();
				}
			void silence(){	
				system("cls");
				printf("\nYou choose to remain silent inside the Yoober car");
				printf("\nAfter a few minutes, you arrive at your mom's office and you pay your Yoober driver");
				getchar();
				fflush(stdout);
				riddle();
			}

				void riddle(){
					system("cls");
					printf("\nYou have arrive at your mom's office");
					printf("\nYou see a signboard at the office main door");
					printf("\n'Only employee and visitors that have password may enter this building, incorrect password will label you as an intruder and may be prosecuted'");
					getchar();
					printf("\n%s : What should I do now Zara?",name);
					getchar();
					printf("\n%s : How should I know mom's password?",name);
					getchar();
					printf("\nZara : How about calling your mom?");
					getchar();
					printf("\n%s : Nice idea Zara, I'll try calling mom",name);
					getchar();
					printf("\nYou try calling your mother but she is not answering..");
					getchar();
					printf("\n%s : I think we need to figure out the password really fast, Zara",name);
					getchar();
					printf("\nZara : Well then, I will help you. Now connect me to the wifi of this building");
					getchar();
					printf("\n%s : Aye aye sir..Connecting you to this building wifi",name);
					getchar();
					printf("\nZara : Good job %s, now I will start hacking the system and try to figure out the password",name);
					getchar();
					printf("\n%s : Okay I'll wait",name);
					getchar();
					printf("\nZara : Okay, listen closely to what I will say next. This is the hint for the password to this building");
					getchar();
					printf("\nZara : You need to answer three questions ");
					getchar();
					printf("\nZara : Also, you need to choose the best answer among the choices given");
					getchar();
					printf("\nZara : Lastly, think carefully before answering the questions as you only got one chance so, please make it right.");
					getchar();
					fflush(stdout);
					tag=25;
					printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
					getchar();
		
					system("cls");
					printf("\nZara : Okay the questions are : ");
					getchar();
					system("cls");
					printf("I can bring tears to your eyes, resurrect the dead, make you smile, and reverse time. I form in an instant but I last a lifetime. What am I? ");//magic
					
					
					setcursor(0,3);
					printf("1. Onions \n2. Time Machine\n3. Healing potion\n4. Memories \n5. Diggie\n6. Grim Reaper\n7. My Mum\n8. Time itself");//magic
					trex = selector(8,3);
					fflush(stdout);
					system("cls");
				
					
					
					if(trex==4){
						printf("\nNice guess!");
					}else if(trex==1 || trex == 2 || trex ==3 || trex ==4 || trex ==5 || trex ==6 || trex ==7 || trex ==8 ){
						printf("You're locked out of the building, vulnerable. Suddenly, a man with a bulky body aim a shotgun at the back of your head. Without any time to react he pull the trigger while saying 'You guessed wrong so you're dead'. Bang!."); //magic
						die();
					}else{
						printf("Invalid choice. Try again.");
						riddle();
					}
					
					getchar();
					system("cls");
					printf("Who makes it, but has no need of it. Who buys it, but has no use of it. Who uses it but can neither see nor feel it. What is it?");
					setcursor(0,3);
					printf("1. Feelings\n2. Coffin\n3. Plastic Surgery\n4. Cigarettes\n5. Smartphones\n6. Drugs\n7. Glasses\n8. Earrings");//magic
					trex = selector(8,3);
					fflush(stdout);
					system("cls");
					
					if(trex==2){
						printf("\nGood job!");
					}else if(trex==1 || trex == 2 || trex ==3 || trex ==4 || trex ==5 || trex ==6 || trex ==7 || trex ==8 ){
						printf("\nYou're locked out of the building, vulnerable. Suddenly, a man with a bulky body aim a shotgun at the back of your head. Without any time to react he pull the trigger while saying 'You guessed wrong so you're dead'. Bang!."); //magic
						die();
					}else{
						printf("\nInvalid choice. Try again.");
						riddle();
					}
					


					getchar();
					system("cls");
					printf("What word consists of four letters that is important to help you for your journey today?");
					setcursor(0,3);
					printf("1. Luck\n2. Fast\n3. Eyes\n4. Card\n5. Fuel\n6. Taxi\n7. Zara\n8. Cash");//magic
					trex = selector(8,3);
					fflush(stdout);
					system("cls");


					if(trex==7){
						savemum();
					}else if(trex==1 || trex == 2 || trex ==3 || trex ==4 || trex ==5 || trex ==6 || trex ==7 || trex ==8 ){
						printf("You're locked out of the building, vulnerable. Suddenly, a man with a bulky body aim a shotgun at the back of your head. Without any time to react he pull the trigger while saying 'You guessed wrong so you're dead'. Bang!."); //magic
						die();
					}else{
						printf("Invalid choice. Try again.");
						riddle();
					}
				}
				
					void savemum(){	
						system("cls");
						tag=26;
						printf("\nCheckpoint Saved. Your progress code is : %d",progcipher());
						getchar();
						fflush(stdout);
						printf("\nPassword correct. You now have access to your mother office");
						getchar();
						printf("\nYou saw your mom walking at the office hallway and stopped her");
						getchar();
						printf("\nMom : %s?? What are you doing here?",name);
						getchar();
						printf("\n%s : Mom we need to talk. Pleasee",name);
						getchar();
						printf("\nMom : Okay dear.. What is it that you want to talk about?");
						getchar();
						printf("\n%s : There are many natural disaster that will happen today and Zara called it 'THE APOCALYPSE'",name);
						getchar();
						printf("\n%s : Mom, I want you to follow me..let's go.. There is only one safe place that we can go during this apocalypse and I know where it is",name);
						getchar();
						printf("\nMom : Oh my dear! I think you watch too much movies and play too much games. There is no way that the natural disaster will happen today, just look at this nice weather");
						getchar();
						printf("\nMom : Who is Zara? and by the way, I think you should go back home my lovely %s, I will continue my work and I can meet you when I go back home around 5 o'clock this evening",name);
						getchar();
						printf("\nZara : %s!!! Convince your mom before it is too late!!",name);
						getchar();
						printf("\n%s : But how Zara?? Mom won't believe me, didn't you hear what mom said just now??",name);
						getchar();
						printf("\nZara : There is three option that I can give you and one of it may convince your mother");
						getchar();
						
						
						
						
						system("cls");
						printf("Zara : There is three option that I can give you and one of it may convince your mother");
						setcursor(0,4);
						if(daddy==1){
							printf("[ ]Show your phone to her and explain everything about me,Zara, your assistant");
							printf("[ ]Call your father and tell him to convince your mother");
							printf("[ ]Drag your mother to the safe place with or without her will of going there");
						}else{
							printf("[ ]Show your phone to her and explain everything about me, Zara, your assistant");
							printf("[ ]Let me pretend to be your dad and convince your mother");
							printf("[ ]Drag your mother to the safe place with or without her will of going there");
						}							
						trex = selector(3,4);
						fflush(stdout);
						system("cls");
						
							
						
						
						fflush(stdout);
						scanf("%d",&trex);
						if(trex==1){
							printf("\n%s : Mom!! Wait!! I'll tell you about Zara, my personal assistant",name);
							getchar();
							printf("\n%s : She is the one who guide me to come and save you, she is an A.I. installed in my phone",name);
							getchar();
							printf("\nMom : Is this one of your online mobile games %s?? Is this what you called 'Mobile Legends'?? ",name);
							getchar();
							printf("\n%s : No mom, look she can also talk-",name);
							getchar();
							printf("\nYour mother ignores you and walks away to continue what she was doing before");
							getchar();
							printf("\n%s : It doesn't work Zara, my mom won't believe me",name);
							getchar();
							printf("\nZara : I think we should hurry %s, we do not have much time left",name);
							getchar();
							printf("\n%s : No, Zara I won't leave mom here",name);
							getchar();
							printf("\nZara : What should we do next %s?You and your family safety is my top priority",name);
							getchar();
							printf("\n%s : I think we should wait for mom's lunch break time this afternoon to talk longer and persuade her",name);
							getchar();
							printf("\nZara : Are you sure about this %s?",name);
							getchar();
							printf("\n%s : Yes Zara, I would do anything for my family",name);
							getchar();
							printf("\nYou wait at a nearby restaurant while arranging words to persuade your mother");
							printf("\nWhile waiting at the restaurant suddenly the restaurant's TV shows stop working and shows no service symbol");
							getchar();
							printf("\nYou look at your phone and your mobile network also shows no service but luckily Zara is still there");
							getchar();
							printf("\nYou feel that something really wrong will be happening really soon");
							printf("\nYou then go back to the office to check your mother");
							getchar();
							printf("\n%s : I'll save mom before it is too late",name);
							getchar();
							printf("\nYou go to the office and saw a huge tornado and storm pass you and moving towards the office");
							printf("\nYou run as fast as you can to the office but it is too late");
							getchar();
							printf("\nThe tornado hit the office really hard that make the building start collapsing");
							printf("\nYou ignore your surrounding and start running towards the office");
							getchar();
							printf("\nThen a huge concrete stone coming from a collapsing building near you fly towards you and hit your head really hard");
							printf("\nYou lost conciousness and fainted right on the spot. A building falls and squash you to death");							
							die();
						}else if(trex==2){
							printf("\n%s : Mom!! Wait!! I found and help papa just now",name);
							getchar();
							printf("\nMom : Papa? Are you sure?");
							getchar();
							printf("\n%s : Yes mom..You can call papa and he will tell you everything",name);
							getchar();
							printf("\nMom : Okay I will call him but don't lie to me my dear %s",name);
							getchar();
							printf("\n%s : I am not lying mom.. please call papa now..",name);
							getchar();
							printf("\nYour mother start dialing your father mobile number and calls him");
							getchar();
							printf("\n%s : Please answer the call papa",name);
							getchar();
							printf("\nYour father answer the call and explains everything to your mother");
							printf("\nYour mother look really shocked and hang up the phone");
							getchar();
							printf("\nMom : Okay I trust you this time. Now show me the way to the safe place");
							getchar();
							printf("%s : Finally!! Okay mom let's goo",name);
							quiz();
						}else if(trex==3){
							printf("\n%s : Mom I am sorry to do this but I have to",name);
							getchar();
							printf("\nYou hold your mother's hand really tight and pull her hand forcely to make her follow you");
							getchar();
							printf("\nMom : Heyy %s, what are you trying to do dragging me like this",name);
							getchar();
							printf("\n%s : I have to do this mom or you and everyone will be dead",name);
							getchar();
							printf("\nMom : SECURITY!!!");
							getchar();
							printf("\nA man with a huge build and wearing a uniform come towards you and your mother");
							getchar();
							printf("\nMom : I want you to take my child home and don't go anywhere else until you make sure he is inside my house");
							getchar();
							printf("\nSecurity Guard : Okay madam");
							getchar();
							printf("\n%s : But mom...",name);
							getchar();
							printf("\nThis time you are the one been dragged away by the bulky security guard");
							printf("\nHe start his car and put you inside. He starts driving");
							getchar();
							printf("\nYou try to persuade the guard to turn back");
							getchar();
							printf("\n%s : Sir there will be earthquake,tornado,tsunami,and many more coming..",name);
							getchar();
							printf("\n%s : I need to save my mom really quick sir before it is too late",name);
							getchar();
							printf("\nThe guard ignores you and continue his driving");
							getchar();
							printf("\n%s : Pssttt Zara.. What should I do now??",name);
							getchar();
							printf("\n%s : Should I jump from this car window??",name);
							getchar();
							printf("\nZara : No, it is too dangerous.");
							getchar();
							printf("\n%s : Then what can I do Zara?",name);
							getchar();
							printf("\nZara : According to my calculations you cannot do anything in this situation");
							getchar();
							printf("\n%s : Whattt??? Why can't I do anything?",name);
							getchar();
							printf("\nZara : This is because in terms of strength,intelligence and everything you lost to the guard.I recommend you to remain silent and do not do anything rash.");
							getchar();
							printf("\n%s : hmmmm k",name);
							getchar();
							printf("\nOn your way home, there is a huge ruckus going on the road because of the earthquake near your house");
							printf("\nthe traffic is not working and there is no police controlling the busy traffic");
							getchar();
							printf("\nWhile your car trying to cross the busy road, suddenly there is a car that lose control and is in a high speed slams the right side of your car");
							printf("\nYour car start spinning and hit another car");
							getchar();
							printf("\nBOOOMMMMM..Your car explodes and you die with the guard");
							die();
						}else{
							printf("Invalid choice. Try again.");
							savemum();
						}
					}




void quiz(){
	system("cls");
	printf("\n%s : Zara, call another ride for us to the cave",name);
	getchar();
	printf("\nZara : Okay, I will now call a rescue ride to the cave ....");
	getchar();
	printf("\nYour ride to the cave arrived and after an hour of ride, you and your mother arrived at the cave");
	getchar();
	printf("\nZara : We have now arrived  at the cave");//magic
	getchar();
	printf("\n%s : Hmmm Zara, we have another problem here..",name);
	getchar();
	printf("\nWaiting in front of you is a huge door and a caveman sitting on a small chair beside the door");
	fflush(stdout);//ending (insert dad's status//magic
	int passcode[3]={5,3,1},guess[3]={0},digit,hmmm[20],dummy;
	int i,r,right=0,wrong=0;
	printf("\nCaveman : Welcome, %s. You must read my mind if you wanna pass through this door. What 3 digit number is in my head?\n", name);
	for(i=1;i<=20;i++){
		right=0;
		wrong=0;
		printf("Guess %d : ",i);
		scanf("%d",&hmmm[i-1]);
		r=2;
		dummy=hmmm[i-1];
		while(r>=0){
			guess[r]=dummy%10;
			dummy/=10;
//			printf("%d\n",guess[r]);
			r--;
		}
		r=0;
		do{
			if(guess[r]==passcode[0] || guess[r]==passcode[1] || guess[r] ==passcode[2]){
				wrong++;
				if(guess[r]==passcode[r]){
					right++;
					wrong--;
				}
			}
			r++;
		}while(r<=2);
		if(right==3)
		break;
		printf("Caveman : You guessed %d correct number in the right position and you guessed %d correct number in the wrong position.\n\n\n",right,wrong);
	}
if(right<3){
	printf("You took too many guesses. YOU ARE DEAD");//magic
	die();
}
printf("Mission Accomplished.");
getchar();
printf("\nInside the cave were other survivors led by their own virtual assistant like Zara.");
printf("\nThere were furious lightning roar, and the shockwave from the earthquake and the tsunami could be felt throughout the cave");
getchar();
printf("\nas the world continue to self - destruct... Suddenly , a bald man with a cape stood up amongst the survivors.");
getchar();
printf("\n""YOU ARE ALL SURVIVOR OF THE WORLD !""");
getchar();
printf("\n""STARTING TOMORROW , ALL OF YOU ARE GOING TO START A NEW CIVILISATION ! A BETTER ONE!!!""");
getchar();
printf("\n""YOU HAVE BEEN HANDPICKED BY THE NEW ORDER TO RULE THE NEW ERA !""");
getchar();
getchar();
printf("\nTHE END");
getchar();
int j;
for(i=0;i<3;i++){
for(j=0;j<time;j++){}
if(i<2)
printf(".");
else
printf("?");
}

if(daddy==1)
printf("\nCongratulations!! You have saved BOTH your dad and your mother.\nYou are a WINNER!");
//your dad is alive
if(daddy==0)
printf("\nCongratulations!! However, you are only able to save your mother as your father has perished earlier in the game ...");
//your dad is dead
//your mum is alive
//number of deaths (int deathcount)
printf("\nNumber of deaths during the game : %d !\nPress enter to return to the main menu.",deathcount);
getchar();
credits();
}
	
	
			
void die(){
	int i;
		for(i=0;i<time/2;i++){
printf("``````  ` ````````...---/+osso/:-.-://:::::-::::-----::::::::///////+++++++++ooooooooooooooooooooo+o/+///:::////:/:::-::::-......```````    ````````  \n");
printf("```````` ````.```...--::+ooso/::.:////://///:::------::::::://///+++++++ooooooooooooooooooooooooooo++////:::::///////::://-:--:.-.-.``````  ``````````\n");
printf("```````````````````..-:/++so+/::/+++++++///:::::::::::::///////+++oooooooooooooooooooooooooooooooo++++//::----:::///////++++//:://-.``````````````````\n");
printf("`````````````````...--:+++o+/:/+++////:---.-----::::://///++++++oooossooooooooooooooooooooooooo+++++++//:::-----:::///////++++///-.`````````          \n");
printf("````````````````....-:///++//++++////:::---..--::////++++++++ooooooososooooooooooooooo++++o+o+++++++++//::---...--::::/::::::-----.``````             \n");
printf("`````````````.```..--://+///++++++++//::-----::://+++++++ooooooooossssoooooooooooooooo++++++++++++++++//::--.....---:::::::-------..```````           \n");
printf("  ```````````````...-:://++oo++o++//:----...-:://+++++ooooooooooooooooooooooooooooooo++++++++++++++++++/::--..`..---::::::::::----...`````            \n");
printf("````  ``````````...-::://+++++++//:------..--:///++++++ooooooooooooooooooooooooooo+++++++++++++++++++++/::--...``..---::::::::-.--.`.`````            \n");
printf("````     ```````..-::::/+++//++/:/:-----...-:://+++++++++oooooooooooooooooooooooo+++++++++++++++++++++///---.-..`...-:-::::::::-.-.``.```             \n");
printf("``````` ` ``````.-::::/o+o+//+///:-----:-.-:::///++++++++++++++ooooooooooooooo+++++++++++oooooo+++++++///:-----.....--::::/:::/:---```.```            \n");
printf("```````````````.-:::::+ooo+:/+//:-.--.::..-::////+++++++++++++++ooooooo++++++++++++++++ooooooooooo++++///:-.---:-...--::////////::-.```````         ``\n");
printf("``````````````.--::::/+++o//+++/:--.--::..-:///++++++++++++++++++++++++++++++///+/////////////+++++++////:-..----:----::////////+-:.```````````   ````\n");
printf("`````````..``..--:::/++++///+/+//-----:-..-:///++++++++++++///++++++++///////:::--.........-------:://////:.`.-:---:::::/+++///++/:-``.`..`````    ```\n");
printf("````````````...--:::+//+////+/+//:---::-..-::::::::::::::://///////+++////:::--..````````.........---::://:...--:/::-:///++++///++/:.`....```````   ` \n");
printf("```````````...-:::://:/+//:/+++/:::-:::-.`.-----.....````....-::///+++++//::--..````````...```....-.---::/:-`.---:///::://+o++//++//......``````````  \n");
printf("``````````.`..-::::+/://:/:/+++/:::-/::-.`.........``````````..-:://++++///:--.````````......````...---::/:-...---://///://++++//+//:.....````````````\n");
printf("`````````...---::-:++://:////+/:::::::--.```````````.`.``.````..-:/++++++//::...``.-.`````````````..--:::/:-......-:://////+++///+/:/.```.````````````\n");
printf(" ``````....--:-:--//+:/://:////-:::::--..```````````````.--.`...-:/+++++++//:-..`.-::...```.-......--::://:-...-....-:///////++//+/:::.`.`````````````\n");
printf("```````....--:::--://:/://:://:::/:::-....``````...``...::-.....-:/++oooo++//:-...--::----::-------:::////:-..`..-...-://+///++///:--::.```````  ```  \n");
printf("```````...--:::---/:/:////:://::/::----....````..----------...--://+oooooo++///::-...-------------:://////:-.` `..--..-://+///++/+:..-/-`.````````````\n");
printf("`````....-:::::---/:::///::://::/:::-:-.....`````..........---:///+ooooooo++++++//:------::::-::::////////:..` ```.----:/+////++/+:--./-``````````````\n");
printf("````..-.-:::::---:::://::::://::::::-:-................---::////++oosssssoo+++++++++/////:://////////++///:.``  ```..--://////+++/-.---.````    ``````\n");
printf("``...-.-::::::--:::--///::-:///::::::--..-....------:::::///+++++oossssssooo++++++++++++++++++++++++++++//.```  ```..--:///////++::::..````      `````\n");
printf("``..----:-::::::::::-://::-:++/:::::::-.-------:::::::///++++++++ossyyyyssoo+++++++oooooo+++++++++++++++/:``   ````...-:/++////++/:-..```````     ``  \n");
printf("``..---:-:::::/::::::///:--:+++//:/:::---------::://///++++++++++osyyyyyyssoo++++++ooooooooooo++++++++++/.`   ````....-:/+/////+//--..`````  ``       \n");
printf("``..-----::///:-:::::///:--:+++/::::::---:----::://++++++++++++/+sssyyyyssssooo+/++ooooooooooooo+++++++/-`  `````....-::///////+//:....``````````     \n");
printf("`...-----:://---::::://::--:/+++//:::::--:-----:///+++++o+++++/oooooooooooo+oooo+/++ooooooooooo++++++++/.`   ```...--:////////://::....````````  `` ``\n");
printf("``..-----://----:::::/:::--:///+//::::::-:-----:://++++++++++//o+//////////:::/++/++++ooooooo+++++++++/-````````..--://://///:///::....`````````  ````\n");
printf("`...----::/:---:/::://:-:--:::://+///:::--:-----:://++++++++////:-----------.-://+++++++++++++++++++///.````````--::::://///::/+/::....```````````````\n");
printf("`....--::::----:/::///:-:--:::-://+//::::--------::///+++++++++////////:://///+++++++++++++++++++/////:`.`````.--:::::::///:://+/:-.....``````````````\n");
printf("...----:-::----:::////::---:::--://++/::-------.--::////+++++++++++++++++++++++ooooo++++++++++////////-......-----:-:::////::/+/::-......`````````````\n");
printf("...------::.---::::/:/:---::-:-.::////:--.-----.--:::///+++++++o+++++o+++ooooooooooo+++++++++////////:.....--------::::///:::++/:-.......`````````````\n");
printf("...-------:----::::::/:---::--:.:::////---...--.---::://///+++++++++++++++++++++++++++++++//////////:.`.--:--------::://::::/+/:--...........````` ```\n");
printf("....-----------:/::::/:--:::--:.::::://:..-...-..---::://///////////:::/:::---::///////////////////:-.----.-------::://:::::+/-----.........``````````\n");
printf("...----.--.----::-:-:/:--::--.-.::::::/:.........----::::////:::-.```......`````...--::://////////:........------:://:---::/+:-----....```..``````````\n");
printf("...---.....---:::::-:::--::----:::::::/:.``......-.---:::::::...-..----...------:---::::////////:-```.....-.--::-:/::----::+/-------.....```.```````  \n");
printf("...--......--:::::-:-::-:::----:/:::::/:.``...``....---::::::..-::::::::::/::::/::://////////:::-``````.....-::::/:-...--:/+:-------.......``.``````  \n");
printf("...--....----:-::-----:::::---://::-::/-`.`..````....---:::::-----------:-:------::///////::::-.``````.....-:::///-..`.--/+:------:---.........````   \n");
printf("...-.....---:---::----:-::::-::/:----/:..`.`````````...---:::--..----..---..----::///////:::-.````````.....-:://::..``.-://--------::--........``   ``\n");
printf("....-....----.--:-------::::-::-----:/-.``.```````````..-----.-:::::::::::::::::////////::-.```````````...--:/:::.````.-:/----------::--.``.....``````\n");
printf("..--.-..-----..-:---.-.-:::::::----:/:.`.`.```.`````````..------://///////++++++//////::-...`````````.`...--:--:-.````.-/:.-::--------:--..`....``````\n");
printf(".--..-----------:---...-::::::-----/:...``.``....`````````..---.-:///////////////////:--....```````..``...-----:-````.-:/...-:-:-------:-....``..`````\n");
printf("-----------.----::--...-::::/:---:/:-...``..`.``````````````..---::///////////////::--.......```````.``...-------..``.-::....-:::-:-----:-......``````\n");
printf("----:----------:::-.....-////::::/:-..-.....`.``.````````````....--:::::::::::::::---.--.....```````.`....--..--.`.``.-::.`...::::-:-----:-.`....`````\n");
printf("-:::::---------:::-.....-///::://:-...-..........`..````````.......---------------------.....```````......--.--..````.-::.....-::::::-----:-.``...````\n");
printf("::::::-------::--:-.....-://:://:--..-.......`..``````````.........----------------------....```````......--......```.-:-......-:::::::--.-:-.``....``\n");
printf("::::::-------::-::--.....-/////::-----....`..``.`````````.......------------------------....```````.......--.-....`.`.-:-.......-/:/::::----:-```...``\n");
printf(":::--::------::-:::-.....-:///::::-.--..........````````.....----------------::::::::----...```````........--.......`.-::.......-::::::::----:.```..``\n");
printf("-:---::---.---:-::-......-:///:::::.......-..........``.....------::::::::::::::::::::---...``````.`.....-.--.........-::.......--:/::/::------````..`\n");
printf(":----:---..---::::-......::::/:::::-...-.---.............------::::::::::::::::::::::::---....```.``.-...--.--....-...-::-..-....-:::-:::---:--.````.`\n");
}
	getchar();
	system("cls");
	deathcount++;
	prog=progcipher();
	if(deathcount>99){
		printf("You have died too many times, you will no longer be able to continue from your last save if you exit the game.\nWould you like to continue?");
	}else{
		printf("Your progress code is: %d (Go to Help on the main menu for instructions)\nWould you like to continue?",prog);

	}
	setcursor(0,5);
	printf("[ ] : Return to previous checkpoint.\n[ ] : Start over.\n[ ] : Quit to main menu",prog);
	tag=99;
	trex = selector(3,5);
	fflush(stdout);
	system("cls");
	


	if(trex==1){//change last choice
		progressset();	
	}else if(trex==2){//startover
		deathcount=0;
		game();
	}else if(trex==3){
		main();
	}
	deathcount--;
	die();
}	
int progcipher(){
	int x;
	x = tag;
	x += deathcount*100;
	x += daddy*10000;
	x = ((((x*35)+43)*3)+2);
	return x;
}
