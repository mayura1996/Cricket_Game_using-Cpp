#include <iostream> //for input and output operations in c++
#include<conio.h> //console input and output operations
#include <windows.h> //inorder to set cursor to desired postion
#include<cstdlib> 
#include<ctime> //library to use time in the seeding of random numbers
#include<string>

using namespace std; //for standard keywords in c==
bool newBall; //this bool check balls cheks the status of the game. if bool is false a new ball will be bowled
const int length = 40; //initalizing the legnth of the pitch
const int breadth = 100; //initializing the breadth of the pitch

int x, bowlerX, bowlerY, noBallCount = 0, ballX, ballY, batX, batY, p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, p5x, p5y, p6x, p6y, wkX, wkY, score1, score2, k = 1,
balls = 0, score = 0, wickets = 0, boundaries = 0, wideBallCount = 0;
string Team, Team1, Team2;
int* pntX = &p1x, * pntY = &p1y; //declaring varialbles for postions and cordinatied as well as other values needed

enum ballDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; //enumerations are used to  define a data type within prefined values or characters which is helpful in continuation of motions in the game
enum Bowler { still = 0, startRun, bowl }; //to start or to check the bowlers status
enum bowlType { inital = 0, mode1, mode2 }; //for different types of balls
enum battingOptions { initialBat = 0, hitA, hitS, hitD, hitW, hitQ, hitE }; //to check for the hitting by the bat
enum fielder { initialfielder = 0, p1, p2, p3, p4, p5, p6, w }; //for the fielder postions
Bowler checkBowling; //check bowling data type from the enumeration bowler whih has data types denied above corresponding to that
battingOptions shot;
ballDirection dir;
bowlType bowls;
fielder fielding;

void gotoxy(short x, short y) //to go to x and y postions input by the user
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//function prototyping
void wideBALL(); //to display wideball msg
void wicket(); //to display wickert
void startScreen(); //to display start screen
void gameName(); //to display the gamename
void LOADING(); //for loading animation
void no_Ball(); //to display no ball
void congrats(); //to display congrats
void instructions();//to diplay the instructions
void setup() //fucntion to setup the intial postions and other stages required for the game
{
	int x = rand() % 5;
	newBall = false;

	dir = STOP;
	checkBowling = still;
	shot = initialBat;
	bowlerX = (breadth / 2) - 3; //position of bowler on X axis
	bowlerY = (length / 2) + (2 * length / 5); //postion of bowler on Y axis
	ballY = (length / 2) + (length / 5); //position of bowl in Y axis
	ballX = (breadth / 2) - 3; //position of bowl in X axis
	batX = (breadth / 2); //position of batsman of x axis
	batY = (length / 2) - (length / 5) + 1; //positonn of batmen of y axis
	//delaring the postions of the players who are fielders
	p1x = breadth / 2 - 25; p1y = length / 6 + 25;
	p2x = breadth / 2 - 30; p2y = length / 2 - 15;
	p3x = breadth / 2 + 25; p3y = length / 2 + 16;
	p4x = breadth / 2 + 25; p4y = length / 2 - 15;
	p5x = breadth / 2 + 45; p5y = length / 3 + 9;
	p6x = breadth / 3 - 25; p6y = (length / 2) - (length / 5) + 1;
	wkX = breadth / 2; wkY = (length / 2) - ((length / 5) + 2);

}

