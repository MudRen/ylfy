// houyuan.c ��Ժ
// by Xiang
inherit ROOM;
void create()
{
    set("short", "��Ժ");
    set("long", @LONG
�����Ǻ�Ժ������������������һ��Բ�ε��Ŷ�����һ��С·ͨ��
��ɽ��
LONG
    );
    set("exits", ([
        "north" : __DIR__"xiaolu1",
        "south" : __DIR__"sanqingdian",
    ]));
    set("objects", ([
        CLASS_D("wudang") + "/yu" : 1]));
    setup();
    replace_program(ROOM);
}
