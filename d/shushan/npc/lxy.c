//����ɽ���ɡ�dhxy-evil 2000.7.5
//yushu�޸� 2001.2
// lilong alter 2002.01.19
inherit NPC;
void create()
{
        set_name("����ң", ({ "li xiaoyao", "li", "xiaoyao" }));
        set("title","��ɽ�������ŵ���");
        set("long", 
"����ң��Ľ��ݣ�����Ũü���ۣ������Ѱ���\n");
        set("gender", "����");
        set("age", 18);
	 set("class", "xiake");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
		set("no_suck", 1);
        set("qi", 3000000);
        set("max_qi", 3000000);
        set("jing", 3000000);
        set("max_jing", 3000000);
        set("neili", 30000000);
        set("max_neili", 3000000);
        set("combat_exp", 2100000000);
        set("max_jingli", 3000000);
        set("jingli", 3000000);
		set("jiali", 15000);
        set_skill("force", 1500);
        set_skill("dodge", 1500);
        set_skill("unarmed", 1500);
         set_skill("fumozhang", 1500);
        set_skill("parry", 1500);
        set_skill("sword", 1500);
        set_skill("canxin-jian", 1500);
        set_skill("shushan-force", 1500);
        set_skill("zuixian-steps",1500);
        set_skill("literate",1500);
        map_skill("unarmed", "fumozhang");
        map_skill("force", "shushan-force");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry", "canxin-jian");
        map_skill("sword", "canxin-jian");
        setup();
        create_family("��ɽ����", 3, "����");
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
			command("say ��������ĳ���ķ���,������Ϊͽ!\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say ��������ĳ���ķ���,������Ϊͽ!\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ������ң����");
              }
              return 0;
}

