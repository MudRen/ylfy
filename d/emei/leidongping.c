// Room: /d/emei/leidongping.c ������ �׶�ƺ


inherit ROOM;


void create()
{
	set("short", "�׶�ƺ");
	set("long", @LONG
����һ������Ȼʯ���������ɵ�С���������׵�ǽ�Ϲ���һЩɽˮ
����,���з���һ�ź�ľ�㰸���㰸�Ϲ�Ʒ�뱸���ϲ�̴����֦��������
�ơ�
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"lingyunti",
                "east": __DIR__"basipan1",
	]));

	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));

	setup();
     }
