// zhaixing.c ժ����
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("ժ����", ({ "zhaixing zi", "zhaixing" }));
    set("nickname", "�����ɴ�ʦ��");
    set("long", 
        "�����Ƕ�����Ĵ���ӡ������ɴ�ʦ��ժ���ӡ�\n"
        "����ʮ���꣬�����������۹���͸��һ˿����֮����\n");
    set("gender", "����");
    set("age", 35);
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("str", 36);
    set("int", 38);
    set("con", 36);
    set("dex", 76);
    
    set("max_qi", 1000);
    set("max_jing", 800);
    set("neili", 1800);
    set("max_neili", 1800);
    set("jiali", 60);
        set("combat_exp", 800000);
    set_skill("force", 200);
    set_skill("huagong-dafa", 200);
    set_skill("dodge", 200);
    set_skill("zhaixinggong", 200);
    set_skill("unarmed", 205);
    set_skill("chousui-zhang", 200);
    set_skill("parry", 200);
    set_skill("staff", 200);
    set_skill("tianshan-zhang", 200);
    set_skill("literate", 200);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "chousui-zhang");
    map_skill("parry", "tianshan-zhang");
    map_skill("staff", "tianshan-zhang");
    create_family("������", 2, "����");
    setup();
//  carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    command("say �ðɣ��Ҿ��������ˡ�");
    command("recruit " + ob->query("id"));
}
void init()
{
        object ob;
        ::init();
   if (this_object()->query("startroom") != base_name(environment()) )  return;
        if (interactive(ob = this_player()) && !is_fighting()) {
                if ((ob->query("shen")>10000) &&
                        (!wizardp(ob))) {
        command("say ���޺����Ƕ����й�֮�أ�\n");
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
                }
        }
}
void do_killing(object ob)
{
    if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}
mixed hit_ob(object me,object victim,int damage)
{
   if (!living(this_object()) )  return;
   switch( random(5)) { 
   case 0:
   command("exert maxsuck "+victim->query("id"));
   break;
   case 1:
   command("exert qisuck "+victim->query("id"));
   break;
   case 2:
   command("exert neilisuck "+victim->query("id"));
   break;
   case 3:
   command("exert jingsuck "+victim->query("id"));
   break;
   case 4:
   command("exert jinglisuck "+victim->query("id"));
   break; 
    }
}

