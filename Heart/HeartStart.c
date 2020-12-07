//이부분에서 크게 신경쓸건 나밖에 없을듯

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

int cardcmp(int cardnum);
int card(void);
void cardprint(void);
void card_3(void);


static int cmp[52], fcmp, b, i;
extern int cardnumber[4][13];

int card(void)
{
	srand(time(NULL));

	for(b = 0; b < 52; b++)
		cmp[b] = 0;
	
	for(i = 0; i < 4; i++)
	for(b = 0; b < 13; b++){
		cardnumber[i][b] = rand() % 52 + 1;
		fcmp = cardnumber[i][b];
		cmp[fcmp - 1]++;
		cardnumber[i][b] = cardcmp(cardnumber[i][b]);
	}



	
	return 0;
}

int cardcmp(int cardnum)
{

	if(cmp[fcmp - 1] == 2){
		cmp[fcmp - 1]--;
		cardnum = rand() % 52 + 1;
		fcmp = cardnum;
		cmp[fcmp - 1]++;
		cardcmp(cardnum);
	}
	else
		return cardnum;
}

void cardprint()		//이 함수의 경우 한 슬롯의 카드번호를 0으로만들면 해당 슬롯이 출력되지 않는다.
{
	extern int cardnumber[4][13];
	printf("당신이 가지고있는 카드 목록 ※ 슬롯번호 - 카드패 입니다.\n");
	for(i = 0; i < 13; i++){
		if(i == 6 || i == 12)
			printf("\n");
		switch(cardnumber[0][i])
	{
		case 1:
			printf("%2d - ♣2   ", i);
			break;
		case 2:
			printf("%2d - ♣3   ", i);
			break;
		case 3:
			printf("%2d - ♣4   ", i);
			break;
		case 4:
			printf("%2d - ♣5   ", i);
			break;
		case 5:
			printf("%2d - ♣6   ", i);
			break;
		case 6:
			printf("%2d - ♣7   ", i);
			break;
		case 7:
			printf("%2d - ♣8   ", i);
			break;
		case 8:
			printf("%2d - ♣9   ", i);
			break;
		case 9:
			printf("%2d - ♣10  ", i);
			break;
		case 10:
			printf("%2d - ♣J   ", i);
			break;
		case 11:
			printf("%2d - ♣Q   ", i);
			break;
		case 12:
			printf("%2d - ♣K   ", i);
			break;
		case 13:
			printf("%2d - ♣A   ", i);
			break;
		case 14:
			printf("%2d - ♠2   ", i);
			break;
		case 15:
			printf("%2d - ♠3   ", i);
			break;
		case 16:
			printf("%2d - ♠4   ", i);
			break;
		case 17:
			printf("%2d - ♠5   ", i);
			break;
		case 18:
			printf("%2d - ♠6   ", i);
			break;
		case 19:
			printf("%2d - ♠7   ", i);
			break;
		case 20:
			printf("%2d - ♠8   ", i);
			break;
		case 21:
			printf("%2d - ♠9   ", i);
			break;
		case 22:
			printf("%2d - ♠10  ", i);
			break;
		case 23:
			printf("%2d - ♠J   ", i);
			break;
		case 24:
			printf("%2d - ♠Q   ", i);
			break;
		case 25:
			printf("%2d - ♠K   ", i);
			break;
		case 26:
			printf("%2d - ♠A   ", i);
			break;
		case 27:
			printf("%2d - ◇2   ", i);
			break;
		case 28:
			printf("%2d - ◇3   ", i);
			break;
		case 29:
			printf("%2d - ◇4   ", i);
			break;
		case 30:
			printf("%2d - ◇5   ", i);
			break;
		case 31:
			printf("%2d - ◇6   ", i);
			break;
		case 32:
			printf("%2d - ◇7   ", i);
			break;
		case 33:
			printf("%2d - ◇8   ", i);
			break;
		case 34:
			printf("%2d - ◇9   ", i);
			break;
		case 35:
			printf("%2d - ◇10  ", i);
			break;
		case 36:
			printf("%2d - ◇J   ", i);
			break;
		case 37:
			printf("%2d - ◇Q   ", i);
			break;
		case 38:
			printf("%2d - ◇K   ", i);
			break;
		case 39:
			printf("%2d - ◇A   ", i);
			break;
		case 40:
			printf("%2d - ♡2   ", i);
			break;
		case 41:
			printf("%2d - ♡3   ", i);
			break;
		case 42:
			printf("%2d - ♡4   ", i);
			break;
		case 43:
			printf("%2d - ♡5   ", i);
			break;
		case 44:
			printf("%2d - ♡6   ", i);
			break;
		case 45:
			printf("%2d - ♡7   ", i);
			break;
		case 46:
			printf("%2d - ♡8   ", i);
			break;
		case 47:
			printf("%2d - ♡9   ", i);
			break;
		case 48:
			printf("%2d - ♡10  ", i);
			break;
		case 49:
			printf("%2d - ♡J   ", i);
			break;
		case 50:
			printf("%2d - ♡Q   ", i);
			break;
		case 51:
			printf("%2d - ♡K   ", i);
			break;
		case 52:
			printf("%2d - ♡A   ", i);
			break;
			}
			}
			printf("\n");
}

