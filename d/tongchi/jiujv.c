inherit ROOM;
void create()
{
          set("short", "�ƹ־�");
        set("long", @LONG
�ƹ־ӣ�Ҳ��������֮һ�����ľ������ƹ�ƽ����ƣ�һ��û
�ƾ���Ҫ�����������������ܰڷŵĶ���һ������̳�ӡ�
LONG
        );
        set("exits", ([
                 "north" : __DIR__"toujv",
                 "east" : __DIR__"yishi",
        ]));
        set("objects", ([
        "/d/tongchi/npc/jiuguai":1,
        ]));
        setup();
        replace_program(ROOM);
}