void draw() //function to draw the ground
{


	{

		for (int i = 0; i < length; i++) {

			for (int j = 0; j < breadth; j++)
			{
				gotoxy(10 + j, 10 + i);

				if (i == 0 || i == length - 1)
					cout << "#";
				else if (j == 0 || j == breadth - 1)
					cout << "#";
				else if ((i == (length / 2) - ((length / 5) + 1)) && (j >= (breadth / 2 - 1)) && (j <= (breadth / 2 + 1)))
					cout << "|"; //to print strikers end wickets
				else if ((i == (length / 2) - (length / 5)) && (j >= (breadth / 2) - 4) && (j <= (breadth / 2) + 4))
					cout << "-"; //to print strikers end
				else if ((i == (length / 2) - (length / 5)) && (j >= (breadth / 2) - 7) && ((j <= (breadth / 2) - 6) || (j >= (breadth / 2) + 6) && (j <= (breadth / 2) + 7)))
					cout << "-"; //to print strikers end
				else if ((i == (length / 2) + (length / 5)) && (j >= (breadth / 2) - 7) && (j <= (breadth / 2) + 7))
					cout << "-"; //to print non strikers end
				else if ((i == (length / 2) + ((length / 5) + 1)) && (j >= (breadth / 2 - 1)) && (j <= (breadth / 2 + 1)))
					cout << "|"; //to print non strikers end wickets
				else if ((i == (length / 2) - (length / 5)) && ((j == (breadth / 2) - 5) || (j == (breadth / 2) + 5)))
					cout << "|"; //to print wide marks
				else if (i == bowlerY && j == bowlerX)
					cout << "^"; //to print bowler
				else if (i == ballY && j == ballX)
					cout << "o"; //to print the bowl
				else if (i == batY && j == batX)
					cout << "/"; //batman
				else if (i == p1y && j == p1x)
					//fielders are defined by 1 2 3 4 .....
					cout << "1";
				else if (i == p2y && j == p2x)
					cout << "2";
				else if (i == p3y && j == p3x)
					cout << "3";
				else if (i == p4y && j == p4x)
					cout << "4";
				else if (i == p5y && j == p5x)
					cout << "5";
				else if (i == p6y && j == p6x)
					cout << "6";
				else if (i == wkY && j == wkX)
					cout << "W";

				else
					cout << " ";


			}
			cout << endl;
		}
	}

	cout << endl;



	//to print the scoreboard

	gotoxy(130, 10); cout << " _________________________________________" << endl;
	gotoxy(130, 11); cout << "|		 |" << "			    |" << endl;
	gotoxy(130, 12); cout << "|	  SCORE  |" << "\t" << (score + (boundaries * 4) + noBallCount + wideBallCount) << "		    |" << endl;
	gotoxy(130, 13); cout << "|______________|__________________________|" << endl;
	gotoxy(130, 14); cout << "|		 |" << "			    |" << endl;
	gotoxy(130, 15); cout << "|	  OVERS	 |" << "	" << balls / 6 << "." << balls % 6 << "		    |" << endl;
	gotoxy(130, 16); cout << "|______________|__________________________|" << endl;
	gotoxy(130, 17); cout << "|		 |" << "			    |" << endl;
	gotoxy(130, 18); cout << "|	WICKETS  |" << "\t" << wickets << "		    |" << endl;
	gotoxy(130, 19); cout << "|______________|__________________________|" << endl;
	gotoxy(130, 20); cout << "|		 |" << "			    |" << endl;
	gotoxy(130, 21); cout << "|	  TEAM   |" << "\t" << Team << "		|" << endl;
	gotoxy(130, 22); cout << "|______________|__________________________|" << endl;
	gotoxy(130, 23); cout << "|		 |" << "			    |" << endl;
	gotoxy(130, 24); cout << "|	BATMAN   |" << "\t" << wickets + 1 << "		    |" << endl;
	gotoxy(130, 25); cout << "|______________|__________________________|" << endl;
	gotoxy(130, 26); cout << "|		 |" << "			    |" << endl;
	gotoxy(130, 27); cout << "|	 BOWLER	 |" << "	" << balls / 6 + 1 << "  " << "		    |" << endl;
	gotoxy(130, 28); cout << "|______________|__________________________|" << endl;

}

