// Room: xiuxishi.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
�����ǽ��е����������Ϣ�ĵط�����ǽ���ż�һ�Ŵ󴲣���ͷ
���Ŵ�����������ĳ���������Կ����ľ�������СԺ������ɽ����
����Ʈ��������Ҷ�����㡣����ͨ����������

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang3",
  "east" : __DIR__"liangongfang2",
]));
        set("sleep_room", "1");
set("no_fight","1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

