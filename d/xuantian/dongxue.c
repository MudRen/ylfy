
// buwei1.c
inherit ROOM;
//int valid_leave();
void create()
{
      set("short", "ʯ��");
    set("long", @LONG
������ƣ��������������һ����Ѩǰ��ֻ����һ�������
���������洫�������㾫��һ��
LONG
        );
    set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 2 */
        "north" : "d/xuantian/door",
    ]));
        set("objects", ([ 
        "d/xuantian/npc/menwei" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
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
            
            return 1;
            }
                else 
            return notify_fail("���ֵ�ס���ȥ·������ĵ���" + RANK_D->query_respect(me) + "��ֹ����\n");
    }
    return ::valid_leave(me, dir);
}


