// Room: caodi1.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
����һƬ�����де���ݵأ������������Ƶ���ɽ���ݴ��м���
��һЩ��ɫ��Ұ���������������һ�㡣ʱ������Щ��С�����������
�����ɽ����һ�ò���Ĺ����������¿������ǳ�����ˬ��

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qingcaodi",
  "west" : __DIR__"caodi",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

