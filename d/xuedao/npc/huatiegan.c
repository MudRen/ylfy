// huatiegan.c

inherit NPC;
#include <ansi.h>
void create()
{
set_name("������", ({  "hua","Hua tiegan" }));
       set("long", 
       "�����������桰�仨��ˮ���е��϶���\n"
       "��������н��ϣ��������壬������һ����ƽǹ���ų���ƽ�޵С���������Ϊ��ȴ��զ�ġ�\n");
       set("gender", "����");
       set("nickname", HIR"��ƽ�޵�"NOR);
       set("age", 45);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

set("max_qi", 50000);
set("max_jing", 50000);
set("neili", 2000000);
       set("max_neili", 2000);
set("jiali", 900);
set("combat_exp", 100000000);
       set("shen_type", 0);

set_skill("force", 1000);
set_skill("zixia-shengong", 1000);
set_skill("dodge", 1000);
set_skill("huashan-shenfa", 1000);
set_skill("cuff", 1000);
set_skill("poyu-quan", 1000);
set_skill("parry", 1000);
set_skill("club", 1000);
set_skill("literate", 400);

       map_skill("force", "zixia-shengong");
       map_skill("dodge", "huashan-shenfa");
map_skill("unarmed", "poyu-quan");
map_skill("cuff", "poyu-quan");	
       set("chat_chance", 20);
       set("chat_msg", ({
              "�����ɻ�������������Х���糱ӿ�������仨������ˮ���������˶�����\n",
       }));
set("chat_chance_combat", 100);			
set("chat_msg_combat", ({		
(: perform_action, "unarmed.leidong" :),		
(: exert_function, "recover" :),		
}) );		
       setup();
}

