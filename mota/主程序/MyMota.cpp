// 此文件保存各种实现
#include"MyMota.h"
#include<iostream>
#include<windows.h>
#include<fstream>


#define F 20			//  楼层 
#define Y 20			//  行数 
#define X 20			//  列数 
extern int map[F+1][Y][X];
extern int off;
extern int bMAX;
extern int mMAX;
extern int game;				// 怪物总数 
extern int map[F+1][Y][X];

void cleanmap()
{
	for (int f=0;f<F+1;f++)
	{
		for (int y=0;y<Y;y++)
		{
			for (int x=0;x<X;x++)
			{
				if (y==0||x==0||y==(Y-1)||x==(X-1))
				map[f][y][x]=0;
				
				else if(y==1&&x==1)
				map[f][y][x]=99;
				
				else if(y==Y-2&&x==X-2)
				map[f][y][x]=-99;
				
				else map[f][y][x]=1;
			}
		}
	}
	
	
	int i;
//第一层 WXR 
	{
		i=0;
		map[i][3][2]=2;
		map[i][2][3]=3; 
		for (int p=1;p<17;p++)
		map[i][Y-5][p+1]=6;
		for (int p=0;p<10;p++)
		map[i][Y-7][p+2]=6;
	}
//第二层 G 
	{for(i=3;i<=8;i++)
			map[1][2][i]=0;
			for(i=3;i<=7;i++)
			map[1][i][2]=0;
			for(i=2;i<=8;i++)
			map[1][7][i]=0;
			for(i=6;i>=4;i--)
			map[1][i][8]=0;//第二层左上角的墙
			for(i=10;i<=17;i++)
			{map[1][i][2]=0;
			map[1][15][i-2]=0;}
			for(i=10;i<=14;i++)
			{map[1][i][15]=0;
			map[1][17][i-7]=0;
			map[1][10][i-7]=0;}
			for(i=8;i<=10;i++)
			{map[1][13][i]=0;
			map[1][i+2][11]=0;
			map[1][10][i+3]=0;}
			map[1][17][8]=0;
			map[1][16][8]=0;
			map[1][11][7]=0;
			map[1][12][7]=0;
			map[1][12][8]=0;
			map[1][13][8]=0;//第二层下面的墙
			for(i=12;i<=16;i++)
			{map[1][3][i]=0;
			map[1][6][i]=0;}
			map[1][4][12]=0;
			map[1][4][16]=0;
			map[1][5][16]=0;//第二层右上角的墙
			map[1][4][4]=2;map[1][5][3]=2;map[1][6][4]=2;
			map[1][5][4]=3;
			map[1][3][6]=11;map[1][4][6]=11;map[1][5][6]=11;map[1][6][6]=11;map[1][5]

[11]=6;map[1][5][12]=6;
			map[1][3][8]=51;map[1][10][14]=51;map[1][14][8]=51;
			map[1][4][14]=11;map[1][4][15]=11;map[1][5][14]=11;map[1][5][15]=11;

	}
	
//第十层
	{
		i=10-1;
		for (int p=2;p<19;p++)
		map[i][Y/2][p]=2;
		map[9][4][3]=987;
 	} 

	{
	map[F][Y/2][X/2]=120;
 	}

}


void win()
{
	for (int f=0;f<F+1;f++)
	{
		for (int y=0;y<Y;y++)
		{
			for (int x=0;x<X;x++)
			{
				if (map[f][y][x]==6 or 0)
				 game++;

			}
		}
	}
}

class Hum;
Hum::Hum()
{
	Mfloot=0;
	floot=0;
	blood=bMAX;
	magic=mMAX;
	leval=1;
	yk=0;
	exp=0;
	x=X-2;
	y=Y-3; 
}

void Hum::beat(int B)
{
	if (Hum::magic>B-1)
	{
		Hum::magic-=B;
		Hum::blood-=B/2;
	}
	else Hum::blood-=B;
	Hum::exp+=B*7;
	if (Hum::exp>100)
	{
		Hum::exp-=100;
		Hum::leval++;
		Hum::blood+=1;
		Hum::magic=mMAX;
	}
	game--;
	
}

void Hum::addblood()
{
	//if (Hum::blood<bMAX)
	Hum::blood++;
}

