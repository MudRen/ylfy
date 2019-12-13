// kuli.c ����
inherit NPC;

void create()
{
    set_name("����", ({ "zhao liu", "liu", "zhao" }));
    set("title", "�̲�����");
    set("nickname", "ˮ���");
    set("str", 37);
    set("gender", "����");
    set("age", 35);
    set("long",
	    "�����̲�������һ��ֵ���С�����ٲ��󣬿�Ȩ��ȴ��С\n");
    set("combat_exp", 1500);
    set("attitude", "friendly");
    set("inquiry", ([
        "����" : "Ҫ�����ȵý�Ǯ��",   //��Ҫ30���ƽ�
    ]));
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
    object ob;

    ::init();
    if (interactive(ob = this_player()) && !is_fighting()) {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
    }
    add_action("do_betray","decide");
}
void greeting(object ob)
{
    if (!ob || environment(ob) != environment())
	return;
    switch(random(2)) {
	case 0 :
	    say("����Ц���е�˵������λ" + RANK_D->query_respect(ob) +
		    "���������Ъ�����ɡ�\n");
	    break;
	case 1 :
	    say("����˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
		    "�����˰�����Ҫ���������ʦ��¼��\n");
	    break;
    }
}
int accept_object(object who, object ob)
{
   /* if(get_system_config(DATA_CONFIG_DIR "system.h", "ALLOW_BETRAYER")==0)//->query("betrayer"))
    {
	tell_object(who, "����˵������͢�Ѿ���ּ�����������ʦ��¼�ˣ�\n");
	return 0;
    }*/

    if(! (int)who->query("betrayer"))
    {
	tell_object(who, "����˵�������Ѿ�û����ʦ��¼��ѽ��\n");
	return 0;
    }

    if (ob->query("money_id") && ob->value() >= 1000000)
    {
	tell_object(who, "����Ц���е�˵�����ðɣ�ÿ���һ����ʦ��¼Ҫ��ȥ15%�ľ��顢���Ҹ��Ź���������\n");
	tell_object(who, "�㿼������˾������������ɡ�(decide)\n");
	who->set_temp("fee_paid",1);
	return 1;
    }
    else if (ob->query("money_id") && ob->value() < 1000000) 
    {
	tell_object(who, "�����ٺ�һЦ��˵�������������Ǯ�� �����ҿ�û�����㰡��\n");
	return 1;
    }
    return 0;
}

int do_betray()
{
    int i,ob_levl, level;
    object me;
    mapping skill_status;
    string *sname;

    me = this_player();

    if(! (int)me->query("betrayer"))
	return notify_fail("����˵�������Ѿ�û����ʦ��¼��ѽ��\n");

    if( !me->query_temp("fee_paid") ) 
	return notify_fail("���������˵�������ܽ�����ʲ�ᣬ���ɵ��ȸ�Ǯ�ģ�\n");

    me->add("betrayer", -1);
    if ( skill_status = me->query_skills() )
    {
	sname  = keys(skill_status);
	for(i = 0; i < sizeof(skill_status); i++) 
	{
	    level = skill_status[sname[i]] - 2;
	    if(level <= 0)
		me->delete_skill(sname[i]);
	    else
		me->set_skill(sname[i], level);
	}
    }

    ob_levl = me->query("xyzx_sys/level");
    me->set("xyzx_sys/levup_exp",0);

   //ʵս������ʧ3%
	me->add("combat_exp", -(int)me->query("combat_exp") / 20 * 3);
	//������ʧ3%
	me->add("xyzx_sys/levup_exp", -(int)me->query("xyzx_sys/levup_exp") / 20 * 3);
				
	//�ȼ���ʧ
	if ( me->query("xyzx_sys/level") > 1 )
	{
		if ( me->query("xyzx_sys/level") > 0 && me->query("xyzx_sys/level") < 5 )
			me->add("xyzx_sys/level",-1);
		else
			me->add("xyzx_sys/level", -(int)me->query("xyzx_sys/level") / 5);
	}
    me->delete_temp("fee_paid");
    tell_object(me, "����Ц���е�˵������������ʦ��¼�����һ�Ρ�\n");
    me->unconcious();
    return 1;
}