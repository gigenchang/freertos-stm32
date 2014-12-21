#ifndef DrinkItem_H
#define DrinkItem_H

typedef enum {
	BLACK_TEA,
	GREEN_TEA,
	QING_TEA,
	OOLONG_TEA
} Tea;

typedef struct {
	Tea tea;
	int tea_volume;
	int ice;
	int sugar;
} DrinkItem;


#endif
