// Room: shanlu1.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�ϵ÷���������ɽ���վ�����ľ���ģ��������ӣ���ˮ��
�ȡ���Խɽ�����ϣ���������ף����վ�����������̫�գ�
��ҡ������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhandao",
  "northwest" : __DIR__"banshanting",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

