//jianshen.c by yushu 2001.2
// lilong alter 2002.01.18
inherit NPC;
void check_fight (object npc, object me);
int accept_fight(object me);
void player_win(object me);
void player_lose(object me);
#include <ansi.h>
void create()
{
       set_name("����", ({"jianshen","shen"}));
       set("gender", "����");
       set("age", 120);
	set("class", "xiake");
       set("attitude", "friendly");
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
	set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
	set("shushan/jianshen_cast", 1);
	set("int", 30);
       set("max_qi", 10000000);
       set("max_jing", 10000000);
       set("neili", 10000000);
	   set("jingli", 10000000);
       set("max_neili", 10000000);
        set("max_jingli", 10000000);
		set("combat_exp", 2100000000);
         set("jiali",30000);
		 set("no_suck", 1);
       set_skill("literate", 3000);
       set_skill("dodge", 3000);
       set_skill("parry", 3000);
       set_skill("unarmed", 3000);
       set_skill("fumozhang",3000); 
	set_skill("sword", 3000);
         set_skill("songhe-sword", 3000);
         set_skill("shushan-force", 3000);
	set_skill("force", 3000);
      set_skill("zuixian-steps", 3000);
       map_skill("force", "shushan-force");
	map_skill("sword", "songhe-sword");
	map_skill("parry", "songhe-sword");
	map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       /*set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "jianshen" :),
        }) );*/
        setup();
    carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void check_fight (object npc, object me)
{
  int npc_qi, my_qi, my_ratio, npc_ratio;
  int npc_max_qi, my_max_qi;
 
  my_qi = me->query("qi");
  npc_qi = npc->query("qi");
  my_max_qi = me->query("max_qi");
  npc_max_qi = npc->query("max_qi");
  my_ratio=my_qi*100/my_max_qi;
  npc_ratio=npc_qi*100/npc_max_qi;

  if (is_fighting())
  {
    call_out ("check_fight",2,npc,me);
    return;
  }
  if (query_temp("last_opponent")!=me) return;
  if (!present(me, environment(npc)))
    return;
  if(npc->query("qi")*100/npc->query("max_qi")
   < me->query("qi")*100/me->query("max_qi"))
    call_out("player_win", 1, me);
  else call_out("player_lose", 1, me);
  return;
}

int accept_fight(object me)
{
      set("qi", query("max_qi"));
      set("neili", query("max_neili"));
      remove_call_out("check_fight");
      call_out("check_fight", 1, this_object(), me);
      return 1;
}

void player_win(object me)
{
    this_object()->delete_temp("last_opponent");
    command("say ���!���!��Ȼ��ϰ��֮�š�");
    command("say �ҾͰѽ�����������̸���ѡ�");
    command("say ������ڣ�����");
    me->set("shushan/xiangsi",1);
    me->move("d/shushan/cangjingge");
    return;
}

void player_lose(object me)
{
    this_object()->delete_temp("last_opponent");
    command("say "+RANK_D->query_respect(me) +"�������٣��ٽ�������");
    return;
}
