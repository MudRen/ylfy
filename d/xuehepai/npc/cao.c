// made by lks

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "xiao.h"
#include "cloth.h"
#include "caojob.h"
void heal_ob();
int ask_me();
void recover_ob();

void create()
{
        set_name("�ܴ�",({"cao dabei","cao"}));
        set("nickname",RED"Ѫ��׷�"NOR);
	set("gender","����");
       set("shen_type",-1);
	set("int",30);	
	set("con",30);
	set("str",30);
	set("dex",30);
	set("bac",40);
        set("book",1);
        set("age",30);
	set("attitude","peaceful");
        set("combat_exp",5000000);
        set("shen",1000);
	set("long",
"Ӣ������,��ʼ�տ�����һ�����֣����Ҳѳ���ˡ�\n"
	);
        set("neili",20000);
        set("jingli",18000);
        set("max_neili",20000);
        set("max_jingli",18000);
        set_skill("yiqiguan-riyue",150);
        set_skill("literate",100);
        set_skill("cuff",350);
        set_skill("parry",350);
        set_skill("dodge",350);
        set_skill("youran-bu",350);
        set_skill("tianhe-jian",350);
        set_skill("sword",350);
        set_skill("force",350);
        set_skill("throwing",350);
        set_skill("huaxue-shenzhen",350);
        set_skill("taoism",300);
        set_skill("feixue-quan",350);
        set_skill("huaxue-dafa",350);
        map_skill("force","huaxue-dafa");
        map_skill("dodge","youran-bu");
        map_skill("cuff","feixue-quan");
        map_skill("throwing","huaxue-shenzhen");
        map_skill("sword","tianhe-jian");
        prepare_skill("cuff","feixue-quan");
	
       create_family("Ѫ����",13,"����");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
        set("chat_chance", 2);
	set("chat_msg", ({
		(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: exert_function, "xisui" :),
                (: exert_function, "xuewu" :),
                (: recover_ob :),
	}) );
       set("inquiry",([
              "job" : (: ask_job :),
       ]));
}

	
void heal_ob()
{
	command("exert heal");
	command("exert recover");
	return;
}

void recover_ob()
{
	command("exert recover");
	return;
}

int ask_me()
{
           object ob;
          // mapping fam;

           object me=this_player();

           if (!me->query("family") || me->query("family/family_name")!="Ѫ����")
           {
                  command("say ���뱾�ɲ��޹ϸ𣬴˻��Ӻ�˵��");
                  return 1;
           }
            if (!query("book"))
            {
                 command("say �ؼ��Ѿ��������ˡ�");
                 return 1;
            }
                  command("say �ðɣ��⼸��������ȥ�ú��о�һ�¡�");
                   set("book",0);
                   if (me->query("combat_exp")>100000) {
                  ob=new("/d/xuehepai/obj/miji");
                  ob->move(me);
                   }				
                  return 1;
}

