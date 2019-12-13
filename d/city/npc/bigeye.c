
inherit NPC;
int look_ob();

void create()
{
	set_name("ǧ����", ({ "bigeye","qianli yan" }) );
	set("nickname", "������");
	set("gender", "����");
	set("age", 46);
	set("long","ǧ���ۿ���ȥ���м����ɷ���ǣ����㲻�������������е��¿�û���������ù�����\n");
	set("attitude", "peaceful");
	set("where",1);
	set_skill("taoism", 300);
	set_skill("force",200);
	set("max_neili",5000);
	set("max_jingli",3000);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("chat_chance", 5);
	set("no_get",1);
	set("chat_msg",
		({
		(: command("open door") :),
		(: look_ob :),
		(: command("close door") :),
		(: command("go northwest") :),
		(: command("go southeast") :),
		}));
	setup();
	carry_object("/clone/cloth/changpao")->wear();
}

int look_ob()
{
	foreach (object player in all_inventory(environment()) )
		command("look "+player->query("id"));
	return 1;
}

void init()
{
	add_action("do_where","where");
}

int do_where(string arg)
{
	object ob,me,where,*obj,wherer;
	int i;
	
	if(!arg || arg == "")
	{
		command("say "+this_player()->query("name")+"��������˭��");
		return 1;
	}
	
	me = this_player();
	
	if (wizardp(me) && !living(me))
		return 0;
	
	ob = find_player(arg);
	
	me->receive_damage("jing", 10, this_object());
	
	if( !ob )
		ob = find_living(arg);
	
	if( !ob || wizardp(ob))
	{
		command("tell "+me->query("id")+" ����û�����...");
		return 1;
	}
	
	where = environment(ob);
	
	if( !where )
	{
		command("tell " + me->query("id") + " ����˲�֪��������Ү....");
		return 1;
	}
	
	if (!stringp(where->query("short")))
	{
		command("tell "+me->query("id")+" "+ob->name(1)+"�����ĳ�������ϰɣ�\n");
		return 1;
	}
	
	//��ѯ���ʱ���ض�̬λ�ã�����PK�Ѷ�
	if(userp(ob) && random(100)>15)
	{
		obj=livings();

		for(i=0;i<sizeof(obj);i++)
		{
			i=random(sizeof(obj));

			if(!environment(obj[i]))
				continue;

			if(!living(obj[i]))
				continue;

			if (obj[i]->query("no_die"))
				continue;

			if (sscanf(base_name(obj[i]),"/u/%*s" ))
				continue;

			wherer = environment(obj[i]);

			if (!stringp(wherer->query("short")))
				continue;

			command("tell " + me->query("id") + sprintf(" %s(%s)������%s��\n",(string)ob->name(1),(string)ob->query("id"),random(20)<4?"����㳡":(string)wherer->query("short")));
			return 1;
		}
	}
	
	command("tell " + me->query("id") + sprintf(" %s(%s)������%s��\n",(string)ob->name(1),(string)ob->query("id"),random(20)<4?"����㳡":(string)where->query("short")));
	return 1;
}
