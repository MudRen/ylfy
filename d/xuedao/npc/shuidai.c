// shuidai.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("ˮ�", ({ "shui dai", "shui" }));
       set("long", 
       "�����������桰�仨��ˮ���е����ġ�\n"
       "��������н��ϣ��������壬ˮ��主�׶��ϣ�����ȴ������ɫ��\n");
       set("gender", "����");
       set("nickname", HIC"���½�"NOR);
       set("age", 39);
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
set("jiali", 1030);
set("combat_exp", 120000000);
       set("shen_type", 1);

set_skill("force", 1300);
set_skill("zixia-shengong", 1000);
set_skill("dodge", 1300);
set_skill("huashan-shenfa", 1300);
set_skill("strike", 1000);
set_skill("huashan-zhangfa", 1000);
set_skill("parry", 1000);
set_skill("sword", 1300);
set_skill("huashan-jianfa", 1300);
set_skill("literate", 800);

       map_skill("force", "zixia-shengong");
       map_skill("dodge", "huashan-shenfa");
       map_skill("strike", "huashan-zhangfa");
       map_skill("parry", "huashan-jianfa");
       map_skill("sword", "huashan-jianfa");
map_skill("unarmed", "huashan-zhangfa");
       set("chat_chance", 20);
       set("chat_msg", ({
              "ˮ᷼���������Х����磺���仨��ˮ�������������ƾ�����ԶԶ������\n",
	}));
set("chat_chance_combat", 100);			
set("chat_msg_combat", ({		
(: perform_action, "sword.jianzhang" :),		
(: perform_action, "sword.wushuang" :),		
(: exert_function, "recover" :),		
}) );		
       setup();
       carry_object("/clone/weapon/changjian")->wield();
}

