//Room:/d/lingshedao/shangang.c
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�ոյ���ɽ��.һ�󺣷�㴵������.����û����ľ������,
��Ŀ����,����һɫ������,�����Ŀ�����.
LONG);
        set("exits", ([
                "southdown"    : __DIR__"lsroad2", 
        ]));
set("objects", ([	
"/d/city3/wenzai/npc/jinshe" : 1,		
]));	
        set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
