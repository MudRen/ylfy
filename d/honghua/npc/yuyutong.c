// yu-yutong.c ����ͬ
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_me();
void create()
{
        set_name("����ͬ", ({ "yu yutong", "yu" }));
        set("nickname", RED"������"NOR);
	set("long", 
                "���Ǻ컨���ʮ�ĸ�����ͬ��\n"
                "��һ����Ϊ����İ�ɫ������\n"
                "����ͺ����ڶ�ʮ���£�����ɫ����������������Ǹ�����ӵ�.\n");
	set("gender", "����");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
	set("jiali", 100);
        set("combat_exp", 400000);
	set("score", 100000);
        set_skill("force", 80);
        set_skill("honghua-shengong", 80);
        set_skill("dodge", 80);
        set_skill("youlong-shenfa", 80);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("luohua-jian", 80);
        set_skill("literate", 150);
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
        if((int)ob->query("shen") < -1000 && ob->query("family/master_id")=="yu yutong")
        {
                command("chat "+ob->query("name")+"!�����а���թ֮ͽ���������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
        }
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0) {
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
