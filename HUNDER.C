//hunter game
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ESC 1
#ifdef __cplusplus
     #define __CPPARGS ...
#else
     #define __CPPARGS
#endif
void interrupt (*prev)(__CPPARGS);
void interrupt our(__CPPARGS);
void initialise();
void cross();
void bird_action();
int stage=1,cc=0,ii=1;
int kk=0,n=0,p=0,l=0,m=0,count=0,b1=0,b2=0,b3=0,o=0,bow=0,speed=100,s=1;
char msg[50];
int xx=296,i,xx3=304,xx5=300,xx8=250,xx9=350,xx4=305,xx2=270,xx6=400;
int yy=251,yy1=301,yy2=351,yy4=304,yy3=410,yy5=310,xx10=310,yy6=305,yy7=290,yy8=400;
int direction=3,can,stop=0;
void main()   //main function
  {
  int gd=DETECT,gm,i;
  clrscr();
  initgraph(&gd,&gm,"d:\\turboc3\\bgi");
  prev=getvect(9);
    for( i=0;i<20;i++)
{
delay(500);
cleardevice();
 setbkcolor(BLACK);
   setcolor(RED);
    setcolor(EGA_YELLOW);
   settextstyle(1,HORIZ_DIR,6);
   outtextxy(250,250,"THE HUNTER");

if(i%2==0)
{
line(500,200,522,185);
ellipse(503,194,270,35,20,15);
ellipse(500,200,180,350,20,15);
pieslice(475,200,0,50,5);
pieslice(488,197,0,360,2);
line(495,215,508,217);
line(493,215,508,218);
ellipse(490,200,0,180,10,10);
}
if(i%2==1)
{
line(500,200,523,190);
ellipse(503,194,270,20,20,15);
ellipse(500,200,180,350,20,15);
pieslice(475,200,0,50,5);
pieslice(488,197,0,360,2);
line(495,215,508,217);
line(493,215,508,218);
ellipse(490,200,0,180,10,10);
}
}  cleardevice();
    setcolor(RED);
   settextstyle(7,HORIZ_DIR,1);
    outtextxy(250,100,"C0DED BY");
   outtextxy(250,175,"MUTHU PANDI");
   outtextxy(250,200,"MANOJ");
   outtextxy(250,225,"BILAL MOHAMMED");
    outtextxy(250,275,"DESIGNED BY");
   outtextxy(250,325,"GOWTHAM RAJA");
   outtextxy(250,350,"AKASH KUMAR");
   outtextxy(250,375,"GAUTHAM SARATHY");
   delay(4000);
   cleardevice();
   printf("\n\n\n\n to move the bow left press <-""\n to move the bow right press ->""\nto shoot press ^" );
    delay(4000);
   cleardevice();


 stag(1);
 while(1)
    {
    setvect(9,our);
    bird_action();
    }
closegraph();
  }

void interrupt our(__CPPARGS)          //interrupter
     {
					 //if(inportb(0x60)==UP){
					 //i=0;j
	  switch(inportb(0x60))
	  {
		case UP:direction=0;if(n!=0)n--;m=1;kk=0;can=0;break;
		//  case DOWN:direction=1;break;
		case RIGHT:if(m==0){direction=3;can=3;}break;
		case LEFT: if(m==0){direction=2;can=2;}break;
		 // case 15:blocks++;break;
		case ESC:  stop=1;direction=5;break;
	  }

	  (*prev)();
      }

