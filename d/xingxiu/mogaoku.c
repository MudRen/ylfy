// /d/xingxiu/mogaoku.c
// Jay 3/17/96
inherit ROOM;
// can put some book about budism here.
void create()
{
        set("short", "Ī�߿�");
        set("long", @LONG
����ǽ���ϻ�����������صĻ��棬����Ů���죬���з������á�����
���кܶ����;��顣�㱻��Щ�������Ļ�֮�������ˡ�
LONG
        );
        set("exits", ([ 
             "out" : __DIR__"yueerquan",
]));
        set("no_clean_up", 0);
	set("item_desc", ([
                "��Ů����" : "����һ�����ʯ��ɵġ���Ů����ͼ����������һ��С׭����xxx�����xxx����\n",
	]));

	setup();
}

void init()
{
	add_action("do_study", "study");
}


int do_study(string arg)
{
	object me;
	int    jing_cost;

	me = this_player();

	if ( !arg || ( arg != "��Ů����ͼ" ) )
		return notify_fail("��Ҫ��ʲô��");

	if ( (int)me->query_skill("literate", 1) < 1){
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}

	if ( (int)me->query_int() < 45){
		write("������Բ�������ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}

	jing_cost = me->query("max_jing")/5;
	if((int)me->query("jing") < jing_cost){
		write("�������ۻ����ң������Ůͼ�Ի��ˡ�\n");
		return 1;
	}
	me->receive_damage("jing", jing_cost );
	me->delete_temp("stone_learned");

	message_vision("$N��ר���ж�ʯ���ϵĹŹ�ͼ�Ρ�\n", me);
	
	write("�����ʯ����ĥ��һ�ض�����������\n");

        if ( (int)me->query_skill("qimen-flee", 1) < 300 && random(10)>3 ){
			me->improve_skill("qimen-flee", me->query_int());
			me->set_temp("stone_learned",1);
		}
	return 1;
}

