// buwei1.c
inherit ROOM;
void create()
{
        set("short", "����");
    set("long", @LONG
���ǻ�ɽ��������Ⱥ�ľ�����������Ϊ�������˴���ǰ�������Ϲ���
�������á������Ҷ���кܿ���ȴûʲô���裬��ǽ�������ѽ��Σ�
����������Ⱥ���¡���ͽ�ĵط������������ҡ�
LONG
        );
    set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"square",
        "north" : __DIR__"buwei2",
    ]));
        set("objects", ([ 
        __DIR__"npc/dayou" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
    object ob;
    if (dir != "north")
        return ::valid_leave(me, dir);
    ob=present("lu dayou", environment(me));
        if (dir == "north" && objectp(ob) && living(ob))
    {
        if ((me->query("family/family_name") == "��ɽ��"))
            {
            if ((me->query("gender") == "����"))
                write("½���в����ÿ���˵����ʦ�������ˣ�ʦ����ȥ�ˣ����ȥ�Ȼᡣ\n");
            else if ((me->query("gender") == "Ů��"))
                write("½���в����ÿ���˵����ʦ�������ˣ�ʦ����ȥ�ˣ����ȥ�Ȼᡣ\n");
            return 1;
            }
        if( present("yingxiong ling", me) && ((int)me->query("shen") > 5000))
        {
            write("½���й���˵����ԭ���ǹ�ͼݵ�����������\n");
            return 1;
        }
                else 
            return notify_fail("½���кȵ��������Ǽ�ʦ���ң���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
    }
    return ::valid_leave(me, dir);
}
