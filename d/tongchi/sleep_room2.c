inherit ROOM;
void create()
{
          set("short", "����");
        set("long", @LONG
ͨ�԰������Са�����ң����ڵĲ��ú�ƽ����
ǽ�Ƿ���һ�Ŵ󴲡�
LONG
        );
        set("exits", ([
                   "east" : __DIR__"xiefj",
        ]));
        set("objects", ([
        ]));
        set("sleep_room", "1");
        setup();
        replace_program(ROOM);
}
