/*���������� Ŭ�ι�2�� ���� �κк��� ���� ���������� ���ԵǴ� �Լ����̴�.
���⼭ ���� ���Ѱ��� �� ī����� ���� ����Ǵ� ��Ģ(ex. Ŭ�ι��� ���� �������� �ڽ��� Ŭ�ι��� �ϳ��� ������������� �װ��� �����Ѵ�.)��
ó���س��� �ʾ����Ƿ� �ߺ��� �߰��� �߰��Һκ��� �߰����ֱ�ٶ���.
�̸� ���� �մ���ϴ� �Լ��� int cardslash(int p); �ϳ����̴�.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

extern int cardnumber[4][13];// ���ο��� �������� �迭&����. ī��ѹ��� �� �÷��̾���� ������ ���Ѵ�.
int gamecard[4];//���÷��̾���� �ϳ��� ���� ī����� ������ ���Ѵ�.
int starter;//Ŭ�ι�2������ �Ǻ����ο� ���ȴ�.

int player_2(void);//Ŭ�ι�2�� ���� �÷��̾ ã�� �Լ�

int cardslash(int p);/*���������� ī�带 ���� ó���ϴ� �Լ�. ���ڰ� �ƹ���Ŀ�� ������ ó�����Ͱ� ��ġ���� ������� ī�带 �������� �÷��̾�� ó������ �ʴ�
�ٴ� �κб����� ������ �Ǿ��ִ�. �ʿ��Ѱ��� �Ƹ��� 
ó�� �� ����� ��ġ�ϴ� ������ ī�尡 �ϳ��� ������� �װ��� ���� �Ѵٴ°�,
��Ʈī�带 ó������ ����� ������ �Ҷ� ������ �Ѹ��̶� ��Ʈ�� ���� �ʾ��� ��� ó������ ���ٴ°� �ΰ����ϰ��̴�.
����� �ι�°�Ϳ� ���ؼ��� ���� �غ� �������Ƿ� ���ϵ��� ����� ������ �ʿ������� �𸥴�.*/

void gamecardprint(int p, int gc);//���� ī�带 ���´°��� ���� ����ϴ� �Լ��̴�.

int player_2(void)//�� �Լ��� ��Ģ���ϴµ� ũ�� �ʿ��� �Լ��� �ƴϹǷ� ���ٸ� �ּ��� �ٿ����� �ʰڴ�.
{
	int i, j;
	for(j = 0; j < 4; j++)
		for(i = 0; i < 13; i++){
			if(cardnumber[j][i] == 1){			//1 = Ŭ�ι�2
				starter = 1;
				return j;
			}
			else
				continue;
		}
}

