inherit ROOM;
void create()
{
          set("short", "�ٹ־�");
        set("long", @LONG
�ٹ־ӣ�ͨ�԰�����֮һ�Ų��ľ������ٹ�ƽ����ϲ�����٣�
���춼������������Ϊ�飬�������ա�
LONG
        );
        set("exits", ([
                  "south" : __DIR__"dujv",
                  "east" : __DIR__"yajv",
        ]));
        set("objects", ([
        "/d/tongchi/npc/qinguai":1,
        ]));
        setup();
        replace_program(ROOM);
}
