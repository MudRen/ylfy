// Room: xiaolu-1.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
���߽�һƬ���֣��������������У�һ��һ�Ƶ����⣬��
�����˵����Ƶģ����������������˵����ϣ���ϸ��һ���泩��
��������������������˽�ĺ�������⡣����ý��������ɽ
���߹���ȫɽ�����ֶ�ҡ�װ��ԣ��������Ǻǡ���������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"banshanyao1",
  "northeast" : __DIR__"qian-ting",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