int cardslash(int p)//cardslash�Լ��� ��� ó������ player�� ��ȣ�� �޾ƾ� �Ѵ�.
{
	//int starter = 1;//Ŭ�ι�2 ������������ ���Ǵº���
	int slot;//�� �÷��̾ �� ī�� ������ �����ϴ� ����
	int player, i, j, k;//player:ī�带 �������� �÷��̾ �����ϴ� ����. �迭�� ����ȭ�Ǿ��־� 1�÷��̾��ǰ�� player = 0�̴�.
	int firstcard;		//ó���� �� ����� ���� ���������� �Ǻ��ϱ� ���� ����ϴ� ����
						//firstcard�� ���������� �Ǻ��ϴ¹���� (�� ī���� ��ȣ-1)/4 = (ó������ ī���� ��ȣ-1)/4�� ���θ� �˾ƺ��°��̴�.
	int OK = 0;			//�ڽ��� ���� ī���� ù��°�� ���� ī��� ������ ��ġ�ϴ� ī�尡 �ִ��� �˾ƺ��� ���ؼ� ����ϴ� ����

	extern int heart;
	
	for(i = 0; i < 4; i++){//ī�带 �׹����Ƿ� �׹��ݺ��Ѵ�.
	
		if(starter == 1){				//���� Ŭ�ι�2���� �����Ұ�� �� if������ ó���Ѵ�.

		for(j = 0; j < 4; j++)			
		for(k = 0; k < 13; k++){
			if(cardnumber[j][k] == 1){		//�÷��̾���� �迭�� �� �����ؼ� �ش�迭�������� 1������ ã�ƺ���.
				cardnumber[j][k] = 0;		//Ŭ�ι�2�� ����ִ� ������ ã�Ƴ��� �� ���Ծ��� ī���ȣ�� 0���� �ٲ۴�. �������� cardprint();�Լ�����
				gamecard[i] = 1;			//ó������ ī��� 1��ī��, Ŭ�ι�2�� �ɰ��̴�.
					starter--;				//�̰��� player_2();�Լ��� �����ϸ� ���صɰ��̴�.

					gamecardprint(p, gamecard[i]);				//p = �÷��̾��ȣ, gamecardprint�Լ��� �ؿ� �ԽõǾ�����
					p++;										//�������� ���°� �غ��ϱ� ���� �÷��̾��ȣ�� �÷��д�./
					if(p > 3)									//�÷��̾��ȣ�� 3����ũ�� 0���� �ʱ�ȭ�Ѵ�.(�迭�� ����ȭ�������Ƿ�)
						p = 0;
					i++;										//������ ī�带 ���� Ƚ���� ó���ϱ����� i�� 1 �÷ȴ�.
					firstcard = 0;				//Ŭ�ι��迭�� �ǹ��ϴ� 0���� �����صд�.
					continue;

			}
		}
		}//����for(i = 0; i < 4; i++) �ȿ��ִ�. �� ���ĺ��ʹ� Ŭ�ι�2�� ��������ī�尡 �ƴҶ��̴�.
		
		if(i != 0)				//ī�峻�� ������ ù��°�� �ƴѰ��
		firstcard = (gamecard[0] - 1) / 13;			//firstcard�� ���������� �����Ѵ�.

		if(p == 0){					//1�÷��̾�(���)�� ���

			if(i != 0)
		for(j = 0; j < 13; j++)
				if((cardnumber[0][j] - 1) / 13 == firstcard && cardnumber[0][j] != 0)
					OK++;			//OK = ó�� �� ī��� ������ ��ġ�ϴ� ī���� ����

			printf("�� ī�忡 �ش��ϴ� ���Թ�ȣ�� �Է��Ͻÿ�:");
		scanf("%d", &slot);

		if(i == 0){				//1p�� ī�带 ó������ ���
			while(cardnumber[0][slot] == 0 || slot > 12 || slot < 0 || cardnumber[p][slot] >= 40 && heart == 0){
			
					j = 0;
				for(k = 0; k < 13; k++)				//��Ʈ�ۿ� ������ �Ǻ��ϱ� ���� �κ�
					if(cardnumber[0][k] >= 40 || cardnumber[0][k] == 0)
						j++;		//j = ��Ʈī���� ����

				if(j == 13 && cardnumber[0][slot] == 0 && slot > 12 && slot < 0){
					heart = 1;		//��Ʈ�� 13���̸� ��Ʈ�� �������� ó���Ѵ�.
					break;
				}
					

				if(cardnumber[0][slot] >= 40 && heart == 0)				//��Ʈ�� �������������¿��� ��Ʈ�� ������/
					printf("��Ʈ�� ������ �ʾҽ��ϴ�.\n");				//�����޽����� ����Ѵ�.
			printf("\n�߸��� ���Թ�ȣ & ī���Դϴ�. �� ī�忡 �ش��ϴ� ���Թ�ȣ�� ����� �Է��Ͻÿ�:");
			scanf("%d", &slot);
	
		}
		}
			
		else			//1p�� ī�带 ó������ ��찡 �ƴ� ���
		while(cardnumber[0][slot] == 0 || slot > 12 || slot < 0 || (cardnumber[0][slot] - 1) / 13 != firstcard){

			if(OK == 0 && cardnumber[0][slot] != 0)		//ī�彽�Կ� ������ ��ġ�ϴ� ī�尡 �ϳ��� �������
				if(slot <= 12 || slot >= 0)
				break;			//�ݺ��� ����
			
			printf("\n�߸��� ���Թ�ȣ & ī���Դϴ�. �� ī�忡 �ش��ϴ� ���Թ�ȣ�� ����� �Է��Ͻÿ�:");
			scanf("%d", &slot);
	
		}


		gamecard[i] = cardnumber[0][slot];			//�̹� Ƚ������ ���� ī�� = �÷��̾ ������ ������ ī��
		cardnumber[0][slot] = 0;				//�� ������ 0���� �ʱ�ȭ
		printf("\n");
		gamecardprint(p, gamecard[i]);			//���� ���´��� �˷��ش�
		}
		
		else{				//��ǻ�Ͱ� ���°��� �����ϴ� �κ�. 2~4p �������Ѵ�.
			srand(time(NULL));					//��ǻ�ʹ� �������� �� ������ �����Ѵ�.

			if(i != 0)
		for(j = 0; j < 13; j++)
				if((cardnumber[p][j] - 1) / 13 == firstcard && cardnumber[p][j] != 0)
					OK++;



			do{
				slot = rand() % 13;				//slot = 0~12�� ���� ���ð��̴�.
			}while(cardnumber[p][slot] == 0);			//��ǻ�Ͱ� �� ������ ī���ȣ�� 0�ϰ�� ��ӹݺ��Ѵ�.
				//���⿡�� ��Ģ�� �°Գ´��� �˻��ϴ°��� �����Ͱ���.

			if(i == 0)

			while(cardnumber[p][slot] == 0 && heart == 0 || cardnumber[p][slot] >= 40 && heart == 0){
			//���⿡�� ��Ģ�� �°Գ´��� �˻��ϴ°� ó���ϴ°� ��������
				j = 0;
				for(k = 0; k < 13; k++)
					if(cardnumber[p][k] >= 40 || cardnumber[p][k] == 0)
						j++;

				if(j == 13 && cardnumber[p][slot] != 0){
					heart = 1;
					break;
				}

			slot = rand() % 13;
			
			
			}
			
		else
		while(cardnumber[p][slot] == 0 || (cardnumber[p][slot] - 1) / 13 != firstcard){
			//���⿡�� ��Ģ�� �°Գ´��� �˻��ϴ°� ó���ϴ°� ��������

			if(OK == 0 && cardnumber[p][slot] != 0)
				break;
			
			slot = rand() % 13;
		}

				gamecard[i] = cardnumber[p][slot];		//�̹� Ƚ���� �� ī���ȣ = p+1�÷��̾ �� ������ ī���ȣ
				cardnumber[p][slot] = 0;				//�� ������ �ʱ�ȭ
				
				gamecardprint(p, gamecard[i]);			//���
		}
		
		
		p++;						//�������� ���°� �غ��ϱ� ���� �÷��̾��ȣ�� �÷��д�.
		if(p > 3)
			p = 0;
		OK = 0;

		}

	//������ʹ� ó���� �� ������� ��ġ���ο� ���� ī�带 ������ ����� �����Ѵ�. ��Ģ�� ��Ű�� �ִ� �κ����� �����ȴ�.

	if(gamecard[0] >= 1 && gamecard[0] <= 13){			//ó���� �� ������Ŭ�ι�
		int max = gamecard[0];							//���⼭���ʹ� ���ڴ� ����ũ�鼭��, ������ ���� ī�带 ã�� �� ī���� ���� = �������� �������/
		player = p % 4;									//ó���ϴ� �κ��̴�.
		
		for(i = 1; i < 4; i++){
			p++;
			if(gamecard[i] >= 1 && gamecard[i] <= 13)
			if(max < gamecard[i]){
				max = gamecard[i];
				player = p % 4;
			}

			}
	}

	else if(gamecard[0] >= 14 && gamecard[0] <= 26){		//ó���� �� ������ �����̵�
		int max = gamecard[0];
		player = p % 4;

		for(i = 1; i < 4; i++){
			p++;
			if(gamecard[i] >= 14 && gamecard[i] <=26) 
				if(max < gamecard[i]){
					max = gamecard[i];
					player = p % 4;
				}
				}
	}

	else if(gamecard[0] >= 27 && gamecard[0] <= 39){		//ó���� �� ������ ���̾�
		int max = gamecard[0];
		player = p % 4;

		for(i = 1; i < 4; i++){
			p++;
			if(gamecard[i] >= 27 && gamecard[i] <= 39)
				if(max < gamecard[i]){
					max = gamecard[i];
					player = p % 4;
				}
		}
	}

	else{				// ������ = ó���� �� ������ ��Ʈ
		int max = gamecard[0];
		player = p % 4;

		for(i = 1; i < 4; i++){
			p++;
			if(gamecard[i] >= 40 && gamecard[i] <= 52)
				if(max < gamecard[i]){
					max = gamecard[i];
					player = p % 4;
				}
				}
	}

	for(i = 1; i < 4; i++)			
		if(gamecard[i] >= 40)				//�� ī����� ��Ʈī�尡 �ϳ��� �־������
			heart = 1;					//��Ʈ�� ����
		

	return player;				//�� �Լ��� ���ϰ��� ī�带 �������� �÷��̾��� ��ȣ�̴�.

}

