
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
�������䵱�������ţ�һ���߸ߵ���¥������ǰ����ʱ���н���ʹ����
����߹��������Ǽ���������һ��������ʯ�״��ö�����ֱͨ�����������е�
�����壬���������������Ƶ���¯������Χ�ϵ���Ը�ˣ�������Ȼ�𾴡�
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "south" : __DIR__"hutou",
        "north" : __DIR__"liantai",
    ]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));
    setup();
    replace_program(ROOM);
}
