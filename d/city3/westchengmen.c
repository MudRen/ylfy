// Room: /chengdu/westchengmen.c
// oooc: 1998/06/20 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "������");
	set("long", @LONG
�����ǳɶ��ǵ����ţ��ߴ�ĳ�ǽ����������ɫ�Ĵ��֡���
����������������С�֡����š������ſ�����վ��һ�ӹٱ�����
�����¼�������������ӣ��ſ��������������˺��ֺ̼ܶ࣬ż
���߹����������Ľ������ܡ����ſ����Ÿ�ʾ(gaoshi)��������
���ǳ��ǵ�·���򶫾������ֵ�������ˡ�
LONG
	);
	set("exits", ([
            "west" : __DIR__"guandao1",
            "east" : __DIR__"xijie",
		   // "south" : __DIR__"work1",
		   // "north"  : __DIR__"work5",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("item_desc",([
             "gaoshi" : "׽�òɻ�����ﲮ�⣬�����ͽ�һ��������ʬ�ͽ���ʮ����\n\n\n�ɶ�Ѳ��������ҫ\n",
        ]));


        set("outdoors", "chengdu");
	setup();
}

