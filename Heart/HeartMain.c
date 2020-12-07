/*��Ʈ���� : �⺻Ʋ�� ���� ���س���
���� : ī�� ��Ģ���ϱ� - HeartPlay.c�� ���ؾ��ϴ��� ��������
���� : ��������ϱ� - HeartPoint.c�� ���ؾ��ϴ��� ��������
*/

#include<stdio.h>
#include<conio.h>			//getch();����� ���� �������. getch();�� getch();���� ���� �ٳ��� �� �ƹ�Ű�� ������ getch();���� ���� �����ϰ����ִ� ��ɾ�


extern int card(void);
extern void cardprint(void);
extern void card_3(void);

//�������HeartStart.c���� �������� �Լ���.

extern int player_2(void);
extern int cardslash(int p);

//�������HeartPlay.c���� �������� �Լ���.

extern int pointcompute1(void);
extern int pointcompute2(void);

//�������HeartPoint.c���� �������� �Լ���

int cardnumber[4][13], gamenum = 1;				//ī��ѹ� : �� �÷��̾���� ī�彽��, gamenum : �����Ǽ�
int point = 0;					//���ǿ����� ������꿡 ����
int rankP[4];					//�����ã�µ� ���Ǵ� �迭
int pointsum[4] = {0, 0, 0, 0};					// ������ü������ ������꿡 ����
int point_1 = 0, point_2 = -1;		//�����а�꿡 ���̴� ����, point_1�� ��� ������ �� �÷��̾ �ٸԾ����� 0, �ƴҶ� 1�̵ȴ�.
									//point_2�� ������ ó������ �÷��̾��ȣ�� �����Ѵ�. ��Ʈ�� �����̵����� �ϳ��� ���� ���� �������� -1�̴�.
/* 1p cardnumber[0][0]~cardnumber[0][12], 2p cardnumber[1][0]~cardnumber[0][12], 
3p cardnumber[2][0]~cardnumber[0][12], 4p cardnumber[3][0]~cardnumber[0][12]
�����÷��̾ 2p, �������̾ 3p, �����÷��̾ 4p���ȴ�.*/
int player;						//ī�尡������ ����� �Ǻ��Ҷ� ����

int heart = 0;	//��Ʈ���������� �Ǻ��ϴ� ����, 1�̵Ǹ� ��Ʈ�� ���������� ó���Ѵ�.

extern int gamecard[4];			//�� �÷��̾���� ���ư��鼭 �ϳ��� �� ī����� �迭.

void main(void)
{
	int i, j;
	int min;		//����ڸ��Ǻ��ϴµ� ���Ǵ� �ּҰ�ã��� ����
	while(pointsum[0] < 100 && pointsum[1] < 100 && pointsum[2] < 100 && pointsum[3] < 100){

		if(gamenum != 1)
		printf("���� �ڵ�� �Ѿ�ϴ�. %d�ڵ�°.", gamenum);
	card();
	cardprint();

	card_3();
	
	cardprint();
	printf("\n");
	//�� �ڵ�� ���ڵ��� 4���� �÷��̾ ī�带 �ϳ��� ���� �κ��� Ŭ�ι�2���� �����Ҷ��ѹ��� �׵�12���� ����ó���Ѵ�.
	printf("%d�÷��̾ ��2�� �������Ƿ� ���� ���ϴ�.\n\n", player_2() + 1);
	player = cardslash(player_2());
	
	printf("\n\nī�带 %d�÷��̾ �������ϴ�.\n", player + 1);

	pointcompute1();			//�������
	pointsum[player] += point;		//����������� ���������迭�� �߰�
	if(point > 0)				//���� ���⼭ ��Ʈ�� �����̵����� ��������
	point_2 = player;			//point_2���� ī�尡�����÷��̾��ȣ�� �����ش�.
	point = 0;					//��������� �ʱ�ȭ


	for(i = 0; i < 12; i++){
	
	cardprint();

	printf("\n");
	player = cardslash(player);

	printf("\n");
	printf("ī�带 %d�÷��̾ �������ϴ�.\n", player + 1);

	pointcompute1();
	pointsum[player] += point;
	if(point_2 == -1 && point > 0)			//point_2�� -1�ΰ�� = ���Ǳ��� �ѹ��� ��Ʈ�� �����̵����� ���� �ʾ������ && ��Ʈ�� �����̵����� �ϳ��󵵳������
		point_2 = player;					//point_2�� �÷��̾��ȣ�� �ٲ��ش�
	else if(point_2 != player && point > 0)		//�̹��ǿ��� ������ ���� ����� ���ǿ� ������������� �ٸ����
		point_1 = 1;
	point = 0;
	}
	pointcompute2();

	

	
	printf(" 1P  2P  3P  4P\n");
	printf("%3d %3d %3d %3d\n\n", pointsum[0], pointsum[1], pointsum[2], pointsum[3]);

	gamenum++;

	
	heart = 0;
	
	}

	min = pointsum[0];			//min���� = 1p�� ��������
	rankP[0] = 1;				//������ ���� ��������� �Ǻ��ϱ� ���� �迭�� rankP[4]�� ����Ǿ��ִ�.
								//rankP[i] = 1�̸� (i+1)P�� ������ ���� ������ �ǹ� 

	for(i = 1; i < 4; i++){			//2p���� ���غ���
		
		
		if(min == pointsum[i])			//min���� (i+1)P�� ���������� �������
			rankP[i]++;					//rankP[4]�� ��� 0���� �ʱ�ȭ�Ǿ��������� ���⼭�� rankP[i] = 1�̶� ���� �ǹ��̴�.

		if(min > pointsum[i]){			//min���� (i+1)P�� ������������ Ŭ��� = min������ (i+1)P�� ���������� �� �������
			printf("%d %d", min, pointsum[i]);
			for(j = 0; j < 4; j++)		//�켱 rankP[4]�迭�� 0���� �ʱ�ȭ���ش�.
				rankP[j] = 0;

			min = pointsum[i];			//min���� (i+1)P�� ���������� �����Ѵ�.
		rankP[i]++;						//(i+1)P�� ���������� ���� ������ ǥ���Ѵ�./
		}
		
		}

	j = 0;						//������ ����j�� ���� ��Ȱ���ϱ����� �ʱ�ȭ��
	for(i = 0; i < 4; i++)
		if(rankP[i] == 1){		//���⼭�� j�� ����ڰ� ����ΰ��� ��� �����̴�.
			player = i;
			j++;
		}

	if(j == 1)					//����ڰ� �Ѹ��϶�
		printf("\n����ڴ� %d�÷��̾��Դϴ�.", player + 1);

	else{				//����ڰ� �������϶� = ��������ڰ� ������
		printf("\n��������ڴ� ");
		for(i = 0; i < 4; i++)
			if(rankP[i] == 1)
				printf("%d�÷��̾�, ", i + 1);				//rankP[i] = 1�϶� i+1�� �� ����Ѵ�.
		printf("%d�� �Դϴ�.", j);				//����ڰ� ������� �����ش�.
	}
		
	getch();
	return;

}