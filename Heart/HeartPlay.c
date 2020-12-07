/*본격적으로 클로버2를 내는 부분부터 한판 끝날때까지 쓰게되는 함수들이다.
여기서 내가 안한것은 각 카드들을 낼때 적용되는 규칙(ex. 클로버가 먼저 나왔을때 자신이 클로버를 하나라도 가지고있을경우 그것을 내야한다.)을
처리해놓지 않았으므로 쭉보고 중간에 추가할부분은 추가해주길바란다.
이를 위해 손대야하는 함수는 int cardslash(int p); 하나뿐이다.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

extern int cardnumber[4][13];// 메인에서 가져오는 배열&변수. 카드넘버는 각 플레이어들의 슬롯을 뜻한다.
int gamecard[4];//각플레이어들이 하나씩 내는 카드들의 슬롯을 뜻한다.
int starter;//클로버2에대한 판별여부에 사용된다.

int player_2(void);//클로버2를 가진 플레이어를 찾는 함수

int cardslash(int p);/*본격적으로 카드를 내고 처리하는 함수. 숫자가 아무리커도 문양이 처음낸것과 일치하지 않을경우 카드를 가져가는 플레이어로 처리하지 않는
다는 부분까지는 구현이 되어있다. 필요한것은 아마도 
처음 낸 문양과 일치하는 문양의 카드가 하나라도 있을경우 그것을 내야 한다는것,
하트카드를 처음내는 사람이 내려고 할때 전판중 한명이라도 하트를 내지 않았을 경우 처음낼수 없다는것 두가지일것이다.
참고로 두번째것에 대해서는 많은 준비를 못했으므로 파일들의 대대적 수정이 필요할지도 모른다.*/

void gamecardprint(int p, int gc);//누가 카드를 뭘냈는가에 대해 출력하는 함수이다.

int player_2(void)//이 함수는 규칙정하는데 크게 필요한 함수가 아니므로 별다른 주석을 붙여놓진 않겠다.
{
	int i, j;
	for(j = 0; j < 4; j++)
		for(i = 0; i < 13; i++){
			if(cardnumber[j][i] == 1){			//1 = 클로버2
				starter = 1;
				return j;
			}
			else
				continue;
		}
}

