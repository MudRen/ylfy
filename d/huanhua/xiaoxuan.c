// xiaoxuan.c �ƺ�С��
// by chenww

inherit ROOM;

void create()
{
        set("short", "�ƺ�С��");
        set("long", @LONG
����ݸ���ȴ��ˬ������̨���������й�һ������С������һ�Ű�ľ
��齡�����֮�࣬ɫɫ�ྻ����ɨ�õ������˺����������л����������У�
ʮ�ַ�ï�������ʱ��л���˽ڳ�����
LONG
        );
        set("exits", ([
                "south" : __DIR__"tingyulou",
             "west" : __DIR__"chashi",
		"east" : __DIR__"jianshi" ,
        ]));
        set("objects", ([
                __DIR__"npc/xiaomeng" : 1,
                       ]));
        set("outdoors", "huanhua" );

        set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
