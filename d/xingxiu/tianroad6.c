// room: /d/xingxiu/tianroad6.c
// Jay 3/18/96
inherit ROOM;
void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
��������ɽ���塣����������Χ��ȥ�����׶���ԭ�ķ�⾡���۵ס�����
һ��С·������ɽ��
LONG
        );
        set("exits", ([
            "eastdown" : __DIR__"tianroad5",
        ]));
        set("objects", ([
               __DIR__"npc/snake" : 2, 
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}
