// 
#ifndef MYMOTA_H
#define MYMOTA_H


void cleanmap();		//��ʼ����ͼ 
void win();				//ɨ���ܹ��� 

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
};		// �������
					// �������	
void drow(Hum *hum);	// ���
int move(Hum *player,int n);
						//�ƶ�
void tips(int q);		//��ʾ��� 
void blink();			//��˸Ч�� 
void readmap(Hum *player);//��ȡ��ͼ
void shuchu(Hum *player);//�����ͼ 
#endif
