inherit ROOM;
int do_xue(string arg);
void create()
{
    set("short", "��ٸ");
    set("long", @LONG
�������ٸ���ﶼ���Ź������Ÿ������ƣ���̬���졣
LONG
    );
    set("exits", ([
           "west":__DIR__"shidao3",
    ]));
    setup();
}
void init()
{
    add_action("do_xue", "xue");
}
int do_xue(string arg)
{
    object me;
    me = this_player();
    if ( !arg || ( arg != "ٸ" ) )
        return notify_fail("ʲô��\n");
    if ( (int)me->query_skill("literate", 1) < 1)
        return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
    if(me->query("hammer")) return notify_fail("���Ѿ�ѧ����ٸ�ˡ�\n");
    if(me->query("sword")) return notify_fail("���Ѿ�ѧ����ٸ�ˡ�\n");
    if(me->query("unarmed")) return notify_fail("���Ѿ�ѧ��ȭٸ�ˡ�\n");
    if(me->query("club")) return notify_fail("���Ѿ�ѧ����ٸ�ˡ�\n");
    if(me->query("axe")) return notify_fail("���Ѿ�ѧ����ٸ�ˡ�\n");
    if(me->query("staff")) return notify_fail("���Ѿ�ѧ����ٸ�ˡ�\n");
    if(me->query("whip")) return notify_fail("���Ѿ�ѧ����ٸ�ˡ�\n");
    if(me->query("blade")) return notify_fail("���Ѿ�ѧ����ٸ�ˡ�\n");
    me->receive_damage("jing", 1000);
    message_vision("$N��ʼģ��ѧϰ��Щ��ٸ�ĸ��ֶ�����\n", me);
    if ( (int)me->query_skill("throwing", 1) < 851)
    {
        me->improve_skill("throwing", me->query_int());
        me->set("throwing",1);
        return 1;
    }
    write("�������ٸ����һ�ض��������Ѿ�û��ʲô��ѧ���ˡ�\n");
    return 1;
}
