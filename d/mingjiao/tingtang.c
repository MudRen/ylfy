// Room: tingtang.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ��нӴ�һ�����ý�������ĵط������ź�ľ̫ʦ�κ�С
�������ϱ����ߣ������м���Сͯ���ֶ�������ʱ�����˲���ˮ��

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"chashi2",
  "east" : __DIR__"guangming-ding",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

