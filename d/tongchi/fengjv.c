inherit ROOM;
void create()
{
          set("short", "��־�");
        set("long", @LONG
��־ӣ�ͨ�԰�����֮һ����ϻ��˵ľ�����?
�������������������񲣬��������ֹ���
��־��ﲻ������ȥ��
LONG
        );
        set("exits", ([
                  "east" : __DIR__"toujv",
        ]));
        set("objects", ([
        "/d/tongchi/npc/fengguai":1,
        ]));
        setup();
        replace_program(ROOM);
}

