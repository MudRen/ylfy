inherit ROOM;
void create()
{
          set("short", "�ƹ־�");
        set("long", @LONG
�ƹ־ӣ�ͨ�԰�����֮һ�ƹ�֣���Եľ������
�ƹ����ڲ������һ�㶼���������
LONG
        );
        set("exits", ([
                  "west" : __DIR__"qinjv",
        ]));
        set("objects", ([
        "/d/tongchi/npc/yaguai":1,
        ]));
        setup();
        replace_program(ROOM);
}
