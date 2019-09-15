/*****************************PINGPONG******************************/
#include<graphics>   // For Using Graphical Functions
#include<dos.h>        // For delay()
#include<conio.h>      // For getch()
#include<time.h>       // For Using Time Class
#include<stdlib.h>     // For srand(), rand() and itoa()


/********************** Defining Ball Class *************************/

class ball
{
   public:
   int radius;
   int speedx;
   int speedy;
   int oldballx;
   int oldbally;
   int newballx;
   int newbally;

/******************Function To Initialize Ball*********************/

   void ball_initialize(int rad, int newx, int newy)
   {
      radius=rad;
      oldballx=newx;
      newballx=newx;
      oldbally=newy;
      newbally=newy;

/****Random Function To Make The Speed and Direction Of Ball Random****/

      time_t t1;
      srand((int)time(&t1));
      speedx=rand()%2+1;    // Random Speed In x Direction
      speedy=rand()%2+1;    // Random Speed In y Direction

      if (rand()%2==0)
      {
	 speedx=-speedx;   //  Move Ball In Random x Direction
	 speedy=-speedy;   //  Move Ball In Random y Direction
      }
      setcolor(4);
      setfillstyle(5,6);
      fillellipse(newballx,newbally,radius,radius);   // Draw Ball
   }

/*********Function moveball() That Controls All the Ball Movements***********/

      void moveball()
      {
	 oldballx=newballx;
	 oldbally=newbally;
	 newballx+=speedx;
	 newbally+=speedy;

	 setcolor(0);
	 setfillstyle(1,0);
	 fillellipse(oldballx,oldbally,10,10);  // Remove Ball at Old xy Position
	 setcolor(4);
	 setfillstyle(5,6);
	 fillellipse(newballx,newbally,10,10);  // Draw Ball at New xy  Position

	 if (newballx-radius<30)    // Reflect From Left Side
	 speedx=-speedx;
	 if (newballx+radius>460)   // Reflect From Right Side
	 speedx=-speedx;
      }


};
// Ball Class Closed


/*****************Score Class To Hold The Score Of Both Players*************/

class score
{
  public:
  int player1;
  int player2;
  score()          // Call Constructors To Set The Scores To Zero
  {
      player1=0;
      player2=0;
  }
};

// Score Class Closed


/**************************Class for Paddles**************************/

class paddle
{
   public:
   int oldbatx;
   int constbaty;
   int newbatx;
   int batlength;
   int batwidth;
   int batspeed;

/********************Function To initialize The Bat*********************/

   void paddle_initialize(int batx, int baty, int len, int wid,int batspd)
   {
      batspeed=batspd;
      oldbatx=batx;
      newbatx=batx;
      constbaty=baty;
      batlength=len;
      batwidth=wid;
      setfillstyle(6,9);
      bar(newbatx,constbaty,newbatx+batlength,constbaty+batwidth);  // Draw Bat
   }
};

/*****************Function To Control All The Bat Movements****************/

void movepaddle(paddle &p1, paddle &p2,char ch)
   {
/***************************For Player1********************************/

      if (ch=='a' && p1.newbatx>30)  // If Input is 'a' The Move
				     // Player 1 Bat Left
      {                              // Also Checks If the Bat Reaches Extreme Left
	 p1.oldbatx=p1.newbatx;
	 p1.newbatx-=40;             // Move New Coordinates To Left
	 setfillstyle(1,0);          // Remove Bat At Previous xy Position
	 bar(p1.oldbatx,p1.constbaty,p1.oldbatx+p1.batlength,p1.constbaty+p1.batwidth);
	 setfillstyle(6,9);          // Draw Bat At New xy Position
	 bar(p1.newbatx,p1.constbaty,p1.newbatx+p1.batlength,p1.constbaty+p1.batwidth);
      }
     if (ch=='d' && p1.newbatx+p1.batlength<470)

      {
	 p1.oldbatx=p1.newbatx;
	 p1.newbatx+=40;              // Move Coordinates To Right
	 setfillstyle(1,0);
	 bar(p1.oldbatx,p1.constbaty,p1.oldbatx+p1.batlength,p1.constbaty+p1.batwidth);
	 setfillstyle(6,9);
	 bar(p1.newbatx,p1.constbaty,p1.newbatx+p1.batlength,p1.constbaty+p1.batwidth);
      }

/*********************************For Player2*******************************/

     if (ch=='j' && p2.newbatx>30)

      {
	 p2.oldbatx=p2.newbatx;
	 p2.newbatx-=40;           // Move Bat To Left
	 setfillstyle(1,0);
	 bar(p2.oldbatx,p2.constbaty,p2.oldbatx+p2.batlength,p2.constbaty+p2.batwidth);
	 setfillstyle(6,9);
	 bar(p2.newbatx,p2.constbaty,p2.newbatx+p2.batlength,p2.constbaty+p2.batwidth);
      }
       if (ch=='l' && p2.newbatx+p2.batlength<470)

      {
	 p2.oldbatx=p2.newbatx;
	 p2.newbatx+=40;           //Move Bat To Right
	 setfillstyle(1,0);
	 bar(p2.oldbatx,p2.constbaty,p2.oldbatx+p2.batlength,p2.constbaty+p2.batwidth);
	 setfillstyle(6,9);
	 bar(p2.newbatx,p2.constbaty,p2.newbatx+p2.batlength,p2.constbaty+p2.batwidth);
      }

       if (ch=='q')               // Q for Quit
       exit(0);

       if (ch=='p')               // P for Pause
       {
	  settextstyle(4,0,5);
	  outtextxy(50,200,"    PAUSED");
	  getch();
	  setcolor(0);
	  outtextxy(50,200,"    PAUSED");
       }
   }

