
inherit ROOM;
void create()
{
    set("short", "�ܵ�");
    set("long", @LONG
�����ǰ��һ���ú������̳ɵ�̨�ף�һֱ�������죬���ߵ�ǽ�ڶ�
�ǻ����ң�ǽ�ϸ�ʮ��������һյ�͵ƣ�ʹ���ܿ�����Χ��
LONG
    );
    set("exits", ([
        "up" : __DIR__"huayuan",
        "northdown": __DIR__"midao2",
    ]));
    set("objects",([
        __DIR__"npc/nvlang" : 1,
    ]));
    setup();
}
int valid_leave(object me, string dir)
{
    object ob;
    ob=present("nv lang", environment(me));
    if (ob && living(ob)){
        if (  (dir == "northdown") && ((string)me->query("family/family_name") != "���չ�") )
        return notify_fail  ("����Ů��������ס�㣬˵�������Բ��𣬱����صأ���أ���\n");
    }
    return ::valid_leave(me, dir);
}
