// 
#ifndef MYMOTA_H
#define MYMOTA_H


void cleanmap();		//初始化地图 
void win();				//扫描总怪数 

class Hum
{
	public:
		Hum();	

		
		void addblood();
		void addmagic();
		void beat(int B); 
		int leval;
		int y,x; 
		int floot;
		int Mfloot;
		int blood;
		int yk;
		int magic;
		int exp;
};		// 创建玩家
					// 创建玩家	
void drow(Hum *hum);	// 输出
int move(Hum *player,int n);
						//移动
void tips(int q);		//提示输出 
void blink();			//闪烁效果 
void readmap(Hum *player);//读取地图
void shuchu(Hum *player);//保存地图 
#endif
