// Room: shiliang.c ʯ��
// arnzh 97/1/24
inherit ROOM;
string look_out();
void create()
{
    set("short", "������");
    set("long", @LONG
�����������£������վ��������ƺ����˶�վ���ȣ��䵱����
������������ϰ�Ṧ��
LONG
    );
    set("exits", ([
        "west" : __DIR__"tyroadct",
    ]));
    set("item_desc",([
        "out"       :   (: look_out :),
    ]));
    set("objects", ([
        CLASS_D("wudang") + "/zhangcui" : 1
       ]));
    setup();
}
void init()
{
    add_action("do_out","out");
}
int do_out(string arg)
{
    object me, killer;
    int i, ging_cost, qi_cost;
    me = this_player();
    i = (int)me->query_skill("dodge", 0) + random(200);
    ging_cost = 600 / (int)me->query_int();
    qi_cost = 500 / (int)me->query_int();
    if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
        i = 0;
    message_vision("$N�����ͱڣ�һ������������ȥ��\n", me);
    me->move(__DIR__"shesheng1");
    reset_eval_cost();
    message_vision("ֻ�����须��һ��$N����������������\n", me);
    if ( i < 50)
    {
        killer = new(CLASS_D("wudang") + "/zhangcui");
         me->set_temp("last_damage_from",killer);
                me->die();
        destruct(killer);
    }
    else{ if( i < 125)
        me->unconcious();
    else {
        message_vision("$N�����ȵ�վ�ڵ��ϡ�\n", me);
                if (me->query_skill("dodge", 1)<450)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
                else me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/2);
        me->receive_damage("jing", ging_cost );
        me->receive_damage("qi", qi_cost );
        me->set_temp("die_for","����ˤ");
        me->delete_temp("last_damage_from");
    }
   }
    return 1;
}
string look_out()
{
    return  "������һ�������ߵ����£���������ȥ��һ��������ȥ�ĸо�.\n";
}

