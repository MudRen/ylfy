
// buwei1.c
inherit ROOM;
//int valid_leave();
void create()
{
      set("short", "ʯ��");
    set("long", @LONG
������ƣ��������������һ��ʯ��ǰ��ֻ����һ�������
���������ڴ��������㾫��һ����Ҫ��ȥ��������������һ
λ�����į����������վ���ſڣ�������������������㡣
LONG
        );
    set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 2 */
        "north" : "d/xuantian/lyj",
		"south" : "d/xuantian/dongxue",
    ]));
        set("objects", ([ 
        "d/xuantian/npc/han" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("no_action", "ansuan");
     add_action("no_action", "set");


}

int no_action(string str)
{
      write("����ɲ�������Ŷ.. \n");
        return 1;
}
int valid_leave(object me, string dir)
{
    object ob;
    if (dir != "north")
        return ::valid_leave(me, dir);
    ob=present("han zhen", environment(me));
        if (dir == "north" && objectp(ob) && living(ob))
    {
        if ((me->query("family/family_name") == "������"))
            {
            if ((me->query("gender") == "����"))
                write("���涢���㿴��һ�ᣬ�������ó���ȥ·��\n");
            else if ((me->query("gender") == "Ů��"))
                write("���濴����һ�ۣ�����΢΢һ�죬���˿�ȥ��\n");
            return 1;
            }
                else 
            return notify_fail("���浲ס���ȥ·������ĵ���" + RANK_D->query_respect(me) + "��ֹ����\n");
    }
    return ::valid_leave(me, dir);
}


