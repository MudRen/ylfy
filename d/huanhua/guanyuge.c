// guanyuge.c �����
// by chenww

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
佻�Ϫ��������㼯��̶��ˮ�������������˳������ЩС���������
��ȥ�����������������Ϫˮ�л������ζ���
LONG
        );
        set("exits", ([
             "south" : __DIR__"huayuan",
          "west" : __DIR__"dating",
             "north" : __DIR__"tingyulou" ,
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
               __DIR__"npc/xiaoxueyu" : 1,
                       ]));
        set("outdoors", "huanhua" );
        
        set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	setup();

        replace_program(ROOM);
}
