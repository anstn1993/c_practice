#include <stdio.h>
#include "monster_repo.h"

int main(void)
{
	add_monster();
	printf("# monsters: %d\n", g_mob_count);
	return 0;
}