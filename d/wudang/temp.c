// liangongfang.c ������
// by Xiang
inherit ROOM;
void create()
{
set("short","����");
    set("long", @LONG
���������ң�һ�������������ڴ��ϣ�����ʮ������
LONG
    );
    set("exits", ([
        "west" : __DIR__"donglang2",
    ]));
    set("objects", ([
 CLASS_D("wudang") + "/yudaiyan" : 1]));
    set("no_fight", 1);
    
    setup();
    replace_program(ROOM);
}