void Hum::addmagic()
{
	if (Hum::magic<mMAX)
	Hum::magic++;
}

int yidong(Hum *player,int n)
{		
	if (n==8)
	player->y--;
	else if(n==2)
	player->y++;
	else if(n==4)
	player->x--;
	else if(n==6)
	player->x++;
}

void drow(Hum *hum)
{
	map[hum->floot][hum->y][hum->x]=-1;
	int f;

	
	f=(hum->floot);
	system("Cls");


	system("TIME /T"); 

	std::cout<<"\t    当前是第"<<f+1<<"层！\n";
	std::cout<<"\t    B:"<<hum->blood<<"    M:"<<hum->magic
			<<"\n\t    EXP:"<<hum->exp<<"  Lev:"<<hum->leval<<"\n";
	for (int y=0;y<Y;y++)
	{
		for (int x=0;x<X;x++)
		{
			switch(map[f][y][x])
			{
				case -1:
					std::cout<<"(x";
					break;
				case 0:
					std::cout<<"= ";
					break;
				case 1:
					std::cout<<"  ";
					break;
				case 99:
					std::cout<<"U ";
					break;
				case -99:
					std::cout<<" D";
					break;
				case 2:
					std::cout<<"* ";
					break;
				case 3:
					std::cout<<"M ";
					break;
				case 6:
					std::cout<<"X ";
					break;
				case 11:
					std::cout<<"*-";
					break;
				case 51:
					std::cout<<"门";
					break;
				default:
					std::cout<<" ?";
					break;
			}
		}
		std::cout<<"\n";
	}
	
}

int move(Hum *player,int n)
{
	
	int ch;
	map[player->floot][player->y][player->x]=1;
	
	if(n==2)//Down
		ch=map[player->floot][player->y+1][player->x];
	else if(n==8)//Up
		ch=map[player->floot][player->y-1][player->x];
	else if(n==4)//left
		ch=map[player->floot][player->y][player->x-1];	
	else if(n==6)//right
		ch=map[player->floot][player->y][player->x+1];
	else if(n==369)// 跳层 
	{
		char jump=-1;
		char ge;
		int yes=10;
		do{
			std::cout<<"\r你要去哪一层？：";
			jump=getchar();
			ge=getchar();
			if (ge!='\n')
			{
				jump=(jump-'0')*10+ge-'0';
				getchar();
			}
			else 
			jump=jump-'0';
			yes--;
		 	jump=jump-1;
		}while ((jump< 0|| jump>=F)&&yes>0);
		fflush(stdin);
		if (yes==0)
		return 1;
		 if (jump>player->floot)
		{
			player->y=Y-3;player->x=X-2;
			player->floot=jump;
			return 1;
		}
		else if (jump<player->floot)
		{
			player->y=2;player->x=1;
			player->floot=jump;
			return 1; 
		}
		else 
		{
			std::cin.get();
		}
	} 
	else if (n==0)
	return 1;


// 判断前方物品  是否移动 
	{
		if (ch==1)
		{	
			yidong(player,n);
			return 1;	
		}
		
		
		else if(ch==0)
		{
			map[player->floot][player->y][player->x]=-1;
			return 0;
		}
		
		
		else if(ch==2)
		{
			player->addblood();
			yidong(player,n);
			return 2;
		}
		
		
		else if(ch==3)
		{
			player->addmagic();
			yidong(player,n);
			return 3;
		}
		
		
		else if(ch==6)
		{
			player->beat(6);
			yidong(player,n);
			return 6;
		}
		
		else if(ch==11)
		{
			player->yk++;
			yidong(player,n);
			return 11;
		}
		else if(ch==51)
		{
			if (player->yk>0) //黄钥匙 
			{
				player->yk--;
				yidong(player,n);
				return 51;
			}
			else return -51;
		}

		else if (ch==120)
		{
			{						//商人的功能 
				system("CLS");
				std::cout<<"\t\t你找到了一个神奇的地方!\n";
				system("pause");
				std::cout<<"\t\t\t在这里\n";
				system("pause");
				std::cout<<"\t你可以买一些东西！\n";
				system("pause");
				system("CLS");
				system("COLOR 27");
				std::cout<<"\n\n>>>>>>>>>>>>>>-小商店-<<<<<<<<<<<<<<\n";
				std::cout<<"  \t1. 20血买30经验。\n"
							" \t2.  30经验买10血。\n"
							" \t0.  exit!\n"
							"\t输入：";
				int c;
				std::cin>>c;
				system("color 07");
				if (c==1)
				{
					player->blood-=20;
					player->exp+=30;
					return 1;
				}
				else if (c==2 and player->exp>=30)
				{
					player->exp-=30;
					player->blood+=10;
					return 1;
				}
				else if (c==0)
				{
					drow(player);
					return 1;
				}
				else 
				{
					std::cout<<"\n\n\n\n\n\n\n\n\t\t无效！";
					Sleep(1000);
					return 1;
				}
			}
		 } 
		
		else if (ch==987)
		{
			player->floot=F;
			return 1;
		}
		else if(ch==99)
		{
			
			if(player->floot<F-1)
			{
				player->floot++;
				if (player->Mfloot<player->floot)
				player->Mfloot=player->floot; 
				player->y=Y-3;player->x=X-2;
				map[player->floot][player->y][player->x]=-1;
				return 1; 
			}
			else 		
			{
				return 99;
			}
			
			
		}
		
		
		else if(ch==-99)
		{
			if(player->floot>0)
			{
				player->floot--;
				player->y=2;player->x=1;
				map[player->floot][player->y][player->x]=-1;
				return 1;
			}
			else 		
			{
				return -99;
			}
		}  	
	}

}

