#include <ansi.h>

inherit NPC;

void create()
{
  set_name("����",({ "meng yun", "dizi","girl" }) );
  set("gender", "Ů��" );
  set("title",YEL+"�۽��"+NOR);
  set("long", "�����ֵ���֮һ,ר�ſ�����Щ͵������.\n");
  set("age", 15+random(10));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",34000000);
  set("neili",9500);
  set("max_neili",9500);
  set("force_factor", 100);
  set("max_jing", 14000);
  set("max_qi", 14000);
  set("max_jingli", 14000);
  set("inquiry",([
  "��ȥ":"Ҫ���ȥ,�ȹ��������.\n",
  ]));
  set_skill("unarmed",350);
  set_skill("dodge",350);
  set_skill("parry",350);
  set_skill("whip",350);
  set_skill("force",350);
  set_skill("baihua-zhang",350);
  set_skill("qiongya-bufa",350);
  map_skill("dodge","qiongya-bufa");
  map_skill("parry","baihua-zhang");
  map_skill("unarmed","baihua-zhang");
  
  set("chat_chance",6);
  set("chat_msg",({
  "����˵��:�������Щ������å��.\n",
  "���ƺٺ�һЦ,��������,���ȥ������.\n",
  "���Ƶ�:Ҫ���ȥ,���ȹ��������.\n",
}));

  setup();
  carry_object("/d/hainan/obj/triger_cloth")->wear();
  carry_object("/d/hainan/obj/whip")->wield();
}
