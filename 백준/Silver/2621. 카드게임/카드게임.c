#include <stdio.h>
#define true 1
#define false 0

typedef struct {
	int colorresult;
	int numresult[4];
}Result;

typedef struct {
	char color;
	int num;
}Card;

typedef struct {
	int pairindex[2];
	int tripleindex;
	Result result;
}Cardresult;

void init(Card * card) {
	for (int j = 1; j < 5; j++) {
		int i = 0;
		while (card[j].num > card[i].num) {
			i++;
		}
		int temp = card[j].num;
		for (int k = 0; k <= j - i - 1; k++) {
			card[j - k].num = card[j - k - 1].num;
		}
		card[i].num = temp;
	}
}

void SearchColor(Card * card, Cardresult * cardresult) {
	cardresult->result.colorresult = false;
	for (int i = 1; card[0].color == card[i].color && i < 5; i++) {
		if (i == 4) cardresult->result.colorresult = true;
	}
}

void SearchNumber(Card * card, Cardresult * cardresult) {
	int j = 0, i = 0, pair = 0, triple = false, fourcard = false, straight = false, samenum;
	while (j != 5) {
		samenum = 0;
		for (; i < 5; i++) {
			if (card[j].num == card[i].num) {
				samenum++;
			}
			else break;
		}
		if (samenum == 2) {
			cardresult->pairindex[pair] = j;
			pair++;
		}
		else if (samenum == 3) {
			cardresult->tripleindex = j;
			cardresult->result.numresult[1] = true;
			triple = true;
		}
		else if (samenum == 4) {
			cardresult->result.numresult[2] = true;
			fourcard = true;
		}
		j = i;
	}
	if (pair == 0 && triple == 0 && fourcard == 0) {
		for (int k = 0; card[k].num + 1 == card[k + 1].num && k < 4; k++) {
			if (k == 3) cardresult->result.numresult[3] = true;
		}
	}
	cardresult->result.numresult[0] = pair;
}

int main(void) {
	Card card[5];
	Cardresult cardresult;
	for (int i = 0; i < 5; i++) scanf(" %c %d", &card[i].color, &card[i].num);
	init(card);
	SearchNumber(card, &cardresult);
	SearchColor(card, &cardresult);
	if (cardresult.result.colorresult == true && cardresult.result.numresult[3] == true) printf("%d", card[4].num + 900);
	else if (cardresult.result.numresult[2] == true) printf("%d", card[2].num + 800);
	else if (cardresult.result.numresult[1] == true && cardresult.result.numresult[0] == true) printf("%d", card[cardresult.tripleindex].num * 10 + card[cardresult.pairindex[0]].num + 700);
	else if (cardresult.result.colorresult == true) printf("%d", card[4].num + 600);
	else if (cardresult.result.numresult[3] == true) printf("%d", card[4].num + 500);
	else if (cardresult.result.numresult[1] == true) printf("%d", card[cardresult.tripleindex].num + 400);
	else if (cardresult.result.numresult[0] == 2) printf("%d", card[cardresult.pairindex[1]].num * 10 + card[cardresult.pairindex[0]].num + 300);
	else if (cardresult.result.numresult[0] == 1) printf("%d", card[cardresult.pairindex[0]].num + 200);
	else printf("%d", card[4].num + 100);
	return 0;
}
