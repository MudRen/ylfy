//ROOM damen.c
inherit ROOM;
void create()
{
    set("short", "����������");
        set("long",@LONG
�����ͨ�����չ����������Ĵ��š��������Ҹ���һͷʯ�������
���ߴ��������࣬��๾�צ���񿥷Ƿ��������������ƺ���ʱҪ�ڿն�ȥ��
LONG
    );
        set("outdoors", "lingjiu");
        set("exits", ([
        "north" : __DIR__"dating",
        "south" : __DIR__"dadao2",
        ]));
    set("objects",([
        CLASS_D("lingjiu") + "/meijian" : 1,
        __DIR__"npc/lanjian" : 1,
    ]));
    setup();
}
int valid_leave(object me, string dir)
{
    object ob1;
    object ob2;
    ob1=present("mei jian", environment(me));
    ob2=present("lan jian", environment(me));
    if (  (dir == "north") && ((string)me->query("family/family_name") != "���չ�") ){
        if (ob1 && living(ob1) && ob2 && living(ob2))
            return notify_fail ("÷��˫�������ס�㣬˵�����������չ�������أ���\n");
        if (ob1 && living(ob1))
            return notify_fail  ("÷��������ס�㣬˵�����������չ�������أ���\n");
        if (ob2 && living(ob2))
            return notify_fail ("����������ס�㣬˵�����������չ�������أ���\n");
    }
    return ::valid_leave(me, dir);
}
