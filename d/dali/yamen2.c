// Room: /d/dali/yamen2.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���϶����������ס������һ������������������ϸ������ǽ������һ�����ң�
���顰[1;33m�������[2;37;0m���ĸ���������Ĵ��֡�֪���������İ����������飬ʦү�����ں�
�������Ա�����������Ｉ�ã�����ᣩ��Ҫ���ɷ���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yamen",
]));

                 set("objects", ([
                __DIR__"npc/cheng" : 1,
                __DIR__"npc/shiye" : 1,
        ]));

         
	setup();
}

void init()
{
	add_action("do_jina","jina");
}

void gethim(object target,object me)
{
	if ( !objectp(target) || !objectp(me) ) return;

	if ( environment(me) == this_object() )
	{
		message("vision", "�����ٱ����˽�����������˵������"+target->name()+"���Ҵ�ææ������ȥ��\n", environment(target));
		target->move(this_object());
		message_vision("$N���ٱ�Ѻ�˽�����\n$n���һ����"+target->name(1)+"������ɱ�˷�����������\n", target, me);
		me->kill_ob(target);
		me->start_busy(3);
		target->kill_ob(me);
		target->start_busy(2+random(3));
	}
}

int do_jina(string arg)
{
	object me, target;

	me = this_player();

	if ( !objectp(me) ) return 0;
	if ( !arg ) return notify_fail("��Ҫ�����˭��\n");
	if ( (string) me->query("class") != "officer" ) 
		return notify_fail("�㲻�Ǵ����Ա�����ɼ����ɷ���\n");	
	/*if( me->query("combat_exp",1) <=100000000 )
		return notify_fail("ֻ�д�������������������Ϲټ��ſ��Լ����ɷ���\n");*/
	if ( (int)me->query("jing") < 100 ) 
		return notify_fail("������񲻹���\n");
	
	me->add("jing",-100);
	
	if ( !objectp(target = find_living(arg)) ) 
		return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
	if ( !environment(target) || wizardp(target) ) 
		return notify_fail("�Ҳ�������Ҫ���ɷ���\n");	
	if ( target->is_ghost() )
		return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
	if ( target == me ) 
		return notify_fail("�Լ������Լ�����ûë���ɣ�\n");
	if ( !(int)target->query_condition("killer") )
	    return notify_fail(target->name(1)+"����û�����鷸�ƣ�����Ȩ����"+gender_pronoun(target->query("gender"))+"��\n");
	/*if (target->query("age") < 18) return notify_fail(target->name(1) + "�����ף��������ҷŹ����ɡ�\n");*/
	if ( file_name(environment(target)) == "/clone/misc/block" )
		return notify_fail(target->name(1) + "�������ڼ����ﷴʡ˼����û��Ҫ�ټ����ˡ�\n");
	
	message_vision("$N�������£������ǣ�����"+target->name(1)+"������������\n",me);
	remove_call_out("gethim");
	call_out("gethim",5, target, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( me->is_fighting() && dir=="east" ) 
		return notify_fail("�����ڲ����뿪��\n");
	
	return 1;
}