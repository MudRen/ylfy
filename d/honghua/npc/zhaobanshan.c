// zhaobanshan.c �԰�ɽ
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_me();
void create()
{
        set_name("�԰�ɽ", ({ "zhao banshan", "zhao" }));
        set("nickname", HIM"ǧ������"NOR);
	set("long", 
                "���Ǻ컨��������԰�ɽ��\n"
		"��һ����Ϊ�������ɫ������\n"
                "����ͺ�������ʮ���£����΢�֣���������¶��Ц��.\n");
	set("gender", "����");
        set("age", 52);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
        set("max_qi", 2000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
	set("jiali", 100);
        set("combat_exp", 2000000);
	set("score", 100000);
        set_skill("force", 150);
        set_skill("honghua-shengong", 150);
        set_skill("dodge", 150);
        set_skill("youlong-shenfa", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("luohua-jian", 150);
        set_skill("throwing", 180);
        set_skill("literate", 100);
	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("unarmed", "baihua-cuoquan");
	map_skill("parry", "luohua-jian");
	map_skill("sword", "luohua-jian");
	create_family("�컨��", 2, "����");
	setup();
     carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        object ob;
        ::init();
        ob = this_player();
        if((int)ob->query("shen") < -1000 && ob->query("family/master_id")=="zhao banshan")
        {
                command("chat "+ob->query("name")+"!�����а���թ֮ͽ���������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
        }
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 10000) {
		command("say �Һ컨����ͽ����");
		command("say ��λ" + RANK_D->query_respect(ob) +
			"ƽʱ��Ҫ����һЩ��������֮�£�");
		return;
	}
	command("say �ã�����������˻��������������ˣ�");
	command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "yishi")
                ob->set("class", "yishi");
}