void input() //to check for inputs
{
	if (_kbhit()) //if a keyboard key is hit this will return a true value
	{
		switch (_getch()) //to check for the ascii value of the that we hit
		{
		case 'k':
			checkBowling = startRun; //pressing z key will make the bowler start running
			break;
		case 'l':
			if (bowlerY <= ((length / 2) + (length / 5) + 3))
			{
				checkBowling = bowl; //pressing the x key will make the bowler to pass the ball
			}
			break;
		case 'z': //pressing z will move the batsman to righahnd side
			if (batX >= (breadth / 2) - 3)
			{
				batX--;
			}
			break;
		case 'x': //pressing x will move the batsman to let hand side
			if (batX <= (breadth / 2) + 3)
			{
				batX++;
			}
			break;
		case 'a': //to hit in the left directiong from the bat
			if ((ballX > (batX - 5)) && (ballX < (batX + 5)) && (ballY > (batY - 5)) && (ballY < batY + 5))
				shot = hitA;
			break;
		case 's': //to hit in the forward direction from the bat
			if ((ballX > (batX - 5)) && (ballX < (batX + 5)) && (ballY > (batY - 5)) && (ballY < batY + 5))
				shot = hitS;
			break;
		case 'd': //to hit in the right direction
			if ((ballX > (batX - 5)) && (ballX < (batX + 5)) && (ballY > (batY - 5)) && (ballY < batY + 5))
				shot = hitD;
			break;
		case 'e': //to hit in the third man direction
			if ((ballX > (batX - 5)) && (ballX < (batX + 5)) && (ballY > (batY - 5)) && (ballY < batY + 5))
				shot = hitE;
			break;

		case 'q': //to hit in the fine leg direction
			if ((ballY < length / 2) - (length / 5) + 1)
				shot = hitQ;
			break;
		case 't': //to move a selected fielder in theupward direction
			(*pntY)--;
			break;
		case'g': //to move the selcted player in the downward direction
			(*pntY)++;
			break;
		case'f': //to  move the player in the left direction
			(*pntX)--;
			break;
		case 'h': //to move the player in the right direction
			(*pntX)++;
			break;
			//1 2 3 4 5 6 can be pressed to select the fielder that you want to move
		case '1':
			pntX = &p1x;
			pntY = &p1y;
			break;
		case '2':
			pntX = &p2x;
			pntY = &p2y;
			break;
		case '3':
			pntX = &p3x;
			pntY = &p3y;
			break;
		case '4':
			pntX = &p4x;
			pntY = &p4y;
			break;
		case '5':
			pntX = &p5x;
			pntY = &p5y;
			break;
		case '6':
			pntX = &p6x;
			pntY = &p6y;
			break;
		case 'p': //to quit from the game
			newBall = true;
			break;
		}
	}

}
void ballPathOnPitch() //in order to move the ball on the pitch
{
	//here the value of x is checked by the values returned by the random fucntion 	
	if (x == 1)
	{
		ballY--;

	}
	if (x == 2)
	{
		ballY = ballY - 4;
		ballX++;
		if (ballY < (length / 2) - ((length / 5) + 1))
		{
			wickets++; //a wicket
			system("CLS");
			wicket(); //will display the out message
			newBall = true; //setup the game again
			Sleep(100);
		}
	}
	if (x == 3)
	{
		ballY--;
	}

	if (x == 4)
	{
		ballY = ballY - 2;
		ballX++;
		//cout << "WIDE BALL";
		if (ballY < (length / 2) - ((length / 5) + 1))
		{
			wideBallCount++;  //increases widebowl count
			system("CLS");
			balls--; //if a wideball is bowled the bowlcount will be decreased since the bowl count is increased everytime so that there wont be no effect to overall balls
			wideBALL();
			Sleep(100);
			system("CLS");
			newBall = true;

		}
	}

	if (x == 5)
	{
		ballY = ballY--;

	}
	else
		ballY--;
}


void bat() //function for batting
{
	//for batting
	switch (shot)
	{


	case hitA: //a value for the hitA is updated and this value will loop untill anohter key is hit,which helps the bowl to move in the desired direction
		if (x == 1)
		{
			ballX--;
			ballY++;

		}
		else if (x == 2)
		{
			ballX = ballX - 2;
			ballY++;

		}
		else if (x == 3)
		{
			ballX = ballX - 3;
			ballY++;

		}
		else if (x == 4)
		{
			ballX--;


		}
		else
		{
			ballX = ballX - 4;
			ballY++;


		}
		break;
	case hitD:
		if (x == 1)
		{
			ballY++;
			ballX++;


		}
		else if (x == 2)
		{
			ballY++;
			ballX = ballX + 2;


		}
		else if (x == 3)
		{
			ballY++;
			ballX = ballX + 3;


		}
		else if (x == 4)
		{
			ballY++;
			ballX = ballX + 4;

		}
		else
		{
			ballX++;

		}
		break;
	case hitS:
		if (x == 1)
		{
			ballY++;

		}
		else if (x == 2)
		{
			ballX--;
			ballY = ballY + 2;

		}
		else if (x == 3)
		{
			ballX++;
			ballY = ballY + 2;

		}
		else if (x == 4)
		{
			ballX++;
			ballY = ballY + 3;

		}
		else
		{
			ballX--;
			ballY = ballY + 3;

		}
		break;
	case hitE:
		if (x == 1)
		{
			ballX++;
			ballY--;

		}
		else if (x == 2)
		{
			ballX = ballX + 2;
			ballY--;

		}
		else if (x == 3)
		{
			ballX = ballX + 3;
			ballY--;

		}
		else if (x == 4)
		{
			ballX = ballX + 4;
			ballY--;

		}
		else
		{
			ballX = ballX + 5;
			ballY--;

		}
		break;
	case hitQ:
		if (x == 1)
		{
			ballX--; //reminder - add more paths after hitting
			ballY--;
			Sleep(30);
		}
		else if (x == 2)
		{
			ballX = ballX - 2;
			ballY--;
			Sleep(30);
		}
		else if (x == 3)
		{
			ballX = ballX - 3;
			ballY--;
			Sleep(30);
		}
		else if (x == 4)
		{
			ballX = ballX - 4;
			ballY--;
			Sleep(30);
		}
		else
		{
			ballX = ballX - 5;
			ballY--;
			Sleep(30);
		}
		break;
	default:
		break;

	}



}
void noBall() //function to print a noball message and to increase the no balls in any case if noballs are bowled
{
	noBallCount++;
	balls--;
	system("CLS");
	no_Ball();
	system("CLS");
	Sleep(500);
	newBall = true;
}

