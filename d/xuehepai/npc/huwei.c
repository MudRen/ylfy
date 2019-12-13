

inherit NPC;
int ask_me();
#include <ansi.h>
void create()
{
        set_name("����", ({ "hu wei", "wei"}) );
        set("gender", "����" );
        set("age", 22);
//      set("title", "Ѫ����");
        set("long",
                "��λ������Ц����ؿ����㡣\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("yiqiguan-riyue",1);
        
        set("max_neili",20000);
        set("neili",20000);
        set("max_qi",20000);
        set("eff_qi",20000);
        set("qi",20000);
        set("max_jingli",20000);
        set("eff_jingli",20000);
        set("jingli",20000);
        
        set_skill("force",300);
        set_skill("dodge",300);
        set_skill("parry",300);
        set_skill("blade",300);
        set_skill("cuff",300);
        set_skill("yiqiguan-riyue",300);
         set_skill("huaxue-dafa",300);
        set_skill("youran-bu",300);
        set_skill("jieniu-dao",300);
		set_skill("taoism",70);
        set_skill("literate",300);
        set_skill("feixue-quan",300);
        
        map_skill("force","yiqiguan-riyue");
        map_skill("dodge","youran-bu");
        map_skill("cuff","feixue-quan");
        map_skill("parry","jieniu-dao");
        map_skill("blade","jieniu-dao");
        
        prepare_skill("cuff","feixue-quan");
        
        create_family("Ѫ����",14,"����");
        setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("silver",20);
        set("chat_chance",1);
        set("chat_msg",({
                (: exert_function, "heal" :),
        }));
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (: exert_function, "recover" :),
        }));
        set("inquiry",([
                "cancel" : (: ask_me :),
        ]));

}

void init()
{       
        object ob;

        ::init();
          if( interactive(ob = this_player()) && !is_fighting() && this_player()->query_temp("xhjob_start") ) {
                   command("sweat");
                   write("�������Ҷ�æ�������ˡ�������(shouwei)ס��������ý�����ʿͨ����\n");
              }
}


int ask_me()
{
                object me;
                mapping family;

                me=this_player();
                family=(mapping)me->query("family");

                if ( !family || family["family_name"]!="Ѫ����")      return 0;
                if ( me->query_temp("xhjob_start") || me->query_temp("shouwei") )  {
                command("poor "+me->query("id"));
                command("say �ðɣ�"+me->query("name")+"���߰ɡ�");
                me->add("combat_exp",-(me->query("combat_exp")/1000));
                me->add("potential",-(me->query("potential")/1000));
                me->delete_temp("shouwei");
                me->delete_temp("xhjob_start");
                if (environment(me)->query("renshu"))  environment(me)->add("renshu",-1);
                return 1;
                }
                return 0;
}


