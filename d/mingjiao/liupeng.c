// Room: liupeng.c

inherit ROOM;

void create()
{
        set("short", "ţ��");
        set("long", @LONG
����һ��СС��é�ݣ�é��ǰ��һƬ�Ƴγεĸ��أ�һ��
��ͯ��վ��é��ǰɵɵ�ķ�㶣�һ����ݣ����૵��������ˣ�
������.....!��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"maowu",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

