#include <ansi.h>
inherit NPC;
void create()
{
  set_name("С��", ({ "xiao yi" , "yi" , "xiaoyi"}) );
  set("gender", "Ů��");
  set("age", 25);
  set("title",MAG"������"NOR);
  set("long","һ��������СѾͷ.\n");
  set("attitude", "peaceful");
  set("combat_exp", 8000000);
  set("per", 30);
  set("int",30);
  set_skill("parry", 400);
  set_skill("unarmed", 400);
  set_skill("dodge", 400);
  set_skill("sword", 400);
  set_skill("force", 400);

  set_skill("baihua-zhang", 400);
  set_skill("feixian-jian", 400);
  set_skill("bitao-shengong", 400);
  set_skill("qiongya-bufa", 400);
  map_skill("sword", "feixian-jian");
  map_skill("unarmed", "baihua-zhang");
  map_skill("parry", "feixian-jian");
  map_skill("force","bitao-shengong");
  map_skill("dodge","qiongya-bufa");
  set("max_qi",12000);
  set("max_jing",12000);
  set("max_jingli",12000);
  set("neili",50000);
  set("max_neili",50000);
  set("force_factor",800);
  setup();
  carry_object("/d/hainan/obj/zishan")->wear();
  carry_object("/d/hainan/obj/shixuejian")->wield();
  add_money("gold",10);
}