void card_3(void)
{
	int cardchange[12], ran[9], cnum1, cnum2, cnum3, cmp[13]/*, c1, c2, c3 = 1*/;
	extern int gamenum;
	
	srand(time(NULL));

	if(gamenum % 4 == 0){
		printf("카드를 교환하지 않습니다.\n");
		return;
	}
	else
	{
		switch(gamenum % 4)
		{
		case 1:
			printf("왼쪽으로 세장교환\n");
			break;
		case 2:
			printf("오른쪽으로 세장교환\n");
			break;
		case 3:
			printf("맞은편으로 세장교환\n");
			break;
		}

		printf("바꿀카드 3장을 선택하십시오. 선택방법은 슬롯번호 세개를 입력하면 됩니다.");
		scanf("%d %d %d", &cnum1, &cnum2, &cnum3);

		while(cnum1 > 12 || cnum2 > 12 ||  cnum3 > 12 || cnum1 == cnum2 || cnum2 == cnum3 || cnum1 == cnum3 || cnum1 < 0 || cnum2 < 0 || cnum3 < 0){
			printf("잘못된 슬롯번호입니다. 선택방법은 슬롯번호(카드문양 앞번호)를 입력하면 됩니다.");
			scanf("%d %d %d", &cnum1, &cnum2, &cnum3);
		}

		for(i = 0; i < 9; i++){
			ran[i] = rand() % 13;//ran[1~3] 2플레이어의 3장 슬롯번호, ran[4~6] 3플레이어의 3장 슬롯번호, ran[7~9] 4플레이어의 3장 슬롯번호
			
			if(i % 3 == 0)
				for(b = 0; b < 13; b++)
				cmp[b] = 0;
			cmp[ran[i]]++;
			if(cmp[ran[i]] == 2)
			{
				cmp[ran[i]]--;
				i--;
			}
		}
			
				

		cardchange[0] = cardnumber[0][cnum1];
		cardchange[1] = cardnumber[0][cnum2];
		cardchange[2] = cardnumber[0][cnum3];

		for(b = 1; b < 4; b++)
		for(i = 0; i < 3; i++)
			cardchange[b * 3 + i] = cardnumber[b][ran[(b - 1) * 3 + i]];

		//cardchange[0~2] 1플레이어의 3장, [3~5] 2플레이어의 3장, [6~8] 3플레이어의 3장, [9~11] 4플레이어의 3장

		if(gamenum % 4 == 1){

			cardnumber[0][cnum1] = cardchange[9];
			cardnumber[0][cnum2] = cardchange[10];
			cardnumber[0][cnum3] = cardchange[11];
			
			for(b = 1; b < 4; b++)
			for(i = 0; i < 3; i++)
				cardnumber[b][ran[(b - 1) * 3 + i]] = cardchange[(b - 1) * 3 + i];

			/*c2 = cardchange[0];

			for(i = 3; i  != 17; i += 3){
				if(i > 14){
					i = c3;
					c3++;
					c2 = cardchange[i];
					continue;
				}
				c1 = cardchange[i % 12];
				cardchange[i % 12] = c2;
				c2 = c1;
			}*/
		}
		
		else if(gamenum % 4 == 2){

			cardnumber[0][cnum1] = cardchange[3];
			cardnumber[0][cnum2] = cardchange[4];
			cardnumber[0][cnum3] = cardchange[5];
			
			for(b = 1; b < 4; b++)
			for(i = 0; i < 3; i++)
				cardnumber[b][ran[(b - 1) * 3 + i]] = cardchange[((b + 1) * 3 + i) % 12];
		}
		
		else if(gamenum % 4 == 3){

		cardnumber[0][cnum1] = cardchange[6];
		cardnumber[0][cnum2] = cardchange[7];
		cardnumber[0][cnum3] = cardchange[8];
		
		for(b = 1; b < 4; b++)
		for(i = 0; i < 3; i++)
			cardnumber[b][ran[(b - 1) * 3 + i]] = cardchange[((b + 2) * 3 + i) % 12];
		}


	}
}