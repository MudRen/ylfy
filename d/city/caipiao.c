// Room: /city/duchang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "����Ͷע����");
	set("long", @LONG
��������̶��ƱͶעվ��һϦ�ɲƣ����ᾡ�����֣���λ����������...��...����������һ�ѣ������ѵã�ʧ��������˵�������������ڵ�������..... 0_0��
LONG
	);
set("no_fight",1);
	set("exits", ([
            "up" : __DIR__"duchang",      	
	]));
set("objects", ([
           "/clone/misc/caipiao_ban" : 1,
        ]));
	setup();
}