void initialise(int n)                //tree with cloud
  {
  setbkcolor(61);
/*   setcolor(WHITE);
   rectangle(0,0,639,470);   */
   setcolor(14);
   setfillstyle(SOLID_FILL,14);
   fillellipse(465,30,20,20);
   setcolor(2);
   setfillstyle(INTERLEAVE_FILL,2);
   fillellipse(250,160,100,50);
    fillellipse(350,200,75,36);
   fillellipse(250,240,80,40);

   fillellipse(150,200,75,36);


   setcolor(6);
   ellipse(200,368,270,90,25,96);
   ellipse(300,368,90,270,25,96);
   setcolor(4);
   setfillstyle(SOLID_FILL,EGA_RED);
   pieslice(270,185,0,360,4);
   pieslice(250,195,0,360,4);
   pieslice(280,140,0,360,4);
   pieslice(220,165,0,360,4);
   pieslice(120,190,0,360,4);
   pieslice(290,220,0,360,4);
   pieslice(220,240,0,360,4);
   pieslice(230,150,0,360,4);
   setcolor(9);
   setfillstyle(SOLID_FILL,9);
   fillellipse(400,40,40,20);
   setfillstyle(SOLID_FILL,9);
   fillellipse(450,60,60,20);

   cross(n);
  }
void cross(int n)             //cross un the bucket
     {
       int i;
	int a1=575,b1=573,c1=577,d1=575;
	setcolor(6);
   /*	line(570,372,570,458);
	line(600,372,600,458);
	ellipse(585,458,180,360,15,5);
	ellipse(585,370,0,180,15,5);*/
	setcolor(15);
	for(i=0;i<n;i++)
	   {
	     line(a1,360,a1,458);
	     line(b1,360,d1,350);
	     line(c1,360,d1,350);
	     line(b1,360,c1,360);
	     a1=a1+3;
	     b1=b1+3;
	     c1=c1+3;
	     d1=d1+3;
	   }
      //	setcolor(6);
    //	ellipse(585,370,180,360,15,5);
     }


void bird1(int x,int y,int i,int j,int u,int v,int yy8,int yy6,int xx5,int p1)
     {
	int a=5,b=3,c=14;
	// FACE
	setcolor(WHITE);
	circle(x,y,a);
	// EYES
	setcolor(4);
	circle(x+(i*2),y-2,1);
	// NOSE
	line(x+(i*a),y-b,x+(i*(a+5)),y-b+2);
	line(x+(i*(a+1)),y,x+(i*(a+5)),y+2);
	line(x+(i*(a+5)),y-b+2,x+(i*(a+5)),y+4);
       if(u==1||v==1)        //fruit at mouth of the bird
	{

	setfillstyle(SOLID_FILL,RED);
	circle(x+(i*(a+8)),y+8,4);
	floodfill(x+(i*(a+8)),y+8,4);
	}
	// BODY
        	setcolor(WHITE);
        if(p1==1)
        setfillstyle(SOLID_FILL,5);
         if(p1==2)
	setfillstyle(SOLID_FILL,EGA_YELLOW);
         if(p1==3)
         setfillstyle(SOLID_FILL,EGA_BLUE);
          fillellipse(x-(i*(a+c)),y,c,9);

    if((y+9)<=yy8&&(y-9)>=yy6)
	  {
	    if((xx5<=x-(i*(a+c))+14)&&xx5>=(x-(i*(a+c)))-14)
	    {
	    bow++;
	    p=1;
	    setcolor(4);
	    setfillstyle(SOLID_FILL,EGA_YELLOW);
	    fillellipse(xx5,y-12,3,2);
	    fillellipse(xx5-3,y-13,2,2);
	    fillellipse(xx5-2,y-11,1,1);
	    count++;
	    sprintf(msg,"PREFECT SHOOT");
	    setcolor(EGA_YELLOW);
	    settextstyle(1,HORIZ_DIR,2);
	    outtextxy(160,70,msg);
	    if(p1==1)
	       b1=1;
	     if(p1==2)
		b2=1;
	     if(p1==3)
		b3=1;
	      if(b1==1&&b2==1&&b3==1)
		  o=1;
	       if(bow==2)
	       {
		  n++;
		  bow=0;
	       }
	       for( i=100;i<700;i+=100)
		       {   //sound
		       sound(i);
		       delay(10);
		       nosound();
			}
	    delay(100);


	    }
	}
         if(count==cc)
	     {
	       cleardevice();
		initialise( n);
		 gotoxy(250,195);
		 printf("YOU COMPLETED STAGE %d",ii);
		 ii++;
		 stag(ii);
                 o=1;  count=0;
	     }
	//TAIL
	setcolor(WHITE);
	line(x-(i*(a+(2*c)+7)),y-a,x-(i*(a+(2*c)+7)),y+a);
	line(x-(i*(a+(2*c)+7)),y-a,x-(i*(a+(2*c))),y-2);
	line(x-(i*(a+(2*c)+7)),y+a,x-(i*(a+(2*c))),y+2);
	// WINGS
	if((j%2)==0)
		{
		    line(x-(i*(a+c+6)),y,x-(i*(a+c)),y-18);
		    line(x-(i*(a+c)),y-18,x-(i*a),y);
		}
	else
		{
		line(x-(i*(a+c+6)),y,x-(i*(a+c)),y+18);
		line(x-(i*(a+c)),y+18,x-(i*a),y);
		}


      }


