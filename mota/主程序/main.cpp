#include<iostream>
#include<conio.h>

#define CE 1 
#define F 20			//  楼层 
#define Y 20			//  行数 
#define X 20			//  列数 
int map[F+1][Y][X];
int off=1;
int bMAX=50;
int mMAX=10;
int game=0;				// 怪物总数 

#include"MyMota.h"
int main()
	{
		Hum one;
		
		cleanmap();
		readmap(&one);
		win();
		
		map[one.floot][one.y][one.x]=-1;
		int n;
		int check;
		system("mode con cols=41 lines=27");	//列数 行数 
		system("title 魔塔 -BY MAN");
		std::cout<<"\n\n   按任意键开启魔塔冒险！！  "; 
		
		do{

		n=getch();
		
		if (n==97 or n==75)
		n=4;
		else if(n==119 or n==72)
		n=8;
		else if(n==115 or n==80)
		n=2;
		else if(n==100 or n==77)
		n=6;
		else if(n==27)
		break;

#if(CE)
		else if(n==106)
		n=369;
#endif
		else n=0;
		check=move(&one,n);
		n=0;
		drow(&one);
		tips(check); 
		check=1;
		if (one.blood<=0 or game==0)
		off=0;
		
		
	}while (off==1);
	system("Cls");
	if (game>0)
	std::cout<<"\n\n\t\t Game Over\n\n";
	else std::cout<<"\n\n\t\t  You Win!\n\n";
	
	blink();
	if (off == 1)
	shuchu(&one); 
	
	return 0; 
		
}
