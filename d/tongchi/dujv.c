inherit ROOM;
void create()
{
          set("short", "�Ĺ־�");
        set("long", @LONG
ͨ�԰�����֮һ�Ĺֶο����ס����ƽʱ�������£���ϲ��
�ģ������Ĵ������ŶĲ����þߣ�ÿ�춼���Ĳ��졣
LONG
        );
        set("exits", ([
                   "west" : __DIR__"yishi",
                   "north" : __DIR__"qinjv",
        ]));
        set("objects", ([
        "/d/tongchi/npc/duguai":1,
        ]));
        setup();
        replace_program(ROOM);
}