int cardslash(int p)//cardslash함수의 경우 처음내는 player의 번호를 받아야 한다.
{
	//int starter = 1;//클로버2 누가가졌나에 사용되는변수
	int slot;//한 플레이어가 낼 카드 슬롯을 결정하는 변수
	int player, i, j, k;//player:카드를 가져가는 플레이어를 결정하는 변수. 배열에 최적화되어있어 1플레이어의경우 player = 0이다.
	int firstcard;		//처음에 낸 문양과 같은 문양인지를 판별하기 위해 사용하는 변수
						//firstcard가 같은문양을 판별하는방법은 (낸 카드의 번호-1)/4 = (처음나온 카드의 번호-1)/4의 여부를 알아보는것이다.
	int OK = 0;			//자신이 가진 카드중 첫번째로 나온 카드와 문양이 일치하는 카드가 있는지 알아보기 위해서 사용하는 변수

	extern int heart;
	
	for(i = 0; i < 4; i++){//카드를 네번내므로 네번반복한다.
	
		if(starter == 1){				//만약 클로버2부터 시작할경우 이 if문에서 처리한다.

		for(j = 0; j < 4; j++)			
		for(k = 0; k < 13; k++){
			if(cardnumber[j][k] == 1){		//플레이어들의 배열을 다 조사해서 해당배열변수값이 1인지를 찾아본다.
				cardnumber[j][k] = 0;		//클로버2가 들어있는 슬롯을 찾아내면 그 슬롯안의 카드번호를 0으로 바꾼다. 왜인지는 cardprint();함수참조
				gamecard[i] = 1;			//처음내는 카드는 1번카드, 클로버2가 될것이다.
					starter--;				//이것은 player_2();함수를 참조하면 이해될것이다.

					gamecardprint(p, gamecard[i]);				//p = 플레이어번호, gamecardprint함수는 밑에 게시되어있음
					p++;										//다음번에 내는걸 준비하기 위해 플레이어번호를 올려둔다./
					if(p > 3)									//플레이어번호가 3보다크면 0으로 초기화한다.(배열에 최적화되있으므로)
						p = 0;
					i++;										//다음번 카드를 내는 횟수로 처리하기위해 i를 1 올렸다.
					firstcard = 0;				//클로버계열을 의미하는 0으로 설정해둔다.
					continue;

			}
		}
		}//아직for(i = 0; i < 4; i++) 안에있다. 이 이후부터는 클로버2가 먼저내는카드가 아닐때이다.
		
		if(i != 0)				//카드내는 순번이 첫번째가 아닌경우
		firstcard = (gamecard[0] - 1) / 13;			//firstcard를 다음과같이 설정한다.

		if(p == 0){					//1플레이어(사람)일 경우

			if(i != 0)
		for(j = 0; j < 13; j++)
				if((cardnumber[0][j] - 1) / 13 == firstcard && cardnumber[0][j] != 0)
					OK++;			//OK = 처음 낸 카드와 문양이 일치하는 카드의 갯수

			printf("낼 카드에 해당하는 슬롯번호를 입력하시오:");
		scanf("%d", &slot);

		if(i == 0){				//1p가 카드를 처음내는 경우
			while(cardnumber[0][slot] == 0 || slot > 12 || slot < 0 || cardnumber[p][slot] >= 40 && heart == 0){
			
					j = 0;
				for(k = 0; k < 13; k++)				//하트밖에 없는지 판별하기 위한 부분
					if(cardnumber[0][k] >= 40 || cardnumber[0][k] == 0)
						j++;		//j = 하트카드의 갯수

				if(j == 13 && cardnumber[0][slot] == 0 && slot > 12 && slot < 0){
					heart = 1;		//하트가 13개이면 하트를 깬것으로 처리한다.
					break;
				}
					

				if(cardnumber[0][slot] >= 40 && heart == 0)				//하트가 깨지지않은상태에서 하트를 냈을때/
					printf("하트가 깨지지 않았습니다.\n");				//다음메시지를 출력한다.
			printf("\n잘못된 슬롯번호 & 카드입니다. 낼 카드에 해당하는 슬롯번호를 제대로 입력하시오:");
			scanf("%d", &slot);
	
		}
		}
			
		else			//1p가 카드를 처음내는 경우가 아닌 경우
		while(cardnumber[0][slot] == 0 || slot > 12 || slot < 0 || (cardnumber[0][slot] - 1) / 13 != firstcard){

			if(OK == 0 && cardnumber[0][slot] != 0)		//카드슬롯에 문양이 일치하는 카드가 하나도 없을경우
				if(slot <= 12 || slot >= 0)
				break;			//반복을 깬다
			
			printf("\n잘못된 슬롯번호 & 카드입니다. 낼 카드에 해당하는 슬롯번호를 제대로 입력하시오:");
			scanf("%d", &slot);
	
		}


		gamecard[i] = cardnumber[0][slot];			//이번 횟수에서 내는 카드 = 플레이어가 선택한 슬롯의 카드
		cardnumber[0][slot] = 0;				//낸 슬롯은 0으로 초기화
		printf("\n");
		gamecardprint(p, gamecard[i]);			//누가 뭐냈는지 알려준다
		}
		
		else{				//컴퓨터가 내는것을 결정하는 부분. 2~4p 다포함한다.
			srand(time(NULL));					//컴퓨터는 랜덤으로 낼 슬롯을 결정한다.

			if(i != 0)
		for(j = 0; j < 13; j++)
				if((cardnumber[p][j] - 1) / 13 == firstcard && cardnumber[p][j] != 0)
					OK++;



			do{
				slot = rand() % 13;				//slot = 0~12의 값이 나올것이다.
			}while(cardnumber[p][slot] == 0);			//컴퓨터가 낸 슬롯의 카드번호가 0일경우 계속반복한다.
				//여기에서 규칙에 맞게냈는지 검사하는것이 좋을것같다.

			if(i == 0)

			while(cardnumber[p][slot] == 0 && heart == 0 || cardnumber[p][slot] >= 40 && heart == 0){
			//여기에서 규칙에 맞게냈는지 검사하는걸 처리하는게 좋을지도
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
			//여기에서 규칙에 맞게냈는지 검사하는걸 처리하는게 좋을지도

			if(OK == 0 && cardnumber[p][slot] != 0)
				break;
			
			slot = rand() % 13;
		}

				gamecard[i] = cardnumber[p][slot];		//이번 횟수에 낸 카드번호 = p+1플레이어가 낸 슬롯의 카드번호
				cardnumber[p][slot] = 0;				//낸 슬롯은 초기화
				
				gamecardprint(p, gamecard[i]);			//출력
		}
		
		
		p++;						//다음번에 내는걸 준비하기 위해 플레이어번호를 올려둔다.
		if(p > 3)
			p = 0;
		OK = 0;

		}

	//여기부터는 처음에 낸 문양과의 일치여부에 따라 카드를 가져갈 사람을 결정한다. 규칙을 지키고 있는 부분으로 생각된다.

	if(gamecard[0] >= 1 && gamecard[0] <= 13){			//처음에 낸 문양이클로버
		int max = gamecard[0];							//여기서부터는 숫자는 가장크면서도, 문양이 같은 카드를 찾고 그 카드의 주인 = 가져가는 사람으로/
		player = p % 4;									//처리하는 부분이다.
		
		for(i = 1; i < 4; i++){
			p++;
			if(gamecard[i] >= 1 && gamecard[i] <= 13)
			if(max < gamecard[i]){
				max = gamecard[i];
				player = p % 4;
			}

			}
	}

	else if(gamecard[0] >= 14 && gamecard[0] <= 26){		//처음에 낸 문양이 스페이드
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

	else if(gamecard[0] >= 27 && gamecard[0] <= 39){		//처음에 낸 문양이 다이아
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

	else{				// 나머지 = 처음에 낸 문양이 하트
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
		if(gamecard[i] >= 40)				//낸 카드들중 하트카드가 하나라도 있었을경우
			heart = 1;					//하트를 깬다
		

	return player;				//이 함수의 리턴값은 카드를 가져가는 플레이어의 번호이다.

}

void gamecardprint(int p, int gc)
{
	printf("%d플레이어가", p + 1);
		switch(gc)
	{
		case 1:
			printf("♣2");
			break;
		case 2:
			printf("♣3");
			break;
		case 3:
			printf("♣4");
			break;
		case 4:
			printf("♣5");
			break;
		case 5:
			printf("♣6");
			break;
		case 6:
			printf("♣7");
			break;
		case 7:
			printf("♣8");
			break;
		case 8:
			printf("♣9");
			break;
		case 9:
			printf("♣10");
			break;
		case 10:
			printf("♣J");
			break;
		case 11:
			printf("♣Q");
			break;
		case 12:
			printf("♣K");
			break;
		case 13:
			printf("♣A");
			break;
		case 14:
			printf("♠2");
			break;
		case 15:
			printf("♠3");
			break;
		case 16:
			printf("♠4");
			break;
		case 17:
			printf("♠5");
			break;
		case 18:
			printf("♠6");
			break;
		case 19:
			printf("♠7");
			break;
		case 20:
			printf("♠8");
			break;
		case 21:
			printf("♠9");
			break;
		case 22:
			printf("♠10");
			break;
		case 23:
			printf("♠J");
			break;
		case 24:
			printf("♠Q");
			break;
		case 25:
			printf("♠K");
			break;
		case 26:
			printf("♠A");
			break;
		case 27:
			printf("◇2");
			break;
		case 28:
			printf("◇3");
			break;
		case 29:
			printf("◇4");
			break;
		case 30:
			printf("◇5");
			break;
		case 31:
			printf("◇6");
			break;
		case 32:
			printf("◇7");
			break;
		case 33:
			printf("◇8");
			break;
		case 34:
			printf("◇9");
			break;
		case 35:
			printf("◇10");
			break;
		case 36:
			printf("◇J");
			break;
		case 37:
			printf("◇Q");
			break;
		case 38:
			printf("◇K");
			break;
		case 39:
			printf("◇A");
			break;
		case 40:
			printf("♡2");
			break;
		case 41:
			printf("♡3");
			break;
		case 42:
			printf("♡4");
			break;
		case 43:
			printf("♡5");
			break;
		case 44:
			printf("♡6");
			break;
		case 45:
			printf("♡7");
			break;
		case 46:
			printf("♡8");
			break;
		case 47:
			printf("♡9");
			break;
		case 48:
			printf("♡10");
			break;
		case 49:
			printf("♡J");
			break;
		case 50:
			printf("♡Q");
			break;
		case 51:
			printf("♡K");
			break;
		case 52:
			printf("♡A");
			break;
		default:
				printf("%3d", gc);
				break;
			}
			printf("를 내었습니다.\n");
}