//item.c
//��Ʒ���ߴ浵

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

void setup()
{
	seteuid(getuid());
}

int query_autoload()
{
	//����Ҫ�浵��Ʒ���
	if ( this_object()->query("owner_id") )
		return 0;
	else
		return 1;
}