void gamecardprint(int p, int gc)
{
	printf("%d�÷��̾", p + 1);
		switch(gc)
	{
		case 1:
			printf("��2");
			break;
		case 2:
			printf("��3");
			break;
		case 3:
			printf("��4");
			break;
		case 4:
			printf("��5");
			break;
		case 5:
			printf("��6");
			break;
		case 6:
			printf("��7");
			break;
		case 7:
			printf("��8");
			break;
		case 8:
			printf("��9");
			break;
		case 9:
			printf("��10");
			break;
		case 10:
			printf("��J");
			break;
		case 11:
			printf("��Q");
			break;
		case 12:
			printf("��K");
			break;
		case 13:
			printf("��A");
			break;
		case 14:
			printf("��2");
			break;
		case 15:
			printf("��3");
			break;
		case 16:
			printf("��4");
			break;
		case 17:
			printf("��5");
			break;
		case 18:
			printf("��6");
			break;
		case 19:
			printf("��7");
			break;
		case 20:
			printf("��8");
			break;
		case 21:
			printf("��9");
			break;
		case 22:
			printf("��10");
			break;
		case 23:
			printf("��J");
			break;
		case 24:
			printf("��Q");
			break;
		case 25:
			printf("��K");
			break;
		case 26:
			printf("��A");
			break;
		case 27:
			printf("��2");
			break;
		case 28:
			printf("��3");
			break;
		case 29:
			printf("��4");
			break;
		case 30:
			printf("��5");
			break;
		case 31:
			printf("��6");
			break;
		case 32:
			printf("��7");
			break;
		case 33:
			printf("��8");
			break;
		case 34:
			printf("��9");
			break;
		case 35:
			printf("��10");
			break;
		case 36:
			printf("��J");
			break;
		case 37:
			printf("��Q");
			break;
		case 38:
			printf("��K");
			break;
		case 39:
			printf("��A");
			break;
		case 40:
			printf("��2");
			break;
		case 41:
			printf("��3");
			break;
		case 42:
			printf("��4");
			break;
		case 43:
			printf("��5");
			break;
		case 44:
			printf("��6");
			break;
		case 45:
			printf("��7");
			break;
		case 46:
			printf("��8");
			break;
		case 47:
			printf("��9");
			break;
		case 48:
			printf("��10");
			break;
		case 49:
			printf("��J");
			break;
		case 50:
			printf("��Q");
			break;
		case 51:
			printf("��K");
			break;
		case 52:
			printf("��A");
			break;
		default:
				printf("%3d", gc);
				break;
			}
			printf("�� �������ϴ�.\n");
}