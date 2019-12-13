// Npc: /kungfu/class/shaolin/hui-zhen.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��������", ({
        "huizhen zunzhe",
        "huizhen",
        "zunzhe",
    }));
    set("long",
        "����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
        "̫��Ѩ΢͹��˫Ŀ��������\n"
    );
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 50);
    set("str", 30000);
    set("int", 30);
    set("con", 30);
    set("dex", 30000);
    set("max_qi", 6000);
    set("max_jing", 5000);
    set("neili", 10000);
    set("max_neili", 8000);
    set("jiali", 1000);
    set("combat_exp", 15000000);
    set_skill("force", 100);
    set_skill("hunyuan-yiqi", 80);
    set_skill("dodge", 800);
    set_skill("shaolin-shenfa", 800);
    set_skill("unarmed", 90);
    set_skill("yizhi-chan", 90);
    set_skill("unarmed", 70);
    set_skill("banruo-zhang", 70);
    set_skill("sword", 80);
    set_skill("damo-jian", 80);
    set_skill("parry", 80);
    set_skill("buddhism", 100);
    set_skill("literate", 100);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "yizhi-chan");
    map_skill("sword", "damo-jian");
    map_skill("parry", "damo-jian");
    
    create_family("������", 38, "����");
    setup();
         carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
void init()
{
    object me, room;
   if (this_object()->query("startroom") != base_name(environment()) )  return;
 if (!living(this_object())) return;
    me = this_player();
    if(!( room = find_object("/d/shaolin/cjlou")) )
    room = load_object("/d/shaolin/cjlou");
  if ( !present("daoyi chanshi", room) && !present("letter", me) )
    {
          command("say �󵨿�ͽ������ɱ�˴���ؾ��󣬿���!\n");
          call_out("kill_ob", 0, this_player()); 
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));        
          return;
    }
    return;
}
