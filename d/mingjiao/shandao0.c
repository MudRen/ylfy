// Room: shandao0.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ����С·�����������Ĳ�֪ͨ���η���·�ߵ�����
�ߵ��Ӳ����ܴдУ�����ܾ�û���߹��ˣ�΢�紵�����ݴ�һ��
��һ������ȥ����ɳɳ�������죡
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"liehuoqi",
  "east" : __DIR__"shandao1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