void tips(int q)
{
	system("color 07");
	if (q==99)
	{std::cout<<"到顶楼了！上不去了";
			system("color 3F");}
	else if (q==-99)
	{std::cout<<"到底楼了！下不去了";
			system("color 3F");}
	else if (q==0)
	std::cout<<"撞到墙了-.-";
	else if (q==2)
	std::cout<<"回了一格血";
	else if (q==3)
	std::cout<<"回了一格蓝";
	else if (q==6)
	{std::cout<<"你打了一个X怪物";
			system("color CE");}
	else if(q==11)
	std::cout<<"你获得了一把黄钥匙！";
	else if (q==51)
	std::cout<<"你开了一扇黄色门";
	else if (q==-51)
	std::cout<<"你没有黄钥匙了!-!";
	else if (q==1); 
	else std::cout<<"联系我!!"; 


}
void blink() //闪烁效果 
{
	
	Sleep(1000);
	for (int i=0;i<40;i++)
	{
		if (i%2==0)
		system("color 09");
		else system("color 0F");
		Sleep (80);
	}
	system("color 0F");
}


void readmap(Hum *player)
{
	std::ifstream ma;
	int f;
	int x;
	int y;
	int Da;
	int CH;
	int cj=0;
	ma.open("map");
	if (ma);
	else 
	{
		std::ofstream md;
		md.open("map");
		md<<"0"<<" "<<"-1"; 
		ma.open("map");
	}
	

	ma>>CH;
	ma>>f;
			while (f!=-1)
			{
				for (x=0;x<=20;x++)
				{
					for (y=0;y<20;y++)
					{
						ma>>Da;
						if (Da==0);
						else if(Da==100)
						{	cj=-1;	
							break;
							
						}
						else
						map[f][x][y]=Da;
					}
					if (cj==-1)
					break;
				}
				ma>>f;
				cj=0;
			}
		if (CH==1)
		ma>>player->blood>>
		player->exp>>
		player->floot>>
		player->leval>>
		player->magic>>
		player->x>>
		player->y>>
		player->yk;
			ma.close();
}

void shuchu(Hum *player)
{
	std::ofstream ma("map");
	ma<<"1 ";
	
	for(int i=0;i<player->Mfloot;i++)
	{
		ma<<i<<"\n"; 
		for(int x=0;x<20;x++)
		{
			for(int y=0;y<20;y++)
			ma<<map[i][x][y]<<" ";
			ma<<"\n";
		}
		ma<<"\n"<<100<<"\n";
	}
	ma<<"-1 ";
	ma<<player->blood<<" "<<
		player->exp<<" "<<
		player->floot<<" "<<
		player->leval<<" "<<
		player->magic<<" "<<
		player->x<<" "<<
		player->y<<" "<<
		player->yk<<" ";
		
	std::cout<<"保存进度成功!\n";
	system("pause");
	ma.close();
}
