// nanjie.c �Ͻ�
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
�������书���Ͻ֣�˵�ǽ֣�������һ��С��ͬ���ѡ�·��һ����Ҳ
û�С��ֵľ�ͷ��һ��С�š������������������书��������ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"zhongxin",
                "southeast" : __DIR__"fu-cemen",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
