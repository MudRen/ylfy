// Room: lianhuachi ������
inherit ROOM;
string look_CAI();
void create()
{
    set("short", "������");
    set("long", @LONG
�������ƻ����ڵ�һ�������أ����ڿ�������������
��ס������ȥժһ�䡣����������ڴ����������������ˣ�
LONG
    );
    set("exits", ([
        "east" : __DIR__"xiaojing2",
    ]));
    set("item_desc",([
        "CAI"       :   (: look_CAI :),
    ]));
    setup();
}
void init()
{
    add_action("do_CAI","CAI");
}
int do_CAI(string arg)
{
    object me, killer;
    int i, ging_cost, qi_cost;
    me = this_player();
    i = (int)me->query_skill("dodge", 0) + random(200);
    ging_cost = 600 / (int)me->query_int();
    qi_cost = 500 / (int)me->query_int();
    if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
        i = 0;
    message_vision("$N�������Ϻ�Ҷ������ȥ����һ��������\n", me);
    me->move(__DIR__"lianhuachi");
    reset_eval_cost();
    message_vision("ֻ�����须��һ��$N�������������˳�����\n", me);
    if ( i < 50)
    {
        killer = new(("/d/yihua/npc") + "/lianxing");
         me->set_temp("last_damage_from",killer);
                me->die();
        destruct(killer);
    }
    else{ if( i < 125)
        me->unconcious();
    else
	{
		message_vision("$N�����ȵ�վ�ڳرߡ�\n", me);
		
		if (me->query_skill("dodge", 1)<450)
			me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
		else if (me->query_skill("dodge", 1) > 1650)//1650���������Ѷ�
			me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/15);
		else
			me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/6);
        me->receive_damage("jing", ging_cost );
        me->receive_damage("qi", qi_cost );
        me->set_temp("die_for","������");
        me->delete_temp("last_damage_from");
    }
   }
    return 1;
}
string look_chi()
{
    return  "�����������صĳرߣ�������ȥ��һƬ�����أ����̲�ס��ȥ���вɶ�����.\n";
}

