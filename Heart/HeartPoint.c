/*점수계산
필요한 함수:4명의 플레이어가 낸 카드를 조건문으로 검사하여 각 플레이어의 점수를 담당하는 배열(point[4])에 각각 점수를 추가하는 함수
특정 플레이어가 하트와 스페이드퀸을 다가졌을때 해당 판에서의 특정플레이어가 획득한점수를 0으로하고 나머지플레이어의 점수가 26점획득된것으로 처리하는함수

gamecard[4]에서 gamecard[0]~gamecard[3]까지의 함수는 각 플레이어들이 차례로 낸 카드의 번호를 가지고있다.
예를들어 2, 3, 4, 1플레이어 순서대로 ♠7, ♠Q, ◇3, ♡6을 냈을때 gamecard[0] = 19, gamecard[1] = 24, gamecard[2] = 28, gamecard[3] = 44인것이다.
여기서 각 플레이어가 낸 순서는 중요치 않다. 점수계산에서 주목해야 할 것은
♠7, ♠Q, ◇3, ♡6을 냈을때 gamecard[0] = 19, gamecard[1] = 24, gamecard[2] = 28, gamecard[3] = 44 이부분이다.

위에서 나온예를 볼때 각 카드중 ♡6이 들어있으므로 1점을 추가해야한다.

point[4]는 각 플레이어의 점수를 의미하는 배열이다. 1플레이어의 점수는 point[0]에, 2플레이어의 점수는 point[1]에, 3플레이어의 점수는 point[2]에,
4플레이어의 점수는 point[3]에 해당한다. 여기서 우리가 해야할 것은 카드를 먹게되는 사람의 배열에 대해 ♡6의 점수를 추가하는것이다.
점수를 추가할때 ♡6이라고 일일이if(gamecard[3] == 44)와같은 스나이핑 개지랄을 하지 않기를 바란다.

하트에 해당하는 카드번호는 다음과 같다. 40~52, 스페이드퀸의 카드번호는 24이다.
우선 반복문으로 4회를 돌리도록 해야 할것이다. 돌리면서 각횟수에따른gamecard[i]가 40~52인지, 24인지확인하고 그에따라 point[player]에 적정 점수를 추가해야한다.
gamecard[i]에서 i가 0부터 3까지라는데에 유의하라.힌트를주자면
for(i = 0; i < 4; i++)를 쓴다음에 for문처리과정중에 gamecard[i]를 쓰면 gamecard[0~3]에 대해 각각 하나씩 처리할수 있을것이다.
하트의경우 조건문에 조건이 두개가들어갈것이고 스페이드퀸의 경우 조건이 하나들어갈것이다.
내예상으로볼때 for문안에 조건문이 두개정도 들어갈것이라 본다.

카드를 먹게되는 사람의 함수는 다음과 같다 : point[player]
player함수는 카드를 먹게되는 사람의 플레이어번호이다. 배열사용에 맞춰진 함수이므로 1p가 카드를 먹게될때 point[player] = point[0]이된다고 보면 된다.
point[4]는 모두 0으로 초기화되어있으므로 여기에다 각 카드에 해당하는 점수를 추가하기만 하면 된다.
예를들어 카드번호가 하트문양에 해당하는 조건문에서는 point[player]++;를하면 카드를 먹는 플레이어의 point[]함수에 1이 추가된다.
이것은 해당 플레이어의 점수가 1점 추가된것이라 보면 되겠다.
스페이드퀸의 경우 point[player] += 13;으로 처리하면 될것이다.

위에 언급한 부분을 다만들었으면 특정플레이어가 하트와 스페이드퀸을 다가졌을때 자신이 그판에서 획득한 점수는 0점으로, 나머지플레이어에겐 26점을 부여하는 부분을
만들어야 할것이다. 하트와 스페이드퀸을 다모았다고 함은 하트의 13장과 스페이드퀸한장을 다가진 점수, 해당 판에서 26점을 획득한것과 동일하다고 할수있다.

이 함수를 위해서 pointsum[4]배열을 준비해두었다. point[4]의 경우 한판이 끝나면 배열의 값들이 0, 0, 0, 0으로 초기화될것이나 pointsum[4]함수의 경우
그간 게임에서 모인 점수를 다 합한 값을 가지고있다.
첫번째판이 끝나고 1p가 2점을 얻었으며 두번째판이 끝나고1p가 5점을 얻었을때 두번째판이 끝났을때의 point[0] = 5, pointsum[0] = 7로 처리될것이다.
그렇다. point[player]함수의 경우 그 판에서의 점수만 처리하고, pointsum[player]의 경우 총점을 처리한다.
내가 이 두함수를 준비한 이유는 point[4]의 값중에 26인 값이 있는가 찾아보고 있을시에는 pointsum[player]에서 각플레이어에 대해 26점으로 짖랄하는 처리를
하라는 것이다.

필요한 함수중 외부에서 끌어와야 할것은 이정도일것이다. void pointcompute1(void)함수에는 각 카드에 해당하는 점수를,
void pointcompute2(void)함수에는 하트전부와 스페이드퀸이 한사람에게 모였을때의 처리를 하도록 하라.
모르는게 있으면 바로바로 질문하도록 한다.

main함수에서 pointcompute함수들이 어떻게쓰이는지 보는것도 도움이 되긴될것이다. 아마도
*/
extern int player;
extern int point;
extern int pointsum[4];
extern int gamecard[4];

void pointcompute1(void)
{
	int i;
	for (i=0; i<4; i++)
	if (gamecard[i] >= 40)
		//point++;
		point ++;
	else if (gamecard[i] == 24)
		point += 13;
}

void pointcompute2(void)
{
	extern int point_1, point_2;
	int i;
	if (point_1 == 0){
		for(i = 0; i < 4; i++)
			if(point_2 == i)
				pointsum[i] -= 26;
			else
			pointsum[i] += 26;
	}
}