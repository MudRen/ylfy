#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","�ؾ���");
         set ("long",@long
������������ɽׯ�Ĳؾ���, �����书���������, ��������,���� "����
��" �Ĳ�����ٵС� ��������ȫ��һ���Ÿߴ����ܡ�
long);
	set("no_fight", 1);
	set("exits",([
	       "down" : __DIR__"yunjinlou",
	]));
        setup();
        replace_program(ROOM);
}
