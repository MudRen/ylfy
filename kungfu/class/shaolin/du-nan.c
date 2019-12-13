// dunan.c
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("����", ({ "du nan", "nan" }) );
    set("title", "���ֳ���");
    set("gender", "����");
    set("age", 90);
    set("class", "bonze");
    set("long",
        "����һ��������ݣ��ݹ��㶡����ɮ������ɫ��ڣ������������ɡ�\n");
    set("attitude", "peaceful");
    set("combat_exp", 5500000);
    set("score", 200000);
    set("str", 30);
    set("int", 30);
    set("cor", 30);
    set("cps", 30);
    set("con", 130);
    set("dex", 130);
	set("qi", 4000);
    set("max_qi", 2000);
    set("neili", 4000);
    set("max_neili", 2000);
    set("jiali", 80);
    create_family("������", 35, "����");
    assign_apprentice("����", 0);
    set_skill("force", 350);
      set_skill("literate", 350);
    set_skill("whip", 360);
    set_skill("parry", 380);
    set_skill("dodge", 380);
    set_skill("hunyuan-yiqi", 350);
    set_skill("riyue-bian", 300);
    set_skill("shaolin-shenfa", 380);
    map_skill("force", "hunyuan-yiqi");
    map_skill("whip",  "riyue-bian");
    map_skill("parry", "riyue-bian");
    map_skill("dodge", "shaolin-shenfa");
    set("inquiry", ([
        "������"     : (: ask_me :),
    ]));
    set("count", 1);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "whip.chan" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/d/shaolin/obj/cheng-cloth")->wear();
    carry_object("/clone/weapon/changbian")->wield();
}
void init()
{
    object me, ob;
    mapping fam;
    me = this_player();
    ob = this_object();
   if (this_object()->query("startroom") != base_name(environment()) )  return;
    ::init();
    if( interactive(me) ) 
    {
        if ( mapp(fam = me->query("family")) && fam["family_name"] == "������" 
        && fam["generation"] == 36 ) return;
        if ( mapp(fam = me->query("family")) && fam["family_name"] == "������" 
        && fam["generation"] > 36       
        && me->query("qi") < 50 ) 
        {
            me->move("/d/shaolin/qyping");
            me->unconcious();
            return;
        }
        COMBAT_D->do_attack(ob, me, query_temp("weapon") );
        me->set_temp("fighter", 1);
        
        ob->fight_ob(me);
        me->fight_ob(ob);
        call_out("halt", 10, me);
        return;
    }
    return;
}
void halt()
{
    command("halt");
}
string ask_me()
{
    object ob;
    
    if ( !this_player()->query_temp("fighter") 
    ||    this_player()->query("combat_exp") < 5000 )
    {
        command("say ���󱲣����δ�ɣ�����͵���շ�ħȦ�������������������㣡");
        this_object()->kill_ob(this_player());
        this_player()->kill_ob(this_object());
    }
    if ( present("puti zi", this_player()) )
        return RANK_D->query_respect(this_player()) + 
        "������ֻ��һ�ţ����Ҿ��������ϣ�����̰�����У�";
    if ( present("puti zi", environment()) )
        return RANK_D->query_respect(this_player()) + 
        "������ֻ��һ�ţ����Ҿ�����������ȡ�ߣ�����̰�����У�";
    if (query("count") < 1)
        return "�����������֮����ɼ������ޱȣ����������ڿ�û�С�";
    if(random((int)this_player()->query("kar")) < 24)
    {
        command("kick " + this_player()->query("id"));
        this_player()->set_temp("marks/no_putizi",1);
        return "�ߣ�";
    }
    else if(this_player()->query_temp("marks/no_putizi",1))
        return "����˵��û�������ʲô����";
    ob = new("/d/shaolin/obj/puti-zi");
    ob->move(this_player());
    add("count", -1);
    message_vision("\n���Ѳ�ȻһЦ�����ų�̾һ������������ȡ���������ƿ�����������ӵݸ�$N��\n\n", this_player());
    return "�ҵ������ڷ�����ǰ���º�Ը��ÿʮ������ɽ�󴨣��������գ�\n" +
           "���ɵ����������ӣ�������Ե�ˣ��ܵô��컯���������Ϊ֮��";
}
#include "/kungfu/class/shaolin/du.h"