// Move Bat Function Closed

/***************************MAIN MENU***************************************/

void main_menu(score sc)
{
   if (sc.player1==0 && sc.player2==0)           // If scores are Zero
   {                                             // Then MainMenu Should Be displayed
      int gd=DETECT,gm;
      initgraph(&gd,&gm,"C:\\TC\\BGI");

      for(int x=0,y=0; x<640,y<479;x++,y++)
	{  setcolor(WHITE);
	   line(x,0,639,y);
	   setcolor(5);
	   line(639-x,479,0,479-y);
	   delay(5);
	}

     while(!kbhit())
     {
	int j=1+rand()%15;
	int i=1+rand()%15;

	setcolor(i);
	settextstyle(4,0,4);
	outtextxy(50,70,"OBJECT ORIENTED PROGRAMMING");
	settextstyle(10,0,1);
	setcolor(4);
	settextstyle(4,0,4);
	outtextxy(120,130,"Submitted To:");
	outtextxy(140,150,"MRS. ZARA HAMID");
	settextstyle(10,0,1);
	setcolor(j);
	outtextxy(240,210,"~~~~~~~~~~~~~~");
	outtextxy(240,220,"~~ PINGPONG ~~");
	outtextxy(240,230,"~~~~~~~~~~~~~~");

	setcolor(4);
	settextstyle(2,0,6);
	outtextxy(290,320,"Made By:");
	setcolor(4);
	settextstyle(4,0,4);
	outtextxy(310,345,"MIRZA SHAHAB UD DIN -SP11-BCS-072");
	outtextxy(310,365,"BILAL HAIDER        -SP11-BCS-032");
	outtextxy(310,385,"ASIF MEHMOOD        -SP11-BCS-026");
	outtextxy(310,405,"BADI UL ZAMAN       -SP11-BCS-030");

       delay(100); //blinking time period of font
     //  cleardevice();
     }

      closegraph();
   }

}

/********************Initialize Background And Graphics*********************/

