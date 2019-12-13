#include <ansi.h>
inherit NPC;
int ask_gao();
void create()
{
    set_name("��ѩͤ", ( { "xu xueting", "xu" }) );
    set("title", "����������ʹ");
    set("nickname", HIR "��Ѫ����" NOR);
    set("gender", "����" );
    set("age", 55);
    set("long", "���Ǹ���ʮ����ĸ��ݺ��ӣ���һϮ���£���Ȼͦ����\n" );
    set("int", 30);
    set("str", 25);
    set("con", 23);
    set("dex", 22);
    
    set_temp("apply/attack", 100);
    set_temp("apply/defense", 100);
    set_temp("apply/damage", 100);
    set("qi",10000);
    set("max_qi", 10000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 150);
    set("combat_exp", 5000000);
    set("score", 250000);
    set_skill("force", 90);
    set_skill("taiji-shengong", 80);
    set_skill("dodge", 90);
    set_skill("tiyunzong", 80);
    set_skill("unarmed", 90);
    set_skill("taiji-quan", 80);
    set_skill("parry", 90);
    set_skill("sword", 100);
    set_skill("taiji-jian", 90);
    set_skill("taoism", 150);
    set_skill("literate", 60);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
       set("inquiry", ([
        "�ٻ����߸�" : (: ask_gao :),
        "������" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
        "�鰲ͨ" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
        "����" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
        "���" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
        "�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
    ]));
        set("chat_chance", 3);
        set("chat_msg", ({
"��ѩͤ��Ȼһ���Դ���˵�����ˣ������ðٻ����߸࣡\n",
"��ѩͤŭ��������ټ��һ�������̣�������һ����ô�����ˣ�\n",
"��ѩͤ̾������˵����������ɱ�˺鰲ͨ��˭Ҳ��ˡ�\n",
        }) );
    setup();
        carry_object("/clone/weapon/duanjian")->wield();
		carry_object("/clone/cloth/cloth")->wear();
}
int ask_gao()
{
say(
"\n��ѩͤ��������˵������Ǳ��̽��ﰡ����һ����Ѫ������Ũ�㣬\n"
"����ס�������ߵ��ϣ����˶��������ۻƾƣ��Աܶ��ߣ��������\n"
"һ�����ۻƾƣ���ʹ�˽���������ܶ��������ˣ�����ôҲ֪����\n"
        );
return 1;
}
int accept_object(object who, object ob)
{
    object obn;
    if( !who || environment(who) != environment() ) return 0;
    if ( !objectp(ob) ) return 0;
    if ( !present(ob, who) ) return notify_fail("��û�����������\n");
    if (  (string)ob->query("name") != "���ߵ�"
        && (string)ob->query("name") != HIG "���㻨" NOR )
            return notify_fail("��ѩͤҡͷ�������ɱ���˺鰲ͨ������ʲôҲû�ð�������\n");
    if ( (string)ob->query("name") == "���ߵ�" )
        {
          if(query_temp("baixianghua"))
          {
          message_vision("\n��ѩͤ���Ǹ��ߵ�����ϲ�������ߵ����㻨������,�ٻ����߸�������!\n",who);
          obn=new("/d/shenlong/obj/baihua");
                  obn->move(who);
          delete_temp("fushedan");
          delete_temp("baixianghua");
               return 1;         
          }         
          else  
          { 
          if(query_temp("fushedan"))
                  {
          message_vision("\n��ѩͤ���Ǹ��ߵ�����$Nҡͷ�������ߵ������ˣ��Ͳ���㻨�ˡ�\n",who);
               return 0;
          }
          else    
                  {
          message("vision","��ѩͤ�������ߵ�����ϲ�������˸��ߵ���ֻ����㻨�ˡ�\n",environment(who));
          set_temp("fushedan",1);   
              return 1;
          }
        }
    }
    if ( (string)ob->query("name") == HIG "���㻨" NOR)
        {
          if(query_temp("fushedan"))
          {
          message_vision("\n��ѩͤ���ǰ��㻨����ϲ�������ߵ����㻨������,�ٻ����߸�������!\n",who);
          obn=new("/d/shenlong/obj/baihua");
                  obn->move(who);
          delete_temp("fushedan");
          delete_temp("baixianghua");
              return 1;      
          }         
          else  
          { 
          if(query_temp("baixianghua"))
                  {
          message_vision("\n��ѩͤ���ǰ��㻨����$Nҡͷ�������㻨�����ˣ��Ͳ�ߵ��ˡ�\n",who);
               return 0;
          }
          else    
                  {
          message("vision","��ѩͤ�������㻨����ϲ�������˰��㻨��ֻ��ߵ��ˡ�\n",environment(who));
          set_temp("baixianghua",1);    
              return 1;
          }
         }  
    }
}
int recognize_apprentice(object ob)
{
    if (!ob->query("shenlongjiao"))
    {
    message_vision("$Nҡ��ҡͷ��\n",this_object());
    command("tell "+ob->query("id")+"�����ز���ʶ������ʲôҪ�����أ� \n"); 
    return 0;
    }
    return 1;   
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
    if( !arg || arg!="xu" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$Nҡ��ҡͷ��\n",this_object());
   write("��ѩͤ˵��������ô�ܿ��ҵ��书�أ�\n");
   return 1;
  }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - һ����ʦ  90/    \n"+
"  �����ڹ� (force)                         - һ����ʦ  90/    \n"+
"  ����д�� (literate)                      - ��Ȼ���  60/    \n"+
"  �����м� (parry)                         - һ����ʦ  90/    \n"+
"  �������� (sword)                         - ��ɲ� 100/    \n"+
"��̫������ (taiji-jian)                    - һ����ʦ  90/    \n"+
"��̫��ȭ (taiji-quan)                      - �Ƿ��켫  80/    \n"+
"��̫���� (taiji-shengong)                - �Ƿ��켫  80/    \n"+
"  ��ѧ�ķ� (taoism)                        - ��ɲ� 150/    \n"+
"�������� (tiyunzong)                       - �Ƿ��켫  80/    \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  90/    \n");
 return 1;
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
    return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if(ob->query("shenlongjiao")) 
    {
    message_vision(HIC "��ѩͤ˵�������Ѿ��������̵����ˡ�\n" NOR,this_player());
    return 1;
    }
   if ((int)ob->query("shen")>-1000)
        {
    message_vision(HIC "��ѩͤ��$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
   if (ob->query("combat_exp")<20000)
        {
    message_vision(HIC "��ѩͤ��$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
    return 1;
    }
  if ( ob->query_skill("bibo-shengong",1)
    || ob->query_skill("hamagong",1)
    || ob->query_skill("huagong-dafa",1))
   {
    ob->set("shenlongjiao",1);
    command("tell "+this_player()->query("id")+" �����ھ��������̵�����.\n");
    return 1;   
   }
   else 
   {
   message_vision(HIC "��ѩͤ��$N��ŭ�����������?һ����Ͳ��Ǻ���!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
}
