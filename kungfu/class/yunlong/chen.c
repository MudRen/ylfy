// chen.c �½���
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_weiwang();
string ask_me();
void create()
{
    set_name("�½���", ({ "chen jin nan", "chen","nan" }));
    set("nickname", HIC "Ӣ���޵�" NOR);
    set("long", 
        "\n����һ����ʿ����������������ɫ�Ͱ���\n"
        "������������������ػ��ܶ����½���,\n"
        "��˵ʮ�˰����գ�������ͨ��\n"
        "ż������߿��������پ���Ŀ����磬Ӣ�����ˡ�\n");
    set("gender", "����");
    set("age", 45);
    set("attitude", "peaceful");
    set("shen_type", 5);
    set("str", 50);
    set("int", 50);
    set("con", 60);
    set("dex", 160);
    
    set("max_qi", 2115000);
    set("max_jing", 1322000);
    set("neili", 3225000);
    set("max_neili", 525000);
    set("jiali", 13000);
    set("combat_exp", 6400000);
    set("score", 500000);
	set("xyzx_sys/level", 1500);//2015.9�޸��������ż����npc��ǿ��
	
    set_skill("literate", 2420);
    set_skill("force", 2400);
    set_skill("dodge", 2400);
    set_skill("unarmed", 2400);
    set_skill("parry", 2400);
    set_skill("whip", 2400);
    set_skill("blade", 2400);
    set_skill("sword",2400);
    set_skill("houquan", 1400);
    set_skill("yunlong-xinfa", 1400);
    set_skill("yunlong-shengong", 1400);
    set_skill("wuhu-duanmendao", 1400);
    set_skill("yunlong-jian", 1400);
    set_skill("yunlong-shenfa", 1400);
    set_skill("yunlong-bian", 1400);
    set_skill("yunlong-shou", 1400);
    set_skill("yunlong-zhua", 1400);
    map_skill("dodge", "yunlong-shenfa");
    map_skill("force", "yunlong-shengong");
    map_skill("unarmed", "yunlong-zhua");
    map_skill("blade", "wuhu-duanmendao");
    map_skill("parry", "yunlong-zhua");
    map_skill("sword", "yunlong-jian");
    map_skill("whip", "yunlong-bian");
    create_family("������",1, "��ɽ��ʦ");
    set("class", "yunlong-xinfa");
    set("book_count", 1);
        set("inquiry", ([
        "��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
        "���" :  "\nֻҪ������ػᣬ�������λ����ѧ���ա�\n",
                "���帴��" : "ȥ�ײĵ�ͻش�����ϸ���ưɣ�\n",
                "����" : "�����£�\n",
                "�п�" : "�����£�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
        "��������" : (: ask_me :),
       ]) );
    set("chat_chance_combat", 70);  


    set("chat_msg_combat", ({
        "\n�½���ҡͷ̾�����۵��������������������������Ǻο���?\n",
        (: command("smile") :),
        (: command("poem") :),
        (: command("nomatch") :),
        (: command("haha") :),
        (: command("chat ��λ" + RANK_D->query_respect(this_player())+",������ԩ�޳𣬺α����?\n") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
(: perform_action, "sword.xunlei" :),	
(: perform_action, "sword.xunlei" :),	
(: perform_action, "sword.xian" :),	
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
                      }) );
    setup();
    carry_object("/clone/cloth/jinduan")->wear();
    carry_object("/d/city2/obj/yaodai")->wear();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/city2/obj/hlbian")->wield();
    carry_object("/clone/weapon/gangdao")->wield();
}
string ask_me()
{
        mapping fam; 
        object ob;
        if (!(fam = this_player()->query("family")) 
        || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ������澭���ڴ˴���";
        add("book_count", -1);
        ob = new("/d/city2/obj/yljianpu");
        ob->move(this_player());
        return "�ðɣ��Ȿ���������ס����û�ȥ�ú����С�";
}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("yunlong-shengong", 1) < 50) {
        command("say �����������ڼ��书���������ڹ��ķ���"); 
        command("say " + RANK_D->query_respect(ob) + 
            "�Ƿ�Ӧ�����������϶��µ㹦��");
        return;
    }
    if ((int)ob->query("weiwang") <60) {
        command("say ���������书�����޵У��������ţ�\n�ش����������������壬Ϊ���²���ı������\n"); 
        command("say " + RANK_D->query_respect(ob) + 
            "�Ƿ�Ӧ���ȳ�ȥ��һ�������������춯�صĴ��£�");
    return ;
    }
    if ((int)ob->query("shen") >0&&(int)ob->query("shen") < 100000) {
        command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
    return ;
    }
    if(ob->query("weiwang")<80)
    {
    if((int)ob->query("shen")<0) command("say "+ RANK_D->query_respect(ob) +"��Ȼ��а�����ˣ���Ҳ������Щ���¡�\n");
    command("chat ����ػ�������Ϊ����һ����ǰ����δ��֮�¡�\n");
    command("chat ���¿������ң��������ţ������Ȼ���ֺ����ۣ�\n");
    command("chat �����������ɣ���\n");
    command("chat �벻����һ������ҵ�������������˴��ˣ�����������������\n");
    message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
    ob->set("weiwang",80);
    }
    command("recruit " + ob->query("id"));
    if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
        ob->set("class","fighter");
}
int do_skills(string arg)

{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="chen" )
     return 0;
   if(wizardp(ob))  return 0;
   if (ob->query("weiwang")<50)
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
   return 1;
   }
   tell_object(ob,this_object()->name()+"˵�������еĻ����书���£�\n"+
"  �������� (blade)                         - ��ɲ� 2400/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 2400/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 2400/    0\n"+
"  ����д�� (literate)                      - ��ɲ� 2420/    0\n"+
"  �����м� (parry)                         - ��ɲ� 2400/    0\n"+
"  �������� (sword)                         - ��ɲ� 2400/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 2400/    0\n"+
"  �����޷� (whip)                          - ��ɲ� 2400/    0\n"+
"  �����ķ� (yunlong-xinfa)                 - ��ɲ� 2400/    0\n"+
"  ����צ (yunlong-zhua)                    - ��ɲ� 2400/    0\n"+
"����ȭ (houquan)                           - ��ɲ� 1450/    0\n"+
"���廢���ŵ� (wuhu-duanmendao)             - ��ɲ� 1400/    0\n"+
"�������� (yunlong-bian)                    - ��ɲ� 1400/    0\n"+
"���������� (yunlong-jian)                  - ��ɲ� 1400/    0\n"+
"�������� (yunlong-shenfa)                - ��ɲ� 1400/    0\n"+
"�������� (yunlong-shengong)              - ��ɲ� 1400/    0\n"+
"�������� (yunlong-shou)                    - ��ɲ� 1400/    0\n");
return 1;
}
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n�½���˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("�½�����˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
    return notify_fail("��Ҫ����ʲô��֯��\n"); 
  if (ob->query("weiwang")<20)
        {
    command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
    message_vision(HIC "�½��϶�$Nҡ��ҡͷ˵����Ľ�������ֵ̫�͡�\n" NOR,this_player());
    return 1;
    }
   if(ob->query("weiwang")<50)
   {
    ob->set("weiwang",50);
    message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
    return 1;   
   }
   else message_vision(HIC "�½��϶�$Nҡ��ҡͷ˵�����Ѿ�������ػ��ˡ�\n" NOR,this_player());
   return 1;
}
