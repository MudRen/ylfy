// gao-laozhe.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("������", ({ "gao laozhe", "gao" }));
	set("title", HIR"��ɽ��ʮ��������"NOR);
	set("long", "�����ǻ�ɽ�ĳ��ϸ����ߡ�һ���벻�ں���ģ�����������죬���²��ӻ���\n"
	"������׷������ʦ�ְ����ߡ�\n");
	set("gender", "����");
	set("age", 65);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 3800);
	set("max_qi", 3800);
	set("jing", 3600);
	set("max_jing", 2000);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);

	set("combat_exp", 1250000);
	set("score", 200000);

	set_skill("cuff", 170);
	set_skill("force", 160);
	set_skill("blade", 170);
	set_skill("sword", 170);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	set_skill("strike", 170);
	set_skill("zixia-shengong", 200);
	set_skill("poyu-quan", 160);
	set_skill("fanliangyi-dao", 170);
	set_skill("huashan-jianfa", 170);
	set_skill("hunyuan-zhang", 160);
        set_skill("feiyan-huixiang",160);
	set_skill("literate", 100);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "fanliangyi-dao");
	map_skill("blade", "fanliangyi-dao");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");

	create_family("��ɽ��", 12, "����");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "blade.sanshen" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	

	if ((string)ob->query("family/family_name") != "" && (string)ob->query("family/family_name") != "��ɽ��")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������������أ�");
		return;
	}

        if (((int)ob->query_skill("force",1) < 80) || ((int)ob->query_skill("zixia-shengong",1) < 80))
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "����ϼ�񹦻�ûѧ���Ұɡ�");
		return;
	}
        if (((int)ob->query_skill("dodge",1) < 80) || ((int)ob->query_skill("feiyan-huixiang",1) < 80))
	{
                command("say �ҿ�" + RANK_D->query_respect(ob) + "�ķ�����軹ûѧ���Ұɡ�");
		return;
	}

        if ((int)ob->query("shen") < 50000)
	{
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "fighter")
		ob->set("class", "fighter");

}