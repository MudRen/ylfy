// Room: /d/shaolin/matou2.c
// Date: Hop 97.06.13
inherit ROOM;
void create()
{
    set("short", "����ͷ");
    set("long", @LONG
�����Ǻ�ˮ������һ����ͷ���͡�С�����������������Ȼ
û������ͷ��ô���֣���Ҳ������һС��������һ�󼯵ġ�����
�߲���Զ�����������µġ������¡���ƫ�򶫱���������ȥ����
�ǵĹٵ���
LONG
    );
    set("exits", ([
        "west" : __DIR__"hanshui2",
         "east" : "/d/xiakedao/xkroad1",
    ]));
    set("objects", ([
        "/d/city/npc/chuanfu2" : 1,
    ]));
    set("outdoors", "shaolin");
    setup();
    replace_program(ROOM);
}