void logic() //here all the logial operations neeed in the game is setuped
{

	switch (checkBowling)
	{
	case startRun:

		if (bowlerY >= ((length / 2) + (length / 5)))  //checks for the position of the bowler
		{
			bowlerY--; //bowler running from start position towards the non strikers end to bowl
		}
		else
		{
			cout << "no ball";
			noBallCount++;
			balls--;
			noBall(); //if bowler moves passing the crease a no ball will taken in to count
			break;
		}
		break;
	case bowl:
		bowlerY; //if l is hit the value of the cehck bowling will be updated gto bowl and this will cause the bowler to stop and pass the bowl
		ballPathOnPitch();

		break;
	default:
		break;
	}



	if (ballX < 0 || breadth < ballX || ballY < 0 || length < ballY) //if the ball reaches boundary
	{
		boundaries++;
		//boundary output
		newBall = true;
	}
	bat();
	//below if command checks whether the cordinated of bowl is quatl to cordinated of a fielder. 
	if ((ballX == p1x && ballY == p1y) || (ballX == p2x && ballY == p2y) || (ballX == p3x && ballY == p3y) || (ballX == p4x && ballY == p4y) || (ballX == p5x && ballY == p5y) || (ballX == p6x && ballY == p6y))
	{
		int x = rand() % 100, y;
		/*if the cordinates are qual depending on
		the random number  generated the it will cuase a wicket whcih is cuaght by the filder or it will icrease the runs by 1 2 or 3*/
		if (x % 2 == 0)
		{
			system("CLS");
			wicket();
			newBall = true;
			wickets++;

		}
		else
		{ //score by running
			y = rand() % 3;
			if (y == 1)
			{
				newBall = true;
				score += 1;
			}
			else if (y == 2)
			{
				newBall = true;
				score += 2;
			}
			else
			{
				newBall = true;
				score += 3;
			}
		}

	}

	if ((ballX <= (breadth / 2 - 1)) && (ballX >= (breadth / 2 + 1))) //if the value of bowl is greater than the range of the pitch it will cause a widebowl
	{
		wideBallCount++;
		system("CLS");
		wideBALL();
		Sleep(100);
		system("CLS");
		newBall = true;
		balls--;
		newBall = true;
	}
}



void wideBALL() { //animation to print wideball
	system("CLS");
	cout << endl;
	cout << endl;
	cout << endl;
	Sleep(50); cout << "    ##      ## #### ########  ########    ########     ###    ##       ##          \n";
	Sleep(50); cout << "    ##  ##  ##  ##  ##     ## ##          ##     ##   ## ##   ##       ##          \n";
	Sleep(50); cout << "    ##  ##  ##  ##  ##     ## ########    ########   ##   ##  ##       ##          \n";
	Sleep(50); cout << "    ##  ##  ##  ##  ##     ## ########    ########  ######### ##       ##          \n";
	Sleep(50); cout << "    ##  ##  ##  ##  ##     ## ##          ##     ## ##     ## ##       ##          \n";
	Sleep(50); cout << "     ###  ###  #### ########  ########    ########  ##     ## ######## ########    \n";
	Sleep(1000);
	system("CLS");
}