void initialize_background(paddle &p1, paddle &p2 , ball &ball1, score &sc)
{



   main_menu(sc);

   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   cleardevice(); //to load graphics

   setbkcolor(BLACK);
   setfillstyle(4,6);
   rectangle(0,0,639,479);
   rectangle(20,20,620,460);
   floodfill(15,15,WHITE);
   rectangle(480,20,500,460);
   floodfill(490,30,WHITE);
   rectangle(500,340,620,360);
   floodfill(510,350,WHITE);

   // Initializing Bats and Ball;

   p1.paddle_initialize(220,450,50,9,5);
   p2.paddle_initialize(221,21,50,9,5);
   ball1.ball_initialize(10,250,240);

   // Two Strings To Hold The Scores

   char str1[15];
   char str2[15];

/**************Printing All The Stuff In Right Pane Of Screen*************/

   itoa(sc.player1,str1,5); // itoa() Converts an Integer To String
   settextstyle(2,0,4);
   setcolor(YELLOW);
   outtextxy(505,40,"Player1 Score");
   outtextxy(505,50,str1);
   itoa(sc.player2,str2,5);
   outtextxy(505,60,"Player2 Score");
   outtextxy(505,70,str2);
   settextstyle(2,0,4);
   setcolor(LIGHTCYAN);
   outtextxy(505,100,"    K E Y S   ");
   outtextxy(505,120,"Player1: ");
   outtextxy(505,140,"A To Move Left");
   outtextxy(505,150,"D To Move Right");
   outtextxy(505,170,"Player2: ");
   outtextxy(505,190,"J To Move Left");
   outtextxy(505,200,"L To Move Right");
   setcolor(WHITE);
   outtextxy(505,300,"WIN LIMIT: 3");
   outtextxy(505,310,"P For Pause");
   outtextxy(505,320,"Q For Quit");
   settextstyle(2,0,4);
   setcolor(GREEN);

   outtextxy(505,365," GROUP MEMBERS ");
   outtextxy(505,385,"SHAHAB UD DIN");
   outtextxy(505,405,"ASIF MEHMOOD");
   outtextxy(505,425,"BADI UL ZAMAN");
   outtextxy(505,445,"BILAL HAIDER");

   settextstyle(4,0,5);
   getch();
   outtextxy(100,200," R E A D Y ");
   getch();
   setcolor(0);
   outtextxy(100,200, " R E A D Y ");
}
// Initialize Background Function Closed

/*****************A Function That Checks If the Ball Hits The Bat***********/

void batstrike(paddle &p1, paddle &p2 ,score &sc, ball &ball1)

/**************************Check For Player1********************************/

{
   if (ball1.newbally+ball1.radius>=450)  // Checks If the Ball Is In Range Of Bat Of player1
   if (ball1.newballx>p1.newbatx && ball1.newballx <p1.newbatx+p1.batlength)
   {                                     // Checks If the Hits the Bat or Not
      time_t t;                          // By Comparing The X-Coordinates
      srand((int) time(&t));             // If The Ball Hits The Bat
      ball1.speedy=2+rand()%2;
      ball1.speedy=-ball1.speedy;        // Then Make Its Speed Random
      ball1.speedx=rand()%5;             //
      if (rand()%2==0)
      ball1.speedx=-ball1.speedx;        // To Make It x-Direction Random
   }
   else                                  // If The Ball Missed The Bat
   {
      sc.player2++;                      // Increase Score for Player2
      initialize_background(p1,p2,ball1,sc); // Re-Initialize The Game
   }

/***************************Check For Player2***************************/

   if (ball1.newbally-ball1.radius<=30)
   if (ball1.newballx >p2.newbatx && ball1.newballx< p2.newbatx+p2.batlength)
   {
      time_t t;
      srand((int) time(&t));

      ball1.speedy=-ball1.speedy;
      ball1.speedy=2+rand()%2;


      if (rand()%2==0)
      ball1.speedx=-ball1.speedx;
   }
   else
   {
      sc.player1++;
      initialize_background(p1,p2,ball1,sc);
   }
}

// batstrike() Function Closed

/******************A Function That Controls All The Playings***************/

void play(paddle &p1, paddle &p2, score &sc, ball &ball1)
{

   while(1)
   {

      delay(15);                  // Set delay()
      if(kbhit())                 // Checks If any Key is Pressed
      movepaddle(p1,p2,getche()); // If key is Pressed Then Control
				  // is transferred To movepaddle()
      ball1.moveball();           // moveball() functions is called
      batstrike(p1,p2,sc,ball1);  // batstrike() functions is called
      if(sc.player1>=3)           // Checks if any player's Score
      {                           // reaches 3 so He should be the winner
	 setcolor(2);
	 settextstyle(4,0,5);
	 outtextxy(50,200,"P L A Y E R  1  W I N S");
	 getch();
	 getch();
	 break;
      }
      if (sc.player2>=3)          // Score check For Player2
      {
	 setcolor(4);
	 settextstyle(4,0,5);
	 outtextxy(50,200,"P L A Y E R  2  W I N S");
	 getch();
	 getch();
	 break;
      }
   }
}
// Play Function Is Closed

/********************************MAIN FUNCTION*******************************/

int main()
{
   paddle p1,p2;             // Make Objects Of bat For Player1 & Player2
   ball ball1;               // Make Object Of Ball Class
   score sc;                 // Make Object Of score Class
   initialize_background(p1,p2,ball1,sc);  // Initialize background & Graphics
   play(p1,p2,sc,ball1);     // Play() called
   getch();
   closegraph();             // Graphics closed
   return 0;
}

/******************************************************************************/
