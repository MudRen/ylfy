// houhuayuan1.c ��԰
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
����һƬ�ķ��˵Ļ�԰������������һƬС����������һЩ����
֮�࣬���ڳ������Ҳ�ɺ��ˡ�����������һ����ɽ��ɽ�ϳ�����
��̦�������Ѿ��ܾ�û���������ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west" : __DIR__"houhuayuan",
        ]));
        set("objects", ([
                __DIR__"npc/wugui" : 1,
        ] ));

        setup();
        replace_program(ROOM);
}

