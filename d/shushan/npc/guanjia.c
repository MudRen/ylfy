//shushan2 by yushu@SHXY 2000.12
#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�ܼ�", ({ "guan jia"}) );
  set("gender", "����");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");
  set("str", 30);
  set("max_qi", 200);
set("max_jingli", 200);
set("max_neili", 200);
set("neili", 200);
set("jingli", 200);
  set("jiali", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);
  setup();
   carry_object("clone/cloth/cloth")->wear();
 carry_object("/clone/weapon/blade")->wield();
}