int small_change(int i,int *j)
	{
	     if((i%2)==0)
		{
		*j=1;
		return 0;
		}
	else
		{
		*j=-1;
		return getmaxx();
		}
	}


void calcx(int *x,int *k,int *j,int *u,int *v)
	{
	   if(*j==1)
	      {
	       *x=*x+5;
	       if(*x<=((getmaxx()/2)+5) && *x>=((getmaxx()/2)-5))
		  {
		     *k=-*k;
		     *j=-1;
		     *x=*x-5;
		    *v=1;
		  }
	      }
	   else
		{
		*x=*x-5;
		  if(*x<=((getmaxx()/2)+2) && *x>=((getmaxx()/2)-2))
		     {
		       *k=-*k;
		       *j=1;
		       *x=*x+5;
		     *u=1;
	       }
		}
	}

void bird_action()
     {
	int i,x[3],y[3],j[3],k[3],u=0,v=0,q=0;
	int p1=1,p2=2,p3=3;
	randomize();
	b1=0;b2=0;b3=0;o=0;
	y[0]=rand()%250;
	y[1]=rand()%250;
	y[2]=rand()%250;
	x[0]=small_change(y[0],&j[0]);
	x[1]=small_change(y[1],&j[1]);
	x[2]=small_change(y[2],&j[2]);
	k[0]=(200-y[0])/50;
	k[1]=(200-y[1])/50;
	k[2]=(200-y[2])/50;
	//get=getmaxx()-40;
	for(i=0;x[2]>=0 && x[2]<=getmaxx()&&o!=1;i++)
	   {

	     gotoxy(2,2);
	     printf("BIRDS SHOT=%d",count);
	     gotoxy(2,3);
	     printf("ARROWS REMAINING=%d",n);
             gotoxy(2,4);
             printf("YOU HAVE TO SHOT=%d",cc);

	     delay(speed/ii);
	     cleardevice();
	     initialise(n);

	      if(n==0)
		stop1();
              if(stop==1)
                exit(0);


	     if(direction==2&&can==2&&xx5>=20)
		{
		  xx-=17;xx3-=17;xx5-=17;xx8-=17;xx9-=17;yy5=-17;
		  yy-=17;yy1-=17;yy2-=17;yy4-=17;yy5-=17;
		  can=0;
		}
	     if(direction==3&&can==3&&xx5<=590)
		{
		xx+=17;xx3+=17;xx5+=17;xx8+=17;xx9+=17;
		yy+=17;yy1+=17;yy2+=17;yy4+=17;yy5+=17;
		can=0;
		}
	   setcolor(WHITE);
	   if(direction!=0&&n>=0)//arrow
	       {
		 line(xx,340,xx3,340);
		 line(xx,340,xx5,325);
		 line(yy4,340,xx5,325);
		 line(xx5,340,xx5,435);
	       }
	     setcolor(4);
	     line(xx,345,xx,445);  //bow
	     line(xx3,345,xx3,445);
	     line(xx8,385,xx5,445);
	     line(yy,385,yy1,445);
	     line(xx9,385,xx5,445);
	     line(yy2,385,yy1,445);
	     line(xx,445,xx3,445);
	     line(xx,345,xx3,345);

	     ellipse(xx5,385,0,180,50,25);
	     ellipse(xx5,389,0,180,50,25);
	     ellipse(xx5,440,0,180,10,10);
		if(direction==0&&can==0&&n>0)
		  {
		       if(p==1)
		       {          //bird shoot
			  kk=14;
			  m=0  ;
		       }
		   setcolor(WHITE);
		   if(kk<=15)
		     {
		      /* for( i=100;i<700;i+=300)
		       {   //sound
		       sound(i);
		       delay(10);
		       nosound();
			}*/
		  line(xx,yy6,xx3,yy6);   //3 line bow
		  line(xx,yy6,xx5,yy7);
		  line(yy4,yy6,xx5,yy7);
		  line(xx5,yy6,xx5,yy8);   //arrow line
		  yy6-=19;yy7-=19;yy8-=19;
		 // delay(300);
		//  printf("%d/n%d",xx,yy6);
		  kk++;
		   if(stop==1)
		   exit(0);

		   if(kk==15)
		      {
			yy6=xx4;yy7=290;yy8=xx6;
			direction=2;direction=3;
			p=0;
			m=0;
		      }
	       }
	  }

		 if(stop==1)
		 exit(0);


		 if(x[0]>=0 && x[0]<=getmaxx()&&b1==0)
		    {
		       q++;
			if(q>=40&&(b2==1||b3==1))
			  {
			     if(x[0]<=0||x[0]>=getmaxx())
			      {
			      o=1;
			      }
			  }
			bird1(x[0],y[0],j[0],i,u,v,yy8,yy6,xx5,p1);
			calcx(&x[0],&k[0],&j[0],&u,&v);
			y[0]+=k[0];
		    }
		if(i>10 && x[1]>=0 && x[1]<=getmaxx()&&b2==0)
		{
		       q++;
			if(q>=40&&(b1==1||b3==1))
			  {
			     if(x[1]==0||x[1]==getmaxx())
			      {
			      o=1;
			      }
			  }
			bird1(x[1],y[1],j[1],i+1,u,v,yy8,yy6,xx5,p2);
			calcx(&x[1],&k[1],&j[1],&u,&v);
			y[1]+=k[1];
		}
		if(i>20 && x[2]>=0 && x[2]<=getmaxx()&&b3==0)
		{
		     q++;
		      if(q>=40&&(b2==1||b1==1))
			  {
			     if(x[2]==0||x[2]==getmaxx())
			      {
			      o=1;

			      }
			  }
			bird1(x[2],y[2],j[2],i,u,v,yy8,yy6,xx5,p3);
			calcx(&x[2],&k[2],&j[2],&u,&v);
			y[2]+=k[2];
		}
	   }
       }
	stop1()
       {
	 int i;
		 setcolor(RED);
		 settextstyle(1,HORIZ_DIR,6);
		outtextxy(250,200,"GAME OVER");
		delay(100);
		 for( i=100;i<700;i+=100)
		       {   //sound
		       sound(i);
		       delay(100);
		       nosound();
			}
		     delay(1000);

	       exit(0);
	}
	stag(int i)
	{
	         n=9*i;
	         cc=13*i-7;
                 printf("\n\n\n\n\t\t\t");
                 printf("STAGE %d",i);
                 printf("\n\t\t");
                 printf("YOU MUST SHOT %d BIRDS YO COMPLETE THIS STAGE",cc);
                 printf("\n\t\t");
                 printf("YOU ARE PROVIDE WITH %dBOWS",n);
		delay(3000);

	}