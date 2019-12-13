inherit NPC;

void create()
{
        set_name("�Ŷ�", ({ "Du er", "du" , "er" }));
        set("title","�Ÿ�����");
        set("long", "�Ŷ��ǶŸ��ĵ��ӣ��������īˮҲ���١�\n");
	set("gender", "����");
        set("age", 45);

        set_skill("literate", 120);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set_temp("apply/damage", 20);

        set("combat_exp", 4000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
		return 0; 
        ob->add_temp("mark/��", -1);
	return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/��"))
                who->set_temp("mark/��", 0);
        if (ob->query("money_id") && ob->value() >= 5000) {
                message_vision("�Ŷ�ͬ��ָ��$NһЩ���⡣\n", who);
                who->add_temp("mark/��", ob->value() / 250);
		return 1;
	}
	return 0;
}
