inherit ROOM;
void create()
{
          set("short", "��Ϣ��");
        set("long", @LONG
��Ϣ�ң�ͨ�԰�ĵ������������˾Ϳ�����������Ϣ���������ҵ�
���ż��Ŵ���
LONG
        );
        set("exits", ([
                   "east" : __DIR__"tianjin",
        ]));
        set("objects", ([
        ]));
        set("sleep_room", "1");
        set("no_fight", "1");
        setup();
        replace_program(ROOM);
}
