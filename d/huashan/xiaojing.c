// xiaojing.c
inherit ROOM;
void create()
{
    set("short", "��Ů��С��");
    set("long", @LONG
��������Ů���ɽ��һ��С����·�߳����˴���ÿ��΢���������
Ҷ��ɳɳ���죬�Ե÷�����ľ���
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
        "northdown" : __DIR__"yunu",
        "southup" : __DIR__"siguoya",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "huashan" );
    setup();
    replace_program(ROOM);
}