int main()
{

	srand(time(0)); //to generate random numbers based on the time which is seed by srand
	system("color F0"); //sets the background and foreground color of the terminal to white color
	LOADING();
	gotoxy(0, 0);
	gameName();
	instructions();
	system("CLS");
	system("color F0");
	startScreen();

	gotoxy(50, 20); cout << "ENTER THE NAME OF THE FIRST TEAM \t:";
	getline(cin, Team1); //getline fucntion allowes to input string values with blank spaces
	gotoxy(50, 21); cout << "ENTER THE NAME OF THE SECCOND TEAM \t:";
	getline(cin, Team2);
	system("CLS");
	while (k <= 2) //since two teams are playing the following commands will loop 2 times
	{

		if (k == 1) //if k==1 the the game is on for batting of the team 1
		{
			balls = 0;
			wickets = 0;
			wideBallCount = 0;
			setup();
			newBall = false;
			Team = Team1;

		}
		score1 = score; //updates the value of score to score 1
		if (k == 2) //if k==2 the the game is on for batting of the team 2
		{
			balls = 0;
			wickets = 0;
			wideBallCount = 0;
			boundaries = 0;
			score = 0;
			setup();
			newBall = false;
			Team = Team2;

		}
		while (balls < 36 && wickets < 6) //here its a 6 over  and a 6 wicket match
		{
			x = rand() % 5; //random numbes for x will be stored inside the loops
			setup();


			while (!newBall) { //this is the core of the game which will loop every function needed to be in the game multiple times till it meets the corresponding commands
				draw();
				input();
				logic();
				//Sleep(00);

			}
			balls++;
		}
		k++;
	}
	Sleep(1000);
	system("CLS");
	score = score2;
	if (score1 > score2)
	{
		congrats();
		cout << Team1 << " WON" << endl; //if marks of team 1 is high team one wins
	}
	else
	{
		congrats();
		cout << Team2 << " WON" << endl; //viseversa
	}


	system("PAUSE");
	return 0;

}

void LOADING() { //to loading animation
	gotoxy(20, 20);
	system("color f0");
	cout << "\n\n\n\t\t\t\tPlease wait while loading.......\n\n";
	char a = 177, b = 219;
	cout << "\t\t\t\t";
	for (int i = 0; i <= 50; i++)
		cout << a;
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i <= 50; i++)
	{
		cout << b;
		for (int j = 0; j <= 1e8; j++);
	}
	system("CLS");
}
void wicket() {

	system("CLS");
	Sleep(50); cout << " \t\t #######  ##     ## ########    ###### ###### \n";
	Sleep(50); cout << "\t\t##     ## ##     ##    ##        ####   #### \n";
	Sleep(50); cout << "\t\t##     ## ##     ##    ##         ##     ## \n";
	Sleep(50); cout << "\t\t##     ## ##     ##    ##         ##     ##  \n";
	Sleep(50); cout << "\t\t##     ## ##     ##    ##                 \n";
	Sleep(50); cout << "\t\t##     ## ##     ##    ##        ####   #### \n";
	Sleep(50); cout << "\t\t #######   #######     ##        ####   #### \n";
	cout << "\n\n\n\n\n\n\n";
	Sleep(1000);
	system("CLS");

}
void congrats()
{
	Sleep(50); cout << " ######   #######  ##    ##  ######   ########     ###    ######## ##     ## ##          ###    ######## ####  #######  ##    ##  ######  \n";
	Sleep(50); cout << "##    ## ##     ## ###   ## ##    ##  ##     ##   ## ##      ##    ##     ## ##         ## ##      ##     ##  ##     ## ###   ## ##    ## \n";
	Sleep(50); cout << "##       ##     ## ####  ## ##        ##     ##  ##   ##     ##    ##     ## ##        ##   ##     ##     ##  ##     ## ####  ## ##       \n";
	Sleep(50); cout << "##       ##     ## ## ## ## ##   #### ########  ##     ##    ##    ##     ## ##       ##     ##    ##     ##  ##     ## ## ## ##  ######  \n";
	Sleep(50); cout << "##       ##     ## ##  #### ##    ##  ##   ##   #########    ##    ##     ## ##       #########    ##     ##  ##     ## ##  ####       ## \n";
	Sleep(50); cout << "##    ## ##     ## ##   ### ##    ##  ##    ##  ##     ##    ##    ##     ## ##       ##     ##    ##     ##  ##     ## ##   ### ##    ## \n";
	Sleep(50); cout << " ######   #######  ##    ##  ######   ##     ## ##     ##    ##     #######  ######## ##     ##    ##    ####  #######  ##    ##  ######  \n";
}
void startScreen() {


	Sleep(50); cout << "			-----------------------------------------------------------------------------------\n";
	cout << endl;
	Sleep(50); cout << "				@                                _                                 ,,   \n";
	Sleep(50); cout << "				 \\\\   _   @'                    ( )_                       .     _  \\\\   \n";
	Sleep(50); cout << "				  \\\\_( )_//                    / Y |                   .    //--( )_//      \n";
	Sleep(50); cout << "		   		    | Y/--                    /\   /               .        //   \\~ \\   \n";
	Sleep(50); cout << "                                    |_/       _ / o          ( _\\ /            .                 \\  \\       \n";
	Sleep(50); cout << "		                  _ //\\      | | |    .       \\_\\\\\\       .                     //  \\\\--,    \n";
	Sleep(50); cout << "		        	 /_// /      | | |      .    / \\ \\\\\\ .                           \\\\             \n";
	Sleep(50); cout << "		             ___/ // /_______|_|_|__________/_/_\\ \\________________________________\\\\______   \n";
	Sleep(50); cout << "	                ------------------------------------------------------------------------------------       \n";

}

