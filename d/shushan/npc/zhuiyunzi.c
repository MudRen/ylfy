//zhui yunzi-yushu 2001.2.
// lilong alter 2002.01.19
inherit NPC;
void create()
{
       set_name("׷����", ({"zhui yunzi", "yunzi", "zi"}));
       set("title", "��ɽ�ɵ���������");   
       set("gender", "����");
       set("age", 32);
       set("attitude", "friendly");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 30);
       set("con", 30);
       set("combat_exp", 2100000000);
       set("max_jing", 1000000);
	   set("eff_jing", 1000000);
	   set("jing", 1000000);
	   set("max_qi", 1000000);
	   set("eff_qi", 1000000);
	   set("qi", 1000000);
       set("neili", 1000000);
       set("max_neili", 10000);
		set("max_jingli", 5000);
        set("jingli", 1000000);
        set("jiali", 3000);
 
	set_skill("shushan-force", 400);
	set_skill("yujianshu",400);
       set_skill("dodge",400);
       set_skill("literate", 400);
       set_skill("sword",400);
       set_skill("force", 400);
       set_skill("parry",400);
       set_skill("zuixian-steps", 400);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "shushan-force");
       create_family("��ɽ��", 3, "����");
       setup();
      carry_object("/clone/cloth/cloth")->wear();
       carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="��ɽ��" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
			else command("say ʦ�ü�Ц�ˡ�\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ��̫�����ˡ�\n");
			else command("say ʦ��̫�����ˡ�\n");
		}
		else 
		{
			command("consider");
			command("say �����Լ�Ҫ�ݵģ��ɱ���Ұ�!��\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say �ã�����ɽ��һ���˲ű�������ɵø�ʦ��������\n");
		command("recruit " + ob->query("id") );
	}

	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ�ɵ��Ĵ�����");
                            }
              return 0;
}

�
