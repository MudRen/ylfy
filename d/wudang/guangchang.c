// guangchang.c �㳡
// by Xiang
inherit ROOM;
void create()
{
    set("short", "�䵱�㳡");
    set("long", @LONG
����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱����ѧϰ�书�ͻ����д�ĵص㡣
��Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ���ڴ�
ɨ������������������
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "southdown" : __DIR__"shijie62",
        "north" : __DIR__"sanqingdian",
        "west"  :__DIR__"shijie7",
    ]));
    set("objects", ([
        CLASS_D("wudang") + "/daotong" : 2]));
    setup();
    replace_program(ROOM);
}