void gameName() { //to print the name of the game as kajuwaththa eksath rikcet game in a smart animatedway. here we have used sleep dunctions.
	system("color F0");
	string array1 = "\t\t                                __      ____________               ___";
	string array2 = "\t\t                               / /     |__________  |              | |";
	string array3 = "\t\t                              / /                 | |              | |";
	string array4 = "\t\t   ____  _______   ____  ___/ /           ____    | |   ____  _____| |    ____  _______";
	string array5 = "\t\t   |_   |/ ___   | |__  ||  ___|         |___ |   | |  |_   |/ ___   |   |_   |/ ___   |";
	string array6 = "\t\t     / __\\ \\  |  ||  ________  |        |  ___|   | |    /__\\ \\   |  |     /__\\ \\   |  |  ";
	string array7 = "\t\t    / /  | |  |  || |        | |        | |       | |  / /   | |  |  |   / /   | |  |  |";
	string array8 = "\t\t   / /___| |  |  || |________| |        | |_______| | / /____| |  |  |  / /____| |  |  |";
	string array9 = "\t\t  /___/\\___|  |__||__________  |        |___________| \\________|  |__|  \\________|  |__|";
	string array10 = "\t\t                             | |";
	string array11 = "\t\t                   __________| | ";
	string array12 = "\t\t                  |____________| ";

	cout << endl;
	cout << endl;
	cout << endl;
	system("color F0");
	string array13 = "\t\t    ***************                  ******                                             ******";
	string array14 = "\t\t   *****************                   *****                                              *****";
	string array15 = "\t\t         **      ***                   ****                                               ****";
	string array16 = "\t\t          **     ***                   ***                                                ***";
	string array17 = "\t\t            ********                   ***                                                ***";
	string array18 = "\t\t                 ***                   ***                                                ***";
	string array19 = "\t\t      *****      ***    *****     *********        ******    ******        *****    *********";
	string array20 = "\t\t     **   **     ***   *** ***  ****    ****      ***  ***  ***  ***      ***  *** ***    ****";
	string array21 = "\t\t   *********     ***    *  *********     ****   *********************         *********     ***";
	string array22 = "\t\t      ***        ***       ***    ***     ***     ***             ***       ***     ***     ***";
	string array23 = "\t\t      ***        ***     ***       ***    ***     ***      *      ***      ***       ***    ***";
	string array24 = "\t\t      ****      ****    ***   *    ***    ***     ***     ***     ***     ***        ***    ***";
	string array25 = "\t\t      **************   ***   ***  ***     ***     *******************    **************     ***";
	string array26 = "\t\t       ************      ****   ****     ***       ******** ********        **********     ***";
	cout << " ";

	cout << "\n";
	system("color F0");
	string array27 = "\t\t\t\t\t              __        __            __                                   \n";
	string array28 = "\t\t\t\t\t .----.----. |__|.----.|  |--. -----.|  |_     .-----. ---.-.--------.  ----- \n";
	string array29 = "\t\t\t\t\t |  __||   _||  ||  __||    <||  -__||   _|    |  _  ||  _  ||        ||  -__| \n";
	string array30 = "\t\t\t\t\t |____||__|  |__||____||__|__||____| |____|    |___  ||___|_||__|__|__||_____| \n";
	string array31 = " \t\t\t\t\t                                               |_____|                      \n";
	cout << "\n\n\n\n\n";


	for (int x1 = 0; array1[x1] != '\0'; x1++) {
		if (array1[x1] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array1[x1];
	}
	cout << endl;

	for (int x2 = 0; array2[x2] != '\0'; x2++) {
		if (array2[x2] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array2[x2];
	}
	cout << endl;
	for (int x3 = 0; array3[x3] != '\0'; x3++) {
		if (array3[x3] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array3[x3];
	}
	cout << endl;
	for (int x4 = 0; array4[x4] != '\0'; x4++) {
		if (array4[x4] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array4[x4];
	}
	cout << endl;
	for (int x5 = 0; array5[x5] != '\0'; x5++) {
		if (array5[x5] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array5[x5];
	}
	cout << endl;
	for (int x6 = 0; array6[x6] != '\0'; x6++) {
		if (array6[x6] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array6[x6];
	}
	cout << endl;
	for (int x7 = 0; array7[x7] != '\0'; x7++) {
		if (array7[x7] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array7[x7];
	}
	cout << endl;
	for (int x8 = 0; array8[x8] != '\0'; x8++) {
		if (array8[x8] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array8[x8];
	}
	cout << endl;
	for (int x9 = 0; array9[x9] != '\0'; x9++) {
		if (array9[x9] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array9[x9];
	}
	cout << endl;
	for (int x10 = 0; array10[x10] != '\0'; x10++) {
		if (array10[x10] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array10[x10];
	}
	cout << endl;
	for (int x11 = 0; array11[x11] != '\0'; x11++) {
		if (array11[x11] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array11[x11];
	}
	cout << endl;
	for (int x12 = 0; array12[x12] != '\0'; x12++) {
		if (array12[x12] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array12[x12];
	}
	cout << "\n\n\n\n\n\n\n\n";
	for (int x13 = 0; array13[x13] != '\0'; x13++) {
		if (array13[x13] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array13[x13];
	}
	cout << endl;
	for (int x14 = 0; array14[x14] != '\0'; x14++) {
		if (array14[x14] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array14[x14];
	}
	cout << endl;
	for (int x15 = 0; array15[x15] != '\0'; x15++) {
		if (array15[x15] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array15[x15];
	}
	cout << endl;
	for (int x16 = 0; array16[x16] != '\0'; x16++) {
		if (array16[x16] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array16[x16];
	}
	cout << endl;
	for (int x17 = 0; array17[x17] != '\0'; x17++) {
		if (array17[x17] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array17[x17];
	}
	cout << endl;
	for (int x18 = 0; array18[x18] != '\0'; x18++) {
		if (array18[x18] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array18[x18];
	}
	cout << endl;
	for (int x19 = 0; array19[x19] != '\0'; x19++) {
		if (array19[x19] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array19[x19];
	}
	cout << endl;
	for (int x20 = 0; array20[x20] != '\0'; x20++) {
		if (array20[x20] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array20[x20];
	}
	cout << endl;
	for (int x21 = 0; array21[x21] != '\0'; x21++) {
		if (array21[x21] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array21[x21];
	}
	cout << endl;
	for (int x22 = 0; array22[x22] != '\0'; x22++) {
		if (array22[x22] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array22[x22];
	}
	cout << endl;
	for (int x23 = 0; array23[x23] != '\0'; x23++) {
		if (array23[x23] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array23[x23];
	}
	cout << endl;
	for (int x24 = 0; array24[x24] != '\0'; x24++) {
		if (array24[x24] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array24[x24];
	}
	cout << endl;
	for (int x25 = 0; array25[x25] != '\0'; x25++) {
		if (array25[x25] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array25[x25];
	}
	cout << endl;
	for (int x26 = 0; array26[x26] != '\0'; x26++) {
		if (array26[x26] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array26[x26];
	}
	cout << endl;
	cout << "\n\n\n\n\n\n\n\n\n";
	for (int x27 = 0; array27[x27] != '\0'; x27++) {
		if (array27[x27] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array27[x27];
	}

	cout << endl;
	for (int x28 = 0; array28[x28] != '\0'; x28++) {
		if (array28[x28] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array28[x28];
	}

	cout << endl;
	for (int x29 = 0; array29[x29] != '\0'; x29++) {
		if (array29[x29] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array29[x29];
	}

	cout << endl;
	for (int x30 = 0; array30[x30] != '\0'; x30++) {
		if (array30[x30] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array30[x30];
	}

	cout << endl;
	for (int x31 = 0; array31[x31] != '\0'; x31++) {
		if (array31[x31] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array31[x31];
	}
	cout << endl;
	cout << "\n\n\n\n\n\n\n\n\n";

	Sleep(2000);
	system("CLS");
}

void no_Ball() {
	Sleep(50); cout << "\t\t##    ##  #######     ########     ###    ##       ##          \n";
	Sleep(50); cout << "\t\t###   ## ##     ##    ##     ##   ## ##   ##       ##          \n";
	Sleep(50); cout << "\t\t####  ## ##     ##    ##     ##  ##   ##  ##       ##          \n";
	Sleep(50); cout << "\t\t## ## ## ##     ##    ########  ##     ## ##       ##          \n";
	Sleep(50); cout << "\t\t##  #### ##     ##    ##     ## ######### ##       ##          \n";
	Sleep(50); cout << "\t\t##   ### ##     ##    ##     ## ##     ## ##       ##          \n";
	Sleep(50); cout << "\t\t##    ##  #######     ########  ##     ## ######## ########    \n";

}

void instructions() {
	gotoxy(18, 2); cout << "\t\t\t\t\tINSTRUCTIONS" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	gotoxy(15, 6); cout << "A : TO HIT IN RIGHT SIDE" << endl;
	gotoxy(15, 7); cout << "D : TO HIT IN LEFT SIDE" << endl;
	gotoxy(15, 8); cout << "S : TO HIT IN FORWARD SIDE" << endl;
	gotoxy(15, 9); cout << "E : TO HIT IN FINELEG SIDE" << endl;
	gotoxy(15, 10); cout << "Q : TO HIT THIRD MAN SIDE" << endl;
	gotoxy(15, 11); cout << "X : TO MOVE THE BATSMAN RIGH SIDE" << endl;
	gotoxy(15, 12); cout << "1 : TO SELECT PLAYER 1" << endl;
	gotoxy(15, 13); cout << "2 : TO SELECT PLAYER 2" << endl;
	gotoxy(15, 14); cout << "3 : TO SELECT PLAYER 3" << endl;
	gotoxy(15, 15); cout << "4 : TO SELECT PLAYER 4" << endl;
	gotoxy(15, 16); cout << "5 : TO SELECT PLAYER 5" << endl;
	gotoxy(15, 17); cout << "6 : TO SELECT PLAYER 6" << endl;
	gotoxy(15, 18); cout << "K : TO START BOWLER RUNNING" << endl;
	gotoxy(15, 19); cout << "L : TO BOWL" << endl;
	cout << endl;
	cout << endl;
	gotoxy(15, 23); Sleep(400); cout << "CREDITS\n\n";
	gotoxy(15, 25); Sleep(400); cout << "KAJUWATHTHA EKSATH CRICKET\n\n";
	gotoxy(15, 27); Sleep(400); cout << "Developed by\n\n";
	gotoxy(15, 29); Sleep(400); cout << "Mayura Manawadu\n";
	gotoxy(15, 30); Sleep(400); cout << "Dushan Ekanayake\n";
	gotoxy(15, 31); Sleep(400); cout << "Shasitha Madhusanka\n";
	gotoxy(15, 32); Sleep(400); cout << "Adheesh Kulathunga\n";
	Sleep(400); cout << "\n\nHeartiest gratitude our sir Dr. RANDIMA DINALANKARA and all the instrcutors of the Department of Computer Engineering University of Sri Jayewardenepura"; cout << endl;
	cout << endl;
	cout << endl;
	system("PAUSE");
}