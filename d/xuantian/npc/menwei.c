//han.c  by:pipip
inherit NPC;
void create()
{
    set_name("�������", ({ "men wei","men","wei"}) );
    set("gender", "����" );
    set("age", 15);
    set("long", "�������������������������Ϊ���ӡ�\n");
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("nickname", HIC "����"HIW"ͯ��" NOR);
    set("str", 110);
    set("int", 90);
    set("con", 90);
    set("dex", 90);
    set("per", 25);
    set("max_qi", 6500000);
    set("max_jing", 150000);
    set("jing",15000);
    set("neili", 2000000);
    set("max_neili", 100000);
    set("jiali",1900);
    set("combat_exp", 30000000);
	set("score", 20); 
    set_skill("force", 500);
    set_skill("dodge", 600);
    set_skill("unarmed", 500);
    set_skill("parry", 500);
    set_skill("blade",500);
    set_skill("yijing-force",500);
    set_skill("lingyunbu", 600);
    set_skill("cuixin-zhang", 500);
    set_skill("tianxin-blade", 500);
    map_skill("force", "yijing-force");
    map_skill("dodge", "lingyunbu");
    map_skill("parry", "cuixin-zhang");
    map_skill("unarmed", "cuixin-zhang");
    map_skill("blade", "tianxin-blade");
    create_family("������",3,"����");
	setup();

    carry_object("/d/xuantian/obj/cloth")->wear();
    carry_object("/d/xuantian/obj/xblade")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("kar") < 28) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"����ȥ����Ե���֮�ˡ�");
                return;
                  } 
        if ((int)ob->query("per") < 28) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"�ĳ����ƺ�....");
                return;
                  } 
     command("recruit "+ob->query("id"));
     return;
}