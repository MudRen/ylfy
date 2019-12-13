// xiaoqiushui.c ����ˮ
#include <ansi.h>
inherit NPC;
void init();
string ask_me_1();
inherit F_MASTER;
int flag=0;
void create()
{
        set_name("����ˮ", ({ "xiao qiushui", "xiao", "qiushui" }));
        set("nickname", HIR "����"NOR);
        set("long", 
"����ˮ��Ĳ��ߣ�������Ũü���ۣ�����ȥ�����Ѱ�������\n"
"佻������������������ڽ�������һ�����Ķ�����֡�\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("per",30);
        set("max_qi", 80000);
        set("jing", 80000);
        set("max_jing", 80000);
        set("neili", 1500000);
        set("max_neili", 4400);
        set("jiali", 3000);
        set("combat_exp", 100000000);
        set("score", 100000);
        set_skill("cuff", 1200);	
        set_skill("strike",1200);	
        set_skill("force", 1200);	
        set_skill("dodge", 1200);	
        set_skill("parry", 1200);	
        set_skill("unarmed",1200);	
        set_skill("sword", 1200);
        set_skill("literate",1100);
        set_skill("huanhua-jian",1100);	
        set_skill("tiexian-quan",1000);
        set_skill("guiyuan-dafa",1100);	
        set_skill("feihua-wuping",1100);	
         map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");
     
        create_family("佻�����", 2, "����");
        
        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: perform_action, "sword.snow" :),
                (: exert_function, "recover" :),
        }) );
        
       
        set("inquiry", ([
                "���ݽ���" : "�����Һͼ������������߽���ʱ�����µ�.\n",
                "�Ʒ�" : "����������Ϣ��˵�գ���������鼤��,�����۾����ģ�\n",
                "����"       : (: ask_me_1 :),                
             ]));
      
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/huanhua/obj/changge")->wield();
      
}
/*
void init()
{
       object ob;
       ::init();
       if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        ob = this_player();
        if((int)ob->query("score") < 50 &&ob->query("family/master_id")=="xiao qiushui")
        {
                    command("chat "+ob->query("name")+"!��Ϊ�˲��Ҳ��壬�������������ʦ����\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","佻�����" + RED + "��ͽ" NOR);   
        }
 }
                
}
*/
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("����ˮ̾�˿���:�Ʒ�,�Ʒ���������?\n");
        
}
string ask_me_1()
{
        mapping fam; 
        object obj,me;
        
        me=this_object();
        if(objectp(obj = present("changge sword", me)))
        {
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "佻�����")
                return RANK_D->query_respect(this_player()) + 
                "���Ǳ��ɵ��ӣ���֪�˻��Ӻ�̸��";
        if ( (int)this_player()->query("shen") < -1000 )
                return RANK_D->query_respect(this_player()) + 
                "��ɱ��̫�أ��������ܽ������ϣ�";
        
        command("give changge sword to "+this_player()->query("id"));        
        message_vision("$N���һ�ѳ��轣��\n",this_player());
        
        return ("�ðɣ�������ѽ�����Ҫ��û������佻����ҡ�");
        }
        else return("�������ˣ������Ѿ�����������!\n");                 
        
}
void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<100000)
        {
          message_vision("����ˮ��$NЦ������ľ���̫����,�һ��������㣡\n",ob);
        return ;
         }
   if ((int)ob->query("score") < 300 ) {
        command("say ��Ա��ŵĹ��׻�����,����Ŭ��ѽ!");
                return;
          }
   message_vision("����ˮ����$N��ͷ��΢΢���˵�ͷ��\n",ob);
   ob->set("class", "swordsman");
   ob->set("title","佻�������������");   
   command("recruit " + ob->query("id"));
   return;
}
void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;
        if (arg == "xiao qiushui" || arg == "xiao")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}
       
int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));
        if ( me->is_fighting()) return 0;
        if ( !present(ob, environment()) ) return 0;
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}
int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;
        if ( !present(ob, environment()) ) return 1; 
        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");
        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }
        return 1;  
}
