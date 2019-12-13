//han.c  by:pipip
inherit NPC;
string ask_me();
void create()
{
    set_name("����", ({ "han zhen","han","zhen"}) );
    set("gender", "����" );
    set("age", 35);
    set("long", "�������˵�Ψһ����--���棬��˵���ѵõ����������߳��洫��\n");
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("nickname", HIC "��ɽ��"HIW"ѩ" NOR);
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
    set("combat_exp", 90000000);
    set("score", 20); 
    set_skill("force", 1000);
    set_skill("dodge", 1800);
    set_skill("unarmed", 1000);
    set_skill("parry", 1000);
    set_skill("blade",1000);
	set_skill("art", 1000);
    set_skill("yijing-force",1000);
	set_skill("qimen-wuxing", 1000);
    set_skill("lingyunbu", 2000);
    set_skill("cuixin-zhang", 1300);
    set_skill("tianxin-blade", 1300);
    map_skill("force", "yijing-force");
    map_skill("dodge", "lingyunbu");
    map_skill("parry", "cuixin-zhang");
    map_skill("unarmed", "cuixin-zhang");
    map_skill("blade", "tianxin-blade");
    create_family("������",2,"�����");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.pai" :),
                (: perform_action, "unarmed.pai" :),
                (: exert_function, "recover" :),
        }) );
    set("inquiry", ([
      "������":(:ask_me:),
    ]) );
    set("biao_count", 1);
        setup();

    carry_object("/d/xuantian/obj/cloth")->wear();
    carry_object("/d/xuantian/obj/xblade")->wield();
}


int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/master_id") != "wuming laoren") {
              ob->apply_condition("cuixin_poison", 6000
              +(int)ob->query_condition("cuixin_poison") );
   tell_object(ob, HIB "�������ʽ����һ�ɴ����ƶ���ӭ��һ�ɺ���������������\n" NOR );
        }
}

string ask_me()
{
    object me,ob;
    ob=this_player(); 
      if ((string)ob->query("family/master_id") != "wuming laoren")
        return "���Ǻ��ˣ�";  
    if (query("biao_count") < 1)
        return "�������ˣ���ֻ���۷������Ѿ����͸������ˡ�";   
    add("biao_count", -1);                  
    command("say �ţ������ϵ�ȷ����ʦ��Ϊʦ�����Ƶ����۷��ڡ�");
    command("say ��Ȼ���������ˣ���ͽ�����ȥ�ɡ�\n");
    message_vision(HIG"����ӻ����ͳ�һö���ڣ�������üͷ��ת�ֽ�����$N \n\n"NOR,ob);
    me=new("d/pipip/biao");
    me->move(ob);
    return HIR"�������̫�أ�ϣ����С��ʹ�ã���Ī����ħ���������������÷���\n";
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("dodge", 1) < 600) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"���Ṧ���������ý���");
                return;
                  } 
        if ((int)ob->query_skill("force", 1) < 600) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"���ڹ����ӻ�û��á�");
                return;
                  } 

        if ((int)ob->query_skill("unarmed", 1) < 300) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"�ƺ���û����ȭ�Ź����Ҫ�졣");
                return;
                  } 
        if ((int)ob->query_skill("blade", 1) < 300) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"�ĵ������û�����������");
                return;
                  } 
             if (ob->query_int() < 200) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"���Բ��㣬���������ҵ��书��");
                return;
                  } 
             if (ob->query_con() < 60) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"���޸���֮��������ϰ�䣿");
                return;
                  } 
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