// yuzhenggong.c ���湬
// by Xiang
inherit ROOM;
void create()
{
    set("short", "���湬");
    set("long", @LONG
�������䵱�����湬����ʱ���н���ʹ��������߹��������Ǽ�����
����һ��������ʯ�״��ö�����ֱͨ�����������е������壬������������
���Ƶ���¯������Χ�ϵ���Ը�ˣ�������Ȼ�𾴡�
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "southdown" : __DIR__"shijie12",
        "northup" : __DIR__"shijie21",
    ]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));
    setup();
    replace_program(ROOM);
}
