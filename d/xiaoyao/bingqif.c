// bingqif.c
// shilling 97.2
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
�������������һ��Сʯ�ݣ������Ǵ�������ģ��������и����¯
���̵��أ����л���һ��ʯ�����������һЩ�Ѿ�����õı�����
LONG
    );
    set("exits", ([
        "south" : __DIR__"xiaodao2",
]));
    set("no_clean_up", 0);
    set("objects", ([
               "clone/weapon/blade": 2,
]));
    setup();
    replace_program(ROOM);
}
