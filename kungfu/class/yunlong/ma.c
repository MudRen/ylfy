
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_weiwang();
string ask_me();
void create()
{
    set_name("����", ({ "ma chaoxing", "ma"}));
    set("gender", "����");
    set("long", "\n��������ػ��˳����������ʹһ���󵶡�\n");
    set("attitude", "peaceful");
    set("age", 45);
    set("int", 30);
    set("str", 30);
	set("dex", 30);
	set("con", 30);
    set("qi", 1500);
    set("max_qi", 1500);
    set("jing", 500);
    set("neili",2000);
    set("max_neili",1000);
    set("shen_type", 1);
    set("combat_exp", 250000);
    set_skill("force", 120);
    set_skill("unarmed",120);
    set_skill("parry", 120);
    set_skill("dodge", 120);
    set_skill("sword", 120);
    set_skill("blade", 120);
    set_skill("whip", 120);
    set_skill("yunlong-shengong", 120);
    set_skill("yunlong-shenfa", 120);
    set_skill("wuhu-duanmendao", 120);
    set_skill("houquan", 120);
    set_skill("yunlong-jian", 120);
    set_skill("yunlong-bian", 120);
    set_temp("apply/attack", 25);
    set_temp("apply/defense", 25);
    set_temp("apply/damage", 25);
    map_skill("force", "yunlong-shengong");
    map_skill("dodge", "yunlong-shenfa");
    map_skill("parry", "wuhu-duanmendao");
        map_skill("blade","wuhu-duanmendao");
    map_skill("sword", "yunlong-jian");
    map_skill("whip", "yunlong-bian");
        map_skill("unarmed","houquan");
    create_family("������",2, "����");
    set("class", "yunlong-xinfa");
    set("book_count", 1);
        set("inquiry", ([
        "�½���" :  "\n��������ֵ�ﵽ70�Ϳ��԰��ܶ���Ϊʦ��\n",
        "��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
        "���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ�书��\n",
                "���帴��" : "ȥҩ�̺͹ײĵ���ϸ���ưɣ�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
        "������" : (: ask_me :),
       ]) );
    set("chat_chance_combat", 50);  
    set("chat_msg_combat", ({
        (: command("smile") :),
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
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
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
    carry_object("/clone/weapon/changbian")->wield();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/city2/obj/dadao")->wield();
    carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",20);
}
void init()
{
::init();
add_action("do_join","join");
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n����˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
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
        ob = new("/d/city2/obj/yljing1");
        ob->move(this_player());
        return "�ðɣ��Ȿ�������������û�ȥ�ú����С�";
}
void attempt_apprentice(object ob)
{
if((string)ob->query("gender")=="����")
           {
        command("say �����Ŷ������أ��������������ķ��ˣ���");
        return;
       }
    command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
        "�ұ����ˣ������������ɡ�");
    command("recruit " + ob->query("id"));
    if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
        ob->set("class","fighter");
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
    message_vision(HIC "���˶�$Nҡ��ҡͷ˵����Ľ�������ֵ̫�͡�\n" NOR,this_player());
    return 1;
    }
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
    return 1;
    }
   else return notify_fail("���Ѿ�������ػ��ˣ�\n"); 
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
               if(random(5)<2) say( "����Ц������λ" + RANK_D->query_respect(ob)
                + "������ʲô��ƽ֮��ô��\n");
 
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="ma" )
     return 0;
   if(wizardp(ob))  return 0;
   if (ob->query("weiwang")<50)
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
   return 1;
   }
   command("tell "+ob->query("id")+" �����еĻ����书���£�\n"+
"  �������� (blade)                         - ��ɲ� 120/    \n"+
"  �����Ṧ (dodge)                         - ��ɲ� 120/    \n"+
"  �����ڹ� (force)                         - ��ɲ� 120/    \n"+
"  �����м� (parry)                         - ��ɲ� 120/    \n"+
"  �������� (sword)                         - ��ɲ� 120/    \n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 120/    \n"+
"  �����޷� (whip)                          - ��ɲ� 120/    \n"+
"���廢���ŵ� (wuhu-duanmendao)             - ��ɲ� 120/    \n"+
"����ȭ (houquan)                           - ��ɲ� 120/    \n"+
"�������� (yunlong-bian)                    - ��ɲ� 120/    \n"+
"���������� (yunlong-jian)                  - ��ɲ� 120/    \n"+
"�������� (yunlong-shenfa)                - ��ɲ� 120/    \n"+
"�������� (yunlong-shengong)              - ��ɲ� 120/    \n");
 return 1;
}
