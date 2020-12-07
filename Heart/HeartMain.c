/*파트설명 : 기본틀은 내가 다해놨다
종우 : 카드 규칙정하기 - HeartPlay.c에 뭐해야하는지 나와있음
한음 : 점수계산하기 - HeartPoint.c에 뭐해야하는지 나와있음
*/

#include<stdio.h>
#include<conio.h>			//getch();쓸라고 넣은 헤더파일. getch();는 getch();앞의 일을 다끝낸 후 아무키나 눌러야 getch();뒤의 일을 진행하게해주는 명령어


extern int card(void);
extern void cardprint(void);
extern void card_3(void);

//여기까지HeartStart.c에서 가져오는 함수들.

extern int player_2(void);
extern int cardslash(int p);

//여기까지HeartPlay.c에서 가져오는 함수들.

extern int pointcompute1(void);
extern int pointcompute2(void);

//여기까지HeartPoint.c에서 가져오는 함수들

int cardnumber[4][13], gamenum = 1;				//카드넘버 : 각 플레이어들의 카드슬롯, gamenum : 게임판수
int point = 0;					//한판에서의 점수계산에 쓰임
int rankP[4];					//우승자찾는데 사용되는 배열
int pointsum[4] = {0, 0, 0, 0};					// 게임전체에서의 점수계산에 쓰임
int point_1 = 0, point_2 = -1;		//으뜸패계산에 쓰이는 변수, point_1은 모든 점수를 한 플레이어가 다먹었을때 0, 아닐때 1이된다.
									//point_2는 점수를 처음먹은 플레이어번호를 저장한다. 하트나 스페이드퀸중 하나라도 누가 내기 전까지는 -1이다.
/* 1p cardnumber[0][0]~cardnumber[0][12], 2p cardnumber[1][0]~cardnumber[0][12], 
3p cardnumber[2][0]~cardnumber[0][12], 4p cardnumber[3][0]~cardnumber[0][12]
좌측플레이어가 2p, 맞은편레이어가 3p, 우측플레이어가 4p가된다.*/
int player;						//카드가져가는 사람을 판별할때 쓰임

int heart = 0;	//하트깨졌는지를 판별하는 변수, 1이되면 하트가 깨진것으로 처리한다.

extern int gamecard[4];			//각 플레이어들이 돌아가면서 하나씩 낸 카드들의 배열.

void main(void)
{
	int i, j;
	int min;		//우승자를판별하는데 사용되는 최소값찾기용 변수
	while(pointsum[0] < 100 && pointsum[1] < 100 && pointsum[2] < 100 && pointsum[3] < 100){

		if(gamenum != 1)
		printf("다음 핸드로 넘어갑니다. %d핸드째.", gamenum);
	card();
	cardprint();

	card_3();
	
	cardprint();
	printf("\n");
	//이 코드는 한핸드중 4명의 플레이어가 카드를 하나씩 내는 부분이 클로버2부터 시작할때한번과 그뒤12번을 따로처리한다.
	printf("%d플레이어가 ♣2를 가졌으므로 먼저 냅니다.\n\n", player_2() + 1);
	player = cardslash(player_2());
	
	printf("\n\n카드를 %d플레이어가 가져갑니다.\n", player + 1);

	pointcompute1();			//점수계산
	pointsum[player] += point;		//계산한점수를 누적점수배열에 추가
	if(point > 0)				//만약 여기서 하트나 스페이드퀸이 나왔을때
	point_2 = player;			//point_2값을 카드가져간플레이어번호로 고쳐준다.
	point = 0;					//계산한점수 초기화


	for(i = 0; i < 12; i++){
	
	cardprint();

	printf("\n");
	player = cardslash(player);

	printf("\n");
	printf("카드를 %d플레이어가 가져갑니다.\n", player + 1);

	pointcompute1();
	pointsum[player] += point;
	if(point_2 == -1 && point > 0)			//point_2가 -1인경우 = 전판까지 한번도 하트나 스페이드퀸을 내지 않았을경우 && 하트나 스페이드퀸을 하나라도냈을경우
		point_2 = player;					//point_2를 플레이어번호로 바꿔준다
	else if(point_2 != player && point > 0)		//이번판에서 점수를 먹은 사람이 전판에 점수먹은사람과 다를경우
		point_1 = 1;
	point = 0;
	}
	pointcompute2();

	

	
	printf(" 1P  2P  3P  4P\n");
	printf("%3d %3d %3d %3d\n\n", pointsum[0], pointsum[1], pointsum[2], pointsum[3]);

	gamenum++;

	
	heart = 0;
	
	}

	min = pointsum[0];			//min변수 = 1p의 누적점수
	rankP[0] = 1;				//점수가 가장 낮은사람을 판별하기 위한 배열로 rankP[4]가 선언되어있다.
								//rankP[i] = 1이면 (i+1)P가 점수가 가장 낮음을 의미 

	for(i = 1; i < 4; i++){			//2p부터 비교해본다
		
		
		if(min == pointsum[i])			//min값과 (i+1)P의 누적점수가 같을경우
			rankP[i]++;					//rankP[4]는 모두 0으로 초기화되어있음으로 여기서는 rankP[i] = 1이랑 같은 의미이다.

		if(min > pointsum[i]){			//min값이 (i+1)P의 누적점수보다 클경우 = min값보다 (i+1)P의 누적점수가 더 작을경우
			printf("%d %d", min, pointsum[i]);
			for(j = 0; j < 4; j++)		//우선 rankP[4]배열을 0으로 초기화해준다.
				rankP[j] = 0;

			min = pointsum[i];			//min값을 (i+1)P의 누적점수로 수정한다.
		rankP[i]++;						//(i+1)P의 누적점수가 가장 낮음을 표시한다./
		}
		
		}

	j = 0;						//위에서 변수j를 쓴걸 재활용하기위해 초기화함
	for(i = 0; i < 4; i++)
		if(rankP[i] == 1){		//여기서의 j는 우승자가 몇명인가를 재는 변수이다.
			player = i;
			j++;
		}

	if(j == 1)					//우승자가 한명일때
		printf("\n우승자는 %d플레이어입니다.", player + 1);

	else{				//우승자가 여러명일때 = 공동우승자가 있을때
		printf("\n공동우승자는 ");
		for(i = 0; i < 4; i++)
			if(rankP[i] == 1)
				printf("%d플레이어, ", i + 1);				//rankP[i] = 1일때 i+1을 다 출력한다.
		printf("%d명 입니다.", j);				//우승자가 몇명인지 보여준다.
	}
		
	getch();
	return;

}