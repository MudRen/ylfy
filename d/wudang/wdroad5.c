// wdroad5.c
// by Xiang
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ����Ϸ����ƺ���һ������·��
�ƺ����Ϸ���һ˿ɱ��,ԶԶ����,���˲�������.
LONG
        );
        set("outdoors", "wudang");
        set("exits", ([
                "southeast" : "/d/heimuya/road1", 
                "southwest" : __DIR__"wdroad6",
                "north" : __DIR__"wdroad4",
        ]));
        setup();
        replace_program(ROOM);
}
