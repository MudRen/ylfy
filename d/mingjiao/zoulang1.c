// Room: zoulang1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�������ĳ��ȣ�����û��ʲô����⻬��ʯ��������һЩ��
Ȼ������ʱ����һЩ���ڴҴ��߹������ƺ���û������ȥ��ϸ����
һ����Щ�������ֹŹֵĻ��ơ�

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shiwangdian",
  "east" : __DIR__"yaofang1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

