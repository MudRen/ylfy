//wuming.c  by:pipip
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
void greeting(object);
void init();
void create()
{
    set_name("��������", ({ "wuming laoren","wuming","laoren"}) );
    set("gender", "����" );
    set("age", 55);
    set("long", "ʧȥ���������ǰ�����ˣ�������һ���̵�����������ʮ��λ���֡�\n");
    set("attitude", "peaceful");
    set("shen_type", 0);
    set("str", 130);
    set("int", 60);
    set("con", 70);
    set("dex", 70);
	set("max_qi", 1200000);
    set("max_jing", 700000);
    set("jing",700000);
    set("neili", 1500000);
    set("max_neili", 200000);
    set("jiali",1800);
    set("combat_exp", 160000000);
    set("score", 20);
    set_skill("force", 1500);
    set_skill("taoism", 1500);
    set_skill("qimen-wuxing", 1500);
    set_skill("dodge", 2200);
    set_skill("art", 1500);
    set_skill("unarmed", 1500);
    set_skill("parry", 2000);
    set_skill("blade",2000);
    set_skill("yijing-force",1500);
    set_skill("lingyunbu", 2100);
    set_skill("cuixin-zhang", 1500);
    set_skill("tianxin-blade", 1500);
    map_skill("force", "yijing-force");
    map_skill("dodge", "lingyunbu");
    map_skill("parry", "cuixin-zhang");
    map_skill("unarmed", "cuixin-zhang");
    map_skill("blade", "tianxin-blade");
    create_family("������",1,"��ɽ��ʦ");
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.pai" :),
                (: perform_action, "blade.zhan" :),
                (: perform_action, "blade.sanfen" :),
                (: exert_function, "recover" :),
        }) );
    set("chat_chance", 2);
    set("chat_msg", ({
        "�������˵���̾�����ҵ�����˭.....\n",
        "���������Ի�������㣬����һ���̲ؾ�����ֳ����Ի���۾�ʹ����úܲ������\n",
       "��������̾�˿�������������Ը��Ƕ����ϵ�֮ѡ����ϧ��������....\n",
    }) );
    setup();
    carry_object("/d/xuantian/obj/cloth")->wear();
    carry_object("/d/xuantian/obj/xblade")->wield();
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
        if ((int)ob->query_skill("qimen-wuxing", 1) < 300) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"���׾�����֮������Ĳ�������");
                return;
                  } 
        if ((int)ob->query_skill("art", 1) < 300) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"�������黭�ļ��ɻ������졣");
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

     command("say ���Ȼ�ܹ�����������Ҳ˵��������Ե���Ҿ�������ɡ�\n");
     message("vision",HIC"��"HIR"��������"HIC"��"NOR+":"+HIG" ��˵"HIM+ob->short()+NOR HIG"�ҵ���ʧ���Ѿõ��������ˣ����ҳ�Ϊ���Ĺ��ŵ��ӣ�\n"NOR,users());
     command("recruit "+ob->query("id"));
     return;
}

